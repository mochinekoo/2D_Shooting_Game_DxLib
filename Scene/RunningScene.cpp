#include <DxLib.h>
#include "BaseScene.h"
#include "RunningScene.h"
#include <array>

namespace {
}

RunningScene::RunningScene()
	: BaseScene("RunningScene") {
	sceneCounter_ = 0;
	hBackground_ = -1;
}

RunningScene::~RunningScene() {
}

void RunningScene::Init() {
	hBackground_ = LoadGraph("../../../Shader/TestTexture.png");
}

void RunningScene::Update() {
}

void RunningScene::Draw() {
	DrawGraph(0, 0, hBackground_, FALSE);
}

void RunningScene::Release() {
}
