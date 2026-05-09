#pragma once
#include <DxLib.h>
#include "BaseScene.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"
#include <vector>

class RunningScene : public BaseScene {
private:
	Player* player;
	std::vector<Enemy*> enemyList;
	int hBackground_;
protected:
public:
	RunningScene();
	~RunningScene();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};