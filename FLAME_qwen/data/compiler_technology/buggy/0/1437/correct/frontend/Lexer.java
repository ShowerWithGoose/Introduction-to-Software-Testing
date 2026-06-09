package frontend;

import error.Error;
import error.ErrorList;
import error.ErrorType;
import symbol.SymType;
import symbol.Symbol;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Lexer {
    public static Lexer getInstance() {
        return new Lexer();
    }

    public static List<Symbol> symList = new ArrayList<>();

    public static String getSymList() {
        StringBuilder str = new StringBuilder();
        for (Symbol symbol : symList) {
            str.append(symbol.toString());
        }
        return str.toString();
    }

    private final HashMap<String, SymType> keywords = new HashMap<>() {
        {
            put("main", SymType.MAINTK);
            put("const", SymType.CONSTTK);
            put("int", SymType.INTTK);
            put("char", SymType.CHARTK);
            put("break", SymType.BREAKTK);
            put("continue", SymType.CONTINUETK);
            put("if", SymType.IFTK);
            put("else", SymType.ELSETK);
            put("for", SymType.FORTK);
            put("getint", SymType.GETINTTK);
            put("getchar", SymType.GETCHARTK);
            put("printf", SymType.PRINTFTK);
            put("return", SymType.RETURNTK);
            put("void", SymType.VOIDTK);
        }
    };

    /**
     * 词法分析程序
     * @param text 源程序的内容
     */
    public void getsym(String text) {
        int line = 1;                                   // 记录行数
        int len = text.length();                        // 源程序长度

        for (int i = 0; i < len; i++) {
            char c = text.charAt(i);
            char nextc = i + 1 < len ? text.charAt(i + 1) : '\0';
            StringBuilder str = new StringBuilder();

            if (c == ' ' || c == '\t' || c == '\n') {
                /* whitespace */
                if (c == '\n')  line++;
            } else if (Character.isLetter(c) || c == '_') {
                /* keyword or identifier */
                for (int j = i; j < len; j++) {
                    char cc = text.charAt(j);
                    if (Character.isLetter(cc) || Character.isDigit(cc) || cc == '_') {
                        str.append(cc);
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                symList.add(new Symbol(keywords.getOrDefault(str.toString(), SymType.IDENFR), str.toString()));
            } else if (Character.isDigit(c)) {
                /* integer */
                for (int j = i; j < len; j++) {
                    char cc = text.charAt(j);
                    if (Character.isDigit(cc)) {
                        str.append(cc);
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                symList.add(new Symbol(SymType.INTCON, str.toString()));
            } else if (c == '\"') {
                /* string todo: check */
                str.append(c);
                for (int j = i + 1; j < len; j++) {
                    char cc = text.charAt(j);
                    if (cc == '\\') {
                        j++;
                        str.append("\\").append(text.charAt(j));
                    } else if (cc != '\"') {
                        str.append(cc);
                    } else {
                        i = j;
                        str.append("\"");
                        break;
                    }
                }
                symList.add(new Symbol(SymType.STRCON, str.toString()));
            } else if (c == '\'') {
                /* char todo: check */
                str.append(c);
                if (nextc == '\\') {
                    i += 2;
                    char cc = text.charAt(i);
                    str.append("\\").append(cc);
                } else {
                    i++;
                    str.append(nextc);
                }
                str.append('\'');
                i++;
                symList.add(new Symbol(SymType.CHRCON, str.toString()));
            } else if (c == '!') {
                /* ! or != */
                str.append(c);
                if (nextc == '=') {
                    str.append(nextc);
                    i++;
                    symList.add(new Symbol(SymType.NEQ, "!="));
                } else {
                    symList.add(new Symbol(SymType.NOT, "!"));
                }
            } else if (c == '&') {
                /* && */
                str.append(c);
                if (nextc == '&') {
                    str.append(nextc);
                    i++;
                    symList.add(new Symbol(SymType.AND, "&&"));
                } else {
                    ErrorList.addError(new Error(line, ErrorType.a));
                }
            } else if (c == '|') {
                /* || */
                str.append(c);
                if (nextc == '|') {
                    str.append(nextc);
                    i++;
                    symList.add(new Symbol(SymType.OR, "||"));
                } else {
                    ErrorList.addError(new Error(line, ErrorType.a));
                }
            } else if (c == '+') symList.add(new Symbol(SymType.PLUS, "+"));
            else if (c == '-') symList.add(new Symbol(SymType.MINU, "-"));
            else if (c == '*') symList.add(new Symbol(SymType.MULT, "*"));
            else if (c == '/') {
                /* / or /* or // */
                if (nextc == '/') {
                    for (int j = i + 1; j < len; j++) {
                        char cc = text.charAt(j);
                        if (cc =='\n') {
                            i = j - 1;
                            break;
                        }
                    }
                } else if (nextc == '*') {
                    for (int j = i + 2; j < len; j++) {
                        char cc = text.charAt(j);
                        if (cc =='\n')  line++;
                        else if (cc == '*' && text.charAt(j + 1) == '/') {
                            i = j + 1;
                            break;
                        }
                    }
                } else {
                    symList.add(new Symbol(SymType.DIV, "/"));
                }
            } else if (c == '%') symList.add(new Symbol(SymType.MOD, "%"));
            else if (c == '<') {
                /* < or <= */
                if (nextc == '=') {
                    i++;
                    symList.add(new Symbol(SymType.LEQ, "<="));
                } else {
                    symList.add(new Symbol(SymType.LSS, "<"));
                }
            } else if (c == '>') {
                /* > or >= */
                if (nextc == '=') {
                    i++;
                    symList.add(new Symbol(SymType.GEQ, ">="));
                } else {
                    symList.add(new Symbol(SymType.GRE, ">"));
                }
            } else if (c == '=') {
                /* = or == */
                if (nextc == '=') {
                    i++;
                    symList.add(new Symbol(SymType.EQL, "=="));
                } else {
                    symList.add(new Symbol(SymType.ASSIGN, "="));
                }
            } else if (c == ';') symList.add(new Symbol(SymType.SEMICN, ";"));
            else if (c == ',') symList.add(new Symbol(SymType.COMMA, ","));
            else if (c == '(') symList.add(new Symbol(SymType.LPARENT, "("));
            else if (c == ')') symList.add(new Symbol(SymType.RPARENT, ")"));
            else if (c == '[') symList.add(new Symbol(SymType.LBRACK, "["));
            else if (c == ']') symList.add(new Symbol(SymType.RBRACK, "]"));
            else if (c == '{') symList.add(new Symbol(SymType.LBRACE, "{"));
            else if (c == '}') symList.add(new Symbol(SymType.RBRACE, "}"));
        }

    }

}
