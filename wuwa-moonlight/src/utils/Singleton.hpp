#pragma once

class Singleton
{
public:
    static Singleton* instance() {
        static Singleton inst;
        return &inst;
    }
private:
    Singleton() {}
    ~Singleton() {}

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};