package frontend;

import java.util.HashMap;
import java.util.Map;

public class Lexer {
    private String source;
    private int curPos;
    private String token;
    private String tokenType;
    private Map<String, String> reservedWords;
    private int lineNum;
    private String number;

    public Lexer(String source) {
        this.source = source;
        this.curPos = 0;
        this.token = "";
        this.tokenType = "";
        this.lineNum = 1;
        this.reservedWords = new HashMap<>();
        this.initReservedWords();
    }

    public String getToken() {
        return token;
    }

    public String getTokenType() {
        return tokenType;
    }

    //识别下一个token
    public int next() {
        token = "";

        skipWhiteSpace();

        if (curPos >= source.length()) {
            return -1;
        }

        char c = source.charAt(curPos);

        //标识符或保留字
        if (isNonDigit(c)) {
            token += c;
            curPos++;
            while (curPos < source.length() && (isNonDigit(source.charAt(curPos)) || Character.isDigit(source.charAt(curPos)))) {
                token += source.charAt(curPos);
                curPos++;
            }
            reserve();
            return 0;
        }

        //无符号整数
        else if (Character.isDigit(c)) {
            token += c;
            curPos++;
            while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                token += source.charAt(curPos);
                curPos++;
            }
            tokenType = "INTCON";
            number = token;
            return 0;
        }

        //注释或除号
        else if (c == '/') {
            curPos++;

            //单行注释
            if (curPos < source.length() && source.charAt(curPos) == '/') {
                curPos++;
                while (curPos < source.length() && source.charAt(curPos) != '\n') {
                    curPos++;
                }
                return next();
            }

            //多行注释
            else if (curPos < source.length() && source.charAt(curPos) == '*') {
                curPos++;
                while (curPos < source.length() && !(source.charAt(curPos) == '*' && curPos + 1 < source.length() && source.charAt(curPos + 1) == '/')) {
                    if (source.charAt(curPos) == '\n') {
                        lineNum++;
                    }
                    curPos++;
                }
                curPos += 2;
                return next();
            }

            //除号
            else {
                token = "/";
                tokenType = "DIV";
                return 0;
            }
        }

        //字符常量
        else if (c == '\'') {
            token += c;
            curPos++;
            while (curPos < source.length() && source.charAt(curPos) != '\'') {
                token += source.charAt(curPos);
                curPos++;
            }
            token += source.charAt(curPos);
            tokenType = "CHRCON";
            number = token;
            curPos++;
            return 0;
        }

        //字符串常量
        else if (c == '\"') {
            token += c;
            curPos++;
            while (curPos < source.length() && source.charAt(curPos) != '\"') {
                token += source.charAt(curPos);
                curPos++;
            }
            token += source.charAt(curPos);
            tokenType = "STRCON";
            number = token;
            curPos++;
            return 0;
        }

