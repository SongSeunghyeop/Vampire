#include "myScene.h"

namespace my
{
	void Scene::Initialize()
	{
		for (Layer& layer : mLayer)
		{
			layer.Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer& layer : mLayer)
		{
			layer.Update();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayer)
		{
			layer.Render(hdc);
		}
	}

	void Scene::Release()
	{
		for (Layer& layer : mLayer)
		{
			layer.Release();
		}
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}

	void Scene::AddGameObj(GameObject* obj, eLayerType Layer)
	{
		mLayer[(UINT)Layer].AddGameObj(obj);
	}

	void Scene::DelGameObj(GameObject* obj, eLayerType Layer)
	{
		mLayer[(UINT)Layer].DelGameObj(obj);
	}

	Scene::Scene()
	{
		//mLayer.reserve(5);
		mLayer.resize((UINT)eLayerType::END);
	}

	Scene::~Scene()
	{

	}
}
