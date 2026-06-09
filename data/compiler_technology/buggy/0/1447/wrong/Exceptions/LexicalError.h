/*
 * @brief: LexicalError is defined here.
 * @birth: Created on 2024/9/26.
 * @revision: last revised on 2024/9/26.
 */

#ifndef COMPILER_LEXICALERROR_H
#define COMPILER_LEXICALERROR_H

#include <exception>

// OVERVIEW: When the CLexicalAnalyzer detects a error 'a',
//    this exception will be thrown out.
class LexicalError : public std::exception {
private:
    int m_nLine;
    int m_nColumn;
    std::string* m_strLexme;

public:
    LexicalError(int line, int column, std::string* lexme) {
        this->m_nLine = line;
        this->m_nColumn = column;
        this->m_strLexme = lexme;
    }

    int GetLine() {
        return m_nLine;
    }

    int GetColumn() {
        return m_nColumn;
    }

    std::string* GetLexme() {
        return m_strLexme;
    }
};


#endif //COMPILER_LEXICALERROR_H
