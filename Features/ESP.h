#pragma once
class ESP
{
private:
    bool    m_enabled;
    float   m_distance;
    float   m_min;
    float   m_max;

    enum Targets {
        chests,
        animals,
        enemies,
        players,
    };

public:

    ESP();
    ~ESP();
    void Enable();
    void Disable();
    void IsEnable();

};

