#pragma once
// Source - https://github.com/tanduRE/VMTHook/blob/master/vmthook.h
/*
 *
 *
	MIT License

	Copyright (c) 2018 tanduRE

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
 *
 *
 */


#include <cstdint>
#include <memory>

class CVMTHook
{
private:
	uintptr_t* m_table = nullptr;
	uintptr_t* m_table_org = nullptr;
	uintptr_t** m_interface = nullptr;
	uint32_t m_vm_count = 0;

public:

	CVMTHook(void* instance)
	{
		m_interface = reinterpret_cast<uintptr_t**>(instance);
		m_table_org = *m_interface;

		for (;; m_vm_count++)
		{
			if (!reinterpret_cast<uintptr_t*>(*m_interface)[m_vm_count])
				break;
		}

		auto _size = m_vm_count * sizeof(uintptr_t);

		m_table = new uintptr_t[_size];

		std::memcpy(m_table, m_table_org, _size);

		*m_interface = m_table;
	}

	uintptr_t HookMethod(void* handler, uint32_t index)
	{
		uintptr_t original = m_table[index];
		m_table[index] = reinterpret_cast<uintptr_t>(handler);
		return original;
	}

	void RestoreTable()
	{
		*m_interface = m_table_org;
	}

};