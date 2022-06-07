#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
public:
    Div(int val) : ASTNode(std::to_string(val)), val_(val) {}
    int value() { 
        val_ /= val_;
        return val_; }

private:
    int val_;
};
