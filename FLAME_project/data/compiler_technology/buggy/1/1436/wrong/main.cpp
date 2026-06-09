#include "components.h"
#include "consts.h"
#include "outputTools.h"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Lexer
{
public:
    struct ParseRes
    {
        bool canUse;
        bool canNext;
    };
    class Parser
    {
    public:
        virtual ParseRes parse(string buf, char next) = 0;
        virtual TokenEnum getKey() = 0;
    };
    class KeywordParser : public Parser
    {
    private:
        string target;
        TokenEnum key;

    public:
        KeywordParser(string target, TokenEnum key)
        {
            this->target = target;
            this->key = key;
        }
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == target.size())
            {
                return {true, false};
            }
            if (target[buf.size()] == next)
            {
                return {false, true};
            }
            return {false, false};
        }
        TokenEnum getKey() override
        {
            return key;
        }
    };
    class CharConstParser : public Parser
    {
    private:
        bool checkAscii(char src)
        {
            if (src <= 126 && src >= 32)
            {
                return 1;
            }
            if (src <= 12 && src >= 7)
            {
                return 1;
            }
            if (src == 34 || src == 39 || src == 92 || src == 0)
            {
                return 1;
            }
            return 0;
        }
        bool checkTrans(char src)
        {
            char lst[] = {'a', 'b', 't', 'n', 'v', 'f', '\"', '\'', '\\', '0'};
            for (int i = 0; i < sizeof(lst) / sizeof(char); i += 1)
            {
                if (src == lst[i])
                {
                    return 1;
                }
            }
            return 0;
        }

    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && next == '\'')
            {
                return {false, true};
            }
            else if (buf.size() == 1 && checkAscii(next))
            {
                return {false, true};
            }
            else if (buf.size() == 1 && next == '\\')
            {
                return {false, true};
            }
            else if (buf.size() == 2 && buf[1] == '\\')
            {
                if (checkTrans(next))
                {
                    return {false, true};
                }
                return {false, false};
            }
            else if (buf.size() == 2 && next == '\'')
            {
                if (buf.back() == '\\')
                {
                    return {false, false};
                }
                return {false, true};
            }
            else if (buf.size() == 3 && buf[1] != '\\')
            {
                return {true, false};
            }
            else if (buf.size() == 3 && buf[1] == '\\')
            {
                if (next == '\'')
                {
                    return {false, true};
                }
                return {false, false};
            }
            else if (buf.size() == 4)
            {
                return {true, false};
            }
            return {false, false};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::CHRCON;
        }
    };
    class StringConstParser : public Parser
    {
    private:
        bool checkAscii(char src)
        {
            if (src <= 126 && src >= 32)
            {
                return 1;
            }
            if (src <= 12 && src >= 7)
            {
                return 1;
            }
            if (src == 34 || src == 39 || src == 92 || src == 0)
            {
                return 1;
            }
            return 0;
        }

    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && next == '\"')
            {
                return {false, true};
            }
            else if (buf.size() > 0)
            {
                if (buf.size() >= 2 && buf[buf.size() - 2] != '\\' && buf.back() == '\"')
                {
                    return {true, false};
                }
                else if (checkAscii(next))
                {
                    return {false, true};
                }
            }
            return {0, 0};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::STRCON;
        }
    };
    class IntConstParser : public Parser
    {
    private:
        bool checkDigit(char src)
        {
            if (src >= '0' && src <= '9')
            {
                return true;
            }
            return false;
        }

    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && checkDigit(next))
            {
                return {true, true};
            }
            else if (buf.size() > 0)
            {
                if (buf.size() == 1 && buf[0] == '0')
                {
                    return {true, false};
                }
                if (checkDigit(next))
                {
                    return {true, true};
                }
                else
                {
                    return {true, false};
                }
            }
            return {0, 0};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::INTCON;
        }
    };
    class IdentParser : public Parser
    {
    private:
        bool isUnderscoreOrLetter(char c)
        {
            return c == '_' || islower(c) || isupper(c);
        }
        bool isDigit(char c)
        {
            return c >= '0' && c <= '9';
        }

    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && isUnderscoreOrLetter(next))
            {
                return {false, true};
            }
            else if (buf.size() > 0)
            {
                if (isUnderscoreOrLetter(next) || isDigit(next))
                {
                    return {true, true};
                }
                else
                {
                    return {true, false};
                }
            }
            return {0, 0};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::IDENFR;
        }
    };
    class SingleCommentParser : public Parser
    {
    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && next == '/')
            {
                return {false, true};
            }
            else if (buf.size() == 1 && next == '/')
            {
                return {false, true};
            }
            else if (buf.size() >= 2)
            {
                if (next == '\n' || next == EOF)
                {
                    return {true, false};
                }
                return {false, true};
            }
            return {0, 0};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::SINGLECMT;
        }
    };
    class MultCommentParser : public Parser
    {
    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && next == '/')
            {
                return {false, true};
            }
            else if (buf.size() == 1 && next == '*')
            {
                return {false, true};
            }
            else if (buf.size() == 2 || buf.size() == 3)
            {
                return {false, true};
            }
            else if (buf.size() >= 4)
            {
                if (buf.back() == '/' && buf[buf.size() - 2] == '*')
                {
                    return {true, false};
                }
                return {false, true};
            }
            return {0, 0};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::MULTCMT;
        }
    };
    class EofParser : public Parser
    {
    public:
        ParseRes parse(string buf, char next) override
        {
            if (buf.size() == 0 && next == EOF)
            {
                return {false, true};
            }
            if (buf.size() == 1)
            {
                return {true, false};
            }
            return {0, 0};
        }
        TokenEnum getKey() override
        {
            return TokenEnum::EOFTK;
        }
    };
    class SpaceParser : public Parser
    {
    private:
        inline bool checkBlank(char src)
        {
            return src == ' ' || src == '\t' || src == '\r';
        }

    public:
        ParseRes parse(string buf, char next)
        {
            if (buf.size() == 0 && checkBlank(next))
            {
                return {false, true};
            }
            else if (buf.size() > 0)
            {
                if (checkBlank(next))
                {
                    return {true, true};
                }
                else
                {
                    return {true, false};
                }
            }
            return {0, 0};
        }
        TokenEnum getKey()
        {
            return TokenEnum::SPACETK;
        }
    };
    class EnterParser : public Parser
    {
    public:
        ParseRes parse(string buf, char next)
        {
            if (buf.size() == 0 && next == '\n')
            {
                return {false, true};
            }
            else if (buf.size() == 1)
            {
                return {true, false};
            }
            return {0, 0};
        }
        TokenEnum getKey()
        {
            return TokenEnum::ENTERTK;
        }
    };

