package frontend.Lexer;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Lexer {
    private TokenList tokens = new TokenList();
    private final BufferedReader bis;
    private int line = 1;
    private char curChar;
    private ArrayList<Integer> errorLine = new ArrayList<>();
    private boolean end = false;

    public ArrayList<Integer> geterrorLine() {
        return errorLine;
    }

    public TokenList getTokens() {
        return tokens;
    }

    private void getChar() {
        if (curChar == '\n') {
            line += 1;
        }
        int Char = -1;
        try {
            Char = bis.read();
        } catch (IOException e) {
            System.err.println("读取字符时发生错误: " + e.getMessage());
        }
        if (Char == -1) {
            end = true;
        }
        curChar = (char) Char;
    }

    public LexType nextIdent() {
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(curChar) || Character.isAlphabetic(curChar)
                || curChar == '_') {
            sb.append(curChar);
            getChar();
        }
        String ident = sb.toString();
        return switch (ident) {
            case "main" -> new LexType(LexType.TokenType.MAINTK, ident, line);
            case "const" -> new LexType(LexType.TokenType.CONSTTK, ident, line);
            case "int" -> new LexType(LexType.TokenType.INTTK, ident, line);
            case "char" -> new LexType(LexType.TokenType.CHARTK, ident, line);
            case "break" -> new LexType(LexType.TokenType.BREAKTK, ident, line);
            case "continue" -> new LexType(LexType.TokenType.CONTINUETK, ident, line);
            case "if" -> new LexType(LexType.TokenType.IFTK, ident, line);
            case "else" -> new LexType(LexType.TokenType.ELSETK, ident, line);
            case "void" -> new LexType(LexType.TokenType.VOIDTK, ident, line);
            case "for" -> new LexType(LexType.TokenType.FORTK, ident, line);
            case "getint" -> new LexType(LexType.TokenType.GETINTTK, ident, line);
            case "getchar" -> new LexType(LexType.TokenType.GETCHARTK, ident, line);
            case "printf" -> new LexType(LexType.TokenType.PRINTFTK, ident, line);
            case "return" -> new LexType(LexType.TokenType.RETURNTK, ident, line);
            default -> new LexType(LexType.TokenType.IDENFR, ident, line);
        };
    }

    public LexType nextNumber() {
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(curChar)) {
            sb.append(curChar);
            getChar();
        }
        return new LexType(LexType.TokenType.INTCON, sb.toString(), line);
    }

    public LexType nextString() {
        StringBuilder sb = new StringBuilder();
        sb.append('\"');
        getChar();
        while (curChar != '\"') {
            if (curChar == '\\') {
                sb.append(curChar);
                getChar();
                sb.append(curChar);
                getChar();
            } else {
                sb.append(curChar);
                getChar();
            }
        }
        sb.append('\"');
        getChar();
        return new LexType(LexType.TokenType.STRCON, sb.toString(), line);
    }

    public LexType nextChar() {
        StringBuilder sb = new StringBuilder();
        sb.append('\'');
        getChar();
        sb.append(curChar);
        if (curChar == '\\') {
            getChar();
            sb.append(curChar);
            getChar();
            if (curChar == '\'') {
                sb.append(curChar);
                getChar();
            }
        } else {
            getChar();
            sb.append('\'');
            getChar();
        }
        return new LexType(LexType.TokenType.CHRCON, sb.toString(), line);
    }

    public LexType nextSymbol() {
        char nowChar = curChar;
        getChar();
        char nextChar = curChar;
        switch (nowChar) {
            case '!':
                if (nextChar == '=') {
                    getChar();
                    return new LexType(LexType.TokenType.NEQ,"!=", line);
                } else {
                    return new LexType(LexType.TokenType.NOT,"!", line);
                }
            case '&':
                if (nextChar == '&') {
                    getChar();
                    return new LexType(LexType.TokenType.AND,"&&", line);
                } else {
                    errorLine.add(line);
                    return new LexType(LexType.TokenType.AND,"&", line);
                }
            case '|':
                if (nextChar == '|') {
                    getChar();
                    return new LexType(LexType.TokenType.OR,"||", line);
                } else {
                    errorLine.add(line);
                    return new LexType(LexType.TokenType.OR,"|", line);
                }
            case '+':
                return new LexType(LexType.TokenType.PLUS,"+", line);
            case '-':
                return new LexType(LexType.TokenType.MINU,"-", line);
            case '*':
                return new LexType(LexType.TokenType.MULT,"*", line);
            case '/':
                if (nextChar == '/') {
                    while (nextChar != '\n' && !end) {
                        getChar();
                        nextChar = curChar;
                    }
                    getChar();
                    return null;
                } else if (nextChar == '*') {
                    while (nowChar != '*' || nextChar != '/' && !end) {
                        nowChar = nextChar;
                        getChar();
                        nextChar = curChar;
                    }
                    getChar();
                    return null;
                } else {
                    return new LexType(LexType.TokenType.DIV,"/", line);
                }
            case '%':
                return new LexType(LexType.TokenType.MOD,"%", line);
            case '<':
                if (nextChar == '=') {
                    getChar();
                    return new LexType(LexType.TokenType.LEQ,"<=", line);
                } else {
                    return new LexType(LexType.TokenType.LSS,"<", line);
                }
            case '>':
                if (nextChar == '=') {
                    getChar();
                    return new LexType(LexType.TokenType.GEQ,">=", line);
                } else {
                    return new LexType(LexType.TokenType.GRE,">", line);
                }
            case '=':
                if (nextChar == '=') {
                    getChar();
                    return new LexType(LexType.TokenType.EQL,"==", line);
                } else {
                    return new LexType(LexType.TokenType.ASSIGN,"=", line);
                }
            case ';':
                return new LexType(LexType.TokenType.SEMICN,";", line);
            case ',':
                return new LexType(LexType.TokenType.COMMA,",", line);
            case '(':
                return new LexType(LexType.TokenType.LPARENT,"(", line);
            case ')':
                return new LexType(LexType.TokenType.RPARENT,")", line);
            case '[':
                return new LexType(LexType.TokenType.LBRACK,"[", line);
            case ']':
                return new LexType(LexType.TokenType.RBRACK,"]", line);
            case '{':
                return new LexType(LexType.TokenType.LBRACE,"{", line);
            case '}':
                return new LexType(LexType.TokenType.RBRACE,"}", line);
            default:
                return null;
        }
    }

    public Lexer(BufferedReader bis) {
        this.bis = bis;
        getChar();
        while (!end) {
            while (Character.isWhitespace(curChar) && !end) {
                getChar();
            }
            if (Character.isAlphabetic(curChar) || curChar == '_') {
                tokens.add(nextIdent());
            }else if (Character.isDigit(curChar)) {
                tokens.add(nextNumber());
            } else if (curChar == '\"') {
                tokens.add(nextString());
            } else if (curChar == '\'') {
                tokens.add(nextChar());
            }  else {
                LexType token = nextSymbol();
                if (token != null) {
                    tokens.add(token);
                }
            }
        }
    }

//    public void printLog() {
//        if (errorLine == 0) {
//            try (FileWriter writer = new FileWriter("lexer.txt")) {
//                for (LexType token : tokens.getTokens()) {
//                    writer.write(token.getType() + " " + token.getText() + "\n");
//                }
//            } catch (IOException e) {
//                System.err.println("Error writing to lexer.txt: " + e.getMessage());
//            }
//        } else {
//            try (FileWriter writer = new FileWriter("error.txt")) {
//                writer.write(errorLine + " a");
//            } catch (IOException e) {
//                System.err.println("Error writing to error.txt: " + e.getMessage());
//            }
//        }
//    }
}
