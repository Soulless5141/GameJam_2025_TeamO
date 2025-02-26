#include "SelectTarget.h"
#include "../../Objects/Mato/Mato.h"

SelectTarget::SelectTarget()
{
	gage = new Gage;
	bullet = new RemainingBullets;

	SelectFlg = FALSE;
	ForcusFlg = FALSE;
	background = LoadGraph("Resource/Images/BGI.jpg");  // 画像のパスを指定
	SuccessImg = LoadGraph("Resource/Images/seikou.jpg");  // 画像のパスを指定
	FaultImg = LoadGraph("Resource/Images/sippai.jpg");  // 画像のパスを指定

	SucSE = LoadSoundMem("Resource/Sounds/成功音.mp3");
	FauSE = LoadSoundMem("Resource/Sounds/失敗音.mp3");
	BGM = LoadSoundMem("Resource/Sounds/mainBGM.mp3");

	for (int i = 0; i < 8; i++)
	{
		mato[i] = nullptr;
	}
}

SelectTarget::~SelectTarget()
{
	
	delete gage;
	delete bullet;
	
	DeleteGraph(background);
	DeleteGraph(SuccessImg);
	DeleteGraph(FaultImg);

	DeleteSoundMem(SucSE);
	DeleteSoundMem(FauSE);
	DeleteSoundMem(BGM);
}

//void SelectSceneInit()
//{
//}

void SelectTarget::Initialize()
{
	Vector2D positions[8] =
	{
		{300,320},{300,550},{530,320},{530, 550},
		{750, 320},{750, 550},{980, 320},{980,550}
	};

	for (int i = 0; i < 8; i++)
	{
		mato[i] = CreateObject<Mato>(positions[i]);
	}

	//的の描画
	//CreateObject<Mato>(Vector2D(300, 320));
	//CreateObject<Mato>(Vector2D(300, 550));
	//CreateObject<Mato>(Vector2D(530, 320));
	//CreateObject<Mato>(Vector2D(530, 550));
	//CreateObject<Mato>(Vector2D(750, 320));
	//CreateObject<Mato>(Vector2D(750, 550));
	//CreateObject<Mato>(Vector2D(980, 320));
	//CreateObject<Mato>(Vector2D(980, 550));

	player = CreateObject<Player>(Vector2D(570, 320));
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
}

//eSceneType SelectTarget::SelectSceneUpdate()
//{
//	player->Update();
//
//	//選択した的からシーン遷移
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


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{

		for (int i = 0; i < 8; i++)
		{
			if (IsHitCheck(player, mato[i]) == true)
			{
				damage *= gage->GetMeter();
				//mato[i]->GetHp();
				mato[i]->DecreaseHp(damage);

				if (mato[i]->GetHp() == 0)
				{
					score += mato[i]->GetScore();
					PlaySoundMem(SucSE, DX_PLAYTYPE_BACK);
					DestroyObject(mato[i]);
				}
				
				
			}
			else
			{
				PlaySoundMem(FauSE, DX_PLAYTYPE_BACK);
			}
		};
	}

	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
	{
		damage = 1;
	}
		
	

	//弾を撃って外したら残弾を減算してシーン遷移
	if (SelectFlg == TRUE)
	{
		SelectFlg = FALSE;
		bullet->LifeReduce();
		//return eForcusMode;
	}

	//残弾がなくなったらリザルトに遷移
	if (bullet->GetLife() <= 0)
	{
		FILE* fp = nullptr;
		errno_t result = fopen_s(&fp, "Resource/Data/result.csv","w");

		if (result != 0)
		{
			throw("Resource/Data/result.csvが開けません\n");
		}
		fprintf(fp, "%d\n", score);
		fclose(fp);
		StopSoundMem(BGM);
		return eResult;
	}

	old_location = player->GetLocation();

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

	//背景画像の描画
	DrawRotaGraph(640, 375, 1.0, 0.0, background, TRUE);

	// 的の仮描画
	SceneBase::Draw();

	//player->Draw();
	
	DrawFormatString(0, 0, 0xffffff, "%d\n", score);
	DrawFormatString(10, 50, 0xffffff, "%d\n", gage->GetMeter());
	SetFontSize(48);
	DrawFormatString(100, 100, 0xff0000, "%d\n", mato[0]->GetHp());
	DrawFormatString(100, 150, 0xff0000, "%d\n", mato[0]->GetScore());
	DrawFormatString(200, 200, 0xff0000, "%d\n", damage);

	gage->Draw();
	bullet->Draw();
}

bool SelectTarget::IsHitCheck(Player* p, Mato* m)
{
	Vector2D playerPos = p->GetLocation();
	Vector2D matoPos = m->GetLocation();
	Vector2D playerSize = p->GetboxSize();
	Vector2D matoSize = m->GetboxSize();

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
