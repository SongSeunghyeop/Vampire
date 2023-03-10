#pragma once
#include "myGameObject.h"
#include "myResourceManager.h"
#include "myInput.h"
#include "myImage.h"
#include "myCollider.h"

namespace my
{
	class BaseBullet : public GameObject
	{
	public:
		BaseBullet();
		~BaseBullet();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;
	private:
		Vector2 bulletPos;
		float mTime;
		Image* Bullet;
		int R;
	};
}
