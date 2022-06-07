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

    //функция_сложения_вычитания
    double expr(){
        for (;;) {
            switch (curr_tok) {
                case: PLUS:
                    //get_token();
                    left += term();
                    break;
                case: MINUS:
                    //get_token();
                    left -= term();
                    break;
                default:
                    return left;
            }
        }
    }

    //функция_умножения_и_деления
    double term() {
        for (;;) {
            switch (curr_tok)
            {
                case: MUL:
                    //get_token();
                    left *= prim();
                    break;
                case: DIV:
                    //get_token();
                    double d = prim();
                    if (d == 0) return error("Divide by zero");
                    left /= d;
                    break;
                default: 
                    return left;
            }
        }
    }

    
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
