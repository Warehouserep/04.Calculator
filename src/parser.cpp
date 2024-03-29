//��������������_�������������_�����_(.hpp - ����������_�����������_���_c++)
#include "parser.hpp"
#include "number.hpp"

#include "Mul.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Div.hpp"

using Token = Lexer::Token;
ASTNode *Parser::parse() { return expr(); }
void Parser::next_token() { tok_ = lexer_.next_token(); }

ASTNode *Parser::expr() {
    ASTNode *root = term();
    for (;;) {
        // �����������_�����_�_case-�������_(��������_tok_�����_����_�������������)
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                root = new Add(root, term());             
                break;
            case '-':
                root = new Sub(root, term());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::term() {
    ASTNode *root = prim();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '*':
                root = new Mul(root, prim());
                break;
            case '/':
                root = new Div(root, prim());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::prim() {
    ASTNode *node = nullptr;
    next_token();
    switch (tok_) {
    case Token::Number:
        node = new Number(lexer_.get_number());
        break;
    //case Token::Name:
    //    node = new Variable(lexer_.get_name());
    //    break;
    default:
        break;
    }
    next_token();
    return node;
}