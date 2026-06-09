package frontend.LexerModule;

import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class ParseLexer {
    private final HashMap<String, LexerType> categoryMap = new HashMap<>();
    private String str;
    private int location;
    private int line;

    public ParseLexer() throws FileNotFoundException {
        FileInputStream fileIn = new FileInputStream("testfile.txt");
        System.setIn(fileIn);
        Scanner scanner = new Scanner(System.in);
        str = "";
        location = 0;
        line = 0;
        while (scanner.hasNext()) {
            String tem = scanner.nextLine();
            str = str + "\n" + tem;
        }
        categoryMap.put("main", LexerType.MAINTK);
        categoryMap.put("const", LexerType.CONSTTK);
        categoryMap.put("int", LexerType.INTTK);
        categoryMap.put("char", LexerType.CHARTK);
        categoryMap.put("break", LexerType.BREAKTK);
        categoryMap.put("continue", LexerType.CONTINUETK);
        categoryMap.put("if", LexerType.IFTK);
        categoryMap.put("else", LexerType.ELSETK);
        categoryMap.put("!", LexerType.NOT);
        categoryMap.put("&&", LexerType.AND);
        categoryMap.put("||", LexerType.OR);
        categoryMap.put("for", LexerType.FORTK);
        categoryMap.put("getint", LexerType.GETINTTK);
        categoryMap.put("getchar", LexerType.GETCHARTK);
        categoryMap.put("printf", LexerType.PRINTFTK);
        categoryMap.put("return", LexerType.RETURNTK);
        categoryMap.put("+", LexerType.PLUS);
        categoryMap.put("-", LexerType.MINU);
        categoryMap.put("void", LexerType.VOIDTK);
        categoryMap.put("*", LexerType.MULT);
        categoryMap.put("/", LexerType.DIV);
        categoryMap.put("%", LexerType.MOD);
        categoryMap.put("<", LexerType.LSS);
        categoryMap.put("<=", LexerType.LEQ);
        categoryMap.put(">", LexerType.GRE);
        categoryMap.put(">=", LexerType.GEQ);
        categoryMap.put("==", LexerType.EQL);
        categoryMap.put("!=", LexerType.NEQ);
        categoryMap.put("=", LexerType.ASSIGN);
        categoryMap.put(";", LexerType.SEMICN);
        categoryMap.put(",", LexerType.COMMA);
        categoryMap.put("(", LexerType.LPARENT);
        categoryMap.put(")", LexerType.RPARENT);
        categoryMap.put("[", LexerType.LBRACK);
        categoryMap.put("]", LexerType.RBRACK);
        categoryMap.put("{", LexerType.LBRACE);
        categoryMap.put("}", LexerType.RBRACE);
    }

    public Lexer getNextLexer() {
        while (isSpace()) {
            removeSpaceAndExplanatory();
        }
        if (location >= str.length()) {
            return null;
        }
        char c = str.charAt(location);
        if (c == '\"') {
            return getStringConst();
        } else if (c == '\'') {
            return getCharConst();
        } else if ('0' <= c && c <= '9') {
            return getIntConst();
        } else if (isIdentifierAlpha(c)) {
            return getIdentOrReserved();
        } else {
            if (c == '|') {
                if (str.charAt(location + 1) != '|') {
                    location += 1;
                    ErrorCollect.addErrorData(new ErrorData(line,'a'));
                    return new Lexer("|", LexerType.OR, 'a', line);
                } else {
                    location += 2;
                    return new Lexer("||", LexerType.OR, '0', line);
                }
            } else if (c == '&') {
                if (str.charAt(location + 1) != '&') {
                    location += 1;
                    ErrorCollect.addErrorData(new ErrorData(line,'a'));
                    return new Lexer("&", LexerType.AND, 'a', line);
                } else {
                    location += 2;
                    return new Lexer("&&", LexerType.AND, '0', line);
                }
            } else {
                StringBuilder sb = new StringBuilder();
                sb.append(c);
                if (location == str.length() - 1) {
                    location += 1;
                } else if (str.charAt(location + 1) == '=' && (c == '<' || c == '>' || c == '=' || c == '!')) {
                    sb.append(str.charAt(location + 1));
                    location += 2;
                } else {
                    location += 1;
                }
                String res = sb.toString();
                return new Lexer(res, categoryMap.get(res), '0', line);
            }
        }
    }

    private void removeSpaceAndExplanatory() {
        int len = str.length();
        if (str.charAt(location) == ' ' || str.charAt(location) == '\n' || str.charAt(location) == '\t') {
            while (str.charAt(location) == ' ' || str.charAt(location) == '\n' || str.charAt(location) == '\t') {
                if (str.charAt(location) == '\n') {
                    line++;
                }
                location++;
                if (location == len) {
                    break;
                }
            }
            return;
        }

        if (str.charAt(location) == '/' && str.charAt(location + 1) == '/') {
            while (str.charAt(location) != '\n') {
                location++;
                if (location == len) {
                    break;
                }
            }
            line++;
            location++;
        } else if (str.charAt(location) == '/' && str.charAt(location + 1) == '*') {
            while (!(str.charAt(location) == '*' && str.charAt(location + 1) == '/')) {
                location++;
                if (str.charAt(location) == '\n') {
                    line++;
                }
            }
            location += 2;
        }
    }//删除注释 同时维护行号

    private Lexer getIntConst() {
        StringBuilder res = new StringBuilder();
        while ('0' <= str.charAt(location) && str.charAt(location) <= '9') {
            res.append(str.charAt(location));
            location++;
            if (location == str.length()) {
                break;
            }
        }
        return new Lexer(res.toString(), LexerType.INTCON, '0', line);
    }

    private Lexer getStringConst() {
        location++;
        StringBuilder res = new StringBuilder();
        res.append('\"');
        while (str.charAt(location) != '\"') {
            res.append(str.charAt(location));
            location++;
            if (location == str.length()) {
                break;
            }
        } //这里location落在结尾引号处
        res.append('\"');
        location++;//现在location指向了下一个单词
        return new Lexer(res.toString(), LexerType.STRCON, '0', line);
    }

    private Lexer getCharConst() {
        location++;
        StringBuilder res = new StringBuilder();
        res.append('\'');
        if (str.charAt(location) == '\\') {
            res.append('\\').append(str.charAt(location + 1)).append('\'');
            location += 3;
        } else {
            res.append(str.charAt(location)).append('\'');
            location += 2;
        }//现在location指向了下一个单词
        return new Lexer(res.toString(), LexerType.CHRCON, '0', line);
    }

    private Lexer getIdentOrReserved() {
        StringBuilder res = new StringBuilder();
        while ('0' <= str.charAt(location) && str.charAt(location) <= '9' || isIdentifierAlpha(str.charAt(location))) {
            res.append(str.charAt(location));
            location++;
            if (location == str.length()) {
                break;
            }
        }
        return new Lexer(res.toString(), categoryMap.getOrDefault(res.toString(), LexerType.IDENFR), '0', line);
    }//获取表示符和特定保留字(比如main)

    private boolean isIdentifierAlpha(char c) {
        return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || c == '_';
    }

    private boolean isSpace() {
        int len = str.length();
        if (location >= len) {
            return false;
        } else {
            char c = str.charAt(location);
            if (c == ' ' || c == '\n' || c == '\t') {
                return true;
            } else {
                if (location == len - 1) {
                    return false;
                }
                char c1 = str.charAt(location + 1);
                return c == '/' && c1 == '/' || c == '/' && c1 == '*';
            }
        }
    }
}
