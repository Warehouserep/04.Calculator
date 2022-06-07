//импортирование_заголовочного_файла_(.hpp - расширение_характерное_для_c++)
#include "parser.hpp"
#include "number.hpp"

//
using Token = Lexer::Token;
//
ASTNode *Parser::parse() { return expr(); }
//
void Parser::next_token() { tok_ = lexer_.next_token(); }
//
ASTNode *Parser::expr() {
    // parse addition and subsctruction
    ASTNode *root = term();
    //создание_цикла_перебора_case'ов
    for (;;) {
        //подключение_свича_с_case-метками_(значение_tok_дожно_быть_целочисленным)
        switch (tok_) {
        //определение_первой_метки_в_качестве_класса_с_перечислением
        case Token::Operator: {
            //в_качестве_работы_метки_возвращает_строковую_переменную
            //принимающую_значение_
            std::string op = lexer_.get_operator();
            //
            switch (op.front()) {
            //
            case '+':
                // Implement Add class and uncomment this line
                // root = new Add(root, term());
                return nullptr;
                //
                break;
            //
            case '-':
                // Implement Sub class and uncomment this line
                //root = new Sub(root, term());
                return nullptr;
                //
                break;
            //
            default:
                //
                return root;
            }
            //
            break;
        }
        //
        default:
            //
            return root;
        }
    }
}
//
ASTNode *Parser::term() {
    // parse multiplication and division
    ASTNode *root = prim();
    //
    for (;;) {
        //
        switch (tok_) {
        //
        case Token::Operator: {
            //
            std::string op = lexer_.get_operator();
            //
            switch (op.front()) {
            //
            case '*':
                // Implement Mul class and uncomment this line
                // root = new Mul(root, prim());
                return nullptr;
                //
                break;
            //
            case '/':
                // Implement Div class and uncomment this line
                //root = new Div(root, prim());
                return nullptr;
                //
                break;
            //
            default:
                //
                return root;
            }
            //
            break;
        }
        //
        default:
            //
            return root;
        }
    }
}
//
ASTNode *Parser::prim() {
    // parse numbers and names
    ASTNode *node = nullptr;
    //
    next_token();
    //
    switch (tok_) {
    //
    case Token::Number:
        //
        node = new Number(lexer_.get_number());
        //
        break;
    //
    case Token::Name:
        // Implement Variable class and uncomment this line
        // node = new Variable(lexer_.get_name());
        return nullptr;
        //
        break;
    //
    default:
        //
        break;
    }
    //
    next_token();
    //
    return node;
}