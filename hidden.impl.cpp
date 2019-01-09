#include "hider.hpp"

class hider::hidden
{
public:
    void custom_solution()
    {
        std::puts(__PRETTY_FUNCTION__);
    }
};

hider::hider() :
        pHidden{new hidden{}}
{}

hider::~hider() = default;

void hider::solution()
{
    pHidden->custom_solution();
}
