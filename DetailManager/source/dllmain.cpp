#include "dllmain.hpp"
wchar_t g_module_dir[MAX_PATH];

#define MAX_DETAILMODULE_NUM 64
#define ROUTE 9 //号線仕様


typedef void (WINAPI* DETAILMODULE_ATSLOAD)(void);
typedef void (WINAPI* DETAILMODULE_ATSDISPOSE)(void);
typedef int (WINAPI* DETAILMODULE_ATSGETPLUGINVERSION)(void);
typedef void (WINAPI* DETAILMODULE_ATSSETVEHICLESPEC)(ATS_VEHICLESPEC);
typedef void (WINAPI* DETAILMODULE_ATSINITIALIZE)(int);
typedef ATS_HANDLES (WINAPI* DETAILMODULE_ATSELAPSE)(ATS_VEHICLESTATE, int*, int*);
typedef void (WINAPI* DETAILMODULE_ATSSETPOWER)(int);
typedef void (WINAPI* DETAILMODULE_ATSSETBRAKE)(int);
typedef void (WINAPI* DETAILMODULE_ATSSETREVERSER)(int);
typedef void (WINAPI* DETAILMODULE_ATSKEYDOWN)(int);
typedef void (WINAPI* DETAILMODULE_ATSKEYUP)(int);
typedef void (WINAPI* DETAILMODULE_ATSHORNBLOW)(int);
typedef void (WINAPI* DETAILMODULE_ATSDOOROPEN)(void);
typedef void (WINAPI* DETAILMODULE_ATSDOORCLOSE)(void);
typedef void (WINAPI* DETAILMODULE_ATSSETSIGNAL)(int);
typedef void (WINAPI* DETAILMODULE_ATSSETBEACONDATA)(ATS_BEACONDATA);

struct ST_DETAILMODULE_ATS_DELEGATE_FUNC
{
    HMODULE hm_dll;
    DETAILMODULE_ATSLOAD atsLoad;
    DETAILMODULE_ATSDISPOSE atsDispose;
    DETAILMODULE_ATSGETPLUGINVERSION atsGetPluginVersion;
    DETAILMODULE_ATSSETVEHICLESPEC atsSetVehicleSpec;
    DETAILMODULE_ATSINITIALIZE atsInitialize;
    DETAILMODULE_ATSELAPSE atsElapse;
    DETAILMODULE_ATSSETPOWER atsSetPower;
    DETAILMODULE_ATSSETBRAKE atsSetBrake;
    DETAILMODULE_ATSSETREVERSER atsSetReverser;
    DETAILMODULE_ATSKEYDOWN atsKeyDown;
    DETAILMODULE_ATSKEYUP atsKeyUp;
    DETAILMODULE_ATSHORNBLOW atsHornBlow;
    DETAILMODULE_ATSDOOROPEN atsDoorOpen;
    DETAILMODULE_ATSDOORCLOSE atsDoorClose;
    DETAILMODULE_ATSSETSIGNAL atsSetSignal;
    DETAILMODULE_ATSSETBEACONDATA atsSetBeaconData;
    ATS_HANDLES last_handle;
};

int g_num_of_detailmodules;
ST_DETAILMODULE_ATS_DELEGATE_FUNC g_detailmodules[MAX_DETAILMODULE_NUM];

ATS_HANDLES g_handles[2];

bool g_first_time;

#include <sys/stat.h>
#include <stdio.h>

#include "ats_define.hpp"

#include "TranslateB.hpp"
#include "TranslateA.hpp"

TranslateA traA;
TranslateB traB;

BOOL WINAPI DllMain(
					HINSTANCE hinstDLL,  // DLL モジュールのハンドル
					DWORD fdwReason,     // 関数を呼び出す理由
					LPVOID lpvReserved   // 予約済み
					)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:

        {
            wchar_t fullpath[MAX_PATH];
            wchar_t drive[MAX_PATH],
                    dir[MAX_PATH];

            GetModuleFileNameW(hinstDLL, fullpath, MAX_PATH);
            _wsplitpath_s(fullpath, drive, MAX_PATH, dir, MAX_PATH, 0, 0, 0, 0);

            wcscpy_s(g_module_dir, drive);
            wcscat_s(g_module_dir, dir);
        }
		
        break;

	case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        {
            atsDispose();
        }
        break;
	}

	return true;
}

