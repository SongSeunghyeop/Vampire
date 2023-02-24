#include "CharactorSelect.h"
#include "myResourceManager.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	CharactorSelect::CharactorSelect()
	{

	}
	CharactorSelect::~CharactorSelect()
	{

	}
	void CharactorSelect::Initialize()
	{
		SelectUI = ResourceManager::Load<Image>(L"SelectUI", L"..\\Resources\\SelectUI.bmp");

		GameObject::Initialize();
	}
	void CharactorSelect::Update()
	{
		GameObject::Update();

	}
	void CharactorSelect::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		//1500//750
		StretchBlt(hdc, 400, 100, 700, 550, SelectUI->GetHdc(), 0, 0, SelectUI->GetWidth(), SelectUI->GetHeight(), SRCCOPY);
	}
	void CharactorSelect::Release()
	{
		GameObject::Release();
	}
}