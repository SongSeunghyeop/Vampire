#pragma once
#include "myComponent.h"


namespace my
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void setCenter(Vector2 center) { mCenter = center; };
		void setSize(Vector2 size) { mSize = size; };
		void setRGB(int r, int g, int b) { mRgb.r = r; mRgb.g = g; mRgb.b = b; };
		Vector2 getPos() 
		{ 
			return mPos; 
		}
		Vector2 getSize() { return mSize; }

	private:
		Vector2 mCenter;
		Vector2 mSize;
		Vector2 mPos;
		MyRGB mRgb;
	};
}
