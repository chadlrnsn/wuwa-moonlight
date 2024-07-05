#pragma once
// Source - https://github.com/tanduRE/VMTHook/blob/master/vmthook.h

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