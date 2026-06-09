package LexParser;
import java.util.ArrayList;
import java.util.HashMap;

import IOcontrol.IO;
import Token.*;
import Config.Config;
// 词法分析器
public class Lexer {
    private ArrayList<Token> tokenList;
    private HashMap<String,TOKENTYPE> keywords;
    private HashMap<Integer,Character> errors;

    public Lexer(HashMap<Integer,Character> errors) {
        this.tokenList = new ArrayList<>();
        this.keywords = new HashMap<>();
        this.keywords.put("main",TOKENTYPE.MAINTK);
        this.keywords.put("const",TOKENTYPE.CONSTTK);
        this.keywords.put("int",TOKENTYPE.INTTK);
        this.keywords.put("char",TOKENTYPE.CHARTK);
        this.keywords.put("break",TOKENTYPE.BREAKTK);
        this.keywords.put("continue",TOKENTYPE.CONTINUETK);
        this.keywords.put("if",TOKENTYPE.IFTK);
        this.keywords.put("else",TOKENTYPE.ELSETK);
        this.keywords.put("for",TOKENTYPE.FORTK);
        this.keywords.put("getint",TOKENTYPE.GETINTTK);
        this.keywords.put("getchar",TOKENTYPE.GETCHARTK);
        this.keywords.put("printf",TOKENTYPE.PRINTFTK);
        this.keywords.put("return",TOKENTYPE.RETURNTK);
        this.keywords.put("void",TOKENTYPE.VOIDTK);
        //Lexer 和 Parser 共享同一个 errors 实例
        this.errors = errors;
    }

    public ArrayList<Token> getTokenList() {
        return tokenList;
    }

