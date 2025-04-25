#pragma once
#include <iostream>
#include <memory>

class Singleton {
private:
    static Singleton* m_instance;

protected:
    Singleton() = default;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& Get() {
        
        if (m_instance == nullptr)
        {
            m_instance = new Singleton;
        }

        return *m_instance;
    }

};