// Called when this plug-in is loaded
void WINAPI atsLoad()
{
    wchar_t detailmodules_txt_path[MAX_PATH];

    g_first_time = true;

    int ret;
    {
        struct _stat buf;

        g_num_of_detailmodules = 0;
        memset(g_detailmodules, 0, sizeof(ST_DETAILMODULE_ATS_DELEGATE_FUNC) * MAX_DETAILMODULE_NUM);
        memset(g_handles, 0, sizeof(ATS_HANDLES) * 2);

        wcscpy_s(detailmodules_txt_path, g_module_dir);
        wcscat_s(detailmodules_txt_path, L"\\MetropiLoader.ini");
        
        ret = _wstat(detailmodules_txt_path, &buf);
    }

    if (!ret)
    {
        FILE *fp = NULL;
        _wfopen_s(&fp, detailmodules_txt_path, L"r");

        while (!feof(fp))
        {
            char module_path[MAX_PATH];
            wchar_t module_full_path[MAX_PATH],
                    module_path_wcs[MAX_PATH];
            size_t tmp = 0;

            memset(module_path, 0, sizeof(char) * MAX_PATH);

            fgets(module_path, MAX_PATH, fp);

            {
                char* p = strchr(module_path, 10);

                if (p)
                {
                    *p = 0;
                }
            }

            wcscpy_s(module_full_path, g_module_dir);
            mbstowcs_s(&tmp, module_path_wcs, module_path, MAX_PATH);
//            wcscat(module_full_path, L"..\\..\\Plugin\\");
            wcscat_s(module_full_path, module_path_wcs);

            {
                struct _stat buf;
                int exists;
                
                exists = _wstat(module_full_path, &buf);

                if (!exists)
                {
                    g_detailmodules[g_num_of_detailmodules].hm_dll = LoadLibrary(module_full_path);

                    g_detailmodules[g_num_of_detailmodules].atsLoad = reinterpret_cast<DETAILMODULE_ATSLOAD>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "Load"));
                    g_detailmodules[g_num_of_detailmodules].atsDispose = reinterpret_cast<DETAILMODULE_ATSDISPOSE>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "Dispose"));
                    g_detailmodules[g_num_of_detailmodules].atsGetPluginVersion = reinterpret_cast<DETAILMODULE_ATSGETPLUGINVERSION>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "GetPluginVersion"));
                    g_detailmodules[g_num_of_detailmodules].atsSetVehicleSpec = reinterpret_cast<DETAILMODULE_ATSSETVEHICLESPEC>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "SetVehicleSpec"));
                    g_detailmodules[g_num_of_detailmodules].atsInitialize = reinterpret_cast<DETAILMODULE_ATSINITIALIZE>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "Initialize"));
                    g_detailmodules[g_num_of_detailmodules].atsElapse = reinterpret_cast<DETAILMODULE_ATSELAPSE>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "Elapse"));
                    g_detailmodules[g_num_of_detailmodules].atsSetPower = reinterpret_cast<DETAILMODULE_ATSSETPOWER>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "SetPower"));
                    g_detailmodules[g_num_of_detailmodules].atsSetBrake = reinterpret_cast<DETAILMODULE_ATSSETBRAKE>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "SetBrake"));
                    g_detailmodules[g_num_of_detailmodules].atsSetReverser = reinterpret_cast<DETAILMODULE_ATSSETREVERSER>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "SetReverser"));
                    g_detailmodules[g_num_of_detailmodules].atsKeyDown = reinterpret_cast<DETAILMODULE_ATSKEYDOWN>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "KeyDown"));
                    g_detailmodules[g_num_of_detailmodules].atsKeyUp = reinterpret_cast<DETAILMODULE_ATSKEYUP>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "KeyUp"));
                    g_detailmodules[g_num_of_detailmodules].atsHornBlow = reinterpret_cast<DETAILMODULE_ATSHORNBLOW>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "HornBlow"));
                    g_detailmodules[g_num_of_detailmodules].atsDoorOpen = reinterpret_cast<DETAILMODULE_ATSDOOROPEN>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "DoorOpen"));
                    g_detailmodules[g_num_of_detailmodules].atsDoorClose = reinterpret_cast<DETAILMODULE_ATSDOORCLOSE>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "DoorClose"));
                    g_detailmodules[g_num_of_detailmodules].atsSetSignal = reinterpret_cast<DETAILMODULE_ATSSETSIGNAL>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "SetSignal"));
                    g_detailmodules[g_num_of_detailmodules].atsSetBeaconData = reinterpret_cast<DETAILMODULE_ATSSETBEACONDATA>(GetProcAddress(g_detailmodules[g_num_of_detailmodules].hm_dll, "SetBeaconData"));

                    memset(&g_detailmodules[g_num_of_detailmodules].last_handle, 0, sizeof(ATS_HANDLES));

					if (g_detailmodules[g_num_of_detailmodules].atsLoad != NULL)
					{
						g_detailmodules[g_num_of_detailmodules].atsLoad();
					}

                    ++g_num_of_detailmodules;
                }
            }
        }

        fclose(fp);
    }
    else
    {
        char* p = 0; *p = 1;
    }
}

