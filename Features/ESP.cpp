#include "ESP.h"

ESP::ESP()
{
    this->m_enabled     = false;
    this->m_distance    = 10000.f;
    this->m_min         = 1000.f;
    this->m_max         = 100000.f;
}

ESP::~ESP()
{
    this->m_enabled     = false;
    this->m_distance    = 0.f;
    this->m_min         = 0.f;
    this->m_max         = 0.f;
}

void ESP::Enable()
{
	this->m_enabled = true;
}

void ESP::Disable()
{
	this->m_enabled = false;
}

void ESP::IsEnable()
{
	this->m_enabled;
}
