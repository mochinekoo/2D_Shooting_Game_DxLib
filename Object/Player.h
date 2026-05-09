#pragma once

#include "BaseObject.h"
#include "../Library/Location.hpp"
#include "../Library/Vector.hpp"

class Player : public BaseObject {
private:
	Location3D location_;
	Vector3D vector_;
	float bulletAngle_;
public:
	Player();
	~Player();
	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	Location3D GetLocation() const { return location_; };
	void SetLocation(const Location3D& location) { location_ = location; };
	Vector3D GetVector() const { return vector_; };
	void SetVector(const Vector3D& vector) { vector_ = vector; };
};