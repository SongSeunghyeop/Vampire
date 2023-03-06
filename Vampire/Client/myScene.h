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

		void AddGameObj(GameObject* obj, eLayerType layer);
		const std::vector<GameObject*>& GetGameObj(eLayerType layer);

	protected:
		std::vector <Layer> mLayers;
	};
}


