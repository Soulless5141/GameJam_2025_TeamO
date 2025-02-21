#include "DxLib.h"
//#include "SceneManager.h"
#include "Scene/Title/Title.h"
#include "Utility/PadInput.h"
#include "Utility/FpsControl.h"
#include "Scene/SceneManager.h"

#define FRAMERATE 60.0 // �t���[�����[�g
#define HEIGHT 720
#define WIDTH 1280 
#define REFRESHRATE 32

/***********************************************
 * �v���O�����̃G���g���[�|�C���g
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E�^�C�g���̐ݒ�
	SetMainWindowText("Russian Roulette");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(WIDTH, HEIGHT, REFRESHRATE);

	// ���������𖳌���
	SetWaitVSyncFlag(0);

	// DxLib �̏������Ɏ��s�����ꍇ�͏I��
	if (DxLib_Init() == -1) return -1;

	// �`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	// �V�[���}�l�[�W���[�̍쐬
	//SceneManager* sceneMng;
	//try
	//{
	//	sceneMng = new SceneManager((AbstractScene*)new Title());
	//}
	//catch (const char* err)
	//{
	//	// �G���[���O�̏o��
	//	FILE* fp = NULL;
	//	DATEDATA data;
	//	GetDateTime(&data);
	//	fopen_s(&fp, "ErrLog.txt", "a");
	//	fprintf_s(fp, "%02d�N %02d�� %02d�� %02d�� %02d�� %02d�b : %s\n",
	//		data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);
	//	return 0;
	//}

	//�Q�[���̏�����
	SceneManagerInitialize();

	// �Q�[�����[�v
	while ((ProcessMessage() == 0) /* && (sceneMng->Update() != nullptr)*/)
	{
		// �t���[�����[�g����
		FpsControll_Update();

		// ��ʃN���A
		ClearDrawScreen();

		// ���͍X�V
		PAD_INPUT::UpdateKey();

		// �V�[���̕`��
		//sceneMng->Draw();

		// �t���[�����[�g�\��
		FpsControll_Draw();

		// �t���[���ҋ@
		FpsControll_Wait();

		// �I�������i�o�b�N�{�^���ŃQ�[���I���j
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		//�V�[���̃A�b�v�f�[�g
		SceneManagerUpdate();

		// ��ʂ̍X�V
		ScreenFlip();
	}

	// DxLib �̏I������
	DxLib_End();
	return 0;
}
