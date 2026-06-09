#include <all.h>
char c;
int linenum = 1;
std::string s;
struct token tk;
std::ifstream file("testfile.txt");
std::ofstream outfile("lexer.txt");
void printtk()
{
    tk.line = linenum;
    tks.push_back(tk);
    outfile << tokenTypeToString(tk.type) << " " << tk.content << std::endl;
    s = "";
}
void opnum()
{
    while (c >= '0' && c <= '9')
    {
        s = s + c;
        file.get(c);
    }
    file.unget();
    tk.type = INTCON;
    tk.content = s;
    printtk();
    s = "";
}
void opchar()
{
    s = s + c;
    file.get(c);
    if (c == '\\')
    {
        s = s + c;
        file.get(c);
        s = s + c;
    }
    else
    {
        s = s + c;
    }
    file.get(c);
    s = s + c;
    tk.type = CHRCON;
    tk.content = s;
    printtk();
    s = "";
}
void opstring()
{
    char lastc = c;
    while (c >= 32 && c <= 126)
    {
        s = s + c;
        lastc = c;
        file.get(c);
        if (c == '\"' && lastc != '\\')
        {
            break;
        }
    }
    s = s + c;
    tk.type = STRCON;
    tk.content = s;
    printtk();
    s = "";
}
void opdiv()
{
    char lastc = c;
    file.get(c);
    if (c == '/')
    {
        while (c != '\n')
        {
            file.get(c);
            if (file.eof())
            {
                return;
            }
        }
        linenum++;
    }
    else if (c == '*')
    {
        lastc = c;
        while (file.get(c))
        {
            if (c == '\n')
            {
                linenum++;
            }
            if (c == '/' && lastc == '*')
            {
                break;
            }
            if (file.eof())
            {
                return;
            }
            lastc=c;
        }
    }
    else
    {
        file.unget();
        tk.type = DIV;
        tk.content = "/";
        printtk();
        s = "";
    }
}
void opident()
{
    while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')
    {
        s = s + c;
        file.get(c);
    }
    file.unget();
    if (s == "main")
    {
        tk.type = MAINTK;
    }
    else if (s == "const")
    {
        tk.type = CONSTTK;
    }
    else if (s == "int")
    {
        tk.type = INTTK;
    }
    else if (s == "char")
    {
        tk.type = CHARTK;
    }
    else if (s == "break")
    {
        tk.type = BREAKTK;
    }
    else if (s == "continue")
    {
        tk.type = CONTINUETK;
    }
    else if (s == "if")
    {
        tk.type = IFTK;
    }
    else if (s == "else")
    {
        tk.type = ELSETK;
    }
    else if (s == "void")
    {
        tk.type = VOIDTK;
    }
    else if (s == "getint")
    {
        tk.type = GETINTTK;
    }
    else if (s == "getchar")
    {
        tk.type = GETCHARTK;
    }
    else if (s == "printf")
    {
        tk.type = PRINTFTK;
    }
    else if (s == "return")
    {
        tk.type = RETURNTK;
    }
    else if (s == "for")
    {
        tk.type = FORTK;
    }
    else
    {
        tk.type = IDENFR;
    }
    tk.content = s;
    printtk();
    s = "";
}
void opassign()
{
    s = s + c;
    char lastc = c;
    file.get(c);
    if (c == '=')
    {
        s = s + c;
        if (lastc == '=')
        {
            tk.type = EQL;
            tk.content = s;
            printtk();
        }
        else if (lastc == '<')
        {
            tk.type = LEQ;
            tk.content = s;
            printtk();
        }
        else if (lastc == '>')
        {
            tk.type = GEQ;
            tk.content = s;
            printtk();
        }
        else if (lastc == '!')
        {
            tk.type = NEQ;
            tk.content = s;
            printtk();
        }
    }
    else
    {
        file.unget();
        if (lastc == '=')
        {
            tk.type = ASSIGN;
            tk.content = s;
            printtk();
        }
        else if (lastc == '<')
        {
            tk.type = LSS;
            tk.content = s;
            printtk();
        }
        else if (lastc == '>')
        {
            tk.type = GRE;
            tk.content = s;
            printtk();
        }
        else if (lastc == '!')
        {
            tk.type = NOT;
            tk.content = s;
            printtk();
        }
    }
}
void opandor()
{
    char lastc = c;
    s = s + c;
    file.get(c);
    if (c == '&')
    {
        s = s + c;
        tk.type = AND;
        tk.content = s;
        printtk();
    }
    else if (c == '|')
    {
        s = s + c;
        tk.type = OR;
        tk.content = s;
        printtk();
    }
    else
    {
        file.unget();
        if (lastc == '&')
        {
            tk.type = AND;
            tk.content = s;
            printtk();
            aerr(linenum);
        }
        else if (lastc == '|')
        {
            tk.type = OR;
            tk.content = s;
            printtk();
            aerr(linenum);
        }
    }
}
void opothers()
{
    if (c == '+')
    {
        s = s + c;
        tk.type = PLUS;
        tk.content = s;
        printtk();
    }
    else if (c == '-')
    {
        s = s + c;
        tk.type = MINU;
        tk.content = s;
        printtk();
    }
    else if (c == '*')
    {
        s = s + c;
        tk.type = MULT;
        tk.content = s;
        printtk();
    }
    else if (c == '%')
    {
        s = s + c;
        tk.type = MOD;
        tk.content = s;
        printtk();
    }
    else if (c == ';')
    {
        s = s + c;
        tk.type = SEMICN;
        tk.content = s;
        printtk();
    }
    else if (c == ',')
    {
        s = s + c;
        tk.type = COMMA;
        tk.content = s;
        printtk();
    }
    else if (c == '(')
    {
        s = s + c;
        tk.type = LPARENT;
        tk.content = s;
        printtk();
    }
    else if (c == ')')
    {
        s = s + c;
        tk.type = RPARENT;
        tk.content = s;
        printtk();
    }
    else if (c == '[')
    {
        s = s + c;
        tk.type = LBRACK;
        tk.content = s;
        printtk();
    }
    else if (c == ']')
    {
        s = s + c;
        tk.type = RBRACK;
        tk.content = s;
        printtk();
    }
    else if (c == '{')
    {
        s = s + c;
        tk.type = LBRACE;
        tk.content = s;
        printtk();
    }
    else if (c == '}')
    {
        s = s + c;
        tk.type = RBRACE;
        tk.content = s;
        printtk();
    }
    else if (c == '\n')
    {
        linenum++;
    }
    else
    {
    }
    return;
}
void cifa()
{

    while (file.get(c) && !file.eof())
    {
        if (c >= '0' && c <= '9')
        {
            opnum();
        }
        else if (c == '\'')
        {
            opchar();
        }
        else if (c == '\"')
        {
            opstring();
        }
        else if (c == '/')
        {
            opdiv();
            if (file.eof())
            {
                break;
            }
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
        {
            opident();
        }
        else if (c == '>' || c == '<' || c == '!' || c == '=')
        {
            opassign();
        }
        else if (c == '&' || c == '|')
        {
            opandor();
        }
        else
        {
            opothers();
        }
        if (file.eof())
        {
            break;
        }
    }
    return;
}
