#include "DxLib.h"
//#include "SceneManager.h"
#include "Scene/Title/Title.h"
#include "Utility/PadInput.h"
#include "Utility/FpsControl.h"
#include "Scene/SceneManager.h"

#define FRAMERATE 60.0 // フレームレート
#define HEIGHT 720
#define WIDTH 1280 
#define REFRESHRATE 32

/***********************************************
 * プログラムのエントリーポイント
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウタイトルの設定
	SetMainWindowText("Russian Roulette");

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// 画面サイズの設定
	SetGraphMode(WIDTH, HEIGHT, REFRESHRATE);

	// 垂直同期を無効化
	SetWaitVSyncFlag(0);

	// DxLib の初期化に失敗した場合は終了
	if (DxLib_Init() == -1) return -1;

	// 描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	// シーンマネージャーの作成
	//SceneManager* sceneMng;
	//try
	//{
	//	sceneMng = new SceneManager((AbstractScene*)new Title());
	//}
	//catch (const char* err)
	//{
	//	// エラーログの出力
	//	FILE* fp = NULL;
	//	DATEDATA data;
	//	GetDateTime(&data);
	//	fopen_s(&fp, "ErrLog.txt", "a");
	//	fprintf_s(fp, "%02d年 %02d月 %02d日 %02d時 %02d分 %02d秒 : %s\n",
	//		data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);
	//	return 0;
	//}

	//ゲームの初期化
	SceneManagerInitialize();

	// ゲームループ
	while ((ProcessMessage() == 0) /* && (sceneMng->Update() != nullptr)*/)
	{
		// フレームレート制御
		FpsControll_Update();

		// 画面クリア
		ClearDrawScreen();

		// 入力更新
		PAD_INPUT::UpdateKey();

		// シーンの描画
		//sceneMng->Draw();

		// フレームレート表示
		FpsControll_Draw();

		// フレーム待機
		FpsControll_Wait();

		// 終了処理（バックボタンでゲーム終了）
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		//シーンのアップデート
		SceneManagerUpdate();

		// 画面の更新
		ScreenFlip();
	}

	// DxLib の終了処理
	DxLib_End();
	return 0;
}
