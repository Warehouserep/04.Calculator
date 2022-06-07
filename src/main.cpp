// OTUS C++ Basic course homework skeleton.
// Lexer using example
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
        NUMBER
    };
    token_value curr_tok;


  
    Lexer lexer(std::cin);
    Parser parser(lexer);
    ASTNode *ast = parser.parse();
    if (ast) {
         ast->print(std::cout);
    }
    return 0;
}
