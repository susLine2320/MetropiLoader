int g_emgBrake; // ���m�b�`
int g_svcBrake; // ��p�ő�m�b�`
int g_brakeNotch; // �u���[�L�m�b�`
int g_powerNotch; // �͍s�m�b�`
int g_reverser; // ���o�[�T
bool g_pilotlamp; // �p�C���b�g�����v
int g_time; // ���ݎ���
float g_speed; // ���x�v�̑��x[km/h]
float g_current; //�d��
int g_deltaT; // �t���[������[ms/frame]

int g_OpeNum; //�^��
ATS_BEACONDATA distRef; //�������␳
class MIni
{
public:
	int Notch; //�n���h���ʒu���ǂ̈ʒu�œǂݍ��ނ�
	int Open2; //�񐶊J�����ǂ̈ʒu�œǂݍ��ނ�
	int Snow; //�ϐ�u���[�L���g�p���邩
	int Snow2; //�ϐ�u���[�L���ǂ̈ʒu�œǂݍ��ނ�
	int Hsa2; //���z�N�����ǂ̈ʒu�ōs����
};

class TranslateB
{
public:
//�Ǝ��T�E���h
	bool g_js1a; //���g����~���i�u�U�[A
	bool g_js1b; //���g����~���i�u�U�[B
	bool g_js2; //������~���i�u�U�[
	bool g_js3a; //���}��~���i�u�U�[A
	bool g_js3b; //���}��~���i�u�U�[B
	bool g_js4; //������~���i�u�U�[
	bool g_js5; //���S��~���i�u�U�[
	bool g_js6a; //JR��~���i�u�U�[A
	bool g_js6b; //JR��~���i�u�U�[B
	bool g_js7; //���c�}��~���i�����f�B
	bool g_js8; //���t��~���i�u�U�[
	bool g_jsc1; //���g����~���i����
	bool g_jsc2; //������~���i����
	bool g_jsc3; //���}��~���i����
	bool g_jsc4; //������~���i�`���C���E����
	bool g_jsc5; //���S��~���i����
	bool g_jsc6; //JR��~���i����
	bool g_jsc7; //���c�}��~���i����
	bool g_jsc8; //���t��~���i����
	bool g_mon;//���j�^���쉹
	bool g_openon;//�񐶊J���I��
	bool g_openoff;//�񐶊J���I�t
//�����w��p�p�l��
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
	int p140;
	int p141;
	int p142;
	int p143;
	int p160;
	int p160A;
	int p166;
	int p176;
	int p234;
//�ϐ�
	int oerNotch;//���c�}PI�̏o��P
	int oerBrake;//���c�}PI�̏o��B
	int tmNotch;//���g��PI�̏o��P
	int tmBrake;//���g��PI�̏o��B
	int outputNotch;//�o�̓m�b�`
	int outputBrake;//�o�̓u���[�L
	int dispNotch;//�\���m�b�`
	int dispBrake;//�\���u���[�L
	bool UsaoDisable;//�����v���̏o�͐ؒf
	bool ATSFlag;
	bool flag;
	bool power;
	int stnum;//�w�ԍ��i���c�}�j
	int direction;
	int direction89;
	int Ekey;
	int Eats; //ATS��ޕύX
	bool Open_nfb; //�񐶊J��
	int UseOpen; //�񐶊J�����g�p���邩
	int Snow3; //B1�}��
	int Lag; //���[�^�[���O�b��[ms]
	int RpbNotch; //�]���h�~�i��
	int UseHsa; //���z�N�����g�p���邩
	int HsaNotch; //���z�N���i��
	int MonType; //���j�^�[�̃^�C�v
	bool Hsa3; //S�L�[�̓ǂݍ��ݏ�
//TraA
	bool ats10;
	bool ats24;
	int ats35;
	int ats40;
	int ats67;
	int ats71;
	int ats80;
	int ats83;
	int ats84;
	int ats85;
	//int ats87;
	//int ats88;
	//int ats89;
	//int ats90;
	int ats93;
	//bool ats94;
	//bool ats95;
	//bool ats97;
	//bool ats98;
	//bool ats99;
	//bool ats100;
	//int ats126;
	//bool ats127;
	int ats128;
	//int ats129;
	int ats130;
	//bool ats136;
	//bool ats138;
	int ats139;
	//int ats140;
	//int ats141;
	//int ats142;
	//int ats143;
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
	int ats26;
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
	int ats207[3];
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
	int s46;
	int s115;

