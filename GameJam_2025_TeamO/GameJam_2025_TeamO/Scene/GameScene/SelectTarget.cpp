#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	player = new Player;
	gage = new Gage;
	bullet = new RemainingBullets;
	mato = new Mato;

	//SelectTarget selector;

	SelectFlg = FALSE;
	ForcusFlg = FALSE;
	background = LoadGraph("Resource/Images/BGI.jpg");  // �摜�̃p�X���w��
	
}

SelectTarget::~SelectTarget()
{
	delete player;
	delete gage;
	delete bullet;
	DeleteGraph(background);
}

//void SelectSceneInit()
//{
//}

void SelectTarget::Initialize()
{
	//�I�̕`��
	Mato* m = CreateObject<Mato>(Vector2D(300, 320));
	CreateObject<Mato>(Vector2D(300, 550));
	CreateObject<Mato>(Vector2D(530, 320));
	CreateObject<Mato>(Vector2D(530, 550));
	CreateObject<Mato>(Vector2D(750, 320));
	CreateObject<Mato>(Vector2D(750, 550));
	CreateObject<Mato>(Vector2D(980, 320));
	CreateObject<Mato>(Vector2D(980, 550));
}

//eSceneType SelectTarget::SelectSceneUpdate()
//{
//	player->Update();
//
//	//�I�������I����V�[���J��
//	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
//	{
//		return eForcusMode;
//	}
//
//	return eSelectMode;
//}

eSceneType SelectTarget::Update(const float& delta_second)
{
	gage->Update();
	bullet->Update();
	SceneBase::Update(delta_second);

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && SelectFlg == FALSE)
	{
		SelectFlg = TRUE;
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) && IsHitCheck(player, mato) == true)
	{
		return eForcusMode;
	}

	//�e�������ĊO������c�e�����Z���ăV�[���J��
	if (SelectFlg == TRUE)
	{
		SelectFlg = FALSE;
		bullet->LifeReduce();
		//return eForcusMode;
	}

	////�c�e���Ȃ��Ȃ����烊�U���g�ɑJ��
	//if (bullet->GetLife() <= 0)
	//{
	//	return eResult;
	//}

	return eSelectMode;
}

//void SelectTarget::SelectSceneDraw(void)
//{
//	player->Draw();
//	DrawFormatString(0, 0, 0xffffff, "select scene");
//	DrawGraph(0, 0, background, TRUE);
//}

void SelectTarget::Draw() const
{

	//�w�i�摜�̕`��
	DrawRotaGraph(640, 375, 0.6, 0.0, background, TRUE);

	// �I�̉��`��
	SceneBase::Draw();

	gage->Draw();
	bullet->Draw();
}

bool SelectTarget::IsHitCheck(Player* p, Mato* m)
{
	Vector2D playerPos = p->GetLocation();
	Vector2D matoPos = m->GetLocation();
	Vector2D playerSize = p->GetSize();
	Vector2D matoSize = m->GetSize();

	Vector2D box_ex = playerSize + matoSize;

	if (fabs(playerPos.x - matoPos.x) < box_ex.x / 2 &&
		fabs(playerPos.y - matoPos.y) < box_ex.y / 2)
	{
		return true;
	}

		return false;
}

const eSceneType SelectTarget::GetNowSceneType() const
{
	return eSceneType::eSelectMode;
}
