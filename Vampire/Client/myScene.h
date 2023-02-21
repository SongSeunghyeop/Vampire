#pragma once
#include "Entity.h"
#include "myLayer.h"

namespace ya
{	
	class myScene : public Entity
	{
	public:
		myScene();
		virtual ~myScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void AddGameObj(MyGameObject* obj, eLayerType Layer);

	private:
		std::vector <myLayer> mLayer;
	};
}


