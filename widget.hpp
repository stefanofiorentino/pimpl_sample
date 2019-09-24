#pragma once
#include <memory>

// https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Ri-pimpl

class widget {
    class impl;
    std::unique_ptr<impl> pimpl;
public:
    void draw(); // public API that will be forwarded to the implementation
    explicit widget(int); // defined in the implementation file
    ~widget();   // defined in the implementation file, where impl is a complete type
    widget(widget&&) = default;
    widget(const widget&) = delete;
    widget& operator=(widget&&) noexcept; // defined in the implementation file
    widget& operator=(const widget&) = delete;
};
