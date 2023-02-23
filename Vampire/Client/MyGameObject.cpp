#include "MyGameObject.h"
#include "Transform.h"

namespace my
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
		mComponents.resize((UINT)ComponentType::END);
		AddComponent<Transform>();
	}
	MyGameObject::~MyGameObject()
	{

	}
}
