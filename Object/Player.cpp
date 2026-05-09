#include <DxLib.h>
#include "Player.h"
#include "../framework.h"
#include <vector>
#include "Bullet.h"
#include "../Library/Location.hpp"
#include "../Library/Vector.hpp"
#include "../ImGUI/imgui.h"
#define RADIAN(angle) (angle * 3.141592) / 180

namespace {
	const unsigned int DRAW_COLOR = GetColor(245, 20, 20);
	const int DRAW_RADIUS = 30;
	const int DRAW_POSNUM = 30;
	const float DEFAULT_SPEED = 5.0f;

	std::vector<Bullet*> bulletList;
}

Player::Player()
	: BaseObject("Player", true) {
	location_ = Location3D(GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2, 0);
	vector_ = Vector3D(DEFAULT_SPEED, DEFAULT_SPEED, DEFAULT_SPEED);
	bulletAngle_ = 0.0f;
}

Player::~Player() {
	for (Bullet* bullet : bulletList) {
		delete bullet;
	}
}

void Player::Init() {
}

void Player::Update() {
	if (CheckHitKey(KEY_INPUT_W)) {
		location_.y_ -= vector_.y_;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		location_.y_ += vector_.y_;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		location_.x_ -= vector_.x_;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		location_.x_ += vector_.x_;
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		float rad = RADIAN(bulletAngle_);
		Bullet* bullet = new Bullet(location_, Vector3D(cos(rad), sin(rad), 0).Scalar(3.0));
		bulletList.push_back(bullet);
	}

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		bulletAngle_ -= 2.0f;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		bulletAngle_ += 2.0f;
	}

	for (Bullet* bullet : bulletList) {
		if (bullet == nullptr) continue;
		bullet->Update();
	}
}

void Player::Draw() {
	DrawCircleAA(location_.x_, location_.y_, DRAW_RADIUS, DRAW_POSNUM, DRAW_COLOR);

	for (Bullet* bullet : bulletList) {
		if (bullet == nullptr) continue;
		bullet->Draw();
	}


#ifdef _DEBUG
	ImGui::Begin("Player");
	ImGui::Text("Location: (%2.0f, %2.0f), Vector(%2.0f, %2.0f)", location_.x_, location_.y_, vector_.x_, vector_.y_);
	ImGui::Text("BulletAngle: %2.0f", bulletAngle_);
	ImGui::End();
#endif
}

void Player::Release() {
}