// Called when this plug-in is unloaded
void WINAPI atsDispose()
{
    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsDispose != NULL)
		{
			g_detailmodules[i].atsDispose();
		}
        FreeLibrary(g_detailmodules[i].hm_dll);
    }

    memset(g_detailmodules, 0, sizeof(ST_DETAILMODULE_ATS_DELEGATE_FUNC));
    g_num_of_detailmodules = 0;
    memset(g_handles, 0, sizeof(ATS_HANDLES));
}

// Returns the version numbers of ATS plug-in
int WINAPI atsGetPluginVersion()
{
	return ATS_VERSION;
}

// Called when the train is loaded
void WINAPI atsSetVehicleSpec(ATS_VEHICLESPEC vspec)
{

    g_svcBrake = vspec.BrakeNotches;
    g_emgBrake = g_svcBrake + 1;

    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsSetVehicleSpec != NULL)
		{
			g_detailmodules[i].atsSetVehicleSpec(vspec);
		}
    }
}

// Called when the game is started
void WINAPI atsInitialize(int param)
{

    g_speed = 0;
    traB.Initialize();

    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsInitialize != NULL)
		{
			g_detailmodules[i].atsInitialize(param);
            if (i == 0)
            {
                
            }
		}
    }
}

// Called every frame
ATS_HANDLES WINAPI atsElapse(ATS_VEHICLESTATE vs, int *p_panel, int *p_sound)
{
    ATS_HANDLES ret{};
    ATS_HANDLES retOER{}; //小田急PI
    ATS_HANDLES retTM; //メトロPI
    
    g_deltaT = vs.Time - g_time;
    g_time = vs.Time;
    g_speed = vs.Speed;
    g_current = vs.Current;
    
    void Elapse(ATS_VEHICLESTATE vs, int*p_panel, int*p_sound);

    if (g_num_of_detailmodules> 0)//プラグインの読み込み有無
    {
        retOER.Power = g_handles[0].Power; //運転士のノッチ段数
        retOER.Brake = g_handles[0].Brake; //運転士のブレーキ段数
        retOER.Reverser = g_handles[0].Reverser; //運転士のレバーサ位置

        if (g_first_time)//初回の場合　ブレーキセット
        {
            for (int i = 0; i < g_num_of_detailmodules; ++i)
            {
				if (g_detailmodules[i].atsSetPower != NULL)
				{
					g_detailmodules[i].atsSetPower(g_handles[0].Power);
				}

				if (g_detailmodules[i].atsSetBrake != NULL)
				{
					g_detailmodules[i].atsSetBrake(g_handles[0].Brake);
				}

				if (g_detailmodules[i].atsSetReverser != NULL)
				{
	                g_detailmodules[i].atsSetReverser(g_handles[0].Reverser);
				}
            }

            g_first_time = false;
        }
        else//初回でない場合　ブレーキセット（1個目のPI）
        {
            if (g_handles[0].Power != g_handles[1].Power)//旧Powerと違うなら
            {
				if (g_detailmodules[0].atsSetPower != NULL)
				{
					g_detailmodules[0].atsSetPower(g_handles[0].Power);
				}
            }

            if (g_handles[0].Brake != g_handles[1].Brake)//旧Brakeと違うなら
            {
				if (g_detailmodules[0].atsSetBrake != NULL)
				{
					g_detailmodules[0].atsSetBrake(g_handles[0].Brake);
				}
            }

            if (g_handles[0].Reverser != g_handles[1].Reverser)//旧Revと違うなら
            {
				if (g_detailmodules[0].atsSetReverser != NULL)
				{
					g_detailmodules[0].atsSetReverser(g_handles[0].Reverser);
				}
            }
        }

        g_handles[1] = g_handles[0];//1（メモリ）に0を保存

        if (g_detailmodules[0].atsElapse != NULL)//1個目のPIのelapse実行
		{
			ret = g_detailmodules[0].atsElapse(vs, p_panel, p_sound);
		}

        //小田急PIのPBをメモリー
        traB.oerBrake = ret.Brake;
        traB.oerNotch = ret.Power;
        traA.oerRev = ret.Reverser;

        
        traA.Elapse(vs, p_panel, p_sound);
        
        ret.Reverser = traA.extRev;

        //2個目以降のPI
        for (int i = 1; i < g_num_of_detailmodules; ++i)
        {
            
            if (g_detailmodules[i].last_handle.Power != ret.Power)//ret（前のPIからのpower）と比較
            {
				if (g_detailmodules[i].atsSetPower != NULL)
				{
					g_detailmodules[i].atsSetPower(ret.Power);
				}
            }

            if (g_detailmodules[i].last_handle.Brake != ret.Brake)
            {
				if (g_detailmodules[i].atsSetBrake != NULL)
				{
					g_detailmodules[i].atsSetBrake(ret.Brake);
				}
            }

            if (g_detailmodules[i].last_handle.Reverser != ret.Reverser)
            {
				if (g_detailmodules[i].atsSetReverser != NULL)
				{
					g_detailmodules[i].atsSetReverser(ret.Reverser);
				}
            }

            g_detailmodules[i].last_handle = ret;//メモリーとして保存
            
			if (g_detailmodules[i].atsElapse != NULL)
			{
				ret = g_detailmodules[i].atsElapse(vs, p_panel, p_sound);
			}

            if (i == 1)//iが1→メトロPI読み込み後
            {
                traB.tmNotch = ret.Power;
                traB.tmBrake = ret.Brake;

                traB.Elapse(vs, p_panel, p_sound);

                ret.Brake = traB.outputBrake;
                ret.Power = traB.outputNotch;
            }
        }
    }
    else//PIを読み込んでいない場合
    {
        memset(&ret, 0, sizeof(ATS_HANDLES));
    }

	return ret;//最終PIからの値を返す
}

