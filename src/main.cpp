// OTUS C++ Basic course homework skeleton.
// Lexer using example
//импортирование_библиотеки
#include <iostream>
//импортирование_заголовочных_файлов
#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

//главная_функция
int main() {
    // TODO
    // Implement the next classes:
    enum token_value {
        //Add
        PLUS = '+',
        //Sub
        MINUS = '-',
        //Mul
        MUL = '*',
        //Div
        Div = '/'
    };
    token_value curr_tok;
    
    // Without implementation that classes this application works only with numbers
    // лексический_анализатор
    Lexer lexer(std::cin);
    // синтаксический_анализатор
    Parser parser(lexer);
    ASTNode *ast = parser.parse();
    //печать_результата
    if (ast) {
         ast->print(std::cout);
    }
    return 0;
}
