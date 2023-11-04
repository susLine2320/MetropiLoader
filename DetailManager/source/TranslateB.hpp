int g_emgBrake; // 非常ノッチ
int g_svcBrake; // 常用最大ノッチ
int g_brakeNotch; // ブレーキノッチ
int g_powerNotch; // 力行ノッチ
int g_reverser; // レバーサ
bool g_pilotlamp; // パイロットランプ
int g_time; // 現在時刻
float g_speed; // 速度計の速度[km/h]
float g_current; //電流
int g_deltaT; // フレーム時間[ms/frame]

int g_OpeNum; //運番
ATS_BEACONDATA distRef; //距離程補正
class MIni
{
public:
	int Notch; //ハンドル位置をどの位置で読み込むか
	int Lag; //メーターラグ秒数[ms]
	int Open2; //回生開放をどの位置で読み込むか
	int Snow; //耐雪ブレーキを使用するか
	int Snow2; //耐雪ブレーキをどの位置で読み込むか
};

class TranslateB
{
public:
	bool g_js1a; //メトロ乗降促進ブザーA
	bool g_js1b; //メトロ乗降促進ブザーB
	bool g_js2; //東武乗降促進ブザー
	bool g_js3a; //東急乗降促進ブザーA
	bool g_js3b; //東急乗降促進ブザーB
	bool g_js4; //西武乗降促進ブザー
	bool g_js5; //相鉄乗降促進ブザー
	bool g_js6a; //JR乗降促進ブザーA
	bool g_js6b; //JR乗降促進ブザーB
	bool g_js7; //小田急乗降促進メロディ
	bool g_js8; //東葉乗降促進ブザー
	bool g_jsc1; //メトロ乗降促進放送
	bool g_jsc2; //東武乗降促進放送
	bool g_jsc3; //東急乗降促進放送
	bool g_jsc4; //西武乗降促進チャイム・放送
	bool g_jsc5; //相鉄乗降促進放送
	bool g_jsc6; //JR乗降促進放送
	bool g_jsc7; //小田急乗降促進放送
	bool g_jsc8; //東葉乗降促進放送
	bool g_mon;//モニタ操作音
	bool g_openon;//回生開放オン
	bool g_openoff;//回生開放オフ
	int p92;
	int p72;
	int p4;
	int p20;
	int p19;
	int p36;
	int p37;
	int p38;
	int p39;
	int p94;
	int p95;
	int p97;
	int p98;
	int p99;
	int p100;
	int p136;
	int p137;
	int p138;
	int p160;
	int p166;
	int p176;
	int p234;
	int oerNotch;//小田急PIの出力P
	int oerBrake;//小田急PIの出力B
	int tmNotch;//メトロPIの出力P
	int tmBrake;//メトロPIの出力B
	int outputNotch;//出力ノッチ
	int outputBrake;//出力ブレーキ
	bool UsaoDisable;//うさプラの出力切断
	bool ATSFlag;
	bool flag;
	bool power;
	int stnum;//駅番号（小田急）
	int direction;
	int direction89;
	int Ekey;
	int Eats; //ATS種類変更
	bool Open_nfb; //回生開放
	int UseOpen; //回生開放を使用するか
	int Snow3; //B1抑速

	MIni p_ini;

	//1回しか呼ばれない
	void setVehicleSpec()
	{
		direction89 = 2;
		Eats = 1;
		Open_nfb = false;
	}

	//駅ジャンプの度に呼ばれる
	void Initialize()
	{
		p234 = stnum;
		m_notchtimer = 0;
	}

