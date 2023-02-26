#pragma once
#include "myEntity.h"
#include "myGameObject.h"

namespace my 
{
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void AddGameObj(GameObject* obj);
		void DelGameObj(GameObject* obj);

	private:
		std::vector<GameObject*> mGameobj;
	};
}
