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
	int Lag; //���[�^�[���O�b��[ms]
	int Open2; //�񐶊J�����ǂ̈ʒu�œǂݍ��ނ�
	int Snow; //�ϐ�u���[�L���g�p���邩
	int Snow2; //�ϐ�u���[�L���ǂ̈ʒu�œǂݍ��ނ�
};

class TranslateB
{
public:
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
	int oerNotch;//���c�}PI�̏o��P
	int oerBrake;//���c�}PI�̏o��B
	int tmNotch;//���g��PI�̏o��P
	int tmBrake;//���g��PI�̏o��B
	int outputNotch;//�o�̓m�b�`
	int outputBrake;//�o�̓u���[�L
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

	void Elapse(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		//�p�l������
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

		//�n���h���o��
		if (p92 == 7 && p72 == 0 && panel[101] == 0 && Eats == 1)//���c�}�L�[�ACgS��ATS�̎��ŁAATC���M��������D-ATS-P�ݒ�
		{
			outputBrake = oerBrake; //���c�}PI����̏o��B���g�p
			outputNotch = oerNotch; //���c�}PI����̏o��P���g�p
			sound[0] = ATS_SOUND_STOP; //ATS�x�����X�g�b�v
		}
		else if (p92 == 7 && p72 == 0 && panel[101] == 0 && Eats == 0)//OM-ATS
		{
			outputBrake = tmBrake; //�����v������̏o��B���g�p
			outputNotch = tmNotch; //�����v������̏o��P���g�p
			sound[21] = ATS_SOUND_STOP;
			//ATS�x���͗L��
		}
		else
		{
			outputBrake = tmBrake; //�����v������̏o��B���g�p
			outputNotch = tmNotch; //�����v������̏o��P���g�p
			sound[25] = ATS_SOUND_STOP; //ATS�x�����X�g�b�v
			sound[21] = ATS_SOUND_STOP; //ATS�x�����X�g�b�v
			if (p160 == 7)
				sound[0] = ATS_SOUND_STOP;
		}

		//�\��������
		flag = p92 == 7 && (p72 == 0) ? 1 : 0;//�}�X�R���L�[���c�}�A����ATS�̂Ƃ���ATS�\�����_���t���O�𗧂Ă�
		if (flag == 0) { power = 0; }
		p94 = power == 1 && p94 == 1 ? 1 : 0;//���x����
		p95 = power == 1 && p95 == 1 ? 1 : 0;//����
		p97 = power == 1 && p97 == 1 ? 1 : 0;//OM-ATS�d��
		p98 = power == 1 && p98 == 1 ? 1 : 0;//D-ATS-P�d��
		p99 = power == 1 && p99 == 1 ? 1 : 0;//���M��
		p100 = power == 1 && p100 == 1 ? 1 : 0;//�p�^�[���ڋ�
		p138 = power == 1 && p138 == 1 ? 1 : 0;//TASC����
		p136 = power == 1 && p136 == 1 ? 1 : 0;//TASC�d��
		//2303�ǉ�
		p36 = p92 == 7 && p36 == 1 ? 1 : 0;//OM-ATS
		p37 = Eats == 0 && p92 == 7 && p37 == 1 ? 1 : 0;//����
		p38 = Eats == 0 && p92 == 7 && p38 == 1 ? 1 : 0;//���x����
		//�o��
		panel[39] = p4 == 1 || p39 == 1 ? 1 : 0;//�t���X�e�b�v�@4/39�Е��������ɓ_��������
		panel[36] = (p36 == 1 || p97 == 1) && p98 == 0 ? 1 : 0;//OM-ATS�@���c�}PI��OM-ATS�ݒ�ɂȂ��Ă��邱�ƑO��
		panel[38] = p38 == 1 || p94 == 1 ? 1 : 0;//���x���Ӂ@38/94�Е��������ɓ_��������
		panel[37] = p37 == 1 || p95 == 1 ? 1 : 0;//����@37/95�Е��������ɓ_��������
		panel[98] = p98;//D-ATS-P�d��
		panel[99] = p99;//���M��
		panel[127] = p100;//�p�^�[���ڋ�
		panel[136] = p136;//TASC�d��
		panel[137] = p19 == 1 && p137 == 1 ? 1 : 0;//ATO�d���@ATC�������O��iATS�ł͍쓮���Ȃ��j
		panel[138] = p138;//TASC����
		panel[176] = p176 == 0 ? 0 : max(p92, 1);//�ϐ�u���[�L�@�}�X�R���L�[���Ƃɒl�ω�
		panel[234] = p160 == 7 ? p234 % 100 : 0;//���̒�ԉw�\���͏��c�}�L�[�̎��̂�
		//�ȉ��Ǝ��d�l
		panel[166] = p166;//���j�^
		panel[170] = Open_nfb;//�񐶊J��
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
	void Notch(ATS_VEHICLESTATE vehicleState, int* panel, int* sound)
	{
		int brake = 0;
		int power = 0;
		//���莞�Ԍo�߂��Ă�����
		if (g_time > m_notchtimer)
		{
			brake = outputBrake;
			power = outputNotch;
			//���̖ڕW���Ԃ�ݒ�
			m_notchtimer = p_ini.Lag == -1 ? g_time + 200 + (g_time % 50) * 5 : g_time + p_ini.Lag;
		}
		panel[51] = brake == g_emgBrake ? 9 : brake;
		panel[55] = brake;
		panel[57] = brake;
		panel[66] = power;
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

	void SetBrake(int notch)
	{
		//�t���O�������Ă���ƃ}�X�R���𓮂������Ƃ��ɕ\��������
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