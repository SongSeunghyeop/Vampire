#include "myCamera.h"
#include "myApplication.h"
#include "myGameObject.h"
#include "myTransform.h"
#include "myInput.h"
#include "Time.h"

extern my::Application myapplication;

namespace my
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initiailize()
	{
		mResolution.x = myapplication.GetWidth();
		mResolution.y = myapplication.GetHeight();
		mLookPosition = (mResolution / 2.0f);
	}

	void Camera::Update()
	{
		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->getPos();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}
