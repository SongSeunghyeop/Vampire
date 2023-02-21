#pragma once
#include "MyGameObject.h"

namespace ya
{
	class Dragon : public MyGameObject
	{
	public:
		Dragon();
		~Dragon();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:

	};
}

