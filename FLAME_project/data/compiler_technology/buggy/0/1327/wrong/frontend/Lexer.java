package frontend;

import frontend.error.ErrorType;
import frontend.error.MyError;
import frontend.lexer.Token;
import frontend.lexer.TokenType;

import java.io.*;
import java.util.ArrayList;

public class Lexer {
    private BufferedInputStream bis;
    private BufferedWriter bw;
    private ArrayList<Token> tokenList;
    private ArrayList<MyError> errorList;
    private int line;
    private int curse;
    private char peekChar;
    private boolean endOfFile;

    private boolean isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    private boolean isLower(char c) {
        return (c >= 'a' && c <= 'z');
    }

    private boolean isUpper(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    private boolean isAlpha(char c) {
        return (isLower(c) || isUpper(c));
    }

    private boolean read() {
        int c = -1;
        try {
            c = bis.read();
        } catch (IOException e) {
            System.out.println("fail to read char");
        }
        if (c == -1) {
            endOfFile = true;
            return false;
        } else {
            peekChar = (char) c;
            if (peekChar == '\n') {
                line += 1;
            }
            return true;
        }
    }

    private Token readWord() {
        StringBuilder sb = new StringBuilder();
        while (!endOfFile && (isAlpha(peekChar) || isDigit(peekChar) || peekChar == '_')) {
            sb.append(peekChar);
            read();
        }
        //TODO
        String word = sb.toString();
        switch (word) {
            case "main" :
                return new Token(TokenType.MAINTK, line);
            case "const":
                return new Token(TokenType.CONSTTK, line);
            case "int":
                return new Token(TokenType.INTTK, line);
            case "char":
                return new Token(TokenType.CHARTK, line);
            case "break":
                return new Token(TokenType.BREAKTK, line);
            case "continue":
                return new Token(TokenType.CONTINUETK, line);
            case "if":
                return new Token(TokenType.IFTK, line);
            case "else":
                return new Token(TokenType.ELSETK, line);
            case "for":
                return new Token(TokenType.FORTK, line);
            case "getint":
                return new Token(TokenType.GETINTTK, line);
            case "getchar":
                return new Token(TokenType.GETCHARTK, line);
            case "printf":
                return new Token(TokenType.PRINTFTK, line);
            case "return":
                return new Token(TokenType.RETURNTK, line);
            case "void":
                return new Token(TokenType.VOIDTK, line);
            default:
                return new Token(TokenType.IDENFR, word, line);
        }
    }

    private Token readNum() {
        StringBuilder sb = new StringBuilder();
        while (!endOfFile && isDigit(peekChar)) {
            sb.append(peekChar);
            read();
        }
        //TODO
        String number = sb.toString();
        return new Token(TokenType.INTCON, number, line);
    }

    private void readAnnotation() {
        if (peekChar == '/') {
            while (!endOfFile && peekChar != '\n') {
                read();
            }
        }
        if (peekChar == '*') {
            int flag = 0;
            while (flag != 2) {
                read();
                if (peekChar == '/' && flag == 1) {
                    flag = 2;
                } else if (peekChar == '*') {
                    flag = 1;
                } else {
                    flag = 0;
                }
            }
        }
        read();
    }

    private Token readChar() {
        read();
        if (peekChar == '\'') {
            return new Token(TokenType.CHRCON, "''", line);
        } else {
           char c = peekChar;
           read();
           if (c == '\\') {
               c = peekChar;
               read();
               if (peekChar == '\'') {
                   read();
                   return new Token(TokenType.CHRCON, "'\\" + c + "'", line);
               } else {
                   //TODO
                   return null;
               }
           }
           if (peekChar == '\'') {
               read();
               return new Token(TokenType.CHRCON, "'" + c + "'", line);
           } else {
               //TODO
               return null;
           }
        }
    }

    private Token readString() {
        read();
        if (peekChar == '\"') {
            return new Token(TokenType.STRCON, "\"\"", line);
        } else {
            StringBuilder sb = new StringBuilder();
            while (peekChar != '\"') {
                if (peekChar == '\\') {
                    sb.append(peekChar);
                    read();
                }
                sb.append(peekChar);
                read();
            }
            read();
            return new Token(TokenType.STRCON, "\"" + sb.toString() + "\"", line);
        }
    }

    private Token readOp() {
        if (peekChar == '/') {
            read();
            if (peekChar == '/' || peekChar == '*') {
                readAnnotation();
                return null;
            } else {
                return new Token(TokenType.DIV, line);
            }
        } else {
            char c = peekChar;
            read();
            switch (c) {
                case '&':
                    if (peekChar == '&') {
                        read();
                        return new Token(TokenType.AND, line);
                    } else {
                        errorList.add(new MyError(line, ErrorType.a));
                        return null;
                    }
                case '|' :
                    if (peekChar == '|') {
                        read();
                        return new Token(TokenType.OR, line);
                    } else {
                        errorList.add(new MyError(line, ErrorType.a));
                    }
                case '+':
                    return new Token(TokenType.PLUS, line);
                case '-':
                    return new Token(TokenType.MINU, line);
                case '*':
                    return new Token(TokenType.MULT, line);
                case '%':
                    return new Token(TokenType.MOD, line);
                case '<':
                    if (peekChar == '=') {
                        read();
                        return new Token(TokenType.LEQ, line);
                    } else {
                        return new Token(TokenType.LSS, line);
                    }
                case '>':
                    if (peekChar == '=') {
                        read();
                        return new Token(TokenType.GEQ, line);
                    } else {
                        return new Token(TokenType.GRE, line);
                    }
                case '=':
                    if (peekChar == '=') {
                        read();
                        return new Token(TokenType.EQL, line);
                    } else {
                        return new Token(TokenType.ASSIGN, line);
                    }
                case '!':
                    if (peekChar == '=') {
                        read();
                        return new Token(TokenType.NEQ, line);
                    } else {
                        return new Token(TokenType.NOT, line);
                    }
                case ';':
                    return new Token(TokenType.SEMICN, line);
                case ',':
                    return new Token(TokenType.COMMA, line);
                case '(':
                    return new Token(TokenType.LPARENT, line);
                case ')':
                    return new Token(TokenType.RPARENT, line);
                case '[':
                    return new Token(TokenType.LBRACK, line);
                case ']':
                    return new Token(TokenType.RBRACK, line);
                case '{':
                    return new Token(TokenType.LBRACE, line);
                case '}':
                    return new Token(TokenType.RBRACE, line);
                default:
                    return null;
            }
        }
    }

    private void printLexer() {
        try {
            for (Token token : tokenList) {
                bw.append(String.valueOf(token)).append("\n");
            }
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Lexer(BufferedInputStream bis, ArrayList<MyError> errorList, BufferedWriter bw) {
        this.bis = bis;
        this.endOfFile = false;
        this.line = 1;
        this.tokenList = new ArrayList<>();
        this.errorList = errorList;
        this.bw = bw;

        read();
        while (!endOfFile) {
            if (isAlpha(peekChar) || peekChar == '_') {
                tokenList.add(readWord());
            } else if (isDigit(peekChar)) {
                tokenList.add(readNum());
            } else if (peekChar == ' ') {
                while (peekChar == ' ') {
                    read();
                }
            } else if (peekChar == '\'') {
                tokenList.add(readChar());
            } else if (peekChar == '\"') {
                tokenList.add(readString());
            }  else {
                Token t = readOp();
                if (t != null) {
                    tokenList.add(t);
                }
            }
        }
        printLexer();
    }



}