	void Elapse(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		//パネル入力
		p92 = panel[92];
		p72 = panel[72];
		p4 = panel[4];
		p19 = panel[19];
		p20 = panel[20];
		p36 = panel[36];
		p37 = panel[37];
		p38 = panel[38];
		//p39 = panel[39];
		p94 = panel[94];
		p95 = panel[95];
		p97 = panel[97];
		p98 = panel[98];
		p99 = panel[99];
		p100 = panel[127];
		p136 = panel[136];
		p137 = panel[137];
		p138 = panel[138];
		p160 = panel[160];
		p176 = panel[176];

		//ハンドル出力
		if (p92 == 7 && p72 == 0 && panel[101] == 0 && Eats == 1)//小田急キー、CgSがATSの時で、ATC無信号時かつD-ATS-P設定
		{
			outputBrake = oerBrake; //小田急PIからの出力Bを使用
			outputNotch = oerNotch; //小田急PIからの出力Pを使用
			sound[0] = ATS_SOUND_STOP; //ATSベルをストップ
		}
		else if (p92 == 7 && p72 == 0 && panel[101] == 0 && Eats == 0)//OM-ATS
		{
			outputBrake = tmBrake; //うさプラからの出力Bを使用
			outputNotch = tmNotch; //うさプラからの出力Pを使用
			sound[21] = ATS_SOUND_STOP;
			//ATSベルは有効
		}
		else
		{
			outputBrake = tmBrake; //うさプラからの出力Bを使用
			outputNotch = tmNotch; //うさプラからの出力Pを使用
			sound[25] = ATS_SOUND_STOP; //ATSベルをストップ
			sound[21] = ATS_SOUND_STOP; //ATSベルをストップ
			if (p160 == 7)
				sound[0] = ATS_SOUND_STOP;
		}

		//表示灯制御
		flag = p92 == 7 && (p72 == 0) ? 1 : 0;//マスコンキー小田急、かつATSのときにATS表示灯点灯フラグを立てる
		if (flag == 0) { power = 0; }
		p94 = power == 1 && p94 == 1 ? 1 : 0;//速度注意
		p95 = power == 1 && p95 == 1 ? 1 : 0;//動作
		p97 = power == 1 && p97 == 1 ? 1 : 0;//OM-ATS電源
		p98 = power == 1 && p98 == 1 ? 1 : 0;//D-ATS-P電源
		p99 = power == 1 && p99 == 1 ? 1 : 0;//無信号
		p100 = power == 1 && p100 == 1 ? 1 : 0;//パターン接近
		p138 = power == 1 && p138 == 1 ? 1 : 0;//TASC制御
		p136 = power == 1 && p136 == 1 ? 1 : 0;//TASC電源
		//2303追加
		p36 = p92 == 7 && p36 == 1 ? 1 : 0;//OM-ATS
		p37 = Eats == 0 && p92 == 7 && p37 == 1 ? 1 : 0;//動作
		p38 = Eats == 0 && p92 == 7 && p38 == 1 ? 1 : 0;//速度注意
		//出力
		panel[39] = p4 == 1 || p39 == 1 ? 1 : 0;//フルステップ　4/39片方成立時に点灯させる
		panel[36] = (p36 == 1 || p97 == 1) && p98 == 0 ? 1 : 0;//OM-ATS　小田急PIがOM-ATS設定になっていること前提
		panel[38] = p38 == 1 || p94 == 1 ? 1 : 0;//速度注意　38/94片方成立時に点灯させる
		panel[37] = p37 == 1 || p95 == 1 ? 1 : 0;//動作　37/95片方成立時に点灯させる
		panel[98] = p98;//D-ATS-P電源
		panel[99] = p99;//無信号
		panel[127] = p100;//パターン接近
		panel[136] = p136;//TASC電源
		panel[137] = p19 == 1 && p137 == 1 ? 1 : 0;//ATO電源　ATC投入が前提（ATSでは作動しない）
		panel[138] = p138;//TASC制御
		panel[176] = p176 == 0 ? 0 : max(p92, 1);//耐雪ブレーキ　マスコンキーごとに値変化
		panel[234] = p160 == 7 ? p234 % 100 : 0;//次の停車駅表示は小田急キーの時のみ
		//以下独自仕様
		panel[166] = p166;//モニタ
		panel[170] = Open_nfb;//回生開放
		//パネル出力（うさプラ代替機能）
		panel[52] = g_current < 0 && g_speed > 4.99f ? 1 : 0;
		panel[53] = g_current < 0 && g_speed > 22.99f ? 1 : 0;
		panel[54] = g_current < 0 && g_speed > 19.99f ? 1 : 0;

		// サウンド出力
		//乗降促進
		if (g_js1a == true)
		{
			sound[33] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[33] = ATS_SOUND_STOP;
		}
		if (g_js1b == true)
		{
			sound[35] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[35] = ATS_SOUND_STOP;
		}

		if (g_js2 == true)
		{
			sound[62] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[62] = ATS_SOUND_STOP;
		}
		if (g_js3a == true)
		{
			sound[64] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[64] = ATS_SOUND_STOP;
		}
		if (g_js3b == true)
		{
			sound[65] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[65] = ATS_SOUND_STOP;
		}
		if (g_js4 == true)
		{
			sound[73] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[73] = ATS_SOUND_STOP;
		}
		/*/
		if (g_js5 == true)
		{
			sound[75] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[75] = ATS_SOUND_STOP;
		}
		*/
		if (g_js6a == true)
		{
			sound[59] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[59] = ATS_SOUND_STOP;
		}
		if (g_js6b == true)
		{
			sound[61] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[61] = ATS_SOUND_STOP;
		}
		if (g_js7 == true)
		{
			sound[57] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[57] = ATS_SOUND_STOP;
		}
		/*
		if (g_js8 == true)
		{
			sound[59] = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			sound[59] = ATS_SOUND_STOP;
		}
		*/
		if (g_jsc1 == true)
		{
			sound[34] = ATS_SOUND_PLAY;
			g_jsc1 = false;
		}
		else
		{
			sound[34] = ATS_SOUND_CONTINUE;
		}

		if (g_jsc2 == true)
		{
			sound[63] = ATS_SOUND_PLAY;
			g_jsc2 = false;
		}
		else
		{
			sound[63] = ATS_SOUND_CONTINUE;
		}
		if (g_jsc3 == true)
		{
			sound[66] = ATS_SOUND_PLAY;
			g_jsc3 = false;
		}
		else
		{
			sound[66] = ATS_SOUND_CONTINUE;
		}
		if (g_jsc4 == true)
		{
			sound[74] = ATS_SOUND_PLAY;
			g_jsc4 = false;
		}
		else
		{
			sound[74] = ATS_SOUND_CONTINUE;
		}
		/*
		if (g_jsc5 == true)
		{
			sound[76] = ATS_SOUND_PLAY;
			g_jsc5 = false;
		}
		else
		{
			sound[76] = ATS_SOUND_CONTINUE;
		}
		*/
		if (g_jsc6 == true)
		{
			sound[60] = ATS_SOUND_PLAY;
			g_jsc6 = false;
		}
		else
		{
			sound[60] = ATS_SOUND_CONTINUE;
		}
		if (g_jsc7 == true)
		{
			sound[58] = ATS_SOUND_PLAY;
			g_jsc7 = false;
		}
		else
		{
			sound[58] = ATS_SOUND_CONTINUE;
		}

		//回生開放
		if (g_openon)
		{
			sound[17] = ATS_SOUND_PLAY;
			g_openon = false;
		}
		else
			sound[17] = ATS_SOUND_CONTINUE;
		if (g_openoff)
		{
			sound[16] = ATS_SOUND_PLAY;
			g_openoff = false;
		}
		else
			sound[16] = ATS_SOUND_CONTINUE;


		/*g_js1a = ATS_SOUND_STOP;
		g_js1b = ATS_SOUND_STOP;
		g_js2 = ATS_SOUND_STOP;
		g_js3 = ATS_SOUND_STOP;
		g_js4 = ATS_SOUND_STOP;
		g_js5 = ATS_SOUND_STOP;
		g_js6a = ATS_SOUND_STOP;
		g_js6b = ATS_SOUND_STOP;
		g_js7 = ATS_SOUND_STOP;
		g_js8 = ATS_SOUND_STOP;
		sound[34] = ATS_SOUND_CONTINUE;
		sound[37] = ATS_SOUND_CONTINUE;
		sound[39] = ATS_SOUND_CONTINUE;
		sound[51] = ATS_SOUND_CONTINUE;
		sound[53] = ATS_SOUND_CONTINUE;
		sound[56] = ATS_SOUND_CONTINUE;
		sound[58] = ATS_SOUND_CONTINUE;
		sound[60] = ATS_SOUND_CONTINUE;
		*/
		//モニタ切替機能
		if (GetKeyState(0x45) < 0)//Eキーが押されている
		{
			if (Ekey == 1)//前フレでOFFの際に実行
			{
				g_mon = true;
				if (p166 == 1)
					p166 = 0;
				else
					p166 = 1;
			}
			Ekey = 0;
		}
		else
		{
			Ekey = 1;
		}
		//モニタ切替音を鳴らす
		if (g_mon == true)
		{
			sound[38] = ATS_SOUND_PLAY;
			g_mon = false;
		}
		else
		{
			sound[38] = ATS_SOUND_CONTINUE;
		}
		//小田急キーでない時spp音を切る
		if (p92 != 7) {
			sound[54] = ATS_SOUND_STOP;
			sound[55] = ATS_SOUND_STOP;
		}
		//非常ブレーキの時緩解音を作動させない
		if (outputBrake == g_emgBrake)
		{
			sound[67] = ATS_SOUND_STOP;
			sound[68] = ATS_SOUND_STOP;
		}
	}

