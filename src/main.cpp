// OTUS C++ Basic course homework skeleton.
// Lexer using example
//��������������_����������
#include <iostream>
//��������������_������������_������
#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

//�������_�������
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

    //�������_��������_���������
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

    //�������_���������_�_�������
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
    // �����������_����������
    Lexer lexer(std::cin);
    // ��������������_����������
    Parser parser(lexer);
    ASTNode *ast = parser.parse();
    //������_����������
    if (ast) {
         ast->print(std::cout);
    }
    return 0;
}
