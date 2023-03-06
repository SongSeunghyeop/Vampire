#include "myCollisionManager.h"
#include "myScene.h"
#include "mySceneManager.h"

namespace my
{
	WORD CollisionManager::mMatrix[(UINT)eLayerType::END] = {}; // 전체 레이어를 배열로 만든다

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::getActiveScene(); // 현재의 씬을 동적 할당

		for (UINT row = 0; row < (UINT)eLayerType::END; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::END; col++) //현재 씬의 전체 레이어
			{
				if (mMatrix[row] & (1 << col)) 
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetGameObj(left);
		const std::vector<GameObject*>& rights = scene->GetGameObj(right);

		for (auto leftObject : lefts)
		{
			Collider* leftCollider = leftObject->GetComponent<Collider>(); // 현재의 오브젝트의 콜라이더
			if (leftCollider == nullptr) // 콜라이더가 없다면 
				continue;

			for (auto rightObject : rights) // 두번째 오브젝트의 콜라이더 
			{
				Collider* rightCollider = rightObject->GetComponent<Collider>();
				if (rightCollider == nullptr)
					continue;

				if (leftObject == rightObject) // 두 오브젝트가 같다면 
					continue;

				if (Intersect(leftCollider, rightCollider))
				{
					// 충돌 O
				}
				else
				{
					// 충돌 X
				}
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Vector2 leftPos = left->getPos(); // 위치를 받아옴 
		Vector2 rightPos = right->getPos();

		// 두 충돌체 간의 거리와, 각면적의 절반끼리의 합을 비교해서
		// 거리가 더 길다면 충돌 X, 거리가 더 짧다면 충돌 O
		Vector2 leftSize = left->getSize(); // 크기 받아옴
		Vector2 rightSize = right->getSize();

		if (fabs(leftPos.x - rightPos.x) < (leftSize.x / 2.0f) + (rightSize.x / 2.0f) // 두 객체의 반지름의 합보다 
			&& fabs(leftPos.y - rightPos.y) < (leftSize.y / 2.0f) + (rightSize.y / 2.0f))
		{
			return true;
		}
		return false;
	}

	void CollisionManager::setLayer(eLayerType left, eLayerType right, bool value)
	{
		UINT row = 0;
		UINT col = 0;

		UINT ileft = (UINT)left;
		UINT iright = (UINT)right;

		if (left <= right)
		{
			row = ileft;
			col = iright;
		}
		else
		{
			row = iright;
			col = ileft;
		}

		if (value == true)
			mMatrix[row] |= (1 << col);

		else
			mMatrix[row] &= ~(1 << col);
	}

	void CollisionManager::clear()
	{

	}
}

