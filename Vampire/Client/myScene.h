#pragma once
#include "myEntity.h"
#include "myLayer.h"

namespace my
{	
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit ();

		void AddGameObj(GameObject* obj, eLayerType Layer);
		void DelGameObj(GameObject* obj, eLayerType Layer);

		//void GotoBack(GameObject* obj, eLayerType Layer);
	protected:
		std::vector <Layer> mLayer;
	};
}


