// OTUS C++ Basic course homework skeleton.
// Lexer using example
//импортирование_библиотек
#include <iostream>
//импортирование_
#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

//главная_функция
int main() {
    // TODO
    // Implement the next classes:
    // Add
    // Sub
    // Mul
    // Div
    // Variable

    // Without implementation that classes this application works only with numbers
    //
    Lexer lexer(std::cin);
    //
    Parser parser(lexer);
    //
    ASTNode *ast = parser.parse();
    //
    if (ast) {
        //
         ast->print(std::cout);
    }
    //
    return 0;
}