// Called when the power is changed
void WINAPI atsSetPower(int notch)
{
    g_handles[0].Power = notch;
}

// Called when the brake is changed
void WINAPI atsSetBrake(int notch)
{
    traB.SetBrake(notch);
    g_handles[0].Brake = notch;
}

// Called when the reverser is changed
void WINAPI atsSetReverser(int pos)
{
    g_handles[0].Reverser = pos;
}

// Called when any ATS key is pressed
void WINAPI atsKeyDown(int ats_key_code)
{
    int key_oer;
    traB.KeyDown(ats_key_code);
    
    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsKeyDown != NULL)
		{
#if (ROUTE == 9)
            if (i == 0)//小田急PIはSと8を入れ替え、9と3を入れ替え
            {
                if (ats_key_code == ATS_KEY_J)
                    key_oer = ATS_KEY_S;
                else if (ats_key_code == ATS_KEY_S)
                    key_oer = ATS_KEY_J;
                else if (ats_key_code == ATS_KEY_E)
                    key_oer = ATS_KEY_K;
                else if (ats_key_code == ATS_KEY_K)
                    key_oer = ATS_KEY_E;
                else
                    key_oer = ats_key_code;

                g_detailmodules[i].atsKeyDown(key_oer);
            }
            else
            {
                g_detailmodules[i].atsKeyDown(ats_key_code);
            }
#elif
            g_detailmodules[i].atsKeyDown(ats_key_code);
#endif
		}
    }
    
}

