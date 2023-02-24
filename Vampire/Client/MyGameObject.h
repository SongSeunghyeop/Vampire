#pragma once
#include "myEntity.h"
#include "myComponent.h"

namespace my
{
	class GameObject : public Entity
	{
	public:
	    virtual void Initialize();
	    virtual void Update();
	    virtual void Render(HDC hdc);
	    virtual void Release();

		GameObject();
		virtual ~GameObject();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			UINT compType = (UINT) comp->getType();	// getType() = ������Ʈ Ÿ��(Enum class) ��ȯ
			mComponents[compType] = comp;

			return comp;
		}
		template <typename T>
		T* GetComponent()
		{
			for (Component* c : mComponents)
			{
				if (dynamic_cast<T*>(c)) // RTTI
					return dynamic_cast<T*>(c);

				return NULL;
			}
		}
	private:
		std::vector<Component*> mComponents;
	};
}