private:
    Parser *allParsers[46] = {

        new EofParser(),
        new SpaceParser(),
        new EnterParser(),
        new SingleCommentParser(),
        new MultCommentParser(),
        new IdentParser(),
        new IntConstParser(),
        new StringConstParser(),
        new CharConstParser(),
        new KeywordParser("main", MAINTK),
        new KeywordParser("const", CONSTTK),
        new KeywordParser("int", INTTK),
        new KeywordParser("char", CHARTK),
        new KeywordParser("break", BREAKTK),
        new KeywordParser("continue", CONTINUETK),
        new KeywordParser("if", IFTK),
        new KeywordParser("else", ELSETK),
        new KeywordParser("!", TokenEnum::NOT),
        new KeywordParser("&&", AND),
        new KeywordParser("||", OR),
        new KeywordParser("for", FORTK),
        new KeywordParser("getint", GETINTTK),
        new KeywordParser("getchar", GETCHARTK),
        new KeywordParser("printf", PRINTFTK),
        new KeywordParser("return", RETURNTK),
        new KeywordParser("+", PLUS),
        new KeywordParser("-", MINU),
        new KeywordParser("void", VOIDTK),
        new KeywordParser("*", TokenEnum::MULT),
        new KeywordParser("/", TokenEnum::DIV),
        new KeywordParser("%", TokenEnum::MOD),
        new KeywordParser("<", TokenEnum::LSS),
        new KeywordParser("<=", TokenEnum::LEQ),
        new KeywordParser(">", TokenEnum::GRE),
        new KeywordParser(">=", TokenEnum::GEQ),
        new KeywordParser("==", TokenEnum::EQL),
        new KeywordParser("!=", TokenEnum::NEQ),
        new KeywordParser("=", ASSIGN),
        new KeywordParser(";", SEMICN),
        new KeywordParser(",", COMMA),
        new KeywordParser("(", LPARENT),
        new KeywordParser(")", RPARENT),
        new KeywordParser("[", LBRACK),
        new KeywordParser("]", RBRACK),
        new KeywordParser("{", LBRACE),
        new KeywordParser("}", RBRACE)

    };
    FILE *input;
    int lineNum = 1;
    string buf;
    char nextChar;
    vector<Parser *> curParsers;
    map<Parser *, ParseRes> results;
    vector<Parser *> canUseParsers;
    vector<Parser *> canNextParsers;
    int totalCanUse;
    int totalCanNext;

    void resetParsers()
    {
        for (int i = 0; i < sizeof(allParsers) / sizeof(Parser *); i += 1)
        {
            curParsers.push_back(allParsers[i]);
        }
    }

    void getNextChar()
    {
        char tmp;

        if (fscanf(input, "%c", &tmp) == EOF)
        {
            tmp = EOF;
        }
        nextChar = tmp;
    }

    void calcParseRes()
    {
        totalCanNext = 0;
        totalCanUse = 0;
        canNextParsers.clear();
        canUseParsers.clear();
        for (vector<Parser *>::iterator it = curParsers.begin(); it != curParsers.end(); it++)
        {
            ParseRes curRes = (*it)->parse(buf, nextChar);

            results[*it] = curRes;
            if (curRes.canUse)
            {
                totalCanUse += 1;
                canUseParsers.push_back(*it);
            }
            if (curRes.canNext)
            {
                totalCanNext += 1;
                canNextParsers.push_back(*it);
            }
        }
    }

    void goNextStatus()
    {
        curParsers.clear();
        curParsers = canNextParsers;
        if (nextChar == '\n')
        {
            lineNum += 1;
        }
        buf += nextChar;
        getNextChar();
    }

