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
////���V�[���N���X
//class SceneType
//{
//public:
//	SceneType() {}
//	virtual ~SceneType() {}
//
//	//����������
//	virtual void Initialize() {}
//	//�X�V����
//	virtual eSceneType Update()
//	{
//		return GetNowScene();
//	}
//	//�`�揈��
//	virtual void Draw() const {}
//	//�I������
//	virtual void Finalize() {}
//
//	//���݂̃V�[�������擾
//	virtual eSceneType GetNowScene() const = 0;
//};