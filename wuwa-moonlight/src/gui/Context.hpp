#pragma once
#include <Singleton.hpp>
#include <includes.h>
#include <memory>

class Context : public Singleton {
private:
	static ImDrawList* m_drawbacklist;
public:
	static const ImDrawList GetBackgroundDrawList() {
		if (m_drawbacklist == nullptr)
		{
			m_drawbacklist = ImGui::GetBackgroundDrawList();
		}
	}
};