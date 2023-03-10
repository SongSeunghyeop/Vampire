#include "myAnimator.h"
#include "myGameObject.h"
#include "myResourceManager.h"

namespace my
{
	Animator::Animator()
		: Component(eComponentType::ANIMATOR)
		, activeAnimation(nullptr)
		, mSpriteSheet(nullptr)
		, mbLoop(false)
	{

	}
	Animator::~Animator()
	{
		for (auto animation : mAnimations)
		{
			delete animation.second;
			animation.second = nullptr;
		}
	}

	void Animator::Initialize()
	{

	}
	void Animator::Update()
	{
		if (activeAnimation)
		{
			activeAnimation->Update();

			if (mbLoop && activeAnimation->IsComplete())
			{
				activeAnimation->Reset();
			}
		}
	}
	void Animator::Render(HDC hdc)
	{
		if (activeAnimation)
		{
			activeAnimation->Render(hdc);
		}
	}
	void Animator::Release()
	{

	}
	void Animator::CreateAnimation(const std::wstring& name
		, Image* sheet, Vector2 leftTop
		, UINT coulmn, UINT row, UINT spriteLength
		, float duration, int r, int g, int b)
	{
		Animation* animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->Create(sheet, leftTop, coulmn, row, spriteLength, duration, r, g, b);
		animation->setName(name);
		animation->setAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}

	void Animator::CreateAnimations(const std::wstring& path, float duration)
	{
		UINT width = 0;
		UINT height = 0;
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<Image*> images = {};
		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = path + L"\\" + fileName;

			const std::wstring ext = p.path().extension();
			if (ext == L".png")
				continue;

			Image* image = ResourceManager::Load<Image>(fileName, fullName);
			images.push_back(image);

			if (width < image->GetWidth())
			{
				width = image->GetWidth();
			}
			if (height < image->GetHeight())
			{
				height = image->GetHeight();
			}
			fileCount++;
		}

		std::wstring key = fs.parent_path().filename();
		key += fs.filename();
		mSpriteSheet = Image::Create(key, width * fileCount, height);

	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator it = mAnimations.find(name);

		if (it == mAnimations.end())
			return nullptr;

		return it->second;
	}
	void Animator::Play(const std::wstring& name, bool loop)
	{
		activeAnimation = FindAnimation(name);
		mbLoop = loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		return nullptr;
	}
}