	int oerRev;
	int extRev;

	int ats213;

	MIni p_ini;

	//1�񂵂��Ă΂�Ȃ�
	void setVehicleSpec()
	{
		direction89 = 2;
		Eats = 1;
		Open_nfb = false;
	}

	//�w�W�����v�̓x�ɌĂ΂��
	void Initialize()
	{
		p234 = stnum;
		m_notchtimer = 0;
	}

	//1�Ԗڂ̃v���O�C���̑O
	void ElapseA(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		if (g_pilotlamp)//�˕��͉񐶔�J�����̓��o�[�T�ʒu��Ԃ�
		{
			if ((panel[14] == 0 || panel[14] == 1) && ats213 == 0 && oerRev == 0)//���o�[�T�O�A���A�񐶊J���s�g�p�A��������
			{
				if (panel[14] == 0) {//�O�Ȃ�
					extRev = 1;
				}
				else {//��Ȃ�
					extRev = -1;
				}
			}
			else {
				extRev = oerRev;
			}
		}
		else//�˕�����Ȃ��Ƃ���14�Ԃɉ������o�[�T��]��
		{
			if (panel[14] == 0) {//�O�Ȃ�
				extRev = 1;
			}
			else if (panel[14] == 1) {//��Ȃ�
				extRev = -1;
			}
			else {//�����łȂ��Ȃ璆��
				extRev = 0;
			}
		}
		// �p�l�����́i�ϊ��j
		//ats100 = panel[43];
		//ats99 = panel[42];
		//ats98 = panel[41];
		//ats97 = panel[40];
		//ats95 = panel[12];
		//ats94 = panel[11];
		ats93 = panel[172];
		//ats90 = panel[37];
		//ats89 = panel[36];
		//ats88 = panel[35];
		//ats87 = panel[34];
		ats85 = panel[33];
		ats84 = panel[32];
		ats83 = panel[31];
		ats80 = panel[54];
		ats71 = panel[53];
		ats67 = panel[52];
		ats40 = panel[51];
		ats35 = panel[50];
		ats24 = panel[8];
		ats10 = panel[10];
		//ats126 = panel[43];
		//ats127 = panel[43];
		ats128 = panel[2];
		//ats129 = panel[59];
		ats130 = panel[55];
		//ats136 = panel[130];
		//ats138 = panel[131];
		ats139 = panel[20];
		//ats140 = panel[132];
		//ats141 = panel[133];
		//ats142 = panel[134];
		//ats143 = panel[135];
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
		ats26 = panel[180];
		ats183 = panel[175];
		ats184 = panel[176];
		ats195 = panel[100];
		ats196 = panel[101];
		ats197 = panel[102];
		ats198 = panel[103];
		ats199 = panel[104];
		ats200 = panel[105];
		ats207[2] = panel[15];
		ats207[1] = panel[16];
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
		ats207[0] = panel[82];

		//�p�l�����́i������r�j
		p4 = panel[4];
		p94 = panel[11];
		p95 = panel[12];
		p97 = panel[40];
		p98 = panel[41];
		p99 = panel[42];
		p100 = panel[43];
		p136 = panel[130];
		p138 = panel[131];
		p140 = panel[132];
		p141 = panel[133];
		p142 = panel[134];
		p143 = panel[135];

		//�T�E���h���́i�ϊ��j
		s21 = sound[41];
		//s23 = sound[34];
		s25 = sound[0];
		s26 = sound[1];
		s54 = sound[3];
		s55 = sound[4];
		s67 = sound[7];
		s68 = sound[8];
		s46 = sound[16];
		s115 = sound[17];
		//s89 = sound[5];

		//�T�E���h�o�́i���ԍ���0�Ɂj
		sound[0] = ATS_SOUND_STOP;
		sound[1] = ATS_SOUND_STOP;
		sound[3] = ATS_SOUND_STOP;
		sound[4] = ATS_SOUND_STOP;
		sound[5] = ATS_SOUND_STOP;
		sound[7] = ATS_SOUND_STOP;
		sound[8] = ATS_SOUND_STOP;
		sound[16] = ATS_SOUND_STOP;
		sound[17] = ATS_SOUND_STOP;
		sound[34] = ATS_SOUND_STOP;
		sound[41] = ATS_SOUND_STOP;
	}

