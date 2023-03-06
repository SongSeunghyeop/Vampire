#pragma once
#include "VampireEngine.h"

namespace my 
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void setName(const std::wstring& name) { mName = name; }
		std::wstring& getName() { return mName; }
	private:
		std::wstring mName;
	};
}
