#include "SceneManager.h"
#include "SceneType.h"
#include "DxLib.h"
#include <string.h>

#include "Title/Title.h"
#include "GameScene/SelectTarget.h"
#include "GameScene/ForcusTarget.h"
#include "Result/Result.h"
#include "Help/HelpScene.h"
#include "Ranking/RankingScene.h"
#include "RankingInput/RankingInput.h"
#include "End/End.h"

eSceneType current_scene_type;  //�V�[���̏��
int is_end_flag;                //�I���

//SelectTarget��ForcusTarget�̃C���X�^���X��ǉ�
SelectTarget* selectTarget = nullptr;
ForcusTarget* forcusTarget = nullptr;
RankingScene* rakingscene = nullptr;

void SceneManagerDraw(void);
void ChangeScene(eSceneType new_scene_type);
void SceneInit(eSceneType new_scene_type);

//�Q�[���̏�����
void SceneManagerInitialize(void)
{
	is_end_flag = FALSE;
	ChangeScene(eSelectMode);
}

//�V�[���̃A�b�v�f�[�g
void SceneManagerUpdate(void)
{
	eSceneType next_scene_type = eEnd;

	switch (current_scene_type)
	{
	case eTitle:

		next_scene_type = TitleSceneUpdate();

		break;

	case eSelectMode:
		if (selectTarget)
		{
			next_scene_type = selectTarget->Update(0.0f);
		}
		break;
	case eForcusMode:
		if (forcusTarget)
		{
			next_scene_type = forcusTarget->ForcusSceneUpdate();
		}
		break;
	case eResult:
		
		next_scene_type = ResultSceneUpdate();

		break;

	case eRanking_Scene:

		if (rakingscene)
		{
			next_scene_type = rakingscene->Update(0.0f);
		}

		break;

	case eRanking_Input:
		break;
	case eHelp:

		next_scene_type = HelpSceneUpdate();

		break;

	case eEnd:

		next_scene_type = eEnd;

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

		TitleSceneDraw();

		break;

	case eSelectMode:
		if (selectTarget)
		{
			selectTarget->Draw();
		}
		break;
	case eForcusMode:
		if (forcusTarget)
		{
			forcusTarget->ForcusSceneDraw();
		}
		break;
	case eResult:

		//ResultSceneDraw();

		break;

	case eRanking_Scene:

		if (rakingscene)
		{
			rakingscene->Draw();
		}

		break;

	case eRanking_Input:
		break;
	case eHelp:

		HelpSceneDraw();

		break;

	case eEnd:

		EndSceneDraw();

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
		current_scene_type = new_scene_type;
		return;
	}

	if (new_scene_type == eEnd)
	{
		is_end_flag = TRUE;
		return;
	}

	//�V�[�����؂�ւ��O�ɃC���X�^���X���폜
	if (current_scene_type == eSelectMode)
	{
		delete selectTarget;
		selectTarget = nullptr;
	}
	else if (current_scene_type == eForcusMode)
	{
		delete forcusTarget;
		forcusTarget = nullptr;
	}
	
	else if (current_scene_type == eRanking)
	{
		delete rakingscene;
		rakingscene = nullptr;
	}
	/*else if (current_scene_type == eRanking)
	{
		delete rakingscene;
		rakingscene = nullptr;
	}*/


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

			TitleSceneInit();

			break;

		case eSelectMode:
			if (!selectTarget)
			{
				// �C���X�^���X�̍쐬
				selectTarget = new SelectTarget();
			}
			selectTarget->Initialize();
			break;

		case eForcusMode:
			if (!forcusTarget)
			{
				// �C���X�^���X�̍쐬
				forcusTarget = new ForcusTarget();
			}
			break;
		case eResult:

			//ResultSceneInit();

			break;

		case eRanking_Scene:

			if (!rakingscene)
			{
				rakingscene = new RankingScene();
			}

			rakingscene->Initialize();

			break;

		case eRanking_Input:
			break;
		case eHelp:

			HelpSceneInit();

			break;

		case eEnd:

			EndSceneInit();

			break;
	}
}