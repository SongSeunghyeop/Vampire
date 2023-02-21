#include "MyGameObject.h"

void ya::MyGameObject::Initialize()
{
	for (myComponent* mcomp : mComponents)
	{
		if (mcomp == NULL) continue;

		mcomp->Initialize();
	}
}

void ya::MyGameObject::Update()
{
	for (myComponent* mcomp : mComponents)
	{
		if (mcomp == NULL) continue;

		mcomp->Update();
	}
}

void ya::MyGameObject::Render(HDC hdc)
{
	for (myComponent* mcomp : mComponents)
	{
		if (mcomp == NULL) continue;

		mcomp->Render(hdc);
	}
}

void ya::MyGameObject::Release()
{
	for (myComponent* mcomp : mComponents)
	{
		if (mcomp == NULL) continue;

		mcomp->Release ();
	}
}

ya::MyGameObject::MyGameObject()
{

}

ya::MyGameObject::~MyGameObject()
{

}
