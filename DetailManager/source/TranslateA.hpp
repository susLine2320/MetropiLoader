#pragma once

// 以下の ifdef ブロックは DLL から簡単にエクスポートさせるマクロを作成する標準的な方法です。 
// この DLL 内のすべてのファイルはコマンドラインで定義された ATS_EXPORTS シンボル
// でコンパイルされます。このシンボルはこの DLL が使用するどのプロジェクト上でも未定義でなけ
// ればなりません。この方法ではソースファイルにこのファイルを含むすべてのプロジェクトが DLL 
// からインポートされたものとして ATS_API 関数を参照し、そのためこの DLL はこのマク 
// ロで定義されたシンボルをエクスポートされたものとして参照します。
//#pragma data_seg(".shared")
//#pragma data_seg()

class TranslateA
{
public:
	bool ats8;
	bool ats24;
	int ats35;
	int ats40;
	int ats67;
	int ats71;
	int ats80;
	int ats83;
	int ats84;
	int ats85;
	int ats87;
	int ats88;
	int ats89;
	int ats90;
	int ats93;
	bool ats94;
	bool ats95;
	bool ats97;
	bool ats98;
	bool ats99;
	bool ats100;
	int ats126;
	bool ats127;
	int ats128;
	int ats129;
	int ats130;
	bool ats136;
	bool ats138;
	int ats139;
	int ats140;
	int ats141;
	int ats142;
	int ats143;
	int ats144;
	int ats145;
	int ats146;
	int ats147;
	int ats148;
	int ats149;
	int ats150;
	int ats170;
	int ats178;
	int ats179;
	int ats180;
	int ats183;
	int ats184;
	int ats242;
	int ats243;
	int ats244;
	int ats188;
	int ats189;
	int ats190;
	int ats191;
	int ats195;
	int ats196;
	int ats197;
	int ats198;
	int ats199;
	int ats200;
	int ats207;
	int ats208;
	int ats209;
	int ats215;
	int ats216;
	int ats217;
	int ats218;
	int ats219;
	int ats220;
	int ats221;
	int ats222;
	int ats223;
	int ats224;
	int ats225;
	int ats226;
	int ats227;
	int ats228;
	int ats229;
	int ats230;
	int ats231;
	int ats233;
	bool ats255;
	int s21;
	int s23;
	int s25;
	int s26;
	int s54;
	int s55;
	int s67;
	int s68;
	int s89;

	int oerRev;
	int extRev;

	int ats213;

	/*
	void Initialize(void)
	{
	}
	*/

