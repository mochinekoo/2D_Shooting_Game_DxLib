#pragma once
#include <DxLib.h>
#include "BaseScene.h"
#include "../Object/Player.h"

class RunningScene : public BaseScene {
private:
	Player* player;
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