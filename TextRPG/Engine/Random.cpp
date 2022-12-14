#include <random>

#include "Random.h"

namespace Random
{
    namespace
    {
        std::random_device Device;
        std::mt19937_64    Engine(Device());
    }

    int GetInt(int const min, int const max)
    {
        return std::uniform_int_distribution<int>(min, max)(Engine);
    }

    float GetFloat(float const min, float const max)
    {
        return std::uniform_real_distribution<float>(min, max)(Engine);
    }
}