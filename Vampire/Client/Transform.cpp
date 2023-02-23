#include "Transform.h"


namespace my
{
	Transform::Transform()
		:myComponent(ComponentType::TRANSFORM)
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
	void Transform::setPos(float x, float y)
	{
		this->mPos.x = x;
		this->mPos.y = y;
	}
	void Transform::setSize(float x, float y)
	{
		this->mPos.x = x;
		this->mPos.y = y;
	}
	Vector2 Transform::getPos()
	{
		return mPos;
	}
	Vector2 Transform::getSize()
	{
		return mSize;
	}
}