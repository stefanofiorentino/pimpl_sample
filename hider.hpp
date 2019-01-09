#pragma once
#include <memory>

class hider
{
public:
    hider();
    ~hider();
    void solution();
private:
    struct hidden;
    std::unique_ptr<hidden> pHidden;
};