	void Elapse(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		if (g_pilotlamp)//戸閉時は回生非開放時はレバーサ位置を返す
		{
			if ((panel[14] == 0 || panel[14] == 1) && ats213 == 0 && oerRev == 0)//レバーサ前、後ろ、回生開放不使用、かつ中立時
			{
				if (panel[14] == 0) {//前なら
					extRev = 1;
				}
				else {//後なら
					extRev = -1;
				}
			}
			else {
				extRev = oerRev;
			}
		}
		else//戸閉時じゃないときは14番に応じレバーサを転換
		{
			if (panel[14] == 0) {//前なら
				extRev = 1;
			}
			else if (panel[14] == 1) {//後なら
				extRev = -1;
			}
			else {//そうでないなら中立
				extRev = 0;
			}
		}
		/*
		g_output.Power = g_powerNotch;
		g_output.ConstantSpeed = ATS_CONSTANTSPEED_CONTINUE;
		*/
		// パネル入力（変換）
		//ats100 = panel[43];
		ats99 = panel[42];
		ats98 = panel[41];
		ats97 = panel[40];
		ats95 = panel[12];
		ats94 = panel[11];
		ats93 = panel[172];
		ats90 = panel[37];
		ats89 = panel[36];
		ats88 = panel[35];
		ats87 = panel[34];
		ats85 = panel[33];
		ats84 = panel[32];
		ats83 = panel[31];
		ats80 = panel[54];
		ats71 = panel[53];
		ats67 = panel[52];
		ats40 = panel[51];
		ats35 = panel[50];
		ats24 = panel[8];
		ats8 = panel[10];
		//ats126 = panel[43];
		ats127 = panel[43];
		ats128 = panel[2];
		//ats129 = panel[59];
		ats130 = panel[55];
		ats136 = panel[130];
		ats138 = panel[131];
		ats139 = panel[20];
		ats140 = panel[132];
		ats141 = panel[133];
		ats142 = panel[134];
		ats143 = panel[135];
		ats144 = panel[79];
		ats145 = panel[80];
		ats146 = panel[81];
		ats147 = panel[87];
		ats148 = panel[88];
		//ats149 = panel[89];
		//ats150 = panel[90];
		ats170 = panel[181];
		ats178 = panel[177];
		ats179 = panel[178];
		ats180 = panel[179];
		ats183 = panel[175];
		ats184 = panel[176];
		ats195 = panel[100];
		ats196 = panel[101];
		ats197 = panel[102];
		ats198 = panel[103];
		ats199 = panel[104];
		ats200 = panel[105];
		ats207 = panel[15];
		ats208 = panel[16];
		ats209 = panel[17];
		ats215 = panel[106];
		ats216 = panel[107];
		ats217 = panel[108];
		ats218 = panel[109];
		ats219 = panel[110];
		ats220 = panel[111];
		ats221 = panel[112];
		ats222 = panel[113];
		ats223 = panel[114];
		ats224 = panel[115];
		ats225 = panel[116];
		ats226 = panel[117];
		ats227 = panel[118];
		ats228 = panel[119];
		ats229 = panel[120];
		ats230 = panel[121];
		ats231 = panel[122];
		ats233 = panel[123];
		ats242 = panel[83];
		ats243 = panel[84];
		ats244 = panel[85];
		ats255 = panel[82];

		// パネル出力
		panel[8] = ats8;
		panel[24] = ats24;
		panel[35] = ats35;
		panel[40] = ats40;
		panel[67] = ats67;
		panel[71] = ats71;
		panel[80] = ats80;
		panel[83] = ats83;
		panel[84] = ats84;
		panel[85] = ats85;
		panel[87] = ats87;
		panel[88] = ats88;
		panel[89] = ats89;
		panel[90] = ats90;
		panel[93] = ats93;
		panel[94] = ats94;
		panel[95] = ats95;
		panel[97] = ats97;
		panel[98] = ats98;
		panel[99] = ats99;
		panel[100] = ats100;
		panel[126] = ats126;
		panel[127] = ats127;
		panel[128] = ats128;
		panel[129] = ats129;
		panel[130] = ats130;
		panel[136] = ats136;
		panel[138] = ats138;
		panel[139] = ats139;
		panel[140] = ats140;
		panel[141] = ats141;
		panel[142] = ats142;
		panel[143] = ats143;
		panel[144] = ats144;
		panel[145] = ats145;
		panel[146] = ats146;
		panel[147] = ats147;
		panel[148] = ats148;
		panel[149] = ats149;
		panel[150] = ats150;
		panel[170] = ats170;
		panel[178] = ats178;
		panel[179] = ats179;
		panel[180] = ats180;
		panel[183] = ats183;
		panel[184] = ats184;
		panel[195] = ats195;
		panel[196] = ats196;
		panel[197] = ats197;
		panel[198] = ats198;
		panel[199] = ats199;
		panel[200] = ats200;
		panel[207] = ats207;
		panel[208] = ats208;
		panel[209] = ats209;
		panel[215] = ats215;
		panel[216] = ats216;
		panel[217] = ats217;
		panel[218] = ats218;
		panel[219] = ats219;
		panel[220] = ats220;
		panel[221] = ats221;
		panel[222] = ats222;
		panel[223] = ats223;
		panel[224] = ats224;
		panel[225] = ats225;
		panel[226] = ats226;
		panel[227] = ats227;
		panel[228] = ats228;
		panel[229] = ats229;
		panel[230] = ats230;
		panel[231] = ats231;
		panel[233] = ats233;
		panel[242] = ats242;
		panel[243] = ats243;
		panel[244] = ats244;
		panel[255] = ats255;

		//試験用
		//panel[213] = ats213;

		//サウンド入力（変換）
		s21 = sound[41];
		//s23 = sound[34];
		s25 = sound[0];
		s26 = sound[1];
		s54 = sound[3];
		s55 = sound[4];
		s67 = sound[7];
		s68 = sound[8];
		//s89 = sound[5];

		// サウンド出力（変換）
		sound[21] = s21;
		sound[23] = s23;
		sound[25] = s25;
		sound[26] = s26;
		sound[54] = s54;
		sound[55] = s55;
		sound[67] = s67;
		sound[68] = s68;
		//sound[89] = s89;

		//sound[238] = g_brakeNotch; //TranslateBに値を転送する
		//sound[239] = g_powerNotch; //TranslateBに値を転送する

		//サウンド出力（元番号を0に）
		sound[0] = ATS_SOUND_STOP;
		sound[1] = ATS_SOUND_STOP;
		sound[3] = ATS_SOUND_STOP;
		sound[4] = ATS_SOUND_STOP;
		sound[5] = ATS_SOUND_STOP;
		sound[7] = ATS_SOUND_STOP;
		sound[8] = ATS_SOUND_STOP;
		sound[34] = ATS_SOUND_STOP;
		sound[41] = ATS_SOUND_STOP;
		//return g_output;
	}
	/*
	ATS_API void WINAPI SetPower(int notch)
	{
		g_powerNotch = notch;
	}
	
	void SetBrake(int notch)
	{
		g_brakeNotch = notch;//フラグがたっているとマスコンを動かしたときに表示灯がつく
		if (flag == 1) {
			power = 1;
		}
	}
	
	ATS_API void WINAPI SetReverser(int pos)
	{
		g_reverser = pos;
	}
	*/
};




//ATS_HANDLES g_output; // 出力
