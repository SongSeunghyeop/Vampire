#include "Skill_1.h"
#include "myTransform.h"
#include "Time.h"
#include "myObject.h"

namespace my
{
	BaseSkill::BaseSkill()
		: mTime(0.0f)
		, effect_Time(0.0f)
	{
		
	}
	BaseSkill::~BaseSkill()
	{
	}
	void BaseSkill::Initialize()
	{
		Skill_R = ResourceManager::Load<Image>(L"Skill_R", L"..\\Resources\\skill_1.bmp");
		Skill_L = ResourceManager::Load<Image>(L"Skill_L", L"..\\Resources\\skill_2.bmp");
		D_effect = ResourceManager::Load<Image>(L"D_effect", L"..\\Resources\\D_effect2.bmp");

		Transform* tr = GetComponent<Transform>();
		skillPos = tr->getPos();

		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(2, 0));
		collider->setSize(Vector2(280, 45));
		collider->setRGB(255, 0, 0);

		SkillColl = false;

		GameObject::Initialize();
	}
	void BaseSkill::Update()
	{
		Transform* tr = GetComponent<Transform>();
		tr->setPos(Krochi::getPlayerPos() + Vector2(40.0f,-40.0f));
		skillPos = tr->getPos();
		mTime += Time::getDeltaTime();
		
		GameObject::Update();

		if (mTime > 0.15f)
		{
			object::Destory(this);
		}

	}
	void BaseSkill::Render(HDC hdc)
	{
		Vector2 pos = Camera::CaluatePos(skillPos);

		if (mTime < 0.02f)
		TransparentBlt(hdc, pos.x, pos.y, Skill_R->GetWidth() * 2 - 150, Skill_R->GetHeight() * 2, Skill_R->GetHdc(), 0, 0,
			Skill_R->GetWidth() - 150, Skill_R->GetHeight(), RGB(255, 0, 255));
		else if (mTime < 0.04f)
			TransparentBlt(hdc, pos.x, pos.y, Skill_R->GetWidth() * 2 - 120, Skill_R->GetHeight() * 2, Skill_R->GetHdc(), 0, 0,
				Skill_R->GetWidth() - 120, Skill_R->GetHeight(), RGB(255, 0, 255));
		else if (mTime < 0.06f)
			TransparentBlt(hdc, pos.x, pos.y, Skill_R->GetWidth() * 2 - 90, Skill_R->GetHeight() * 2, Skill_R->GetHdc(), 0, 0,
				Skill_R->GetWidth() - 90, Skill_R->GetHeight(), RGB(255, 0, 255));
		else if (mTime < 0.08f)
			TransparentBlt(hdc, pos.x, pos.y, Skill_R->GetWidth() * 2 - 60, Skill_R->GetHeight() * 2, Skill_R->GetHdc(), 0, 0,
				Skill_R->GetWidth() - 60, Skill_R->GetHeight(), RGB(255, 0, 255));
		else if (mTime < 0.1f)
			TransparentBlt(hdc, pos.x, pos.y, Skill_R->GetWidth() * 2 - 30, Skill_R->GetHeight() * 2, Skill_R->GetHdc(), 0, 0,
				Skill_R->GetWidth() - 30, Skill_R->GetHeight(), RGB(255, 0, 255));
		else
			TransparentBlt(hdc, pos.x, pos.y, Skill_R->GetWidth() * 2, Skill_R->GetHeight() * 2, Skill_R->GetHdc(), 0, 0,
				Skill_R->GetWidth() , Skill_R->GetHeight(), RGB(255, 0, 255));

		if (SkillColl)
		{
			Vector2 pos = Camera::CaluatePos(EnemyPos);
			effect_Time += Time::getDeltaTime() * 0.3f;
			TransparentBlt(hdc, pos.x , pos.y, D_effect->GetWidth() * 2.5, D_effect->GetHeight() * 2.5, D_effect->GetHdc(), 0, 0,
				D_effect->GetWidth(), D_effect->GetHeight(), RGB(255, 0, 255));

			if (effect_Time >= 0.1f)
			{
				SkillColl = false;
				effect_Time = 0.0f;
			}
		}

		GameObject::Render(hdc);
	}
	void BaseSkill::Release()
	{

	}
	void BaseSkill::onCollisionEnter(Collider* other)
	{
		SkillColl = true;
		EnemyPos = other->getPos();
	}

	void BaseSkill::onCollisionStay(Collider* other)
	{
		SkillColl = true;
	}

	void BaseSkill::onCollisionExit(Collider* other)
	{
		//BulletColl = false;
	}
}
