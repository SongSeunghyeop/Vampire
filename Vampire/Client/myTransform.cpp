#include "myTransform.h"

namespace my
{
	Transform::Transform()
		:Component(eComponentType::TRANSFORM)
		, mPos(Vector2::Zero)
		, mScale(Vector2::One)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
	void Transform::Release()
	{
	}
	void Transform::setPos(Vector2 pos)
	{
		mPos = pos;
	}
	void Transform::setScale(Vector2 scale)
	{
		this->mScale.x = scale.x;
		this->mScale.y = scale.y;
	}
	Vector2 Transform::getPos()
	{
		return mPos;
	}
	Vector2 Transform::getScale()
	{
		return mScale;
	}
}