#include "widget.hpp"

class widget::impl
{
    int n; // private data
public:
    void draw(const widget &w)
    {
        std::puts(std::to_string(n).c_str());
    }

    explicit impl(int n) :
            n(n)
    {
    }
};

void widget::draw()
{
    pimpl->draw(*this);
}

widget::widget(int n) :
        pimpl{std::make_unique<impl>(n)}
{
}

widget::~widget() = default;

widget &widget::operator=(widget &&) noexcept = default;