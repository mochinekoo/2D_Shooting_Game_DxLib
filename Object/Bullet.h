#pragma once

#include "BaseObject.h"
#include "../Library/Location.hpp"
#include "../Library/Vector.hpp"

class Bullet : public BaseObject {
private:
	Location3D location_;
	Vector3D vector_;
public:
	Bullet(const Location3D& location, const Vector3D& vector);
	~Bullet();
	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	Location3D GetLocation() const { return location_; };
	void SetLocation(const Location3D& location) { location_ = location; };
	Vector3D GetVector() const { return vector_; };
	void SetVector(const Vector3D& vector) { vector_ = vector; };
};