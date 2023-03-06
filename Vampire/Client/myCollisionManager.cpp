#include "myCollisionManager.h"
#include "myScene.h"
#include "mySceneManager.h"

namespace my
{
	WORD CollisionManager::mMatrix[(UINT)eLayerType::END] = {}; // ��ü ���̾ �迭�� �����

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::getActiveScene(); // ������ ���� ���� �Ҵ�

		for (UINT row = 0; row < (UINT)eLayerType::END; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::END; col++) //���� ���� ��ü ���̾�
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
			Collider* leftCollider = leftObject->GetComponent<Collider>(); // ������ ������Ʈ�� �ݶ��̴�
			if (leftCollider == nullptr) // �ݶ��̴��� ���ٸ� 
				continue;

			for (auto rightObject : rights) // �ι�° ������Ʈ�� �ݶ��̴� 
			{
				Collider* rightCollider = rightObject->GetComponent<Collider>();
				if (rightCollider == nullptr)
					continue;

				if (leftObject == rightObject) // �� ������Ʈ�� ���ٸ� 
					continue;

				if (Intersect(leftCollider, rightCollider))
				{
					// �浹 O
				}
				else
				{
					// �浹 X
				}
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Vector2 leftPos = left->getPos(); // ��ġ�� �޾ƿ� 
		Vector2 rightPos = right->getPos();

		// �� �浹ü ���� �Ÿ���, �������� ���ݳ����� ���� ���ؼ�
		// �Ÿ��� �� ��ٸ� �浹 X, �Ÿ��� �� ª�ٸ� �浹 O
		Vector2 leftSize = left->getSize(); // ũ�� �޾ƿ�
		Vector2 rightSize = right->getSize();

		if (fabs(leftPos.x - rightPos.x) < (leftSize.x / 2.0f) + (rightSize.x / 2.0f) // �� ��ü�� �������� �պ��� 
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

