#include "PE_Hook.hpp"
#include "SDK/Basic.hpp"

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

/**
 * Finds the index of the ProcessEvent function in the vtable.
 *
 * @return The index of the ProcessEvent function in the vtable, or -1 if not found.
 */
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

		if (function == (module_base + SDK::Offsets::ProcessEvent))
		{
			return index;
		}
	}

	return -1;
}

/**
 * Apply a hook to a class function pointer.
 *
 * @param pClass memory address of the class
 * @param pOrgFunc original function pointer
 * @param pFunc new function pointer to be applied
 */
void ProcessEventHook::ApplyHook(std::uintptr_t pClass, std::uintptr_t pOrgFunc, std::uintptr_t pFunc)
{
	if (this->m_eventindex == -1 || this->m_vtablesize == -1)
	{
		std::cout << "Invalid event index or vtable size. Skipping hook application." << std::endl;
		return;
	}

	if (pClass != m_class)
	{
		this->m_vtable = *reinterpret_cast<std::uintptr_t**>(pClass);

		if (!ValidPtr((void*)m_vtable))
		{
			std::cout << "Invalid vtable pointer. Skipping hook application." << std::endl;
			return;
		}

		this->m_vtable_cache = reinterpret_cast<decltype(m_vtable_cache)>(malloc(m_vtablesize));

		if (!m_vtable_cache)
		{
			std::cout << "Failed to allocate memory for vtable cache. Skipping hook application." << std::endl;
			return;
		}

		memcpy(m_vtable_cache, m_vtable, m_vtablesize);

		pOrgFunc = m_vtable_cache[this->m_eventindex]; // or just (module_base + ProcessEventOffset)

		m_vtable_cache[this->m_eventindex] = pFunc;

		*reinterpret_cast<std::uintptr_t**>(pClass) = m_vtable_cache;

		this->m_class = pClass;
	}
}

bool ProcessEventHook::IsHooked() const {
	return m_class != 0;
}