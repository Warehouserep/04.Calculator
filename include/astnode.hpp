// OTUS C++ basic course homework.
// ASTNode

#pragma once
//��������������_���������
#include <cctype>
#include <iostream>
#include <string>

//���������_������_ASTNode
class ASTNode {
  public:
    //�����������_�����_(����_���_��������_�����)
    explicit ASTNode(const std::string &repr);
    //�����������_����_(�_�����_���_�����_���������_������)
    ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
    //
    ASTNode(const ASTNode &other) = delete;
    //
    ASTNode &operator=(const ASTNode &other) = delete;
    //����������
    ~ASTNode();
    //�������������_�����_����_�_����_������
    std::string repr() const { return repr_; }
    //������_�����_������_�_���������_����
    void print(std::ostream &out) const;

  private:
    void inner_print(std::ostream &out, size_t indent) const;

    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;
};
