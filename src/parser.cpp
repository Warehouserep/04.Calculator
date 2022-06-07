//импортирование_заголовочного_файла_(.hpp - расширение_характерное_для_c++)
#include "parser.hpp"
#include "number.hpp"

using Token = Lexer::Token;
ASTNode *Parser::parse() { return expr(); }
void Parser::next_token() { tok_ = lexer_.next_token(); }

ASTNode *Parser::expr() {
    ASTNode *root = term();
    for (;;) {
        // подключение_свича_с_case-метками_(значение_tok_дожно_быть_целочисленным)
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                class Add:public ASTNode {
                    //left += term();
                    //root = new Add(root, term());
                };                
                return nullptr;
                break;
            case '-':
                class Sub:public ASTNode {
                    // left -= term();
                    // root = new Sub(root, term());
                };
                return nullptr;
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
                class Mul : public ASTNode {
                    // left *= prim();
                    // root = new Mul(root, prim());
                };
                return nullptr;
                break;
            case '/':
                class Div : public ASTNode {
                    // double d = prim();
                    // if (d == 0) return error("Divide by zero");
                    // left /= d;
                    // root = new Div(root, prim());
                };
                return nullptr;
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
    case Token::Name:
        class Variable : public ASTNode {
            // node = new Variable(lexer_.get_name());
        };
        return nullptr;
        break;
    default:
        break;
    }
    next_token();
    return node;
}