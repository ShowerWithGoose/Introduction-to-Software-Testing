package lexicalanalysis;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexical {
    private final String content;
    private final ArrayList<Token> words;
    private final StringBuilder builder;
    private char curChar;
    private int curCharIndex;
    private HashMap<String, Token.Type> reserveCode;
    private int line;
    private ErrorInfo errorInfo;

    public Lexical(String content,ArrayList<Token> words,ErrorInfo errorInfo) {
        this.content = content;
        this.words = words;
        this.curCharIndex = 0;
        this.builder = new StringBuilder();
        this.curChar = content.charAt(curCharIndex);
        init_reserveCode();
        this.line = 1;
        this.errorInfo = errorInfo;
    }

    private void init_reserveCode() {
        reserveCode = new HashMap<>();
        reserveCode.put("main", Token.Type.MAINTK);
        reserveCode.put("const", Token.Type.CONSTTK);
        reserveCode.put("int", Token.Type.INTTK);
        reserveCode.put("char", Token.Type.CHARTK);
        reserveCode.put("break", Token.Type.BREAKTK);
        reserveCode.put("continue", Token.Type.CONTINUETK);
        reserveCode.put("if", Token.Type.IFTK);
        reserveCode.put("else", Token.Type.ELSETK);
        reserveCode.put("!", Token.Type.NOT);
        reserveCode.put("&&", Token.Type.AND);
        reserveCode.put("||", Token.Type.OR);
        reserveCode.put("for", Token.Type.FORTK);
        reserveCode.put("getint", Token.Type.GETINTTK);
        reserveCode.put("getchar", Token.Type.GETCHARTK);
        reserveCode.put("printf", Token.Type.PRINTFTK);
        reserveCode.put("return", Token.Type.RETURNTK);
        reserveCode.put("+", Token.Type.PLUS);
        reserveCode.put("-", Token.Type.MINU);
        reserveCode.put("void", Token.Type.VOIDTK);
        reserveCode.put("*", Token.Type.MULT);
        reserveCode.put("/", Token.Type.DIV);
        reserveCode.put("%", Token.Type.MOD);
        reserveCode.put("<", Token.Type.LSS);
        reserveCode.put("<=", Token.Type.LEQ);
        reserveCode.put(">", Token.Type.GRE);
        reserveCode.put(">=", Token.Type.GEQ);
        reserveCode.put("==", Token.Type.EQL);
        reserveCode.put("!=", Token.Type.NEQ);
        reserveCode.put("=", Token.Type.ASSIGN);
        reserveCode.put(";", Token.Type.SEMICN);
        reserveCode.put(",", Token.Type.COMMA);
        reserveCode.put("(", Token.Type.LPARENT);
        reserveCode.put(")", Token.Type.RPARENT);
        reserveCode.put("[", Token.Type.LBRACK);
        reserveCode.put("]", Token.Type.RBRACK);
        reserveCode.put("{", Token.Type.LBRACE);
        reserveCode.put("}", Token.Type.RBRACE);
    }

    public void lexical_analysis() {
        while (curCharIndex < content.length()) {
            if (curChar != content.charAt(curCharIndex)) {
                curCharIndex++;
            }
            //System.out.println(curChar);
            builder.setLength(0);
            getCharNbc();
            if (Character.isLetter(curChar) || curChar == '_') {
                while (Character.isLetter(curChar) ||
                        Character.isDigit(curChar) || curChar == '_') {
                    cat();
                    getChar();
                }
                int cur = reserve();
                if (cur == 0) {
                    words.add(new Token(Token.Type.IDENFR, builder.toString(), line));
                } else {
                    words.add(new Token(reserveCode.get(builder.toString())
                            , builder.toString(), line));
                }
            } else if (Character.isDigit(curChar)) {
                while (Character.isDigit(curChar)) {
                    cat();
                    getChar();
                }
                words.add(new Token(Token.Type.INTCON, builder.toString(), line));
            } else if (curChar == '"') {
                cat();
                getChar();
                while ((curChar >= 32 && curChar <= 126)) {
                    if (curChar == '"') {
                        break;
                    }
                    cat();
                    getChar();
                }
                cat();
                getChar();
                words.add(new Token(Token.Type.STRCON, builder.toString(), line));
            } else if (curChar == '\'') {
                cat();
                getChar();
                if (curChar == '\\') {
                    cat();
                    getChar();
                    cat();
                    getChar();
                    if (curChar == '\'') {
                        cat();
                        getChar();
                    }
                } else {
                    cat();
                    getChar();
                    cat();
                    getChar();
                }
                words.add(new Token(Token.Type.CHRCON, builder.toString(), line));
            } else if (curChar == '!') {
                getChar();
                if (curChar == '=') {
                    words.add(new Token(Token.Type.NEQ, "!=", line));
                    getChar();
                } else {
                    words.add(new Token(Token.Type.NOT, "!", line));
                    unGetCh();
                }
            } else if (curChar == '&') {
                getChar();
                if (curChar == '&') {
                    words.add(new Token(Token.Type.AND, "&&", line));
                    getChar();
                } else {
                    errorInfo.addError('a',line);
                    words.add(new Token(Token.Type.AND, "&&", line));
                }
            } else if (curChar == '|') {
                getChar();
                if (curChar == '|') {
                    words.add(new Token(Token.Type.OR, "||", line));
                    getChar();
                } else {
                    errorInfo.addError('a',line);
                    words.add(new Token(Token.Type.OR, "||", line));
                }
            } else if (curChar == '+') {
                words.add(new Token(Token.Type.PLUS, "+", line));
                getChar();
            } else if (curChar == '-') {
                words.add(new Token(Token.Type.MINU, "-", line));
                getChar();
            } else if (curChar == '*') {
                words.add(new Token(Token.Type.MULT, "*", line));
                getChar();
            } else if (curChar == '/') {
                getChar();
                if (curChar == '/') {
                    while (curCharIndex < content.length() && curChar != '\n') {
                        getChar();
                    }
                    if (curChar == '\n') {
                        line++;
                        getChar();
                    }
                } else if (curChar == '*') {
                    while (curCharIndex < content.length()) {
                        getChar();
                        while (curChar != '*') {
                            if (curChar == '\n') {
                                line++;
                            }
                            getChar();
                        }
                        while (curChar == '*') {
                            getChar();
                        }
                        if (curChar == '/') {
                            getChar();
                            break;
                        }
                    }
                } else {
                    words.add(new Token(Token.Type.DIV, "/", line));
                    unGetCh();
                }
            } else if (curChar == '%') {
                words.add(new Token(Token.Type.MOD, "%", line));
                getChar();
            } else if (curChar == '<') {
                getChar();
                if (curChar == '=') {
                    words.add(new Token(Token.Type.LEQ, "<=", line));
                    getChar();
                } else {
                    words.add(new Token(Token.Type.LSS, "<", line));
                    unGetCh();
                }
            } else if (curChar == '>') {
                getChar();
                if (curChar == '=') {
                    words.add(new Token(Token.Type.GEQ, ">=", line));
                    getChar();
                } else {
                    words.add(new Token(Token.Type.GRE, ">", line));
                    unGetCh();
                }
            } else if (curChar == '=') {
                getChar();
                if (curChar == '=') {
                    words.add(new Token(Token.Type.EQL, "==", line));
                    getChar();
                } else {
                    words.add(new Token(Token.Type.ASSIGN, "=", line));
                    unGetCh();
                }
            } else if (curChar == ';') {
                words.add(new Token(Token.Type.SEMICN, ";", line));
                getChar();
            } else if (curChar == ',') {
                words.add(new Token(Token.Type.COMMA, ",", line));
                getChar();
            } else if (curChar == '(') {
                words.add(new Token(Token.Type.LPARENT, "(", line));
                getChar();
            } else if (curChar == ')') {
                words.add(new Token(Token.Type.RPARENT, ")", line));
                getChar();
            } else if (curChar == '[') {
                words.add(new Token(Token.Type.LBRACK, "[", line));
                getChar();
            } else if (curChar == ']') {
                words.add(new Token(Token.Type.RBRACK, "]", line));
                getChar();
            } else if (curChar == '{') {
                words.add(new Token(Token.Type.LBRACE, "{", line));
                getChar();
            } else if (curChar == '}') {
                words.add(new Token(Token.Type.RBRACE, "}", line));
                getChar();
            }
        }
    }

    public void getChar() {
        curCharIndex++;
        if (curCharIndex < content.length()) {
            curChar = content.charAt(curCharIndex);
        }
    }

    private void getCharNbc() {
        while (Character.isWhitespace(curChar) && curCharIndex < content.length()) {
            if (curChar == '\n') {
                line++;
            }
            getChar();
        }
    }

    private void cat() {
        builder.append(curChar);
    }

    private void unGetCh() {
        curCharIndex--;
    }

    private int reserve() {
        String curToken = builder.toString();
        if (reserveCode.containsKey(curToken)) {
            return 1;
        } else {
            return 0;
        }
    }

    public void lexical_print() {
        if (!errorInfo.isEmpty()) {
            String filePath = "lexer.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath, true))) {
                for (Token word : words) {
                    writer.write(word + "\n");
                }
                writer.flush();
            } catch (IOException e) {
                e.printStackTrace();
                System.out.println("写入文件时发生错误。");
            }
        } else {
            String filePath = "error.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath, true))) {
                //writer.write(errorLine + " " + errorText);
                writer.flush();
            } catch (IOException e) {
                e.printStackTrace();
                System.out.println("写入文件时发生错误。");
            }
        }
    }
}
