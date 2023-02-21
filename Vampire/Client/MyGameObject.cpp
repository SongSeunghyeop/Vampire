#include "MyGameObject.h"

namespace ya
{
	void MyGameObject::Initialize()
	{
		for (myComponent* mcomp : mComponents)
		{
			if (mcomp == NULL) continue;

			mcomp->Initialize();
		}
	}
	void MyGameObject::Update()
	{
		for (myComponent* mcomp : mComponents)
		{
			if (mcomp == NULL) continue;

			mcomp->Update();
		}
	}
	void MyGameObject::Render(HDC hdc)
	{
		for (myComponent* mcomp : mComponents)
		{
			if (mcomp == NULL) continue;

			mcomp->Render(hdc);
		}
	}
	void MyGameObject::Release()
	{
		for (myComponent* mcomp : mComponents)
		{
			if (mcomp == NULL) continue;

			mcomp->Release ();
		}
	}
	MyGameObject::MyGameObject()
	{

	}
	MyGameObject::~MyGameObject()
	{

	}
	void MyGameObject::setPos(float x, float y)
	{
		this->mPos.x = x;
		this->mPos.y = y;
	}
}
