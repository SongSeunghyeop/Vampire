#include "myResourceManager.h"
#include "Level_bar.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"
#include "myPlayScene.h"

namespace my
{
	float PlayScene::player_health;

	Level_bar::Level_bar()
	{

	}
	Level_bar::~Level_bar()
	{

	}
	void Level_bar::Initialize()
	{
		level_bar = ResourceManager::Load<Image>(L"levelBar", L"..\\Resources\\InGameBar_.bmp");
		Charactor = ResourceManager::Load<Image>(L"charactor", L"..\\Resources\\Arca.bmp");
		health = ResourceManager::Load<Image>(L"health", L"..\\Resources\\health.bmp");
		health_zero = ResourceManager::Load<Image>(L"health_z", L"..\\Resources\\health_zero.bmp");
	
		GameObject::Initialize();
	}
	void Level_bar::Update()
	{
		GameObject::Update();
	}
	void Level_bar::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		TransparentBlt(hdc, 152, 5, level_bar->GetWidth(), level_bar->GetHeight(),
			level_bar->GetHdc(), 0, 0, level_bar->GetWidth(), level_bar->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 15, 5, Charactor->GetWidth(), Charactor->GetHeight(),
			Charactor->GetHdc(), 0, 0, Charactor->GetWidth(), Charactor->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 22, 120, health_zero->GetWidth(), health_zero->GetHeight(),
			health_zero->GetHdc(), 0, 0, health_zero->GetWidth(), health_zero->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 22, 120, PlayScene::player_health, health->GetHeight(),
			health->GetHdc(),0, 0, health->GetWidth(), health->GetHeight(), RGB(255, 0, 255));

	}
	void Level_bar::Release()
	{
		GameObject::Release();
	}
}