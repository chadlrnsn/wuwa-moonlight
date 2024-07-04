#include "PE_Hook.hpp"

using namespace Hook;

int VTable::GetVTableSize()
{
	if (!ValidPtr((void*)m_vtable))
		return NULL;

	auto count = 0;

	MEMORY_BASIC_INFORMATION mbi;

	while (VirtualQuery(reinterpret_cast<LPVOID>(this->m_vtable[count]), &mbi, sizeof(mbi)))
	{
#define PAGE_TEXT (PAGE_EXECUTE | PAGE_EXECUTE_READ)

		if ((mbi.Protect & PAGE_NOACCESS) || !(mbi.Protect & PAGE_TEXT) || (mbi.State != MEM_COMMIT))
			break;

		if (!ValidPtr(this->m_vtable[count]))
			break;

		count++;
	}

	return count;
}

void VTable::FreeVTableCache()
{
	if (this->m_vtable_cache)
		free(this->m_vtable_cache);
}

int ProcessEventHook::FindProcessEventIndex()
{
	if (!ValidPtr((void*)m_vtable) || this->m_vtablesize == -1)
		return NULL;

	static auto module_base = (std::uintptr_t)GetModuleHandleA(NULL);

	for (int index = 0; index <= this->m_vtablesize; index++)
	{
		auto function = *reinterpret_cast<std::uintptr_t*>(this->m_vtable + (index * 0x8));

		if (!ValidPtr((void*)function))
			continue;

		if (function == (module_base + ProcessEventOffset))
		{
			return index;
		}
	}

	return -1;
}

void ProcessEventHook::ApplyHook(std::uintptr_t pClass, std::uintptr_t pOrgFunc, std::uintptr_t pFunc)
{
	if (this->m_eventindex == -1 || this->m_vtablesize == -1)
		return;

	if (pClass != m_class)
	{
		this->m_vtable = *reinterpret_cast<std::uintptr_t**>(pClass);

		if (!ValidPtr((void*)m_vtable))
			return;

		this->m_vtable_cache = reinterpret_cast<decltype(m_vtable_cache)>(malloc(m_vtablesize));

		if (!m_vtable_cache)
			return;

		memcpy(m_vtable_cache, m_vtable, m_vtablesize);

		pOrgFunc = m_vtable_cache[this->m_eventindex]; // or just (module_base + ProcessEventOffset)

		m_vtable_cache[this->m_eventindex] = pFunc;

		*reinterpret_cast<std::uintptr_t**>(pClass) = m_vtable_cache;

		this->m_class = pClass;
	}
}
