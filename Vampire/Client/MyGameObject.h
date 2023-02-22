#pragma once
#include "Entity.h"
#include "myComponent.h"

namespace my
{
	class MyGameObject : public Entity
	{
	public:
	    virtual void Initialize();
	    virtual void Update();
	    virtual void Render(HDC hdc);
	    virtual void Release();

		MyGameObject();
		virtual ~MyGameObject();
		void setPos(float x, float y);

	protected:
		Vector2 mPos;

	private:
		std::vector<myComponent*> mComponents;
	};
}


