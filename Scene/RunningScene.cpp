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
	player = nullptr;
}

RunningScene::~RunningScene() {
}

void RunningScene::Init() {
	hBackground_ = LoadGraph("../../../Shader/TestTexture.png");
	player = new Player();
	player->Init();
}

void RunningScene::Update() {
	player->Update();
}

void RunningScene::Draw() {
	DrawGraph(0, 0, hBackground_, FALSE);
	player->Draw();
}

void RunningScene::Release() {
}