// Called when any ATS key is released
void WINAPI atsKeyUp(int ats_key_code)
{
    int keyup_oer;
    traB.KeyUp(ats_key_code);

    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsKeyUp != NULL)
		{
#if (ROUTE == 9)
            if (i == 0)//小田急PIはSと8を入れ替え
            {
                if (ats_key_code == ATS_KEY_J)
                    keyup_oer = ATS_KEY_S;
                else if (ats_key_code == ATS_KEY_S)
                    keyup_oer = ATS_KEY_J;
                else if (ats_key_code == ATS_KEY_E)
                    keyup_oer = ATS_KEY_K;
                else if (ats_key_code == ATS_KEY_K)
                    keyup_oer = ATS_KEY_E;
                else
                    keyup_oer = ats_key_code;

                g_detailmodules[i].atsKeyUp(keyup_oer);
            }
            else
            {
                g_detailmodules[i].atsKeyUp(ats_key_code);
            }
#elif
            g_detailmodules[i].atsKeyUp(ats_key_code);
#endif
		}
    }
}

// Called when the horn is used
void WINAPI atsHornBlow(int ats_horn)
{
    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsHornBlow != NULL)
		{
			g_detailmodules[i].atsHornBlow(ats_horn);
		}
    }
}

// Called when the door is opened
void WINAPI atsDoorOpen()
{
    g_pilotlamp = false;
    traB.DoorOpen();

    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsDoorOpen != NULL)
		{
			g_detailmodules[i].atsDoorOpen();
		}
    }
}

// Called when the door is closed
void WINAPI atsDoorClose()
{
    g_pilotlamp = true;
    traB.DoorClose();

    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsDoorClose != NULL)
		{
			g_detailmodules[i].atsDoorClose();
		}
    }
}

// Called when current signal is changed
void WINAPI atsSetSignal(int signal)
{
    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsSetSignal != NULL)
		{
            if (signal >= 100 && signal <= 112)//100～112
            {
                if (signal == 100)
                    signal = 0;
                else if (signal == 101)
                    signal = 9;
                else if (signal == 102)
                    signal = 10;
                else if (signal == 103)//15
                    signal = 13;
                else if (signal == 104)//25
                    signal = 15;
                else if (signal == 105)//45
                    signal = 19;
                else if (signal == 106)//55
                    signal = 21;
                else if (signal == 107)//65
                    signal = 23;
                else if (signal == 108)//75
                    signal = 25;
                else if (signal == 109)//90
                    signal = 28;
                else if (signal == 110)//100
                    signal = 30;
                else if (signal == 111)//110
                    signal = 32;
                else if (signal == 112)//120
                    signal = 33;
            }
			g_detailmodules[i].atsSetSignal(signal);
		}
    }
}