	void ElapseB(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		// �p�l���o��
		panel[10] = ats10;
		panel[8] = ats24;
		panel[178] = ats35;
		panel[179] = ats40;
		panel[180] = ats67;
		panel[207] = ats71;
		panel[208] = ats80;
		panel[83] = ats83;
		panel[84] = ats84;
		panel[85] = ats85;
		//panel[87] = ats87;
		//panel[88] = ats88;
		//panel[89] = ats89;
		//panel[90] = ats90;
		panel[93] = ats93;
		//panel[94] = ats94;
		//panel[95] = ats95;
		//panel[97] = ats97;
		//panel[98] = ats98;
		//panel[99] = ats99;
		//panel[100] = ats100;
		//panel[126] = ats126;
		//panel[127] = ats127;
		panel[4] = ats128;
		//panel[129] = ats129;
		panel[209] = ats130;
		//panel[136] = ats136;
		//panel[138] = ats138;
		panel[139] = ats139;
		//panel[140] = ats140;
		//panel[141] = ats141;
		//panel[142] = ats142;
		//panel[143] = ats143;
		panel[144] = ats144;
		panel[145] = ats145;
		panel[146] = ats146;
		panel[147] = ats147;
		panel[148] = ats148;
		panel[149] = ats149;
		panel[150] = ats150;
		panel[13] = ats178;
		panel[14] = ats179;
		panel[15] = ats180;
		panel[195] = ats195;
		panel[196] = ats196;
		panel[197] = ats197;
		panel[198] = ats198;
		panel[199] = ats199;
		panel[200] = ats200;
		//panel[207] = ats207;
		//panel[208] = ats208;
		panel[213] = ats209;
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
		panel[255] = ats207[MonType];

		// �T�E���h�o�́i�ϊ��j
		sound[21] = s21;
		//sound[23] = s23;
		sound[25] = s25;
		sound[26] = s26;
		sound[54] = s54;
		sound[55] = s55;
		sound[67] = s67;
		sound[68] = s68;
		sound[46] = s46;
		sound[115] = s115;
		//sound[89] = s89;
	}

