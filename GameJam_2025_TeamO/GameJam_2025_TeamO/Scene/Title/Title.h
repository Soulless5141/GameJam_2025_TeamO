#pragma once

#include "../SceneBase.h"

void TitleSceneInit(void);
eSceneType TitleSceneUpdate();
void TitleSceneDraw(void);

enum eTitle
{
	eStart_Title,
	eHelp_Title,
	eEnd_title,
};