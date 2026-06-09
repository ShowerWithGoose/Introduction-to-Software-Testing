/*
 * @brief: CLexicalAnalyzer is defined here.
 * @birth: Created on 2024/9/26.
 * @revision: last revised on 2024/9/26.
 */

#ifndef COMPILER_CLEXICALANALYZER_H
#define COMPILER_CLEXICALANALYZER_H

#include <map>
#include <string>
#include "../InputBuffer/CInputBuffer.h"
#include "../Exceptions/LexicalError.h"

using std::string;

// OVERVIEW: This enum distinct tokens.
enum _TOKEN_TYPE {
    IDENFR, INTCON, STRCON, CHRCON, MAINTK,
    CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK,
    IFTK, ELSETK, NOT, AND, OR,
    FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK,
    PLUS, MINU, VOIDTK, MULT, DIV,
    MOD, LSS, LEQ, GRE, GEQ,
    EQL, NEQ, ASSIGN, SEMICN, COMMA,
    LPARENT, RPARENT, LBRACK, RBRACK, LBRACE,
    RBRACE
};

// OVERVIEW: Read char from CInputBuffer, and form chars into token.
class CLexicalAnalyzer {
private:
    // Members
    CInputBuffer* m_InputBuffer = nullptr;
    int m_nLineCount = 1;
    int m_nColumnCount = 1;
    int m_nTokenType{};

    // Private Methods
    char NextChar(bool transEscape);
    char CurrentChar() {
        return m_InputBuffer->GetChar();
    }
    string* dealNonterminal(char ch);

public:
    // Constructor
    CLexicalAnalyzer() {
        try {
            this->m_InputBuffer = new CInputBuffer();
        } catch (std::invalid_argument& e) {
            throw e;
        }
    };

    explicit CLexicalAnalyzer(char const* name) {
        try {
            this->m_InputBuffer = new CInputBuffer(name);
        } catch (std::invalid_argument& e) {
            throw e;
        }
    }

    // Method
    void* NextToken();
    int GetTokenType() {
        return this->m_nTokenType;
    }

    // Destructor
    ~CLexicalAnalyzer() {
        delete this->m_InputBuffer;
    }
};


#endif //COMPILER_CLEXICALANALYZER_H