	void ElapseC(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		//�p�l������
		p92 = panel[92];
		p72 = panel[72];
		//p4 = panel[4];
		p19 = panel[19];
		p20 = panel[20];
		p36 = panel[36];
		p37 = panel[37];
		p38 = panel[38];
		//p39 = panel[39];
		//p94 = panel[94];
		//p95 = panel[95];
		//p97 = panel[97];
		//p98 = panel[98];
		//p99 = panel[99];
		//p100 = panel[127];
		//p136 = panel[136];
		//p137 = panel[137];
		//p138 = panel[138];
		//p140 = panel[140];
		//p141 = panel[141];
		//p142 = panel[142];
		//p143 = panel[143];
 		p160 = panel[160];
		p160A = p160 == 0 ? 9 : p160;//�}�X�R���L�[0��9
		p176 = panel[176];

		//�n���h���o��
		if (p92 == 7 && p72 == 0 && panel[101] == 0 && Eats == 1)//���c�}�L�[�ACgS��ATS�̎��ŁAATC���M��������D-ATS-P�ݒ�
		{
			outputBrake = oerBrake; //���c�}PI����̏o��B���g�p
			outputNotch = oerNotch; //���c�}PI����̏o��P���g�p
			sound[0] = ATS_SOUND_STOP; //ATS�x�����X�g�b�v
		}
		else if (p92 == 7 && p72 == 0 && panel[101] == 0 && Eats == 0)//OM-ATS
		{
			outputBrake = max(tmBrake, oerBrake); //�����v���E���c�}PI����̏o��B���g�p
			outputNotch = min(tmNotch, oerNotch); //�����v���E���c�}PI����̏o��P���g�p
			sound[21] = ATS_SOUND_STOP;
			//ATS�x���͗L��
		}
		else
		{
			outputBrake = panel[139] >= 1 ? max(tmBrake, min(RpbNotch, g_svcBrake)) : tmBrake; //�����v������̏o��B���g�p
			outputNotch = tmNotch; //�����v������̏o��P���g�p
			sound[25] = ATS_SOUND_STOP; //ATS�x�����X�g�b�v
			sound[21] = ATS_SOUND_STOP; //ATS�x�����X�g�b�v
			if (p160 == 7)
				sound[0] = ATS_SOUND_STOP;
		}

		//�\��������
		flag = p92 == 7 && (p72 == 0) ? 1 : 0;//�}�X�R���L�[���c�}�A����ATS�̂Ƃ���ATS�\�����_���t���O�𗧂Ă�
		if (flag == 0) { power = 0; }
		p94 = power == 1 && p94 != 0 ? 1 : 0;//���x����
		p95 = power == 1 && p95 != 0 ? 1 : 0;//����
		p97 = power == 1 && p97 != 0 ? 1 : 0;//OM-ATS�d��
		p98 = power == 1 && p98 != 0 ? 1 : 0;//D-ATS-P�d��
		p99 = power == 1 && p99 != 0 ? 1 : 0;//���M��
		p100 = power == 1 && p100 != 0 ? 1 : 0;//�p�^�[���ڋ�
		p138 = power == 1 && p138 != 0 ? 1 : 0;//TASC����
		p136 = power == 1 && p136 != 0 ? 1 : 0;//TASC�d��
		//2303�ǉ�
		p36 = p92 == 7 && p36 == 1 ? 1 : 0;//OM-ATS
		p37 = Eats == 0 && p92 == 7 && p37 == 1 ? 1 : 0;//����
		p38 = Eats == 0 && p92 == 7 && p38 == 1 ? 1 : 0;//���x����
		//2311�ǉ�
		p140 = power == 1 && p140 != 0 ? 1 : 0;//TASC�u���[�L
		p141 = power == 1 && p141 >= 1 ? p141 : 0;//TASC�u���[�L
		p142 = power == 1 && p142 < 10 ? p142: 10;//TASC�u���[�L
		p143 = power == 1 && p143 < 10 ? p143 : 10;//TASC�u���[�L
		//�p�l���o�́i�����v�������j
		panel[22] = (bool)panel[22] == false && (bool)panel[25] == false ? 0 : p160A;//ATC���
		panel[23] = (bool)panel[23] == false && (bool)panel[26] == false ? 0 : p160A;//ATC��p
		panel[29] = (bool)panel[28] == false && (bool)panel[29] == false && (bool)panel[30] == false ? 0 : p160A;//���
		panel[31] = (bool)panel[31] == false && (bool)panel[33] == false ? 0 : p160A;//�\��
		//�o��
		panel[39] = p4 != 0 || p39 == 1 ? 1 : 0;//�t���X�e�b�v�@4/39�Е��������ɓ_��������
		panel[36] = (p36 == 1 || p97 == 1) && p98 == 0 ? 1 : 0;//OM-ATS�@���c�}PI��OM-ATS�ݒ�ɂȂ��Ă��邱�ƑO��
		panel[38] = p38 == 1 || p94 == 1 ? 1 : 0;//���x���Ӂ@38/94�Е��������ɓ_��������
		panel[37] = p37 == 1 || p95 == 1 ? 1 : 0;//����@37/95�Е��������ɓ_��������
		panel[35] = p98;//D-ATS-P�d��
		panel[33] = p99;//���M��
		panel[40] = p100;//�p�^�[���ڋ�
		panel[136] = p136;//TASC�d��
		panel[137] = p19 == 1 && p137 == 1 ? 1 : 0;//ATO�d���@ATC�������O��iATS�ł͍쓮���Ȃ��j
		panel[138] = p138;//TASC����
		panel[140] = p140;
		panel[141] = p141;
		panel[142] = p142;
		panel[143] = p143;
		panel[176] = p176 == 0 ? 0 : p160A;//�ϐ�u���[�L�@�}�X�R���L�[���Ƃɒl�ω�
		panel[234] = p160 == 7 ? p234 % 100 : 0;//���̒�ԉw�\���͏��c�}�L�[�̎��̂�
		//Index�d�����������
		panel[24] = ats183;
		panel[25] = ats184;
		panel[26] = ats26;
		panel[28] = ats170;
		//�ȉ��Ǝ��d�l
		panel[166] = p166;//���j�^
		panel[170] = !Open_nfb ? 0 : p160A;//�񐶊J��
		//�p�l���o�́i�����v����֋@�\�j
		panel[52] = g_current < 0 && g_speed > 4.99f ? 1 : 0;
		panel[53] = g_current < 0 && g_speed > 22.99f ? 1 : 0;
		panel[54] = g_current < 0 && g_speed > 19.99f ? 1 : 0;

		// �T�E���h�o��
		//��~���i
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

		//�񐶊J��
		if (g_openon == true)
		{
			sound[17] = ATS_SOUND_PLAY;
			g_openon = false;
		}
		else
			sound[17] = ATS_SOUND_CONTINUE;
		if (g_openoff == true)
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
		//���j�^�ؑ֋@�\
		if (GetKeyState(0x45) < 0)//E�L�[��������Ă���
		{
			if (Ekey == 1)//�O�t����OFF�̍ۂɎ��s
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
		//���j�^�ؑ։���炷
		if (g_mon == true)
		{
			sound[38] = ATS_SOUND_PLAY;
			g_mon = false;
		}
		else
		{
			sound[38] = ATS_SOUND_CONTINUE;
		}
		//���c�}�L�[�łȂ���spp����؂�
		if (p92 != 7) {
			sound[54] = ATS_SOUND_STOP;
			sound[55] = ATS_SOUND_STOP;
		}
		//���u���[�L�̎��ɉ������쓮�����Ȃ�
		if (outputBrake == g_emgBrake)
		{
			sound[67] = ATS_SOUND_STOP;
			sound[68] = ATS_SOUND_STOP;
		}
	}

	//�m�b�`�\����
	void Notch(int* panel, int outB, int outP)
	{
		//���莞�Ԍo�߂��Ă�����
		if (g_time > m_notchtimer)
		{
			dispBrake = outB;
			dispNotch = outP;
			//���̖ڕW���Ԃ�ݒ�
			m_notchtimer = Lag == -1 ? g_time + 200 + (g_time % 50) * 5 : g_time + Lag;
		}
		panel[51] = dispBrake == g_emgBrake ? 9 : dispBrake;
		panel[55] = dispBrake;
		panel[57] = dispBrake;
		panel[66] = dispNotch;
	}

	//�񐶊J��
	int Open(int Reverser, int Brake)
	{
		if (Open_nfb && g_speed > 0 && Brake > 0)
			return 0;
		else
			return Reverser;
	}

	//�ϐ�u���[�L
	int Snow(int Brake)
	{
		if (Snow3 == 0 && p176 == 1 && Brake == 0)//B1�}���Ȃ�
			return 1;
		else if (Snow3 == 1 && p176 == 1 && Brake <= 1)//B1�}������
			return 2;
		else
			return Brake;
	}

	//���z�N��
	int Hsa(int Brake)
	{
		if (g_pilotlamp && Hsa3 && Brake <= min(HsaNotch, g_svcBrake) && g_speed < 1.0f)
		{
			return min(HsaNotch, g_svcBrake);
		}
		return Brake;
	}

	void SetBrake(int notch)
	{
		//�t���O�������Ă���ƃ}�X�R���𓮂������Ƃ��ɕ\��������
		if (flag == 1) {
			power = 1;
		}
	}
	
	void KeyDown(int atsKeyCode)
	{
		if (atsKeyCode == ATS_KEY_D && g_speed == 0)//��~���i
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
		if (atsKeyCode == ATS_KEY_E && g_handles[0].Brake >= 4 && g_handles[0].Power == 0 && UseOpen == 1)//�񐶊J��
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
		if (atsKeyCode == ATS_KEY_S)//���z�N��
			Hsa3 = true;
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
		if (hornType == ATS_KEY_S)
			Hsa3 = false;
	}


	void DoorOpen()//�h�A���J���Ƃ��Ɏ��̒�ԉw��������
	{
		p234 = stnum;
	}

	void DoorClose()
	{
	}

	void SetBeaconData(ATS_BEACONDATA beaconData)
	{
		if (beaconData.Type == 70) {//���̒�ԉw���擾
			stnum = beaconData.Optional;
		}
		if (beaconData.Type == 89) {//�^�]�������擾�i�{�d�l�j
			direction89 = 1;
			direction = beaconData.Optional % 2;
		}
		if (beaconData.Type == 19 && direction89 == 2) {//�^�]�������擾�i�o�b�N�A�b�v�j
			direction = beaconData.Optional % 2;
		}
		if (beaconData.Type == 100) {
			Eats = beaconData.Optional % 10; //ATS��ނ��擾
		}
	}
private:
	int m_notchtimer; //�m�b�`�\�����^�C�}�[
};