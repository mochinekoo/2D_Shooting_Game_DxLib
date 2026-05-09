#pragma once
#include <DxLib.h>
#include "BaseScene.h"

class RunningScene : public BaseScene {
private:
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