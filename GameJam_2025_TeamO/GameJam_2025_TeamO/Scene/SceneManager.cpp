#include "SceneManager.h"
#include "SceneType.h"
#include "DxLib.h"

#include "Title/Title.h"
#include "GameScene/SelectTarget.h"
#include "GameScene/ForcusTarget.h"
#include "Result/Result.h"
#include "Help/HelpScene.h"
#include "Ranking/RankingScene.h"
#include "RankingInput/RankingInput.h"
#include "End/End.h"

eSceneType current_scene_type;  //シーンの状態
int is_end_flag;                //終わり

//SelectTargetとForcusTargetのインスタンスを追加
SelectTarget* selectTarget = nullptr;
ForcusTarget* forcusTarget = nullptr;

void SceneManagerDraw(void);
void ChangeScene(eSceneType new_scene_type);
void SceneInit(eSceneType new_scene_type);

//ゲームの初期化
void SceneManagerInitialize(void)
{
	is_end_flag = FALSE;
	ChangeScene(eTitle);
}

//シーンのアップデート
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
			next_scene_type = selectTarget->SelectSceneUpdate();
		}
		break;
	case eForcusMode:
		if (forcusTarget)
		{
			next_scene_type = forcusTarget->ForcusSceneUpdate();
		}
		break;
	case eResult:

		ResultSceneUpdate();

		break;

	case eRanking:
		break;
	case eRanking_Input:
		break;
	case eHelp:

		next_scene_type = HelpSceneUpdate();

		break;

	//case eEnd:
		//break;
	}

	SceneManagerDraw();

	//シーンの切り替え
	if (current_scene_type != next_scene_type)
	{
		ChangeScene(next_scene_type);
	}
}

//終了
int IsFinish(void)
{
	return is_end_flag;
}

//シーンの描画
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
			selectTarget->SelectSceneDraw();
		}
		break;
	case eForcusMode:
		if (forcusTarget)
		{
			forcusTarget->ForcusSceneDraw();
		}
		break;
	case eResult:

		ResultSceneDraw();

		break;

	case eRanking:
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

//シーンの切り替え
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

	//シーンが切り替わる前にインスタンスを削除
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


	//新しいシーンに切り替える
	SceneInit(new_scene_type);
	current_scene_type = new_scene_type;
}

//シーンの初期化
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
				// インスタンスの作成
				selectTarget = new SelectTarget();
			}
			break;

		case eForcusMode:
			if (!forcusTarget)
			{
				// インスタンスの作成
				forcusTarget = new ForcusTarget();
			}
			break;
		case eResult:

			ResultSceneInit();

			break;

		case eRanking:
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