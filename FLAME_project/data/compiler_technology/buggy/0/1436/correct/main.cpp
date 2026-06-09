#include "consts.h"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct TokenBlock
{
    TokenEnum key;
    int lineNum;
    string content;
    bool correct;
};

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
        new KeywordParser("!", NOT),
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
        new KeywordParser("*", MULT),
        new KeywordParser("/", DIV),
        new KeywordParser("%", MOD),
        new KeywordParser("<", LSS),
        new KeywordParser("<=", LEQ),
        new KeywordParser(">", GRE),
        new KeywordParser(">=", GEQ),
        new KeywordParser("==", EQL),
        new KeywordParser("!=", NEQ),
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

int main()
{
    FILE *file = fopen("testfile.txt", "r");
    FILE *output1 = fopen("lexer.txt", "w");
    FILE *output2 = fopen("error.txt", "w");
    Lexer lexer(file);
    TokenBlock tb;
    do
    {
        tb = lexer.getNext();
        if (!(tb.key >= TokenEnum::EOFTK && tb.key <= TokenEnum::MULTCMT))
        {
            if (tb.correct)
            {
                fprintf(output1, "%s %s\n", TokenStrings[tb.key].c_str(), tb.content.c_str());
            }
            if (!tb.correct)
            {
                fprintf(output2, "%d %s\n", tb.lineNum, "a");
            }
        }
    } while (tb.key != EOFTK);
    fclose(file);
    fclose(output1);
    fclose(output2);
    return 0;
}
