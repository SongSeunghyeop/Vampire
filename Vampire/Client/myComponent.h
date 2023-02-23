#pragma once
#include "Entity.h"

namespace my 
{
	class myComponent : public Entity
	{
	public:
		myComponent(ComponentType Type);
	    ~myComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		ComponentType getType() { return myType; }
	private:
		const ComponentType myType;
	};
}
