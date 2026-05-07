#pragma once
#include<memory>
#include<string>

// PIMPL (Pointer to Implementation) idiom
// Used to hide implementation details and reduce compilation dependencies
class Widget{
    public:
        Widget();
        ~Widget();

        // Rule of 5 (explicit intent)
        Widget(const Widget&) = delete;
        Widget& operator=(const Widget&) = delete;

        // This function will never throw an exception
        Widget(Widget&&) noexcept;
        Widget& operator=(Widget&&) noexcept;

        void setName(const std::string& name);
        void printname() const;
    private:
        struct Impl;                // Forward declaration
        std::unique_ptr<Impl>pImpl;     // Pimpl pointer
};