// OTUS C++ basic course homework.
// ASTNode

#pragma once
//импортирование_библиотек
#include <cctype>
#include <iostream>
#include <string>

//интерфейс_класса_ASTNode
class ASTNode {
  public:
    //конструктор_листа_(узел_без_дочерних_узлов)
    explicit ASTNode(const std::string &repr);
    //конструктор_узла_(с_одним_или_двумя_дочерними_узлами)
    ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
    //
    ASTNode(const ASTNode &other) = delete;
    //
    ASTNode &operator=(const ASTNode &other) = delete;
    //деструктор
    ~ASTNode();
    //представление_имени_узла_в_виде_строки
    std::string repr() const { return repr_; }
    //печать_всего_дерева_в_текстовом_виде
    void print(std::ostream &out) const;

  private:
    void inner_print(std::ostream &out, size_t indent) const;

    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;
};
