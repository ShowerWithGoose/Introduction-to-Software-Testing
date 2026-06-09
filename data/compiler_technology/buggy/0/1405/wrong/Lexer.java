public class Lexer {
    private String token; // 解析到的单词
    private int lexType; // 类别码
    private int number; // 单词值（无符号整数的值）
    private char errorType; // 错误类型

    private String[] types = {
            "IDENFR", "INTCON", "STRCON", "CHRCON", "MAINTK", "CONSTTK", "INTTK", "CHARTK", "BREAKTK",
            "CONTINUETK", "IFTK", "ELSETK", "NOT", "AND", "OR", "FORTK", "GETINTTK", "GETCHARTK", "PRINTFTK",
            "RETURNTK", "PLUS", "MINU", "VOIDTK", "MULT", "DIV", "MOD", "LSS", "LEQ", "GRE", "GEQ", "EQL",
            "NEQ", "ASSIGN", "SEMICN", "COMMA", "LPARENT", "RPARENT", "LBRACK", "RBRACK", "LBRACE", "RBRACE"
    };

    private boolean flagForSingleAnno;
    private boolean flagForCrossAnno;
    private boolean flagForError;

    public int next(String source, int pos) {
        int curPos = pos;
        while (curPos < source.length() && (source.charAt(curPos) == ' ' || source.charAt(curPos) == '\t')) curPos++;

        if (curPos >= source.length()) return curPos;

        char ch = source.charAt(curPos++);
        token = "";

        if (isNotDigit(ch)) { // 标识符 或者 保留字
            token += ch;
            while (curPos < source.length() && (isNotDigit(source.charAt(curPos)) || isDigit(source.charAt(curPos)))) {
                ch = source.charAt(curPos++);
                token += ch;
            }
            setType();

        } else if (isDigit(ch)) { // 无符号整数
            token += ch;
            while (curPos < source.length() && isDigit(source.charAt(curPos))) {
                ch = source.charAt(curPos++);
                token += ch;
            }
            lexType = 1;
            //number = transferToNum(token);

        } else if (ch == '"') { // 字符串
            token += ch;
            while (curPos < source.length()) {
                ch = source.charAt(curPos++);
                if (ch != '"') token += ch;
                else break;
            }
            token += ch;
            lexType = 2;

        } else if (ch == '\'') { // 字符
            token += ch;
            if (source.charAt(curPos) == '\\') {
                token += source.charAt(curPos++);
                token += source.charAt(curPos++);
                token += source.charAt(curPos++);
            } else {
                token += source.charAt(curPos++);
                token += source.charAt(curPos++);
            }

            lexType = 3;

        } else {
            token += ch;
            if (curPos >= source.length()) {
                setType();
            } else {
                char nextCh = source.charAt(curPos);
                if ((ch == '&' && nextCh != '&') || (ch == '|' && nextCh != '|')) {
                    errorType = 'a';
                    flagForError = true;
                    curPos++;
                }

                if (ch == '/' && nextCh == '/') {
                    flagForSingleAnno = true;
                    return source.length();
                } else if (ch == '/' && nextCh == '*') {
                    flagForCrossAnno = true;
                    return curPos;
                } else if ((ch == '|' && nextCh == '|') || (ch == '&' && nextCh == '&') ||
                        (ch == '<' && nextCh == '=') || (ch == '>' && nextCh == '=') ||
                        (ch == '=' && nextCh == '=') || (ch == '!' && nextCh == '=')) {
                    curPos++;
                    token += nextCh;
                    setType();
                } else {
                    setType();
                }
            }
        }
        return curPos;
    }

    public String getToken() {
        return token;
    }

    public String getLexType() {
        return types[lexType];
    }

    public char getErrorType() {
        return errorType;
    }

    public boolean isNotDigit(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
    }

    public boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    public void setType() {
        switch (token) {
            case "main":
                lexType = 4; break;
            case "const":
                lexType = 5; break;
            case "int":
                lexType = 6; break;
            case "char":
                lexType = 7; break;
            case "break":
                lexType = 8; break;
            case "continue":
                lexType = 9; break;
            case "if":
                lexType = 10; break;
            case "else":
                lexType = 11; break;
            case "!":
                lexType = 12; break;
            case "&&":
                lexType = 13; break;
            case "||":
                lexType = 14; break;
            case "for":
                lexType = 15; break;
            case "getint":
                lexType = 16; break;
            case "getchar":
                lexType = 17; break;
            case "printf":
                lexType = 18; break;
            case "return":
                lexType = 19; break;
            case "+":
                lexType = 20; break;
            case "-":
                lexType = 21; break;
            case "void":
                lexType = 22; break;
            case "*":
                lexType = 23; break;
            case "/":
                lexType = 24; break;
            case "%":
                lexType = 25; break;
            case "<":
                lexType = 26; break;
            case "<=":
                lexType = 27; break;
            case ">":
                lexType = 28; break;
            case ">=":
                lexType = 29; break;
            case "==":
                lexType = 30; break;
            case "!=":
                lexType = 31; break;
            case "=":
                lexType = 32; break;
            case ";":
                lexType = 33; break;
            case ",":
                lexType = 34; break;
            case "(":
                lexType = 35; break;
            case ")":
                lexType = 36; break;
            case "[":
                lexType = 37; break;
            case "]":
                lexType = 38; break;
            case "{":
                lexType = 39; break;
            case "}":
                lexType = 40; break;
            default:
                lexType = 0;
        }
    }

    public boolean getFlagForSingleAnno() {
        return flagForSingleAnno;
    }

    public void setFlagForSingleAnno(boolean flagForSingleAnno) {
        this.flagForSingleAnno = flagForSingleAnno;
    }

    public int transferToNum(String str) {
        return Integer.parseInt(str);
    }

    public boolean getFlagForCrossAnno() {
        return flagForCrossAnno;
    }

    public void setFlagForCrossAnno(boolean flagForCrossAnno) {
        this.flagForCrossAnno = flagForCrossAnno;
    }

    public boolean getFlagForError() {
        return flagForError;
    }

    public void setFlagForError(boolean flagForError) {
        this.flagForError = flagForError;
    }

    public int getNumber() {
        return number;
    }
}