#include "SceneManager.h"
#include "SceneType.h"
#include "DxLib.h"

#include "Title/Title.h"

eSceneType current_scene_type;  //�V�[���̏��
int is_end_flag;                //�I���

void SceneManagerDraw(void);
void ChangeScene(eSceneType new_scene_type);
void SceneInit(eSceneType new_scene_type);

//�Q�[���̏�����
void SceneManagerInitialize(void)
{
	is_end_flag = FALSE;
	ChangeScene(eTitle);
}

//�V�[���̃A�b�v�f�[�g
void SceneManagerUpdate(void)
{
	eSceneType next_scene_type = eEnd;

	switch (current_scene_type)
	{
	case eTitle:
		break;
	case eInGame:
		break;
	case eResult:
		break;
	case eRanking:
		break;
	case eHelp:
		break;
	case eEnd:
		break;
	}

	SceneManagerDraw();

	//�V�[���̐؂�ւ�
	if (current_scene_type != next_scene_type)
	{
		ChangeScene(next_scene_type);
	}
}

//�I��
int IsFinish(void)
{
	return is_end_flag;
}

//�V�[���̕`��
void SceneManagerDraw(void)
{
	switch (current_scene_type)
	{
	case eTitle:
		break;
	case eInGame:
		break;
	case eResult:
		break;
	case eRanking:
		break;
	case eHelp:
		break;
	case eEnd:
		break;
	}
}

//�V�[���̐؂�ւ�
void ChangeScene(eSceneType new_scene_type)
{
	static int is_once = TRUE;

	if (is_once == TRUE)
	{
		is_once = FALSE;
		SceneInit(new_scene_type);
		return;
	}

	if (new_scene_type == eEnd)
	{
		is_end_flag = TRUE;
		return;
	}

	//�V�����V�[���ɐ؂�ւ���
	SceneInit(new_scene_type);
	current_scene_type = new_scene_type;
}

//�V�[���̏�����
void SceneInit(eSceneType new_scene_type)
{
	switch (new_scene_type)
	{
	case eTitle:
		break;
	case eInGame:
		break;
	case eResult:
		break;
	case eRanking:
		break;
	case eHelp:
		break;
	case eEnd:
		break;
	}
}