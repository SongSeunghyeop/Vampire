#include "myCollider.h"
#include "myTransform.h"
#include "myGameObject.h"

namespace my
{
	Collider::Collider()
		: Component(eComponentType::COLLIDER)
		, mCenter(Vector2::Zero)
		, mPos(Vector2::Zero)
		, mSize(50.0f, 60.0f)
		,mRgb(0,255,0)
	{

	}

	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
		Transform* tr = getOwner()->GetComponent<Transform>();
		mPos = tr->getPos() + mCenter;
	}

	void Collider::Render(HDC hdc)
	{
		HPEN pen = CreatePen(BS_SOLID, 2, RGB(mRgb.r, mRgb.g, mRgb.b));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y);

		(HPEN)SelectObject(hdc, oldPen);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(pen);
	}
	void Collider::Release()
	{

	}

}