	//ノッチ表示灯
	void Notch(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		int brake = 0;
		int power = 0;
		//所定時間経過していたら
		if (g_time > m_notchtimer)
		{
			brake = outputBrake;
			power = outputNotch;
			//次の目標時間を設定
			m_notchtimer = p_ini.Lag == -1 ? g_time + 200 + (g_time % 50) * 5 : g_time + p_ini.Lag;
		}
		panel[51] = brake == g_emgBrake ? 9 : brake;
		panel[55] = brake;
		panel[57] = brake;
		panel[66] = power;
	}

	//回生開放
	int Open(int Reverser, int Brake)
	{
		if (Open_nfb && g_speed > 0 && Brake > 0)
			return 0;
		else
			return Reverser;
	}

	//耐雪ブレーキ
	int Snow(int Brake)
	{
		if (Snow3 == 0 && p176 == 1 && Brake == 0)//B1抑速なし
			return 1;
		else if (Snow3 == 1 && p176 == 1 && Brake <= 1)//B1抑速あり
			return 2;
		else
			return Brake;
	}

	void SetBrake(int notch)
	{
		//フラグがたっているとマスコンを動かしたときに表示灯がつく
		if (flag == 1) {
			power = 1;
		}
	}
	/*
	ATS_API void WINAPI SetReverser(int pos)
	{
		g_reverser = pos;
	}
	*/
	
