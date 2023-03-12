#pragma once
#include "VampireEngine.h"

namespace my
{
	class GameObject;
	class Camera
	{
	public:
		static void Initiailize();
		static void Update();
		static void Clear();

		static void setTarget(GameObject* target) { mTarget = target; }
		static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }
	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;
	};
}
