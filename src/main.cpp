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
