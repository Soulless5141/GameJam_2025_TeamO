#include "Title.h"
#include "../SceneType.h"
#include "../../Utility/PadInput.h"
#include "DxLib.h"

int title_background_image;  //�w�i�ݒ�p�̕ϐ�

//�^�C�g����ʂ̏�����
void TitleSceneInit(void)
{

}

//�^�C�g����ʂ̃A�b�v�f�[�g
eSceneType TitleSceneUpdate(void)
{
	return eTitle;
}

//�^�C�g����ʂ̕`��
void TitleSceneDraw(void)
{
	/*�`�悷�镶��*/
	SetFontSize(30);
	DrawFormatString(100,500,GetColor(255,255,255), "�X�^�[�g");
	DrawFormatString(500,500, GetColor(255, 255, 255),"�w���v");
}