#include <bits/stdc++.h>

using namespace std;

struct Lexer_out {
    int row_cnt;
    char error_code;
    string tk;
    string txt;

    Lexer_out(int r, string _tk, string _txt, char e = 0) {
        row_cnt = r, tk = move(_tk), txt = move(_txt), error_code = e;
    }

    Lexer_out(int r) {
        row_cnt = r, error_code = -1;  // this means EOF
    }
};
namespace LEXER {
    int is_identifier_nondigit(char c) {
        return c == '_' || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
    }

    map<string, string> reverse_map;

    void init_reverse() {
        reverse_map["main"] = "MAINTK";
        reverse_map["const"] = "CONSTTK";
        reverse_map["int"] = "INTTK";
        reverse_map["char"] = "CHARTK";
        reverse_map["break"] = "BREAKTK";
        reverse_map["continue"] = "CONTINUETK";
        reverse_map["if"] = "IFTK";
        reverse_map["else"] = "ELSETK";
        reverse_map["for"] = "FORTK";
        reverse_map["getint"] = "GETINTTK";
        reverse_map["getchar"] = "GETCHARTK";
        reverse_map["printf"] = "PRINTFTK";
        reverse_map["return"] = "RETURNTK";
        reverse_map["void"] = "VOIDTK";
    }

    ifstream testfile;
    string input_file;
    int input_file_pos, row_cnt;

    char sym;

    char input_file_get() {
        assert(input_file_pos < input_file.size());
        return input_file[input_file_pos++];
    }

    char input_file_peek() {
        if (input_file_pos < input_file.size())
            return input_file[input_file_pos];
        return EOF;
    }

    char input_file_peek_peek() {
        if (input_file_pos + 1 < input_file.size())
            return input_file[input_file_pos + 1];
        return EOF;
    }

    void read() {  // just go
        if (input_file_get() == '\n') row_cnt++;
        sym = input_file_peek();
    }

    void skip_white() {
        while (sym == ' ' || sym == '\n' || sym == '\r' || sym == '\t')
            read();
    }

    string cur;
    string code;
    string ecode;

    void add() {  // go and add to cur
        cur += sym;
        read();
    }

    void parse_intconst() {
        assert(isdigit(sym));
        while (sym != EOF) {
            if (!isdigit(sym)) break;
            add();
        }
        code = "INTCON";
    }

    void parse_stringconst() {
        assert(sym == '\"');
        add();
        while (sym != EOF) {
            if (sym == '\"') {
                add();
                break;
            }
            if (sym == '\\')
                add(), add();
            else
                add();
        }
        code = "STRCON";
    }

    void parse_charconst() {
        assert(sym == '\'');
        add();
        if (sym == '\\')
            add(), add();
        else
            add();
        assert(sym == '\'');
        add();
        code = "CHRCON";
    }

    void parse_ident_reserve() {
        assert(is_identifier_nondigit(sym));
        add();
        while (is_identifier_nondigit(sym) || isdigit(sym)) add();
        if (reverse_map.count(cur))
            code = reverse_map[cur];
        else
            code = "IDENFR";
    }

    void parse_sign() {  // 除数字、字符串，字符常量，保留字&变量名外其他的
        if (sym == '+')
            add(), code = "PLUS";
        else if (sym == '-')
            add(), code = "MINU";
        else if (sym == '*')
            add(), code = "MULT";
        else if (sym == '/')
            add(), code = "DIV";
        else if (sym == '%')
            add(), code = "MOD";
        else if (sym == ';')
            add(), code = "SEMICN";
        else if (sym == ',')
            add(), code = "COMMA";
        else if (sym == '(')
            add(), code = "LPARENT";
        else if (sym == ')')
            add(), code = "RPARENT";
        else if (sym == '[')
            add(), code = "LBRACK";
        else if (sym == ']')
            add(), code = "RBRACK";
        else if (sym == '{')
            add(), code = "LBRACE";
        else if (sym == '}')
            add(), code = "RBRACE";
        else if (sym == '&') {
            add();
            if (sym == '&')
                add(), code = "AND";
            else
                ecode = "ERRORa", code = "AND";
        } else if (sym == '|') {
            add();
            if (sym == '|')
                add(), code = "OR";
            else
                ecode = "ERRORa", code = "OR";
        } else if (sym == '!') {
            add();
            if (sym == '=')
                add(), code = "NEQ";
            else
                code = "NOT";
        } else if (sym == '<') {
            add();
            if (sym == '=')
                add(), code = "LEQ";
            else
                code = "LSS";
        } else if (sym == '>') {
            add();
            if (sym == '=')
                add(), code = "GEQ";
            else
                code = "GRE";
        } else if (sym == '=') {
            add();
            if (sym == '=')
                add(), code = "EQL";
            else
                code = "ASSIGN";
        } else
            assert(0);
    }

