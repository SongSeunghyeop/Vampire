#pragma once
#include "myComponent.h"

namespace my
{
	class Transform : public myComponent
	{
	public:
		Transform();
		~Transform();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void setPos(float x, float y);
		void setSize(float x, float y);

		Vector2 getPos();
		Vector2 getSize();
	private:
		Vector2 mPos;
		Vector2 mSize;
	};
}

