//��������������_�������������_�����_astnode
#include "astnode.hpp"

//����������_������_�_����������_�_����_�����������_���������_������
ASTNode::ASTNode(const std::string &repr)
//�����������_����������
    : repr_(repr)
    , lhs_{nullptr}
    , rhs_{nullptr} {}

//�����������_������_�_�����������_�_����_������������_������_�_�����_�����������
ASTNode::ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
//�����������_����������
    : repr_(repr)
    , lhs_{lhs}
    , rhs_{rhs} {}

//����������_������������
ASTNode::~ASTNode() {
    //���_����������_lhs_rhs
    delete lhs_;
    delete rhs_;
}
//������_������
void ASTNode::print(std::ostream &out) const { inner_print(out, 0); }

//��������_�_�����_��������_indent
void ASTNode::inner_print(std::ostream &out, size_t indent) const {
    //��������_���������_lhs_����_true_��������_�_�����
    if (lhs_) {
        lhs_->inner_print(out, indent + 1);
    }
    for (size_t i = 0; i < indent; ++i) {
        out << "    ";
    }
    out << repr_ << '\n';
    //��������_���������_rhs_����_true_��������_�_�����
    if (rhs_) {
        rhs_->inner_print(out, indent + 1);
    }
}
