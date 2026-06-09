package frontend;


import error.Error;
import error.ErrorType;
import token.Token;
import token.TokenType;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Lexer {
    private final Map<String, TokenType> keyWordMap = new HashMap<String, TokenType>() {};
    public List<Token> tokens = new ArrayList<>();
    public List<Error> errors = new ArrayList<>();
    public Lexer() {
        {
            keyWordMap.put("main", TokenType.MAINTK);
            keyWordMap.put("const", TokenType.CONSTTK);
            keyWordMap.put("int", TokenType.INTTK);
            keyWordMap.put("char", TokenType.CHARTK);
            keyWordMap.put("break", TokenType.BREAKTK);
            keyWordMap.put("continue", TokenType.CONTINUETK);
            keyWordMap.put("if", TokenType.IFTK);
            keyWordMap.put("else", TokenType.ELSETK);
            keyWordMap.put("for", TokenType.FORTK);
            keyWordMap.put("void",TokenType.VOIDTK);
            keyWordMap.put("!",TokenType.NOT);
            keyWordMap.put("!=",TokenType.NEQ);
            keyWordMap.put("&&",TokenType.AND);
            keyWordMap.put("||",TokenType.OR);
            keyWordMap.put("getint",TokenType.GETINTTK);
            keyWordMap.put("getchar",TokenType.GETCHARTK);
            keyWordMap.put("printf",TokenType.PRINTFTK);
            keyWordMap.put("return",TokenType.RETURNTK);
            keyWordMap.put("+",TokenType.PLUS);
            keyWordMap.put("-",TokenType.MINU);
            keyWordMap.put("*",TokenType.MULT);
            keyWordMap.put("/",TokenType.DIV);
            keyWordMap.put("%",TokenType.MOD);
            keyWordMap.put(";",TokenType.SEMICN);
            keyWordMap.put(",",TokenType.COMMA);
            keyWordMap.put("(",TokenType.LPARENT);
            keyWordMap.put(")",TokenType.RPARENT);
            keyWordMap.put("[",TokenType.LBRACK);
            keyWordMap.put("]",TokenType.RBRACK);
            keyWordMap.put("{",TokenType.LBRACE);
            keyWordMap.put("}",TokenType.RBRACE);
        }
    }

    public void read(String program) {
        int len = program.length();
        char next;
        int currentLine = 1;//记录当前行数
        for (int i = 0; i < len; i++) {
            String token;
            if (i != len - 1) {
                next = program.charAt(i + 1);
            } else {
                next = '\0';
            }
            char c = program.charAt(i);
            if (c == '\n') {
                currentLine++;
            } else if (Character.isLetter(c) || c == '_') {
                //是字母
                StringBuilder str = new StringBuilder();
                for (int j = i; j < len; j++) {
                    char ch = program.charAt(j);
                    if (ch == '_' || Character.isLetter(ch) || Character.isDigit(ch)) {
                        str.append(ch);
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                if (keyWordMap.get(str.toString()) == null) {
                    tokens.add(new Token(TokenType.IDENFR, str.toString()));

                } else {
                    tokens.add(new Token(keyWordMap.get(str.toString()), str.toString()));
                }
            } else if (Character.isDigit(c)) {
                StringBuilder str = new StringBuilder();
                for (int j = i; j < len; j++) {
                    char ch = program.charAt(j);
                    if (Character.isDigit(ch)) {
                        str.append(ch);
                    } else {
                        i = j - 1;
                        break;
                    }

                }
                tokens.add(new Token(TokenType.INTCON, str.toString()));
            } else if (c == '\"') {
                StringBuilder str = new StringBuilder("\"");
                for (int j = i + 1; j < len; j++) {
                    char ch = program.charAt(j);
                    if (ch != '\"') {
                        str.append(ch);
                    } else {
                        i = j;
                        str.append('\"');
                        break;
                    }
                }
                tokens.add(new Token(TokenType.STRCON, str.toString()));
            } else if (c == '\'') {
                if (program.charAt(i + 2) == '\'' &&program.charAt(i + 1) <= 126&&program.charAt(i+1)!='\\') {//普通字符
                    tokens.add(new Token(TokenType.CHRCON, "'" + program.charAt(i + 1) + "'"));
                    i += 2;
                }else if(i+3<len&&program.charAt(i+3)=='\''&&program.charAt(i+1)=='\\'){//转义字符
                    char tmp = program.charAt(i+2);
                    if(tmp!='a'&&tmp!='b'&&tmp!='t'&&tmp!='n'&&tmp!='v'&&tmp!='f'&&tmp!='\"'&&tmp!='\''&&tmp!='\\'&&tmp!='0'){
                        continue;
                    }else{
                        tokens.add(new Token(TokenType.CHRCON, "'" + program.charAt(i + 1) + program.charAt(i + 2) +"'"));
                        i+=3;
                    }
                }
            } else if (c == '!') {
                if (next != '=') {
                    tokens.add(new Token(TokenType.NOT, "!"));
                } else {
                    tokens.add(new Token(TokenType.NEQ, "!="));
                    i++;
                }
            } else if (c == '&' && next == '&') {
                tokens.add(new Token(TokenType.AND, "&&"));
                i++;
            } else if (c == '|' && next == '|') {
                tokens.add(new Token(TokenType.OR, "||"));
                i++;

            } else if (c == '&' && next != '&') {
                errors.add(new Error(ErrorType.a, currentLine));
            } else if (c == '|' && next != '|') {
                errors.add(new Error(ErrorType.a, currentLine));

            } else if (c == '/') {
                if (next == '/') {
                    for (int j = i + 2; j < len; j++) {
                        if (program.charAt(j) == '\n' || program.charAt(j)=='\t'|| program.charAt(j)=='\r') {
                            i = j;
                            currentLine++;
                            break;
                        }
                    }
                } else if (next == '*') {
                    for (int j = i + 2; j < len - 1; j++) {
                        if (program.charAt(j) == '*' && program.charAt(j + 1) == '/') {
                            i = j + 2;
                            break;
                        }
                    }
                } else {
                    tokens.add(new Token(TokenType.DIV, "/"));
                }
            } else if (c == '<') {
                if (next == '=') {
                    tokens.add(new Token(TokenType.LEQ, "<="));
                    i++;

                } else {
                    tokens.add(new Token(TokenType.LSS, "<"));
                }
            } else if (c == '=') {
                if (next == '=') {
                    tokens.add(new Token(TokenType.EQL, "=="));
                    i++;

                } else {
                    tokens.add(new Token(TokenType.ASSIGN, "="));
                }
            } else if (c == '>') {
                if (next == '=') {
                    tokens.add(new Token(TokenType.GEQ, ">="));
                    i++;
                } else {
                    tokens.add(new Token(TokenType.GRE, ">"));
                }
            } else if (Character.isSpaceChar(c)) {
                continue;
            } else if(c!='\r'&&c!='\t'){
                if(keyWordMap.get(Character.toString(c))!=null) {
                    tokens.add(new Token(keyWordMap.get(Character.toString(c)), Character.toString(c)));
                }
            }
        }
    }
}