public:
    Lexer(FILE *input)
    {
        this->input = input;
        resetParsers();
        buf = "";
        getNextChar();
    }
    TokenBlock getNext()
    {
        while (1)
        {
            calcParseRes();
            if (totalCanNext == 0)
            {
                TokenBlock res;
                res.lineNum = lineNum;
                if (totalCanUse >= 1)
                {
                    res.correct = 1;
                    res.key = canUseParsers.back()->getKey();
                }
                else
                {
                    res.correct = 0;
                    res.key = curParsers.back()->getKey();
                }
                res.content = buf;
                buf = "";
                resetParsers();

                return res;
            }
            else if (totalCanNext > 0)
            {
                goNextStatus();
                continue;
            }
            else
            {
                printf("Err: In getNext.");
            }
        }
    }
};

class Parser
{
public:
    struct ParseRes
    {
        Component *comp;
        vector<ErrorBlock> errs;
        int nextPlace;
    };
    struct PatternRes
    {
        vector<Component *> parts;
        vector<ErrorBlock> errs;
        int lineNum;
        bool correct;
        int nextPlace;
    };
    struct MatchRes
    {
        vector<Component *> parts;
        vector<ErrorBlock> errs;
        int lineNum;
        bool correct;
        int nextPlace;
    };

private:
    vector<TokenBlock> *tokens;
    vector<Pattern> patterns[ComponentEnum::C_COUNT];

