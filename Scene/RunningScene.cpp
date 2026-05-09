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
	enemyList.push_back(new Enemy());
}

void RunningScene::Update() {
	player->Update();
	for (Enemy* enemy : enemyList) {
		enemy->Update();
	}
}

void RunningScene::Draw() {
	DrawGraph(0, 0, hBackground_, FALSE);
	player->Draw();
	for (Enemy* enemy : enemyList) {
		enemy->Draw();
	}
}

void RunningScene::Release() {
}
