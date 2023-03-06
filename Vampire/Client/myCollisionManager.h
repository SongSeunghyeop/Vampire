#pragma once
#include "CommonInclude.h"
#include "Enum.h"
#include "myCollider.h"

namespace my
{
	class Scene;
	class CollisionManager
	{
	public:
		static void Update();
		static void LayerCollision(Scene* scene, eLayerType left, eLayerType right);
		static bool Intersect(Collider* left, Collider* right);

		static void setLayer(eLayerType left, eLayerType right, bool value);
		static void clear();

	private:
		static WORD mMatrix[(UINT)eLayerType::END];
	};
}