	void KeyDown(int atsKeyCode)
	{
		if (atsKeyCode == ATS_KEY_D && g_speed == 0)//乗降促進
		{
			if (p92 == 1 && direction == 1)
				g_js1a = true;
			else if (p92 == 1 && direction == 0)
				g_js1b = true;
			else if (p92 == 2)
				g_js2 = true;
			else if (p92 == 3 && direction == 1)
				g_js3a = true;
			else if (p92 == 3 && direction == 0)
				g_js3b = true;
			else if (p92 == 4)
				g_js4 = true;
			else if (p92 == 5)
				g_js5 = true;
			else if (p92 == 6 && direction == 1)
				g_js6a = true;
			else if (p92 == 6 && direction == 0)
				g_js6b = true;
			else if (p92 == 7)
				g_js7 = true;
			else if (p92 == 8)
				g_js8 = true;
			else
				g_js1a = true;
		}
		if (atsKeyCode == ATS_KEY_E && g_handles[0].Brake >= 4 && g_handles[0].Power == 0 && UseOpen == 1)//回生開放
		{
			if (Open_nfb) {
				g_openoff = true;
				Open_nfb = false;
			}
			else {
				g_openon = true;
				Open_nfb = true;
			}
		}
	}

	void KeyUp(int hornType)
	{
		if (hornType == ATS_KEY_D)
		{
			g_js1a = false;
			g_js1b = false;
			g_js2 = false;
			g_js3a = false;
			g_js3b = false;
			g_js4 = false;
			g_js5 = false;
			g_js6a = false;
			g_js6b = false;
			g_js7 = false;
			g_js8 = false;
			if (g_speed == 0) {
				if (p92 == 1)
					g_jsc1 = true;
				else if (p92 == 2)
					g_jsc2 = true;
				else if (p92 == 3)
					g_jsc3 = true;
				else if (p92 == 4)
					g_jsc4 = true;
				else if (p92 == 5)
					g_jsc5 = true;
				else if (p92 == 6)
					g_jsc6 = true;
				else if (p92 == 7)
					g_jsc7 = true;
				else if (p92 == 8)
					g_jsc8 = true;
				else
					g_jsc1 = true;
			}
		}
	}


	void DoorOpen()//ドアが開くときに次の停車駅を代入する
	{
		p234 = stnum;
	}

	void DoorClose()
	{
	}

	void SetBeaconData(ATS_BEACONDATA beaconData)
	{
		if (beaconData.Type == 70) {//次の停車駅を取得
			stnum = beaconData.Optional;
		}
		if (beaconData.Type == 89) {//運転方向を取得（本仕様）
			direction89 = 1;
			direction = beaconData.Optional % 2;
		}
		if (beaconData.Type == 19 && direction89 == 2) {//運転方向を取得（バックアップ）
			direction = beaconData.Optional % 2;
		}
		if (beaconData.Type == 100) {
			Eats = beaconData.Optional % 10; //ATS種類を取得
		}
	}
private:
	int m_notchtimer; //ノッチ表示灯タイマー
};