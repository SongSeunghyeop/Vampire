#pragma once
#include "myGameObject.h"
#include "myResourceManager.h"
#include "myInput.h"
#include "myImage.h"
#include "myCollider.h"
#include "Krochi.h"
namespace my
{
	class BaseSkill : public GameObject
	{
	public:
		BaseSkill();
		~BaseSkill();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void onCollisionEnter(Collider* other);
		void onCollisionStay(Collider* other);
		void onCollisionExit(Collider* other);
	private:
		Vector2 skillPos;
		Vector2 EnemyPos;

		int R;
		bool SkillColl;
		float mTime;
		float effect_Time;

		Image* Skill_R;
		Image* Skill_L;
		Image* D_effect;
	};
}
