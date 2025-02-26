#include "SceneManager.h"
#include "SceneType.h"
#include "DxLib.h"
#include <string.h>

#include "Title/Title.h"
#include "GameScene/SelectTarget.h"
#include "GameScene/ForcusTarget.h"
#include "Result/Result.h"
#include "Help/HelpScene.h"
#include "Help/HelpScene2.h"
#include "Ranking/RankingScene.h"
#include "RankingInput/RankingInput.h"
#include "End/End.h"

eSceneType current_scene_type;  //�V�[���̏��
int is_end_flag;                //�I���

//SelectTarget��ForcusTarget�̃C���X�^���X��ǉ�
SelectTarget* selectTarget = nullptr;
ForcusTarget* forcusTarget = nullptr;
RankingScene* rakingscene = nullptr;
RankingInputScene* rankinginput = nullptr;
Result* result = nullptr;

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
		
		if (result)
		{
			next_scene_type = result->Update(0.0f);

		}
		
		break;

	case eRanking_Scene:

		if (rakingscene)
		{
			next_scene_type = rakingscene->Update(0.0f);
		}

		break;

	case eRanking_Input:

		if (rankinginput)
		{
			next_scene_type = rankinginput->Update();
		}
		break;

	case eHelp:

		next_scene_type = HelpSceneUpdate();

		break;


	case eHelp2:

		next_scene_type = HelpScene2Update();

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
		if (result)
		{
			result->Draw();
		}

		break;

	case eRanking_Scene:

		if (rakingscene)
		{
			rakingscene->Draw();
		}

		break;

	case eRanking_Input:

		if (rankinginput)
		{
			rankinginput->Draw();
		}

		break;
	case eHelp:

		HelpSceneDraw();

		break;

	case eHelp2:

		HelpScene2Draw();

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
		selectTarget->Finalize();
		delete selectTarget;
		selectTarget = nullptr;
	}
	else if (current_scene_type == eForcusMode)
	{
		forcusTarget->Finalize();
		delete forcusTarget;
		forcusTarget = nullptr;
	}
	
	else if (current_scene_type == eRanking_Scene)
	{
		rakingscene->Finalize();
		delete rakingscene;
		rakingscene = nullptr;
	}
	else if (current_scene_type == eRanking_Input)
	{
		delete rankinginput;
		rakingscene = nullptr;
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
			if (not result)
			{
				result = new Result();
			}
			result->Initialize();
			break;

		case eRanking_Scene:

			if (!rakingscene)
			{
				rakingscene = new RankingScene();
			}

			rakingscene->Initialize();

			break;

		case eRanking_Input:

			if (!rankinginput)
			{
				rankinginput = new RankingInputScene();
			}

			rankinginput->Initialize();

			break;
		case eHelp:

			HelpSceneInit();

			break;

		case eHelp2:

			HelpScene2Init();

			break;

		case eEnd:

			EndSceneInit();

			break;
	}
}