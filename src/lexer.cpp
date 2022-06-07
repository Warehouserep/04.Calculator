// OTUS C++ Basic course homework skeleton.
// Lexer implementation
//��������������_�������������_�����_lexer(����������_hpp_���_c++)
#include "lexer.hpp"
//��������������_����������_��type
#include <cctype>
//
Lexer::Token Lexer::next_token() {
    //��������_�����
    for (;;) {
        //�����������_�����(state_ - ������_���������_�������������_��������)
        switch (state_) {

        //������������_�����_���_��������_End_������_������������
        case State::End:
            //�������_��������_END.
            return Token::End;

        //�����������_�����_���_��������_RealNumber_������_������������
        case State::ReadNumber:
            //�������_����_end_true
            if (end()) {
                //���������_��������_state_��������_������_������������_End.
                state_ = State::End;
                //�������_�����
                return Token::Number;
            }
            //��������_��������_(ch_)_��_true_���_���_�����
            if (std::isdigit(ch_)) {
                //����������_��������_number_
                number_ = 10 * number_ + (ch_ - '0');
                //����������_��������_state
                state_ = State::ReadNumber;
                //�����_����������_�������
                next_char();
                //���������_������_���������_���������_����_��������_������_���
                break;
            }
            //����������_��������_���_state_
            state_ = State::Empty;
            //�������_�����
            return Token::Number;

        //���������_�����_ReadName
        case State::ReadName:
            //����_end_true
            if (end()) {
                //����������_��������_state::end
                state_ = State::End;
                //�_�������_���
                return Token::Name;
            }
            //����_�h(�����)_�_������_���������_�_�������_ASCII
            if (std::isalpha(ch_) || std::isdigit(ch_)) {
                //����������������_name_��_��������_ch
                name_ += ch_;
                //�_�������_���������_������
                next_char();
                //��������_����������_���������_���������
                break;
            }
            //����������_��������_state_��������_������_������������_Empty
            state_ = State::Empty;
            //����������_��������_Name
            return Token::Name;

        //
        case State::Empty:
            //
            if (end()) {
                //
                state_ = State::End;
                //
                return Token::End;
            }
            //
            if (std::isspace(ch_)) {
                //
                next_char();
                //
                break;
            }
            //
            if (isoperator(ch_)) {
                //
                operator_ = ch_;
                //
                next_char();
                //
                return Token::Operator;
            }
            //
            if (ch_ == '(') {
                //
                next_char();
                //
                return Token::Lbrace;
            }
            //
            if (ch_ == ')') {
                //
                next_char();
                //
                return Token::Rbrace;
            }
            //
            if (std::isdigit(ch_)) {
                //
                number_ = ch_ - '0';
                //
                state_ = State::ReadNumber;
                //
                next_char();
                //
                break;
            }
            //
            if (std::isalpha(ch_)) {
                //
                name_ = ch_;
                //
                state_ = State::ReadName;
                //
                next_char();
                //
                break;
            }
        }
    }
}
