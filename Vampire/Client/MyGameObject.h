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
			T* comp = new T(); // ���� ������Ʈ�� �ڽ� Ŭ������ ���� �Ҵ�
			UINT compType = (UINT) comp->getType();	// getType() = ������Ʈ Ÿ��(Enum class) ��ȯ
			mComponents[compType] = comp; // ���������迭�� �� Ÿ���� ��ü ����
			comp->setOwner(this);
			return comp; // �����Ҵ�� ��ü ����
		}
		template <typename T>
		T* GetComponent()
		{
			for (Component* c : mComponents) // ������Ʈ �迭�� ã�ƺ��鼭
			{
				if (dynamic_cast<T*>(c)) // ���� �� Ŭ���� Ÿ���� �߰ߵȴٸ�, 
					return dynamic_cast<T*>(c); // �� Ŭ���� Ÿ������ ����ȯ�ؼ� ��ȯ
			}
				return NULL;
		}
	private:
		std::vector<Component*> mComponents;
	};
}


