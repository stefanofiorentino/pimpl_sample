#ifndef PIMPL_SAMPLE_IMPLEMENTATIONHIDINGCLASS_HPP
#define PIMPL_SAMPLE_IMPLEMENTATIONHIDINGCLASS_HPP

#include <memory>

class hider
{
public:
    hider();
    ~hider();
    void solution();

private:
    class hidden;
    std::unique_ptr<hidden> pHidden;
};

#endif //PIMPL_SAMPLE_IMPLEMENTATIONHIDINGCLASS_HPP
