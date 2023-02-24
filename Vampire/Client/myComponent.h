#pragma once
#include "myEntity.h"

namespace my 
{
	class Component : public Entity
	{
	public:
		Component(eComponentType Type);
	    ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		eComponentType getType() { return myType; }
	private:
		const eComponentType myType;
	};
}