    public void parse(String content) {
        int lineNum = 1;
        for (int present = 0;present < content.length();present++) {
            char c = content.charAt(present);
            //1. 标识符 Ident and "...TK"
            if (Character.isLetter(c) || c == '_') {
                String ident = new String();
                for (int i = present;i < content.length();i++) {
                    char tmp = content.charAt(i);
                    if (Character.isLetter(tmp) || tmp == '_' || Character.isDigit(tmp)) {
                        ident += tmp;
                    }
                    else {
                        present = i - 1;
                        break;
                    }
                }
                if (keywords.containsKey(ident)) {
                    tokenList.add(new Token(ident, keywords.get(ident), lineNum));
                }
                else {
                    tokenList.add(new Token(ident, TOKENTYPE.IDENFR, lineNum));
                }
            }
            //2. 数值常量 IntConst
            else if (Character.isDigit(c)) {
                String intConst = new String();
                for (int i = present;i < content.length();i++) {
                    char tmp = content.charAt(i);
                    if (Character.isDigit(tmp)) {
                        intConst += tmp;
                    }
                    else {
                        present = i - 1;
                        break;
                    }
                }
                tokenList.add(new Token(intConst,TOKENTYPE.INTCON,lineNum));
            }
            //3. 字符串常量 StringConst
            else if (c == '\"') {
                String stringConst = new String();
                for (int i = present;i < content.length();i++) {
                    char tmp = content.charAt(i);
                    stringConst += tmp;
                    if (tmp == '\"' && i != present) {
                        if (content.charAt(i - 1) == '\\') {
                            stringConst += tmp;
                        }
                        else {
                            present = i;
                            break;
                        }
                    }
                }
                tokenList.add(new Token(stringConst,TOKENTYPE.STRCON,lineNum));
            }
            //4. 字符常量 CharConst
            else if (c == '\'') {
                String charConst = new String();
                for (int i = present;i < content.length();i++) {
                    char tmp = content.charAt(i);
                    if (tmp != '\'' || i == present) {
                        charConst += tmp;
                    }
                    else if (tmp == '\'' && content.charAt(i - 1) == '\\') {
                        charConst += tmp;
                    }
                    else {
                        charConst += tmp;
                        present = i;
                        break;
                    }
                }
                tokenList.add(new Token(charConst,TOKENTYPE.CHRCON,lineNum));
            }
            //5:other
            else if (c == '!') {
                if (content.charAt(present + 1) == '=') {
                    tokenList.add(new Token("!=",TOKENTYPE.NEQ,lineNum));
                    present++;
                }
                else {
                    tokenList.add(new Token("!",TOKENTYPE.NOT,lineNum));
                }
            }
            else if (c == '&') {
                tokenList.add(new Token("&&",TOKENTYPE.AND,lineNum));
                if (content.charAt(present + 1) == '&') {
                    present++;
                }
                else {
                    errors.put(lineNum,'a');
                }
            }
            else if (c == '|') {
                tokenList.add(new Token("||",TOKENTYPE.OR,lineNum));
                if (content.charAt(present + 1) == '|') {
                    present++;
                }
                else {
                    errors.put(lineNum,'a');
                }
            }
            else if (c == '<') {
                if (content.charAt(present + 1) == '=') {
                    tokenList.add(new Token("<=", TOKENTYPE.LEQ,lineNum));
                    present++;
                }
                else {
                    tokenList.add(new Token("<",TOKENTYPE.LSS,lineNum));
                }
            }
            else if (c == '>') {
                if (content.charAt(present + 1) == '=') {
                    tokenList.add(new Token(">=", TOKENTYPE.GEQ,lineNum));
                    present++;
                }
                else {
                    tokenList.add(new Token(">",TOKENTYPE.GRE,lineNum));
                }
            }
            else if (c == '=') {
                if (content.charAt(present + 1) == '=') {
                    tokenList.add(new Token("==", TOKENTYPE.EQL,lineNum));
                    present++;
                }
                else {
                    tokenList.add(new Token("=",TOKENTYPE.ASSIGN,lineNum));
                }
            }
            else if (c == '/') {
                if (content.charAt(present + 1) == '/') {
                    int j = present + 2;
                    while (content.charAt(j) != '\n' && j < content.length() - 1) {
                        j++;
                    }
                    if (j == content.length() - 1) {
                        break;
                    }
                    present = j - 1;
                }
                else if (content.charAt(present + 1) == '*') {
                    int j = present + 2;
                    while (!(content.charAt(j - 1) == '*' && content.charAt(j) == '/')) {
                        j++;
                        if (j == '\n') {
                            lineNum++;
                        }
                    }
                    present = j;
                }
                else {
                    tokenList.add(new Token("/", TOKENTYPE.DIV, lineNum));
                }
            }
            else if (c == '*')  tokenList.add(new Token("*", TOKENTYPE.MULT, lineNum));
            else if (c == '+') tokenList.add(new Token("+",TOKENTYPE.PLUS,lineNum));
            else if (c == '-') tokenList.add(new Token("-",TOKENTYPE.MINU,lineNum));
            else if (c == '%') tokenList.add(new Token("%",TOKENTYPE.MOD,lineNum));
            else if (c == ';') tokenList.add(new Token(";",TOKENTYPE.SEMICN,lineNum));
            else if (c == ',') tokenList.add(new Token(",",TOKENTYPE.COMMA,lineNum));
            else if (c == '(') tokenList.add(new Token("(",TOKENTYPE.LPARENT,lineNum));
            else if (c == ')') tokenList.add(new Token(")",TOKENTYPE.RPARENT,lineNum));
            else if (c == '[') tokenList.add(new Token("[",TOKENTYPE.LBRACK,lineNum));
            else if (c == ']') tokenList.add(new Token("]",TOKENTYPE.RBRACK,lineNum));
            else if (c == '{') tokenList.add(new Token("{",TOKENTYPE.LBRACE,lineNum));
            else if (c == '}') tokenList.add(new Token("}",TOKENTYPE.RBRACE,lineNum));
            else if (c == '\n') {
                lineNum++;
            }
        }
    }
}
