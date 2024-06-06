#pragma once
#include <iostream>

namespace Utilities
{
	namespace DummyFunctions {

		template <typename T>
		T Read(uintptr_t dummy)
		{
			T buffer;
			return buffer;
		}

	}

	template <typename T>
	bool IsAddrValid(T Address)
	{
		return !(Address == 0);
	}
}