#pragma once
#include "Entity.h"

namespace ya 
{
	class myComponent : public Entity
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();
	};
}