    void initPatterns()
    {
        vector<PUnit> units;
        vector<PUnit> subs;
        //CompUnit
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, ComponentEnum::Decl));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, ComponentEnum::FuncDef));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::MainFuncDef));
        patterns[ComponentEnum::CompUnit].push_back(Pattern(units));
        units.clear();
        ///Decl
        ///-const
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstDecl));
        patterns[ComponentEnum::Decl].push_back(Pattern(units));
        units.clear();
        ///-var
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::VarDecl));
        patterns[ComponentEnum::Decl].push_back(Pattern(units));
        units.clear();
        //ConstDecl
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::CONSTTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::BType));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstDef));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstDef));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::ConstDecl].push_back(Pattern(units));
        units.clear();
        ///BType
        ///-int
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::INTTK));
        patterns[ComponentEnum::BType].push_back(Pattern(units));
        units.clear();
        ///-char
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::CHARTK));
        patterns[ComponentEnum::BType].push_back(Pattern(units));
        units.clear();
        //ConstDef
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Ident));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACK));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstExp));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACK));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ASSIGN));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstInitVal));
        patterns[ComponentEnum::ConstDef].push_back(Pattern(units));
        units.clear();
        ///ConstInitVal
        ///-exp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstExp));
        patterns[ComponentEnum::ConstInitVal].push_back(Pattern(units));
        units.clear();
        ///-exps
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACE));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstExp));
        PUnit tmp(PUnit::AmountType::OPTIONAL, subs);
        subs.clear();
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstExp));
        subs.push_back(tmp);
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACE));
        patterns[ComponentEnum::ConstInitVal].push_back(Pattern(units));
        units.clear();
        ///-str
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::StringConst));
        patterns[ComponentEnum::ConstInitVal].push_back(Pattern(units));
        units.clear();
        ///VarDecl
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::BType));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::VarDef));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::VarDef));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::VarDecl].push_back(Pattern(units));
        units.clear();
        ///VarDef
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Ident));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACK));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::ConstExp));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACK));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ASSIGN));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::InitVal));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        patterns[ComponentEnum::VarDef].push_back(Pattern(units));
        units.clear();
        ///InitVal
        ///-exp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        patterns[ComponentEnum::InitVal].push_back(Pattern(units));
        units.clear();
        ///-exps
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACE));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        tmp = PUnit(PUnit::AmountType::OPTIONAL, subs);
        subs.clear();
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        subs.push_back(tmp);
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACE));
        patterns[ComponentEnum::InitVal].push_back(Pattern(units));
        units.clear();
        ///-str
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::StringConst));
        patterns[ComponentEnum::InitVal].push_back(Pattern(units));
        units.clear();
        ///FuncDef
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::FuncType));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Ident));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::FuncFParams));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Block));
        patterns[ComponentEnum::FuncDef].push_back(Pattern(units));
        units.clear();
        ///MainFuncDef
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::INTTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::MAINTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Block));
        patterns[ComponentEnum::MainFuncDef].push_back(Pattern(units));
        units.clear();
        ///FuncType
        ///-void
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::VOIDTK));
        patterns[ComponentEnum::FuncType].push_back(Pattern(units));
        units.clear();
        ///-int
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::INTTK));
        patterns[ComponentEnum::FuncType].push_back(Pattern(units));
        units.clear();
        ///-char
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::CHARTK));
        patterns[ComponentEnum::FuncType].push_back(Pattern(units));
        units.clear();
        ///FuncFParams
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::FuncFParam));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::FuncFParam));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::FuncFParams].push_back(Pattern(units));
        units.clear();
        ///FuncFParam
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::BType));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Ident));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACK));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACK));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        patterns[ComponentEnum::FuncFParam].push_back(Pattern(units));
        units.clear();
        ///Block
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACE));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, ComponentEnum::BlockItem));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACE));

        patterns[ComponentEnum::Block].push_back(Pattern(units));
        units.clear();
        ///BlockItem
        ///-Decl
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Decl));
        patterns[ComponentEnum::BlockItem].push_back(Pattern(units));
        units.clear();
        ///-Stmt
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Stmt));
        patterns[ComponentEnum::BlockItem].push_back(Pattern(units));
        units.clear();
        ///Stmt
        ///-LVAL_EXP
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LVal));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ASSIGN));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();

        ///-BLOCK
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Block));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-IF
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::IFTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Cond));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Stmt));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ELSETK));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Stmt));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-FOR
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::FORTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::ForStmt));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::Cond));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::ForStmt));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Stmt));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-BREAK
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::BREAKTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-CONTINUE
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::CONTINUETK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-Return
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RETURNTK));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::Exp));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-getint
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LVal));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ASSIGN));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::GETINTTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-getChar
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LVal));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ASSIGN));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::GETCHARTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-printf
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::PRINTFTK));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::StringConst));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///-EXP
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::Exp));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::SEMICN));
        patterns[ComponentEnum::Stmt].push_back(Pattern(units));
        units.clear();
        ///ForStmt
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LVal));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::ASSIGN));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        patterns[ComponentEnum::ForStmt].push_back(Pattern(units));
        units.clear();
        ///Exp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::AddExp));
        patterns[ComponentEnum::Exp].push_back(Pattern(units));
        units.clear();
        ///Cond
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LOrExp));
        patterns[ComponentEnum::Cond].push_back(Pattern(units));
        units.clear();
        ///LVal
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Ident));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LBRACK));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RBRACK));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, subs));
        subs.clear();

        patterns[ComponentEnum::LVal].push_back(Pattern(units));
        units.clear();
        ///PrimaryExp
        ///-exp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        patterns[ComponentEnum::PrimaryExp].push_back(Pattern(units));
        units.clear();
        ///-lval
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LVal));
        patterns[ComponentEnum::PrimaryExp].push_back(Pattern(units));
        units.clear();
        ///-num
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Number));
        patterns[ComponentEnum::PrimaryExp].push_back(Pattern(units));
        units.clear();
        ///-char
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Character));
        patterns[ComponentEnum::PrimaryExp].push_back(Pattern(units));
        units.clear();
        ///Number
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::IntConst));
        patterns[ComponentEnum::Number].push_back(Pattern(units));
        units.clear();
        ///Character
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::CharConst));
        patterns[ComponentEnum::Character].push_back(Pattern(units));
        units.clear();
        ///UnaryExp
        ///-ident
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Ident));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LPARENT));
        units.push_back(PUnit(PUnit::AmountType::ZERO_ONE, ComponentEnum::FuncRParams));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::RPARENT));
        patterns[ComponentEnum::UnaryExp].push_back(Pattern(units));
        units.clear();
        ///-pri
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::PrimaryExp));
        patterns[ComponentEnum::UnaryExp].push_back(Pattern(units));
        units.clear();
        ///-op_exp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::UnaryOp));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::UnaryExp));
        patterns[ComponentEnum::UnaryExp].push_back(Pattern(units));
        units.clear();
        ///UnaryOp
        ///-add
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::PLUS));
        patterns[ComponentEnum::UnaryOp].push_back(Pattern(units));
        units.clear();
        ///-sub
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::MINU));
        patterns[ComponentEnum::UnaryOp].push_back(Pattern(units));
        units.clear();
        ///-not
        units.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::NOT));
        patterns[ComponentEnum::UnaryOp].push_back(Pattern(units));
        units.clear();
        ///FuncRParams
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::COMMA));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Exp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::FuncRParams].push_back(Pattern(units));
        units.clear();
        ///MulExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::UnaryExp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::MULT));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::DIV));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::MOD));
        tmp = PUnit(PUnit::AmountType::SINGLE, subs, PUnit::DataType::OR_SUBS);
        subs.clear();
        subs.push_back(tmp);
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::UnaryExp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::MulExp].push_back(Pattern(units));
        units.clear();
        ///AddExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::MulExp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::PLUS));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::MINU));
        tmp = PUnit(PUnit::AmountType::SINGLE, subs, PUnit::DataType::OR_SUBS);
        subs.clear();
        subs.push_back(tmp);

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::MulExp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::AddExp].push_back(Pattern(units));
        units.clear();
        ///RelExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::AddExp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LSS));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::GRE));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::LEQ));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::GEQ));
        tmp = PUnit(PUnit::AmountType::SINGLE, subs, PUnit::DataType::OR_SUBS);
        subs.clear();
        subs.push_back(tmp);

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::AddExp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::RelExp].push_back(Pattern(units));
        units.clear();
        ///EqExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::RelExp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::EQL));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::NEQ));
        tmp = PUnit(PUnit::AmountType::SINGLE, subs, PUnit::DataType::OR_SUBS);
        subs.clear();
        subs.push_back(tmp);

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::RelExp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::EqExp].push_back(Pattern(units));
        units.clear();
        ///LAndExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::EqExp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::AND));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::EqExp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::LAndExp].push_back(Pattern(units));
        units.clear();
        ///LOrExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LAndExp));

        subs.push_back(PUnit(PUnit::AmountType::SINGLE, TokenEnum::OR));
        subs.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::LAndExp));
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, subs));
        subs.clear();

        patterns[ComponentEnum::LOrExp].push_back(Pattern(units));
        units.clear();
        ///ConstExp
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::AddExp));
        patterns[ComponentEnum::ConstExp].push_back(Pattern(units));
        units.clear();
        ///end
    }

