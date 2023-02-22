#pragma once
#include "Entity.h"
#include "MyGameObject.h"

namespace my 
{
	class myLayer : public Entity
	{
	public:
		myLayer();
		virtual ~myLayer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void AddGameObj(MyGameObject* obj);

	private:
		std::vector<MyGameObject*> mGameobj;
	};
}
