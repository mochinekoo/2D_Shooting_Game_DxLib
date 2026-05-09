#include "BaseObject.h"
#include "../Library/Location.hpp"
#include "../Library/Vector.hpp"

class Player : public BaseObject {
private:
	Location3D location_;
	Vector3D vector_;
public:
	Player();
	~Player();
	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};