// Called when the beacon data is received
void WINAPI atsSetBeaconData(ATS_BEACONDATA beacon_data)
{
    traB.SetBeaconData(beacon_data);
    ATS_BEACONDATA beaconTM{};
    ATS_BEACONDATA beaconOER{};

    for (int i = 0; i < g_num_of_detailmodules; ++i)
    {
		if (g_detailmodules[i].atsSetBeaconData != NULL)
		{
#if (ROUTE == 9)
            if (i == 1)//うさプラに対して
            {
                //int OpeNum;
                if (beacon_data.Type == 2 && beacon_data.Optional != 0)//2番地上子
                {
                    beaconTM.Type = 18; //18番に変更
                    int TrainType = beacon_data.Optional == -1 ? 0 : beacon_data.Optional / 100000000;//-1の際は無効にする。以下同様
                    int TrainTypeS = TrainType == 1 ? 14 : TrainType == 2 ? 11 : TrainType == 3 ? 2 : TrainType == 4 ? 6 :TrainType == 5 ? 9 : TrainType == 6 ? 5 : 0;
                    int Pattern = beacon_data.Optional == -1 ? 0 : (beacon_data.Optional / 1000000) % 100;
                    int Destination = beacon_data.Optional == -1 ? 0 : (beacon_data.Optional / 10000) % 100;
                    beaconTM.Optional = TrainTypeS * 10000 + Destination * 100 + g_OpeNum;
                }
                else if (beacon_data.Type == 18)//18番地上子（運番）
                {
                    g_OpeNum = beacon_data.Optional % 100;
                    beaconTM = beacon_data;
                }
                else if (beacon_data.Type == 1 && beacon_data.Optional != 0)//1番地上子（合図ブザー）
                {
                    beaconTM.Type = 33;
                    beaconTM.Optional = beacon_data.Optional % 10000 == 0 ? 99 : beacon_data.Optional % 10000 <= 9500 ? 9 : ((beacon_data.Optional + 500) / 1000) % 10;//0000は不鳴動、9500以上は9s、他は四捨五入で処理
                }
                else if (beacon_data.Type == 22)//22番地上子（P2）
                {
                    beaconTM.Type = 297; //実質的な無効化
                }
                /*
                else if (beacon_data.Type == 26)//26番地上子
                {
                    beaconTM.Type = 1;//P2
                    beaconTM.Signal = beacon_data.Signal;
                    beaconTM.Distance = beacon_data.Distance;
                    beaconTM.Optional = beacon_data.Optional;
                }
                else if (beacon_data.Type == 27)
                {
                    beaconTM.Type = 2;//P3
                    beaconTM.Signal = beacon_data.Signal;
                    beaconTM.Distance = beacon_data.Distance;
                    beaconTM.Optional = beacon_data.Optional;
                }
                else if (beacon_data.Type == 29)
                {
                    beaconTM.Type = 4;//P2絶対
                    beaconTM.Signal = beacon_data.Signal;
                    beaconTM.Distance = beacon_data.Distance;
                    beaconTM.Optional = beacon_data.Optional;
                }
                else if (beacon_data.Type == 30)
                {
                    beaconTM.Type = 5;//P1絶対
                    beaconTM.Signal = beacon_data.Signal;
                    beaconTM.Distance = beacon_data.Distance;
                    beaconTM.Optional = beacon_data.Optional;
                }
                */
                else if (beacon_data.Type == 4 && traB.Eats != 0)//4番地上子 OM以外の際は無効
                {
                    beaconTM.Type = 298;
                }
                else if (beacon_data.Type == 5 && traB.Eats != 0)//5番地上子 OM以外の際は無効
                {
                    beaconTM.Type = 299;
                }
                else if (beacon_data.Type == 41 && beacon_data.Optional == 0 && traB.Eats == 0)//41番地上子 OMの際は無効
                {
                    beaconTM.Type = 301;
                }
                else if (beacon_data.Type == 54)
                {
                    beaconTM.Type = 41;
                    beaconTM.Optional = 1;
                }
                else
                {
                    beaconTM = beacon_data;
                }
                g_detailmodules[i].atsSetBeaconData(beaconTM);
            }
            else if (i == 0)//小田急PIに対して
            {
                if (beacon_data.Type == 1 && beacon_data.Optional == 0)
                {
                    beaconOER.Type == 296; //実質的な無効化
                }
                else if (beacon_data.Type == 2 && beacon_data.Optional == 0)
                {
                    beaconOER.Type == 297; //実質的な無効化
                }
                else if (beacon_data.Type == 4 && traB.Eats == 0)//4番地上子、OMの時は無効
                {
                    beaconOER.Type == 299; //実質的な無効化
                }
                else if (beacon_data.Type == 5 && traB.Eats == 0)//5番地上子、OMの時は無効
                {
                    beaconOER.Type == 300; //実質的な無効化
                }
                else if (beacon_data.Type == 41 && beacon_data.Optional != 0)//41番地上子、0以外は無効（合図ブザー)
                {
                    beaconOER.Type == 301; //実質的な無効化
                }
                else
                {
                    beaconOER = beacon_data;
                }
                g_detailmodules[i].atsSetBeaconData(beaconOER);
            }
            else
            {
                g_detailmodules[i].atsSetBeaconData(beacon_data);
            }
#elif
			g_detailmodules[i].atsSetBeaconData(beacon_data);
#endif
		}
    }
}