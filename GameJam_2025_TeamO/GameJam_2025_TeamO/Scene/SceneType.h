//#pragma once
//
//#include <vector>
//#include <string>
//
////enum eSceneType
////{
////	eTitle,
////	eSelectMode,
////	eForcusMode,
////	eResult,
////	eRanking,
////	eRanking_Input,
////	eRanking_Scene,
////	eHelp,
////	eEnd,
////};
//
////基底シーンクラス
//class SceneType
//{
//public:
//	SceneType() {}
//	virtual ~SceneType() {}
//
//	//初期化処理
//	virtual void Initialize() {}
//	//更新処理
//	virtual eSceneType Update()
//	{
//		return GetNowScene();
//	}
//	//描画処理
//	virtual void Draw() const {}
//	//終了処理
//	virtual void Finalize() {}
//
//	//現在のシーン情報を取得
//	virtual eSceneType GetNowScene() const = 0;
//};