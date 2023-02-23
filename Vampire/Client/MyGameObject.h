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

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			UINT compType = (UINT) comp->getType();	
			mComponents[compType] = comp;

			return comp;
		}
		template <typename T>
		T* GetComponent()
		{
			for (myComponent* c : mComponents)
			{
				if (dynamic_cast<T*>(c)) // RTTI
					return dynamic_cast<T*>(c);

				return NULL;
			}
		}
	private:
		std::vector<myComponent*> mComponents;
	};
}


