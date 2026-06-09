package frontend.lexer;

import error.ErrorHandling;

public class Lexer {
    private TokenList tokenList;
    private String sourceFile;
    private int pos;
    private String curToken;
    private LexType curTokenType;
    private int curLineNum;
    private int errorNum;

    public Lexer(String sourceFile) {
        this.tokenList = new TokenList();
        this.sourceFile = sourceFile;
        this.pos = 0;
        this.curToken = "";
        this.curLineNum = 1;
        this.errorNum = 0;
    }

    public TokenList getAllTokens() {
        while(next()) {
            Token token = new Token(curTokenType, curToken, curLineNum);
            tokenList.addToken(token);
        }
        return tokenList;
    }

    public int getErrorNum() { return errorNum; }

    public boolean next() {
        if (pos >= sourceFile.length()) {
            return false;
        }
        curToken = "";
        char c = sourceFile.charAt(pos);

        //跳过空白符
        while(pos < sourceFile.length() && (c == ' ' || c == '\n' || c == '\t')) {
            if (c == '\n') {
                curLineNum++;
            }
            c = getNextChar();
        }
        if (pos == sourceFile.length()) {
            return false;
        }

        //跳过单行多行注释（顺便处理除号情况）
        if (c == '/') { //处理注释和除
            curToken += c;
            c = getNextChar();
            if (pos < sourceFile.length() && c == '/') { //单行注释
                curToken += c;
                c = getNextChar();
                while(pos < sourceFile.length() && c != '\n') {
                    c = getNextChar();
                }
                if(pos < sourceFile.length()) {
                    curLineNum++;
                    pos++;
                }
                return this.next(); //重新开始读下一个词
            } else if (pos < sourceFile.length() && c == '*') { //多行注释
                curToken += c;
                c = getNextChar();
                while(pos < sourceFile.length()) {
                    while (pos < sourceFile.length() && c != '*') {
                        if (c == '\n') {
                            curLineNum++;
                        }
                        c = getNextChar();
                    }
                    //检测到/**
                    while (pos < sourceFile.length() && c == '*') {
                        c = getNextChar();
                    }
                    if (pos < sourceFile.length() && c == '/') { //检测到/****/
                        pos++;
                        return this.next(); //重新开始读下一个词
                    } //否则的话非*非/重新开始循环
                }
                return false; //impossible
            } else { //单独的除号
                this.curTokenType = LexType.DIV;
                return true;
            }
        }

        //正常处理
        if (this.isNonDigit(c)) { //标识符或保留字
            curToken += c;
            c = getNextChar();
            while(pos < sourceFile.length() && (this.isNonDigit(c) || Character.isDigit(c))) {
                curToken += c;
                c = getNextChar();
            }
            this.reserve(); //查关键字表
            return true;
        } else if (Character.isDigit(c)) { //无符号整数
            curToken += c;
            c = getNextChar();
            while(pos < sourceFile.length() && Character.isDigit(c)) {
                curToken += c;
                c = getNextChar();
            }
            this.curTokenType = LexType.INTCON;
            return true;
        } else if (c == '\'') { //字符常量,curToken存储有单引号,不考虑end of file
            curToken += c;
            c = getNextChar();
            curToken += c;
            if (c == '\\') { //转义字符比普通字符多一位
                c = getNextChar();
                curToken += c;
            }
            c = getNextChar();
            curToken += c;
            pos = pos + 1; //跳过'且无需检验
            this.curTokenType = LexType.CHRCON;
            return true;
        } else if (c == '\"') { //字符串常量,curToken存储有双引号,不考虑end of file
            curToken += c;
            char prev = c; //区分转义符"和字符串终结符"
            c = getNextChar();
            while(pos < sourceFile.length() && (c != '\"' || prev == '\\')) {
                curToken += c;
                prev = c;
                c = getNextChar();
            }
            curToken += c;
            pos++; //跳过"
            this.curTokenType = LexType.STRCON;
            return true;
        } else if (c == '*') { //单独乘号
            curToken += c;
            pos++;
            curTokenType = LexType.MULT;
            return true;
        } else if (c == '!') { // !=和!
            curToken += c;
            c = getNextChar();
            if (pos < sourceFile.length() && c == '=') { // !=
                curToken += c;
                pos++;
                this.curTokenType = LexType.NEQ;
            } else { // !
                this.curTokenType = LexType.NOT;
            }
            return true;
        } else if (c == '<') { // <=和<
            curToken += c;
            c = getNextChar();
            if (pos < sourceFile.length() && c == '=') {
                curToken += c;
                pos++;
                this.curTokenType = LexType.LEQ;
            } else {
                this.curTokenType = LexType.LSS;
            }
            return true;
        } else if (c == '>') { // >=和>
            curToken += c;
            c = getNextChar();
            if (pos < sourceFile.length() && c == '=') {
                curToken += c;
                pos++;
                this.curTokenType = LexType.GEQ;
            } else {
                this.curTokenType = LexType.GRE;
            }
            return true;
        } else if (c == '=') { // ==和=
            curToken += c;
            c = getNextChar();
            if (pos < sourceFile.length() && c == '=') {
                curToken += c;
                pos++;
                this.curTokenType = LexType.EQL;
            } else {
                this.curTokenType = LexType.ASSIGN;
            }
            return true;
        } else if (c == '+') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.PLUS;
            return true;
        } else if (c == '-') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.MINU;
            return true;
        } else if (c == '%') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.MOD;
            return true;
        } else if (c == ';') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.SEMICN;
            return true;
        } else if (c == ',') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.COMMA;
            return true;
        } else if (c == '(') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.LPARENT;
            return true;
        } else if (c == ')') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.RPARENT;
            return true;
        } else if (c == '[') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.LBRACK;
            return true;
        } else if (c == ']') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.RBRACK;
            return true;
        } else if (c == '{') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.LBRACE;
            return true;
        } else if (c == '}') {
            curToken += c;
            pos++;
            this.curTokenType = LexType.RBRACE;
            return true;
        } else if (c == '&') { //&(end of file)也算词法错误
            curToken += c;
            c = getNextChar();
            if (c == '&') {
                curToken += c;
                pos++;
                this.curTokenType = LexType.AND;
                return true;
            } else {
                errorNum++;
                ErrorHandling.printError(curLineNum, 'a');
                curToken += '&'; //词法错误自动修正，继续词法分析
                this.curTokenType = LexType.AND;
                return true;
            }
        } else if (c == '|') { //|(end of file)也算词法错误
            curToken += c;
            c = getNextChar();
            if (c == '|') {
                curToken += c;
                pos++;
                this.curTokenType = LexType.OR;
                return true;
            } else {
                errorNum++;
                ErrorHandling.printError(curLineNum, 'a');
                curToken += '|'; //词法错误自动修正，继续词法分析
                this.curTokenType = LexType.OR;
                return true;
            }
        } else {
            return false; //impossible
        }
    }

    private char getNextChar() {
        pos++;
        if (pos < sourceFile.length()) {
            return sourceFile.charAt(pos);
        } else {
            return 0; //end of file
        }
    }

    private boolean isNonDigit(char c) { //字母或下划线
        if (Character.isLetter(c) || c == '_') {
            return true;
        } else {
            return false;
        }
    }

    private void reserve() { //标识符 or 保留字
        if (curToken.equals("main")) {
            curTokenType = LexType.MAINTK;
        } else if (curToken.equals("const")) {
            curTokenType = LexType.CONSTTK;
        } else if (curToken.equals("int")) {
            curTokenType = LexType.INTTK;
        } else if (curToken.equals("char")) {
            curTokenType = LexType.CHARTK;
        } else if (curToken.equals("break")) {
            curTokenType = LexType.BREAKTK;
        } else if (curToken.equals("continue")) {
            curTokenType = LexType.CONTINUETK;
        } else if (curToken.equals("if")) {
            curTokenType = LexType.IFTK;
        } else if (curToken.equals("else")) {
            curTokenType = LexType.ELSETK;
        } else if (curToken.equals("for")) {
            curTokenType = LexType.FORTK;
        } else if (curToken.equals("getint")) {
            curTokenType = LexType.GETINTTK;
        } else if (curToken.equals("getchar")) {
            curTokenType = LexType.GETCHARTK;
        } else if (curToken.equals("printf")) {
            curTokenType = LexType.PRINTFTK;
        } else if (curToken.equals("return")) {
            curTokenType = LexType.RETURNTK;
        } else if (curToken.equals("void")) {
            curTokenType = LexType.VOIDTK;
        } else {
            curTokenType = LexType.IDENFR; //标识符
        }
    }
}
