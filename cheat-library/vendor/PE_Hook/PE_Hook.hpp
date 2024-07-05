#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdint>

namespace Hook
{
	template <typename T = void*>
	inline auto ValidPtr(T ptr) -> bool {
		return (ptr && ptr > (T)0xFFFFFF && ptr < (T)0x7FFFFFFFFFFF);
	}

	class VTable
	{
	public:
		//
		// Get VTable Size By Memory Validation
		//
		int GetVTableSize();

		//
		// Frees Our VTable Cache
		//
		void FreeVTableCache();

		std::uintptr_t m_class;
		std::uintptr_t* m_vtable;
		int m_vtablesize;
		std::uintptr_t* m_vtable_cache;
	};

	class ProcessEventHook : public VTable
	{
	public:
		//
		// Initialise Class' VTable Information
		//
		template <typename T = void*> explicit ProcessEventHook(const T pClass)
		{
			m_vtable = *(std::uintptr_t**)pClass;
			m_vtablesize = this->GetVTableSize();
			m_eventindex = this->FindProcessEventIndex();
		};

		//
		// Apply Shadow VMT Hook
		//
		void ApplyHook(std::uintptr_t pClass, std::uintptr_t pOrgFunc, std::uintptr_t pFunc);

		//
		// Find ProcessEvent Index By Bruteforcing
		//
		int FindProcessEventIndex();


		~ProcessEventHook()	{ this->FreeVTableCache(); } 
		
		bool IsHooked() const;
		int GetEventIndex() const { return m_eventindex; }

	private:
		int m_eventindex;
	};
}