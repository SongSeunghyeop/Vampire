#include "myComponent.h"
#include "myAnimation.h"
#include "myImage.h"

namespace my
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
				{
					mEvent();
				}
			}
			std::function<void()> mEvent;
		};

		struct EventFunc
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

		Animator();
		~Animator();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void CreateAnimation(); // �ϳ��� ������ ��� �ִϸ��̼�
		void CreateAnimations(); // �ִϸ��̼��� ���� ���Ϸ� ����������

		Animation* FindAnimtion(const std::wstring& name);
		void Play(const std::wstring& name, bool loop);

		EventFunc* FindEvent(const std::wstring& name);

		std::function<void>& GetStartEvent(const std::wstring& name);
		std::function<void>& GetCompleteEvent(const std::wstring& name);
		std::function<void>& GetEndEvent(const std::wstring& name);

	private:
		std::map<std::wstring, Animation*> mAnimations;
		std::map<std::wstring, EventFunc*> mEvents;

		Animation activeAnimation;
		Image* mSpritesheet;
	};
}
