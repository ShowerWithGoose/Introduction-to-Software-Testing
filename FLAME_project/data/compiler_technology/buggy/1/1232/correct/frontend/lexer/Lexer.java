package frontend.lexer;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

public class Lexer {
    private static volatile Lexer instance;

    private String srcCode;
    private int curChar;
    private int lineNum;
    private BufferedReader reader;
    private String tokenContent;
    private TokenType tokenType;
    private int errorFlag;

    private Lexer() {
        srcCode = "";
        curChar = 0;
        lineNum = 1;
        reader = null;
        tokenContent = "";
        tokenType = TokenType.EOF;
        errorFlag = 0;
    }

    public static Lexer getInstance() {
        if (instance == null) {
            synchronized (Lexer.class) {
                if (instance == null) {
                    instance = new Lexer();
                }
            }
        }
        return instance;
    }

    public void setSource(Reader source) throws IOException {
        this.reader = new BufferedReader(source);
    }

    public boolean isAlpha(int c) {
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && c >= 0)
            return true;
        return false;
    }

    public boolean isDigit(int c) {
        if (c >= '0' && c <= '9' && c >= 0)
            return true;
        return false;
    }

    public void reserve(){
        if (tokenContent.equals("main")) {
            tokenType = TokenType.MAINTK;
            return;
        } else if (tokenContent.equals("const")) {
            tokenType = TokenType.CONSTTK;
            return;
        } else if (tokenContent.equals("int")) {
            tokenType = TokenType.INTTK;
            return;
        } else if (tokenContent.equals("char")) {
            tokenType = TokenType.CHARTK;
            return;
        } else if (tokenContent.equals("break")) {
            tokenType = TokenType.BREAKTK;
            return;
        } else if (tokenContent.equals("continue")) {
            tokenType = TokenType.CONTINUETK;
            return;
        } else if (tokenContent.equals("if")) {
            tokenType = TokenType.IFTK;
            return;
        } else if (tokenContent.equals("else")) {
            tokenType = TokenType.ELSETK;
            return;
        } else if (tokenContent.equals("for")) {
            tokenType = TokenType.FORTK;
            return;
        } else if (tokenContent.equals("getint")) {
            tokenType = TokenType.GETINTTK;
            return;
        } else if (tokenContent.equals("getchar")) {
            tokenType = TokenType.GETCHARTK;
            return;
        } else if (tokenContent.equals("printf")) {
            tokenType = TokenType.PRINTFTK;
            return;
        } else if (tokenContent.equals("void")) {
            tokenType = TokenType.VOIDTK;
            return;
        } else if (tokenContent.equals("return")) {
            tokenType = TokenType.RETURNTK;
            return;
        } else {
            tokenType = TokenType.IDENFR;
            return;
        }
    }

    public void next() throws IOException{
        tokenContent = "";
        
        if (curChar == -1) {
            tokenType = TokenType.EOF;
            tokenContent = "EOF";
            return;
        }

        while (curChar != -1) {
            if (isAlpha(curChar) || (char)curChar == '_') {
                while(isAlpha(curChar) || isDigit(curChar) || (char)curChar == '_') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                }
                reserve();
                return;
            } else if (isDigit(curChar)) {
                while(isDigit(curChar)) {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                }
                tokenType = TokenType.INTCON;
                return;
            } else if ((char)curChar == '/') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if ((char)curChar == '/') {
                    while(curChar != '\n' && curChar != -1) {
                        tokenContent += (char)curChar;
                        curChar = reader.read();
                    }
                    if (curChar == '\n') {
                        tokenContent += (char)curChar;
                        curChar = reader.read();
                        lineNum++;
                    }
                    tokenType = TokenType.NOTE;
                    return;
                
                } else if ((char)curChar == '*') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    while (curChar != -1) {
                        while (curChar != -1 && (char)curChar != '*') {
                            tokenContent += (char)curChar;
                            if (curChar == '\n') {
                                lineNum++;
                            }
                            curChar = reader.read();
                        }
                        while (curChar != -1 && (char)curChar == '*') {
                            tokenContent += (char)curChar;
                            curChar = reader.read();
                        }
                        if (curChar == '/') {
                            tokenContent += (char)curChar;
                            curChar = reader.read();
                            tokenType = TokenType.NOTE;
                            return;
                        }
                    }
                    tokenType = TokenType.NOTE;
                    return;
                } else {
                    tokenType = TokenType.DIV;
                    return;
                }
            } else if ((char)curChar == '\"') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                while (curChar != -1 && (char)curChar != '\"') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                }
                if (curChar == '\"') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.STRCON;
                    return; 
                }
                return;
            } else if (curChar == '\'') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar != -1 && (char)curChar == '\\') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();

                    tokenContent += (char)curChar;
                    curChar = reader.read();
                }
                while (curChar != -1 && (char)curChar != '\'') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                }
                if (curChar == '\'') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.CHRCON;
                    return; 
                }
            } else if (curChar == '\n') {
                lineNum++;
                curChar = reader.read();
                continue;
            } else if (curChar == '!') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar == '=') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.NEQ;
                    return;
                }
                if (curChar != '=') {
                    tokenType = TokenType.NOT;
                    return;
                }
                return;
            } else if (curChar == '&') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar == '&') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.AND;
                    return;
                }
                if (curChar != '&') {
                    errorFlag = lineNum;
                    tokenType = TokenType.AND;
                    return;
                }
                return;
            } else if (curChar == '|') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar == '|') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.OR; 
                    return;
                }
                if (curChar != '|') {
                    errorFlag = lineNum;
                    tokenType = TokenType.OR;
                    return;
                }
                return;
            } else if (curChar == '+') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.PLUS;
                return;
            } else if (curChar == '-') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.MINU;
                return;
            } else if (curChar == '*') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.MULT;
                return;
            } else if (curChar == '%') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.MOD;
                return;
            } else if (curChar == '<') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar == '=') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.LEQ; 
                    return;
                }
                if (curChar != '=') {
                    tokenType = TokenType.LSS;
                    return;
                }
                return; 
            } else if (curChar == '>') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar == '=') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.GEQ; 
                    return;
                }   
                if (curChar != '=') {
                    tokenType = TokenType.GRE;
                    return;
                }
                return; 
            } else if (curChar == '=') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                if (curChar == '=') {
                    tokenContent += (char)curChar;
                    curChar = reader.read();
                    tokenType = TokenType.EQL; 
                    return;
                }
                if (curChar != '=') {
                    tokenType = TokenType.ASSIGN;
                    return;
                }
                return; 
            } else if (curChar == ';') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.SEMICN;
                return;
            } else if (curChar == ',') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.COMMA;
                return;
            } else if (curChar == '(') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.LPARENT;
                return;
            } else if (curChar == ')') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.RPARENT;
                return;
            } else if (curChar == '[') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.LBRACK;
                return;
            } else if (curChar == ']') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.RBRACK;
                return;
            } else if (curChar == '{') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.LBRACE; 
                return;
            } else if (curChar == '}') {
                tokenContent += (char)curChar;
                curChar = reader.read();
                tokenType = TokenType.RBRACE; 
                return;
            } else {
                curChar = reader.read();
                continue;
            }   
        }

        tokenContent = "";
        tokenType = TokenType.EOF;

        return;
    }

    public ArrayList<Token> Tokenize() throws IOException{
        ArrayList<Token> tokens = new ArrayList<>();
        curChar = reader.read();

        while(true){
            next();
            Token token = new Token(tokenType, tokenContent, lineNum);
            if(token.getType() == TokenType.EOF) 
                break;
            if (token.getType() != TokenType.NOTE)
                tokens.add(token);
        }
        return tokens;
    }

    public void outputTokens(List<Token> tokens) throws FileNotFoundException{
        if (errorFlag == 0) {
            PrintStream ps = new PrintStream("lexer.txt");
            System.setOut(ps);
            for(Token token : tokens) {
                if (token.getType() != TokenType.NOTE)
                    System.out.println(token);
            }
            ps.close();
        } else {
            PrintStream ps = new PrintStream("error.txt");
            System.setOut(ps);
            System.out.println(errorFlag + " a");
            ps.close();
        }
    }


}