public:
    Parser(vector<TokenBlock> *tokens)
    {
        this->tokens = tokens;
        initPatterns();
    }
    void clearMemory(Component *src)
    {
        for (int i = 0; i < src->getParts().size(); i += 1)
        {
            clearMemory(src->getParts()[i]);
        }
        delete src;
    }
    void clearMemory(vector<Component *> src)
    {
        for (int i = 0; i < src.size(); i += 1)
        {
            clearMemory(src[i]);
        }
    }
    void clearMemory(PatternRes src)
    {
        clearMemory(src.parts);
    }
    void clearMemory(vector<PatternRes> src)
    {
        for (int i = 0; i < src.size(); i += 1)
        {
            clearMemory(src[i]);
        }
    }
    MatchRes parsePUnit(int place, ComponentEnum target, int form, PUnit unit)
    {
        vector<Component *> parts;
        vector<ErrorBlock> errs;
        bool correct = 0;
        int lineNum = place == 0 ? 1 : tokens->at(place - 1).lineNum;
        int np = place;

        for (;;)
        {
            vector<Component *> curParts;
            vector<ErrorBlock> curErrs;
            bool curRight = 0;
            int curNp = np;

            if (unit.getDType() == PUnit::DataType::TK)
            {
                ParseRes curRes = parseTerminateComponent(curNp, unit.getTk());
                curNp = curRes.nextPlace;
                curParts.push_back(curRes.comp);
                curErrs.insert(curErrs.end(), curRes.errs.begin(), curRes.errs.end());
                curRight = curRes.comp->getCorrect();
                if (!curRight)
                {
                    if (unit.getTk() == TokenEnum::RBRACK)
                    {
                        if (target == ComponentEnum::ConstDef || target == ComponentEnum::VarDef ||
                            target == ComponentEnum::FuncFParam || target == ComponentEnum::LVal)
                        {
                            curErrs.push_back({lineNum, 'k'});
                            curRight = 1;
                        }
                    }
                    if (unit.getTk() == TokenEnum::RPARENT)
                    {
                        if (target == ComponentEnum::UnaryExp || target == ComponentEnum::FuncDef ||
                            target == ComponentEnum::MainFuncDef || target == ComponentEnum::Stmt ||
                            target == ComponentEnum::PrimaryExp)
                        {
                            curErrs.push_back({lineNum, 'j'});
                            curRight = 1;
                        }
                    }
                    if (unit.getTk() == TokenEnum::SEMICN)
                    { ///stmt in other place
                        if (target == ComponentEnum::ConstDecl || target == ComponentEnum::VarDecl ||
                            (target == ComponentEnum::Stmt && form != StmtEnum::STMT_EXP))
                        {
                            curErrs.push_back({lineNum, 'i'});
                            curRight = 1;
                        }
                    }
                }
            }
            else if (unit.getDType() == PUnit::DataType::COMP)
            {
                ParseRes curRes = parseComponent(curNp, unit.getComp());
                curNp = curRes.nextPlace;
                curParts.push_back(curRes.comp);
                curErrs.insert(curErrs.end(), curRes.errs.begin(), curRes.errs.end());
                curRight = curRes.comp->getCorrect();
            }
            else if (unit.getDType() == PUnit::DataType::SUBS)
            {
                vector<PUnit> subs = unit.getSubUnits();
                curRight = 1;
                for (int i = 0; i < subs.size(); i += 1)
                {
                    MatchRes curRes = parsePUnit(curNp, target, form, subs[i]);
                    curParts.insert(curParts.end(), curRes.parts.begin(), curRes.parts.end());
                    curErrs.insert(curErrs.end(), curRes.errs.begin(), curRes.errs.end());
                    curRight = curRight && curRes.correct;
                    curNp = curRes.nextPlace;
                    if (!curRight)
                    {
                        break;
                    }
                }
            }
            else
            {
                vector<PUnit> subs = unit.getSubUnits();
                curRight = 1;
                for (int i = 0; i < subs.size(); i += 1)
                {
                    MatchRes curRes = parsePUnit(curNp, target, form, subs[i]);
                    if (curRes.correct || i == subs.size() - 1)
                    {
                        curParts.insert(curParts.end(), curRes.parts.begin(), curRes.parts.end());
                        curErrs.insert(curErrs.end(), curRes.errs.begin(), curRes.errs.end());
                        curRight = curRight && curRes.correct;
                        curNp = curRes.nextPlace;
                        break;
                    }
                    curRight = 1;
                }
            }

            if (unit.getAType() == PUnit::AmountType::SINGLE)
            {
                parts.insert(parts.end(), curParts.begin(), curParts.end());
                errs.insert(errs.end(), curErrs.begin(), curErrs.end());
                correct = curRight;
                np = curNp;
                break;
            }
            else if (unit.getAType() == PUnit::AmountType::ZERO_ONE)
            {
                if (curRight)
                {
                    parts.insert(parts.end(), curParts.begin(), curParts.end());
                    errs.insert(errs.end(), curErrs.begin(), curErrs.end());
                    np = curNp;
                    correct = curRight;
                    break;
                }
                clearMemory(curParts);
                correct = 1;
                break;
            }
            else
            {
                if (curRight)
                {
                    parts.insert(parts.end(), curParts.begin(), curParts.end());
                    errs.insert(errs.end(), curErrs.begin(), curErrs.end());
                    np = curNp;
                    correct = curRight;
                }
                else
                {
                    clearMemory(curParts);
                    correct = 1;
                    break;
                }
            }
        }
        if (parts.size() > 0)
        {
            lineNum = parts[0]->getLineNum();
        }
        return {parts, errs, lineNum, correct, np};
    }
    PatternRes parseCompUnitPattern(int place)
    {
        ComponentEnum target = ComponentEnum::CompUnit;
        int form = 0;
        vector<Component *> parts;
        vector<ErrorBlock> errs;
        bool correct = 1;
        int lineNum = place == 0 ? 1 : tokens->at(place - 1).lineNum;
        int np = place;

        PUnit declUnit = PUnit(PUnit::AmountType::SINGLE, ComponentEnum::Decl);
        PUnit funcUnit = PUnit(PUnit::AmountType::SINGLE, ComponentEnum::FuncDef);
        ///Decl
        while (1)
        {
            MatchRes curRes = parsePUnit(np, target, form, declUnit);
            if (curRes.correct)
            {
                if (curRes.errs.size() > 0)
                {
                    MatchRes tmpRes = parsePUnit(np, target, form, funcUnit);
                    if (tmpRes.correct)
                    {
                        parts.insert(parts.end(), tmpRes.parts.begin(), tmpRes.parts.end());
                        errs.insert(errs.end(), tmpRes.errs.begin(), tmpRes.errs.end());
                        correct = correct && tmpRes.correct;
                        np = tmpRes.nextPlace;
                        break;
                    }
                }
                parts.insert(parts.end(), curRes.parts.begin(), curRes.parts.end());
                errs.insert(errs.end(), curRes.errs.begin(), curRes.errs.end());
                correct = correct && curRes.correct;
                np = curRes.nextPlace;
            }
            else
            {
                break;
            }
        }

        vector<PUnit> units;
        units.push_back(PUnit(PUnit::AmountType::OPTIONAL, ComponentEnum::FuncDef));
        units.push_back(PUnit(PUnit::AmountType::SINGLE, ComponentEnum::MainFuncDef));
        for (auto i = units.begin(); i != units.end(); i++)
        {
            MatchRes curRes = parsePUnit(np, target, form, *i);

            parts.insert(parts.end(), curRes.parts.begin(), curRes.parts.end());
            errs.insert(errs.end(), curRes.errs.begin(), curRes.errs.end());
            correct = correct && curRes.correct;
            if (!curRes.correct)
            {
                if (target == ComponentEnum::Stmt && form == StmtEnum::STMT_EXP && parts.size() == 2 &&
                    (*i).getDType() == PUnit::DataType::TK && (*i).getTk() == TokenEnum::SEMICN)
                {
                    correct = 1;
                    errs.push_back({np == 0 ? 1 : tokens->at(np - 1).lineNum, 'i'});
                }
                else
                {
                    break;
                }
            }
            np = curRes.nextPlace;
        }
        if (parts.size() > 0)
        {
            lineNum = parts[0]->getLineNum();
        }
        return {parts, errs, lineNum, correct, np};
    }
    PatternRes parsePattern(int place, ComponentEnum target, int form, Pattern pattern)
    {
        vector<Component *> parts;
        vector<ErrorBlock> errs;
        bool correct = 1;
        int lineNum = place == 0 ? 1 : tokens->at(place - 1).lineNum;
        int np = place;

        vector<PUnit> units = pattern.getUnits();
        for (auto i = units.begin(); i != units.end(); i++)
        {
            MatchRes curRes = parsePUnit(np, target, form, *i);

            parts.insert(parts.end(), curRes.parts.begin(), curRes.parts.end());
            errs.insert(errs.end(), curRes.errs.begin(), curRes.errs.end());
            correct = correct && curRes.correct;
            if (!curRes.correct)
            {
                if (target == ComponentEnum::Stmt && form == StmtEnum::STMT_EXP && parts.size() == 2 &&
                    (*i).getDType() == PUnit::DataType::TK && (*i).getTk() == TokenEnum::SEMICN)
                {
                    correct = 1;
                    errs.push_back({np == 0 ? 1 : tokens->at(np - 1).lineNum, 'i'});
                }
                else
                {
                    break;
                }
            }
            np = curRes.nextPlace;
        }
        if (parts.size() > 0)
        {
            lineNum = parts[0]->getLineNum();
        }
        return {parts, errs, lineNum, correct, np};
    }
    ParseRes packagePatternResToParseRes(ComponentEnum target, vector<PatternRes> src)
    {
        int choice = 0;
        for (int i = 0; i < src.size(); i += 1)
        {
            if (src[i].correct)
            {
                choice = i;
                break;
            }
        }
        ParseRes curRes = packagePatternResToParseRes(target, choice, src[choice]);
        src.erase(src.begin() + choice);
        clearMemory(src);
        return curRes;
    }
    ParseRes packagePatternResToParseRes(ComponentEnum target, int form, PatternRes src)
    {
        Component *comp = new Component(src.lineNum, src.correct, target, form, src.parts);
        vector<ErrorBlock> errs = src.errs;
        int nextPlace = src.nextPlace;
        return {comp, errs, nextPlace};
    }

    ParseRes parseComponent(int place, ComponentEnum target)
    {
        if (target >= ComponentEnum::Ident && target <= ComponentEnum::StringConst)
        {
            return parseTerminateComponent(place, target);
        }
        vector<PatternRes> res;
        for (int i = 0; i < patterns[target].size(); i += 1)
        {
            PatternRes curRes;
            if (target == ComponentEnum::CompUnit)
            {
                curRes = parseCompUnitPattern(place);
            }
            else
            {
                curRes = parsePattern(place, target, i, patterns[target][i]);
            }
            if (curRes.correct && curRes.errs.empty())
            {
                clearMemory(res);
                return packagePatternResToParseRes(target, i, curRes);
            }
            res.push_back(curRes);
        }
        ParseRes curRes = packagePatternResToParseRes(target, res);
        return curRes;
    }

    ParseRes parseTerminateComponent(int place, TokenEnum target)
    {
        int nextPlace = place;
        int lineNum = place == 0 ? 1 : tokens->at(place - 1).lineNum;
        Component *comp;
        vector<ErrorBlock> errs;

        bool correct = 0;

        TokenBlock tk;
        if (tokens->at(nextPlace).key == target)
        {
            tk = tokens->at(nextPlace);
            nextPlace += 1;
            correct = 1;
            lineNum = tk.lineNum;
        }
        else
        {
            tk = {target, lineNum, TokenStrings[target], 0};
        }

        comp = new Component(lineNum, correct, ComponentEnum::TokenConst, tk);
        return {comp, errs, nextPlace};
    }

    ParseRes parseTerminateComponent(int place, ComponentEnum target)
    {
        int nextPlace = place;
        int lineNum = place == 0 ? 1 : tokens->at(place - 1).lineNum;
        Component *comp;
        vector<ErrorBlock> errs;

        bool correct = 0;
        TokenEnum toMatch;
        if (target == ComponentEnum::Ident)
        {
            toMatch = TokenEnum::IDENFR;
        }
        else if (target == ComponentEnum::IntConst)
        {
            toMatch = TokenEnum::INTCON;
        }
        else if (target == ComponentEnum::CharConst)
        {
            toMatch = TokenEnum::CHRCON;
        }
        else if (target == ComponentEnum::StringConst)
        {
            toMatch = TokenEnum::STRCON;
        }
        else
        {
            toMatch = TokenEnum::OUTRANGE;
        }
        TokenBlock tk;
        if (tokens->at(nextPlace).key == toMatch)
        {
            tk = tokens->at(nextPlace);
            nextPlace += 1;
            correct = 1;
            lineNum = tk.lineNum;
        }
        comp = new Component(lineNum, correct, target, tk);
        return {comp, errs, nextPlace};
    }
};

int main()
{
    FILE *file = fopen("testfile.txt", "r");
    FILE *resFile = fopen("parser.txt", "w");
    FILE *errFile = fopen("error.txt", "w");
    Lexer lexer(file);
    vector<TokenBlock> tokens;
    vector<ErrorBlock> errs;
    TokenBlock tb;
    do
    {
        tb = lexer.getNext();
        if (!(tb.key >= TokenEnum::SPACETK && tb.key <= TokenEnum::MULTCMT))
        {
            tokens.push_back(tb);
            if (!tb.correct)
            {
                errs.push_back({tb.lineNum, 'a'});
            }
        }
    } while (tb.key != EOFTK);
    Parser parser(&tokens);
    Parser::ParseRes res = parser.parseComponent(0, ComponentEnum::CompUnit);
    errs.insert(errs.end(), res.errs.begin(), res.errs.end());
    Component *comp = res.comp;
    outputComponent(comp, resFile);
    outputErrors(errs, errFile);
    fclose(file);
    fclose(errFile);
    fclose(resFile);
    return 0;
}
