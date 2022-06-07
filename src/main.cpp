#include <iostream>
#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

int main() {
    enum token_value {
        PLUS = '+',
        MINUS = '-',
        MUL = '*',
        DIV = '/',
    };
    token_value curr_tok;
       
    double expr(const std::string &curr_tok) {
        for (;;)
            switch (curr_tok) {
            case PLUS:
                left += term();
                break;
            case MINUS:
                left -= term();
                break;
            default:
                return left;
            }
    }

    double term(const std::string &curr_tok) {
        for (;;)
            switch (curr_tok) {
            case MUL:
                left *= prim();
                break;
            case DIV:
                double d = prim();
                if (d == 0) return error("Divede by zero");
                left /= d;
                break;
            default:
                return left;
            }
    };
  
    Lexer lexer(std::cin);
    Parser parser(lexer);
    ASTNode *ast = parser.parse();
    if (ast) {
         ast->print(std::cout);
    }
    return 0;
}