    Lexer_out parse() {
        cur = code = "";
        ecode = "";
        if (isdigit(sym)) {
            parse_intconst();
        } else if (sym == '\"') {
            parse_stringconst();
        } else if (sym == '\'') {
            parse_charconst();
        } else if (is_identifier_nondigit(sym)) {
            parse_ident_reserve();
        } else
            parse_sign();
        if (ecode.size() >= 5 && ecode.substr(0, 5) == "ERROR") {
            return Lexer_out(row_cnt, code, cur, ecode[5]);
        } else {
            return Lexer_out(row_cnt, code, cur);
        }
    }

    void skip_white_and_comments() {
        skip_white();
        while (sym != EOF) {
            assert(sym == input_file_peek());
            if (input_file_peek() == '/' && input_file_peek_peek() == '/') {
                while (sym != EOF && sym != '\n') read();
                if (sym == '\n') read();
            } else if (input_file_peek() == '/' && input_file_peek_peek() == '*') {
                read(), read();
                char last = '6';
                while (sym != EOF) {
                    if (sym == '/' && last == '*') {
                        read();
                        break;
                    }
                    last = sym;
                    read();
                }
            } else
                break;
            skip_white();
        }
    }

    void init() {
        // 读文件
        input_file = "";
        while (testfile.peek() != EOF) {
            input_file += (char)testfile.peek();
            testfile.get();
        }
        input_file_pos = 0;
        sym = input_file_pos < input_file.size() ? input_file[input_file_pos] : EOF;
        row_cnt = 1;
        skip_white_and_comments();
        init_reverse();
    }

    vector<Lexer_out> output;
    int output_pos;

    void lexer_init() {
        testfile = ifstream("testfile.txt");
        init();
        while (sym != EOF) {
            output.push_back(parse());
            skip_white_and_comments();
        }
        output_pos = 0;
    }

    Lexer_out peek() {
        if (output_pos < output.size())
            return output[output_pos];
        return Lexer_out(row_cnt);
    }

    Lexer_out peek_peek() {
        if (output_pos + 1 < output.size())
            return output[output_pos + 1];
        return Lexer_out(row_cnt);
    }

    Lexer_out peek_peek_peek() {
        if (output_pos + 2 < output.size())
            return output[output_pos + 2];
        return Lexer_out(row_cnt);
    }

    void get() {
        ++output_pos;
    }
    int get_pos(){
        return output_pos;
    }
    void put_pos(int pos){
        output_pos=pos;
    }
}  // namespace LEXER

set<string> initParserComponents() {
    return set<string>{"CompUnit", "Decl", "ConstDecl", "BType", "ConstDef", "ConstInitVal", "VarDecl",
                       "VarDef", "InitVal", "FuncDef", "MainFuncDef", "FuncType", "FuncFParams", "FuncFParam",
                       "Block", "BlockItem", "Stmt", "ForStmt", "Exp", "Cond", "LVal", "PrimaryExp", "UnaryExp",
                       "UnaryOp", "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp",
                       "ConstExp"};
}

set<string> parserComponents = initParserComponents();

const int MAXNODE=1111111;
struct Parser_unit {
    int is_end;
    int row_cnt;
    int way;
    vector<int> son;
    string txt;
    string name;
    char ecode;
    Parser_unit(){}
    // 开个内存池得了
    Parser_unit(int _is_end, string _name, string _txt = "", int r = 0, char e = 0) {
        is_end = _is_end, name = _name, txt = _txt, row_cnt = r, ecode = e;
        way = -1;
        if(is_end==0){
            assert(parserComponents.count(name));
        }
    }

