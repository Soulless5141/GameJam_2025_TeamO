#include "SceneManager.h"
#include "SceneType.h"
#include "DxLib.h"

#include "Title/Title.h"

eSceneType current_scene_type;  //シーンの状態
int is_end_flag;                //終わり

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
		break;
	case eSelectMode:
		break;
	case eForcusMode:
		break;
	case eResult:
		break;
	case eRanking:
		break;
	case eRanking_Input:
		break;
	case eHelp:
		break;
	case eEnd:
		break;
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
		break;
	case eSelectMode:
		break;
	case eForcusMode:
		break;
	case eResult:
		break;
	case eRanking:
		break;
	case eRanking_Input:
		break;
	case eHelp:
		break;
	case eEnd:
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
		return;
	}

	if (new_scene_type == eEnd)
	{
		is_end_flag = TRUE;
		return;
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
			break;
		case eSelectMode:
			break;
		case eResult:
			break;
		case eRanking:
			break;
		case eRanking_Input:
			break;
		case eHelp:
			break;
		case eEnd:
			break;
	}
}