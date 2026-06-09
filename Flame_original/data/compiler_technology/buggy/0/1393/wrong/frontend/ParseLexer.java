package frontend;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

import static frontend.LexerType.*;

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
        categoryMap.put("main", MAINTK);
        categoryMap.put("const", CONSTTK);
        categoryMap.put("int", INTTK);
        categoryMap.put("char", CHARTK);
        categoryMap.put("break", BREAKTK);
        categoryMap.put("continue", CONTINUETK);
        categoryMap.put("if", IFTK);
        categoryMap.put("else", ELSETK);
        categoryMap.put("!", NOT);
        categoryMap.put("&&", AND);
        categoryMap.put("||", OR);
        categoryMap.put("for", FORTK);
        categoryMap.put("getint", GETINTTK);
        categoryMap.put("getchar", GETCHARTK);
        categoryMap.put("printf", PRINTFTK);
        categoryMap.put("return", RETURNTK);
        categoryMap.put("+", PLUS);
        categoryMap.put("-", MINU);
        categoryMap.put("void", VOIDTK);
        categoryMap.put("*", MULT);
        categoryMap.put("/", DIV);
        categoryMap.put("%", MOD);
        categoryMap.put("<", LSS);
        categoryMap.put("<=", LEQ);
        categoryMap.put(">", GRE);
        categoryMap.put(">=", GEQ);
        categoryMap.put("==", EQL);
        categoryMap.put("!=", NEQ);
        categoryMap.put("=", ASSIGN);
        categoryMap.put(";", SEMICN);
        categoryMap.put(",", COMMA);
        categoryMap.put("(", LPARENT);
        categoryMap.put(")", RPARENT);
        categoryMap.put("[", LBRACK);
        categoryMap.put("]", RBRACK);
        categoryMap.put("{", LBRACE);
        categoryMap.put("}", RBRACE);
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
                    return new Lexer("|", OR, 'a', line);
                } else {
                    location += 2;
                    return new Lexer("||", OR, '0', line);
                }
            } else if (c == '&') {
                if (str.charAt(location + 1) != '&') {
                    location += 1;
                    return new Lexer("&", AND, 'a', line);
                } else {
                    location += 2;
                    return new Lexer("&&", AND, '0', line);
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

    public void removeSpaceAndExplanatory() {
        int len = str.length();
        if (str.charAt(location) == ' ' || str.charAt(location) == '\n') {
            while (str.charAt(location) == ' ' || str.charAt(location) == '\n') {
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

    public Lexer getIntConst() {
        StringBuilder res = new StringBuilder();
        while ('0' <= str.charAt(location) && str.charAt(location) <= '9') {
            res.append(str.charAt(location));
            location++;
            if (location == str.length()) {
                break;
            }
        }
        return new Lexer(res.toString(), INTCON, '0', line);
    }

    public Lexer getStringConst() {
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
        return new Lexer(res.toString(), STRCON, '0', line);
    }

    public Lexer getCharConst() {
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
        return new Lexer(res.toString(), CHRCON, '0', line);
    }

    public Lexer getIdentOrReserved() {
        StringBuilder res = new StringBuilder();
        while ('0' <= str.charAt(location) && str.charAt(location) <= '9' || isIdentifierAlpha(str.charAt(location))) {
            res.append(str.charAt(location));
            location++;
            if (location == str.length()) {
                break;
            }
        }
        return new Lexer(res.toString(), categoryMap.getOrDefault(res.toString(), IDENFR), '0', line);
    }//获取表示符和特定保留字(比如main)

    public boolean isIdentifierAlpha(char c) {
        return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || c == '_';
    }

    public boolean isSpace() {
        int len = str.length();
        if (location >= len) {
            return false;
        } else {
            char c = str.charAt(location);
            if (c == ' ' || c == '\n') {
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