        //其他
        else {
            switch (c) {
                case '+':
                    token = "+";
                    tokenType = "PLUS";
                    break;
                case '-':
                    token = "-";
                    tokenType = "MINU";
                    break;
                case '*':
                    token = "*";
                    tokenType = "MULT";
                    break;
                case '%':
                    token = "%";
                    tokenType = "MOD";
                    break;
                case '<':
                    if (curPos + 1 < source.length() && source.charAt(curPos + 1) == '=') {
                        token = "<=";
                        tokenType = "LEQ";
                        curPos++;
                    } else {
                        token = "<";
                        tokenType = "LSS";
                    }
                    break;
                case '>':
                    if (curPos + 1 < source.length() && source.charAt(curPos + 1) == '=') {
                        token = ">=";
                        tokenType = "GEQ";
                        curPos++;
                    } else {
                        token = ">";
                        tokenType = "GRE";
                    }
                    break;
                case '=':
                    if (curPos + 1 < source.length() && source.charAt(curPos + 1) == '=') {
                        token = "==";
                        tokenType = "EQL";
                        curPos++;
                    } else {
                        token = "=";
                        tokenType = "ASSIGN";
                    }
                    break;
                case '!':
                    if (curPos + 1 < source.length() && source.charAt(curPos + 1) == '=') {
                        token = "!=";
                        tokenType = "NEQ";
                        curPos++;
                    } else {
                        token = "!";
                        tokenType = "NOT";
                    }
                    break;
                case '&':
                    if (curPos + 1 < source.length() && source.charAt(curPos + 1) == '&') {
                        token = "&&";
                        tokenType = "AND";
                        curPos++;
                    } else {
                        curPos++;
                        return 1;
                    }
                    break;
                case '|':
                    if (curPos + 1 < source.length() && source.charAt(curPos + 1) == '|') {
                        token = "||";
                        tokenType = "OR";
                        curPos++;
                    } else {
                        curPos++;
                        return 1;
                    }
                    break;
                case ';':
                    token = ";";
                    tokenType = "SEMICN";
                    break;
                case ',':
                    token = ",";
                    tokenType = "COMMA";
                    break;
                case '(':
                    token = "(";
                    tokenType = "LPARENT";
                    break;
                case ')':
                    token = ")";
                    tokenType = "RPARENT";
                    break;
                case '[':
                    token = "[";
                    tokenType = "LBRACK";
                    break;
                case ']':
                    token = "]";
                    tokenType = "RBRACK";
                    break;
                case '{':
                    token = "{";
                    tokenType = "LBRACE";
                    break;
                case '}':
                    token = "}";
                    tokenType = "RBRACE";
                    break;
                default:
                    curPos++;
                    return 1;
            }
            curPos++;
        }

        return 0;
    }

    //获取tokenType
    private void reserve() {
        if (reservedWords.containsKey(token)) {
            tokenType = reservedWords.get(token);
        } else if (Character.isDigit(token.charAt(0))) {
            tokenType = "INTCON";
            number = token;
        } else if (token.charAt(0) == '\'') {
            tokenType = "CHRCON";
            number = token;
        } else if (token.charAt(0) == '\"') {
            tokenType = "STRCON";
            number = token;
        } else {
            tokenType = "IDENFR";
        }
    }

    //跳过空白字符
    private void skipWhiteSpace() {
        while (curPos < source.length() && Character.isWhitespace(source.charAt(curPos))) {
            if (source.charAt(curPos) == '\n') {
                lineNum++;
            }
            curPos++;
        }
    }

    //判断是否为非数字字符
    private boolean isNonDigit(char c) {
        return c == '_' || Character.isLetter(c);
    }

    private void initReservedWords() {
        reservedWords.put("main", "MAINTK");
        reservedWords.put("const", "CONSTTK");
        reservedWords.put("int", "INTTK");
        reservedWords.put("char", "CHARTK");
        reservedWords.put("break", "BREAKTK");
        reservedWords.put("continue", "CONTINUETK");
        reservedWords.put("if", "IFTK");
        reservedWords.put("else", "ELSETK");
        reservedWords.put("!", "NOT");
        reservedWords.put("&&", "AND");
        reservedWords.put("||", "OR");
        reservedWords.put("for", "FORTK");
        reservedWords.put("getint", "GETINTTK");
        reservedWords.put("getchar", "GETCHARTK");
        reservedWords.put("printf", "PRINTFTK");
        reservedWords.put("return", "RETURNTK");
        reservedWords.put("+", "PLUS");
        reservedWords.put("-", "MINU");
        reservedWords.put("void", "VOIDTK");
        reservedWords.put("*", "MULT");
        reservedWords.put("/", "DIV");
        reservedWords.put("%", "MOD");
        reservedWords.put("<", "LSS");
        reservedWords.put("<=", "LEQ");
        reservedWords.put(">", "GRE");
        reservedWords.put(">=", "GEQ");
        reservedWords.put("==", "EQL");
        reservedWords.put("!=", "NEQ");
        reservedWords.put("=", "ASSIGN");
        reservedWords.put(";", "SEMICN");
        reservedWords.put(",", "COMMA");
        reservedWords.put("(", "LPARENT");
        reservedWords.put(")", "RPARENT");
        reservedWords.put("[", "LBRACK");
        reservedWords.put("]", "RBRACK");
        reservedWords.put("{", "LBRACE");
        reservedWords.put("}", "RBRACE");
    }
}