    void set_way(int _way) {
        assert(!is_end);
        way = _way;
    }

    void push(int i) {
        assert(!is_end);
        son.push_back(i);
    }
}tr[MAXNODE];
namespace PARSER {
    int nodecnt;
    int row_cnt;
    using LEXER::peek;
    using LEXER::peek_peek;
    using LEXER::peek_peek_peek;
    void get() {
        row_cnt = peek().row_cnt;
        // cerr<<peek().txt<<" ";
        LEXER::get();
    }
    int startByAnExp() {
        return peek().tk == "LPARENT" || peek().tk == "IDENFR" || peek().tk == "INTCON" ||
               peek().tk == "CHRCON" || peek().tk == "PLUS" || peek().tk == "MINU" ||
               peek().tk == "NOT";
    }
    int parseEnd() {
        tr[++nodecnt]=Parser_unit(1, peek().tk, peek().txt, peek().row_cnt, peek().error_code);
        get();
        return nodecnt;
    }
#define parseijk(a, b) (peek().tk == (a) ? tr[cur].push(parseEnd()) : (tr[++nodecnt]=Parser_unit(1, (a), "", row_cnt, (b)), tr[cur].push(nodecnt)))

    int parseCompUnit();
    int parseDecl();
    int parseConstDecl();
    int parseBType();
    int parseConstDef();
    int parseConstInitVal();
    int parseVarDecl();
    int parseVarDef();
    int parseInitVal();
    int parseFuncDef();
    int parseMainFuncDef();
    int parseFuncType();
    int parseFuncFParams();
    int parseFuncFParam();
    int parseBlock();
    int parseBlockItem();
    int parseStmt();
    int parseForStmt();
    int parseExp();
    int parseCond();
    int parseLVal();
    int parsePrimaryExp();
    int parseUnaryExp();
    int parseUnaryOp();
    int parseFuncRParams();
    int parseMulExp();
    int parseAddExp();
    int parseRelExp();
    int parseEqExp();
    int parseLAndExp();
    int parseLOrExp();
    int parseConstExp();
    int parseConstExp() {
        tr[++nodecnt]=Parser_unit(0, "ConstExp");
        int cur = nodecnt;
        tr[cur].push(parseAddExp());
        return cur;
    }
    int parseLOrExp() {
        tr[++nodecnt]=Parser_unit(0, "LOrExp");
        int cur = nodecnt;
        tr[cur].push(parseLAndExp());
        while (peek().tk == "OR") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseLAndExp());
        }
        return cur;
    }
    int parseLAndExp() {
        tr[++nodecnt]=Parser_unit(0, "LAndExp");
        int cur = nodecnt;
        tr[cur].push(parseEqExp());
        while (peek().tk == "AND") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseEqExp());
        }
        return cur;
    }
    int parseEqExp() {
        tr[++nodecnt]=Parser_unit(0, "EqExp");
        int cur = nodecnt;
        tr[cur].push(parseRelExp());
        while (peek().tk == "EQL" || peek().tk == "NEQ") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseRelExp());
        }
        return cur;
    }
    int parseRelExp() {
        tr[++nodecnt]=Parser_unit(0, "RelExp");
        int cur = nodecnt;
        tr[cur].push(parseAddExp());
        while (peek().tk == "LSS" || peek().tk == "GRE" || peek().tk == "LEQ" ||
               peek().tk == "GEQ") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseAddExp());
        }
        return cur;
    }
    int parseAddExp() {
        tr[++nodecnt]=Parser_unit(0, "AddExp");
        int cur = nodecnt;
        tr[cur].push(parseMulExp());
        while (peek().tk == "PLUS" || peek().tk == "MINU") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseMulExp());
        }
        return cur;
    }
    int parseMulExp() {
        tr[++nodecnt]=Parser_unit(0, "MulExp");
        int cur = nodecnt;
        tr[cur].push(parseUnaryExp());
        while (peek().tk == "MULT" || peek().tk == "DIV" || peek().tk == "MOD") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseUnaryExp());
        }
        return cur;
    }
    int parseFuncRParams() {
        tr[++nodecnt]=Parser_unit(0, "FuncRParams");
        int cur = nodecnt;
        tr[cur].push(parseExp());
        while (peek().tk == "COMMA") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseExp());
        }
        return cur;
    }
    int parseUnaryOp() {
        tr[++nodecnt]=Parser_unit(0, "UnaryOp");
        int cur = nodecnt;
        if (peek().tk == "PLUS" || peek().tk == "MINU" || peek().tk == "NOT")
            tr[cur].push(parseEnd());
        else
            assert(0);
        return cur;
    }
    int parseUnaryExp() {
        tr[++nodecnt]=Parser_unit(0, "UnaryExp");
        int cur = nodecnt;
        if (peek().tk == "IDENFR" && peek_peek().tk == "LPARENT") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseEnd());
            if (startByAnExp()) {
                tr[cur].push(parseFuncRParams());
            }
            parseijk("RPARENT", 'j');
        } else if (peek().tk == "PLUS" || peek().tk == "MINU" || peek().tk == "NOT") {
            tr[cur].push(parseUnaryOp());
            tr[cur].push(parseUnaryExp());
        } else {
            tr[cur].push(parsePrimaryExp());
        }
        return cur;
    }
    int parsePrimaryExp() {
        tr[++nodecnt]=Parser_unit(0, "PrimaryExp");
        int cur = nodecnt;
        if (peek().tk == "LPARENT") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseExp());
            parseijk("RPARENT", 'j');
        } else if (peek().tk == "IDENFR") {
            tr[cur].push(parseLVal());
        } else if (peek().tk == "INTCON" || peek().tk == "CHRCON") {
            tr[cur].push(parseEnd());
        } else
            assert(0);
        return cur;
    }
    int parseLVal() {
        tr[++nodecnt]=Parser_unit(0, "LVal");
        int cur = nodecnt;
        tr[cur].push(parseEnd());
        if (peek().tk == "LBRACK") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseExp());
            parseijk("RBRACK", 'k');
        }
        return cur;
    }
    int parseCond() {
        tr[++nodecnt]=Parser_unit(0, "Cond");
        int cur = nodecnt;
        tr[cur].push(parseLOrExp());
        return cur;
    }
    int parseExp() {
        tr[++nodecnt]=Parser_unit(0, "Exp");
        int cur = nodecnt;
        tr[cur].push(parseAddExp());
        return cur;
    }
    int parseForStmt() {
        tr[++nodecnt]=Parser_unit(0, "ForStmt");
        int cur = nodecnt;
        tr[cur].push(parseLVal());
        tr[cur].push(parseEnd());
        tr[cur].push(parseExp());
        return cur;
    }
    int parseStmt() {
        tr[++nodecnt]=Parser_unit(0, "Stmt");
        int cur = nodecnt;
        if (peek().tk == "IDENFR") {
            int lexer_pos=LEXER::get_pos();
            int tmp=parseLVal();
            //这里还要分情况：有可能是个Exp;
            //Lexer必须支持回溯
            if(peek().tk == "ASSIGN"){
                tr[cur].push(tmp);
                tr[cur].push(parseEnd());
                if (peek().tk == "GETINTTK" || peek().tk == "GETCHARTK") {  // 不会出现getint/getchar在exp中
                    tr[cur].push(parseEnd());
                    tr[cur].push(parseEnd());
                    parseijk("RPARENT", 'j');
                } else {
                    tr[cur].push(parseExp());
                }
                parseijk("SEMICN", 'i');
            }
            else{
                LEXER::put_pos(lexer_pos);
                tr[cur].push(parseExp());
                parseijk("SEMICN", 'i');
            }
        } else if (peek().tk == "LBRACE") {
            tr[cur].push(parseBlock());
        } else if (peek().tk == "IFTK") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseEnd());
            tr[cur].push(parseCond());
            parseijk("RPARENT", 'j');
            tr[cur].push(parseStmt());
            if (peek().tk == "ELSETK") {
                tr[cur].push(parseEnd());
                tr[cur].push(parseStmt());
            }
        } else if (peek().tk == "FORTK") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseEnd());
            if (peek().tk != "SEMICN") {
                tr[cur].push(parseForStmt());
            }
            tr[cur].push(parseEnd());
            if (peek().tk != "SEMICN") {
                tr[cur].push(parseCond());
            }
            tr[cur].push(parseEnd());
            if (peek().tk != "RPARENT") {
                tr[cur].push(parseForStmt());
            }
            tr[cur].push(parseEnd());
            tr[cur].push(parseStmt());
        } else if (peek().tk == "BREAKTK" || peek().tk == "CONTINUETK") {
            tr[cur].push(parseEnd());
            parseijk("SEMICN", 'i');
        } else if (peek().tk == "RETURNTK") {
            tr[cur].push(parseEnd());
            if (startByAnExp()) {
                tr[cur].push(parseExp());
            }
            parseijk("SEMICN", 'i');
        } else if (peek().tk == "PRINTFTK") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseEnd());
            tr[cur].push(parseEnd());
            while (peek().tk == "COMMA") {
                tr[cur].push(parseEnd());
                tr[cur].push(parseExp());
            }
            parseijk("RPARENT", 'j');
            parseijk("SEMICN", 'i');
        } else if (peek().tk == "SEMICN") {
            tr[cur].push(parseEnd());
        } else {
            tr[cur].push(parseExp());
            parseijk("SEMICN", 'i');
        }
        return cur;
    }
    int parseBlockItem() {
        tr[++nodecnt]=Parser_unit(0, "BlockItem");
        int cur = nodecnt;
        if (peek().tk == "CONSTTK" || peek().tk == "INTTK" || peek().tk == "CHARTK") {
            tr[cur].push(parseDecl());
            tr[cur].set_way(0);
        } else {
            tr[cur].push(parseStmt());
            tr[cur].set_way(1);
        }
        return cur;
    }
    int parseBlock() {
        tr[++nodecnt]=Parser_unit(0, "Block");
        int cur = nodecnt;
        tr[cur].push(parseEnd());
        while (peek().tk != "RBRACE") {
            tr[cur].push(parseBlockItem());
        }
        tr[cur].push(parseEnd());
        return cur;
    }
    int parseFuncFParam() {
        tr[++nodecnt]=Parser_unit(0, "FuncFParam");
        int cur = nodecnt;
        tr[cur].push(parseBType());
        tr[cur].push(parseEnd());
        if (peek().tk == "LBRACK") {
            tr[cur].push(parseEnd());
            parseijk("RBRACK", 'k');
        }
        return cur;
    }
    int parseFuncFParams() {
        tr[++nodecnt]=Parser_unit(0, "FuncFParams");
        int cur = nodecnt;
        tr[cur].push(parseFuncFParam());
        while (peek().tk == "COMMA") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseFuncFParam());
        }
        return cur;
    }
    int parseFuncType() {
        tr[++nodecnt]=Parser_unit(0, "FuncType");
        int cur = nodecnt;
        if (peek().tk == "VOIDTK") {
            tr[cur].set_way(0);
        }
        if (peek().tk == "INTTK") {
            tr[cur].set_way(1);
        }
        if (peek().tk == "CHARTK") {
            tr[cur].set_way(2);
        }
        tr[cur].push(parseEnd());
        return cur;
    }
    int parseMainFuncDef() {
        tr[++nodecnt]=Parser_unit(0, "MainFuncDef");
        int cur = nodecnt;
        tr[cur].push(parseEnd());
        tr[cur].push(parseEnd());
        tr[cur].push(parseEnd());
        parseijk("RPARENT", 'j');
        tr[cur].push(parseBlock());
        return cur;
    }
    int parseFuncDef() {
        tr[++nodecnt]=Parser_unit(0, "FuncDef");
        int cur = nodecnt;
        tr[cur].push(parseFuncType());
        tr[cur].push(parseEnd());
        tr[cur].push(parseEnd());
        if (peek().tk == "INTTK" || peek().tk == "CHARTK") {
            tr[cur].push(parseFuncFParams());
        }
        parseijk("RPARENT", 'j');
        tr[cur].push(parseBlock());
        return cur;
    }
    int parseInitVal() {
        tr[++nodecnt]=Parser_unit(0, "InitVal");
        int cur = nodecnt;
        if (peek().tk == "LBRACE") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseExp());
            while (peek().tk == "COMMA") {
                tr[cur].push(parseEnd());
                tr[cur].push(parseExp());
            }
            tr[cur].push(parseEnd());
        } else if (peek().tk == "STRCON") {
            tr[cur].push(parseEnd());
        } else
            tr[cur].push(parseExp());
        return cur;
    }
    int parseVarDef() {
        tr[++nodecnt]=Parser_unit(0, "VarDef");
        int cur = nodecnt;
        tr[cur].push(parseEnd());
        if (peek().tk == "LBRACK") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseConstExp());
            parseijk("RBRACK", 'k');
        }
        if (peek().tk == "ASSIGN") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseInitVal());
        }
        return cur;
    }
    int parseVarDecl() {
        tr[++nodecnt]=Parser_unit(0, "VarDecl");
        int cur = nodecnt;
        tr[cur].push(parseBType());
        tr[cur].push(parseVarDef());
        while (peek().tk == "COMMA") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseVarDef());
        }
        parseijk("SEMICN", 'i');
        return cur;
    }
    int parseConstInitVal() {
        tr[++nodecnt]=Parser_unit(0, "ConstInitVal");
        int cur = nodecnt;
        if (peek().tk == "LBRACE") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseConstExp());
            while (peek().tk == "COMMA") {
                tr[cur].push(parseEnd());
                tr[cur].push(parseConstExp());
            }
            tr[cur].push(parseEnd());
        } else if (peek().tk == "STRCON") {
            tr[cur].push(parseEnd());
        } else
            tr[cur].push(parseConstExp());
        return cur;
    }
    int parseConstDef() {
        tr[++nodecnt]=Parser_unit(0, "ConstDef");
        int cur = nodecnt;
        tr[cur].push(parseEnd());
        if (peek().tk == "LBRACK") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseConstExp());
            parseijk("RBRACK", 'k');
        }
        tr[cur].push(parseEnd());
        tr[cur].push(parseConstInitVal());
        return cur;
    }
    int parseBType() {
        tr[++nodecnt]=Parser_unit(0, "BType");
        int cur = nodecnt;
        if (peek().tk == "INTTK") {
            tr[cur].set_way(0);
        } else
            tr[cur].set_way(1);
        tr[cur].push(parseEnd());
        return cur;
    }
    int parseConstDecl() {
        tr[++nodecnt]=Parser_unit(0, "ConstDecl");
        int cur = nodecnt;
        tr[cur].push(parseEnd());
        tr[cur].push(parseBType());
        tr[cur].push(parseConstDef());
        while (peek().tk == "COMMA") {
            tr[cur].push(parseEnd());
            tr[cur].push(parseConstDef());
        }
        parseijk("SEMICN", 'i');
        return cur;
    }
    int parseDecl() {
        tr[++nodecnt]=Parser_unit(0, "Decl");
        int cur = nodecnt;
        if (peek().tk == "CONSTTK") {
            tr[cur].set_way(0);
            tr[cur].push(parseConstDecl());
        } else {
            tr[cur].set_way(1);
            tr[cur].push(parseVarDecl());
        }
        return cur;
    }
    int parseCompUnit() {
        tr[++nodecnt]=Parser_unit(0, "CompUnit");
        int cur = nodecnt;
        while (peek_peek_peek().tk != "LPARENT") {
            tr[cur].push(parseDecl());
        }
        while (peek_peek().tk != "MAINTK") {
            tr[cur].push(parseFuncDef());
        }
        int u=parseMainFuncDef();
        tr[cur].push(u);
        return cur;
    }

    ofstream parser_file("parser.txt");
    ofstream error_file("error.txt");
    void print_tree(int cur){
        set<string>do_not_output({"BlockItem", "Decl", "BType"});
        if(tr[cur].is_end){
            parser_file << tr[cur].name << " " << tr[cur].txt << "\n";
            if(tr[cur].ecode)
                error_file << tr[cur].row_cnt << " " << tr[cur].ecode << "\n";
        }
        else{
            for(int ne:tr[cur].son){
                print_tree(ne);
            }
            if(do_not_output.count(tr[cur].name)==0)
                parser_file<<"<"<<tr[cur].name<<">\n";
        }
    }
    void main(/*vector<Parser_unit> &Parser*/) {
        nodecnt=0;
        int rt = parseCompUnit();
        print_tree(rt);
    }
}  // namespace PARSER

int main() {
    LEXER::lexer_init();
    PARSER::main();
    return 0;
}
