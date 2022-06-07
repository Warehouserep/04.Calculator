//импортирование_заголовочного_файла_astnode
#include "astnode.hpp"

//оределение_класса_с_параметром_в_виде_константной_строковой_ссылки
ASTNode::ASTNode(const std::string &repr)
//определение_перегрузок
    : repr_(repr)
    , lhs_{nullptr}
    , rhs_{nullptr} {}

//определение_класса_с_парематрами_в_виде_константиной_ссылки_и_двумя_указателями
ASTNode::ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
//определение_перегрузок
    : repr_(repr)
    , lhs_{lhs}
    , rhs_{rhs} {}

//опрделение_деструкторов
ASTNode::~ASTNode() {
    //для_переменных_lhs_rhs
    delete lhs_;
    delete rhs_;
}
//печать_потока
void ASTNode::print(std::ostream &out) const { inner_print(out, 0); }

//передача_в_поток_рразмера_indent
void ASTNode::inner_print(std::ostream &out, size_t indent) const {
    //проверка_параметра_lhs_если_true_передача_в_поток
    if (lhs_) {
        lhs_->inner_print(out, indent + 1);
    }
    for (size_t i = 0; i < indent; ++i) {
        out << "    ";
    }
    out << repr_ << '\n';
    //проверка_параметра_rhs_если_true_передача_в_поток
    if (rhs_) {
        rhs_->inner_print(out, indent + 1);
    }
}
