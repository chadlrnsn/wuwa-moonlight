#pragma once

// implemented but not ended
enum class Features
{
    Player,
    ESP,
    Misc,
    Config,
    Debug
};

namespace Settings
{
	bool Watermark = true;

    namespace Player
    {
        bool god = false;
        
        namespace Rapidfire
        {
            bool enabled = false;
            int hits = 10;
            int hitsmin = 1;
            int hitsmax = 1000;
        }

        namespace Speed
        {
            bool enabled = false;
            float speed = 10;
            float max = 10;
            float min = 0;
        }

        namespace Fly
        {
            bool enabled = false;
            float speed = 10;
            float multiplier = 2;
            float altspeed = 40;
            float altmultiplier = 2;
            enum Type {
                FreeFlight,
                Planner,
                StopedAnim,
            };
        }
    }

    namespace ESP
    {
        bool enabled = false;
        float range = 1000;
        float min = 1000;
        float max = 100000;

        enum Targets {
            chests,
            animals,
            enemies,
            players,
        };
    }

    namespace Misc
    {

    }

    namespace Config
    {

    }

    namespace Debug
    {

    }
}