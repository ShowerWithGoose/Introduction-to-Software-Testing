package frontend;

import error.ErrorCode;
import error.ErrorType;
import token.Token;
import token.TokenType;

import java.io.*;
import java.util.*;

public class Lexer {
    private BufferedReader reader;
    private int lineNumber;
    private char currentChar;

    private List<Token> tokens;
    private Map<Integer,ErrorCode> errors;
    private int cur;

    private static final Map<String, TokenType> KEYWORDS = new HashMap<>();
    private static final Map<String, TokenType> SYMBOLS = new HashMap<>();

    static {
        // 初始化关键字
        KEYWORDS.put("main", TokenType.MAINTK);
        KEYWORDS.put("const", TokenType.CONSTTK);
        KEYWORDS.put("int", TokenType.INTTK);
        KEYWORDS.put("char", TokenType.CHARTK);
        KEYWORDS.put("break", TokenType.BREAKTK);
        KEYWORDS.put("continue", TokenType.CONTINUETK);
        KEYWORDS.put("if", TokenType.IFTK);
        KEYWORDS.put("else", TokenType.ELSETK);
        KEYWORDS.put("for", TokenType.FORTK);
        KEYWORDS.put("getint", TokenType.GETINTTK);
        KEYWORDS.put("getchar", TokenType.GETCHARTK);
        KEYWORDS.put("printf", TokenType.PRINTFTK);
        KEYWORDS.put("return", TokenType.RETURNTK);
        KEYWORDS.put("void", TokenType.VOIDTK);

        // 初始化符号
        SYMBOLS.put("+", TokenType.PLUS);
        SYMBOLS.put("-", TokenType.MINU);
        SYMBOLS.put("*", TokenType.MULT);
        SYMBOLS.put("/", TokenType.DIV);
        SYMBOLS.put("%", TokenType.MOD);
        SYMBOLS.put(";", TokenType.SEMICN);
        SYMBOLS.put(",", TokenType.COMMA);
        SYMBOLS.put("(", TokenType.LPARENT);
        SYMBOLS.put(")", TokenType.RPARENT);
        SYMBOLS.put("[", TokenType.LBRACK);
        SYMBOLS.put("]", TokenType.RBRACK);
        SYMBOLS.put("{", TokenType.LBRACE);
        SYMBOLS.put("}", TokenType.RBRACE);
        SYMBOLS.put("=", TokenType.ASSIGN);
        SYMBOLS.put("!", TokenType.NOT);
        SYMBOLS.put("&&", TokenType.AND);
        SYMBOLS.put("&", TokenType.AND);
        SYMBOLS.put("||", TokenType.OR);
        SYMBOLS.put("|", TokenType.OR);
        SYMBOLS.put("<", TokenType.LSS);
        SYMBOLS.put("<=", TokenType.LEQ);
        SYMBOLS.put(">", TokenType.GRE);
        SYMBOLS.put(">=", TokenType.GEQ);
        SYMBOLS.put("==", TokenType.EQL);
        SYMBOLS.put("!=", TokenType.NEQ);
    }

    public Lexer(String filename) throws FileNotFoundException {
        this.reader = new BufferedReader(new FileReader(filename));
        this.lineNumber = 1;
        this.cur = 0;

        this.tokens = new ArrayList<>();
        this.errors = new HashMap<>();
    }

    private void nextChar() {
        try {
            int next = reader.read();
            if (next == -1) {
                currentChar = '\0';
            } else {
                currentChar = (char) next;
            }
            if (currentChar == '\n') {
                lineNumber++;
            }
        } catch (IOException e) {
            currentChar = '\0';
        }
    }
    
    private boolean isKeyword(String ident) {
        return KEYWORDS.containsKey(ident);
    }

    private boolean isSymbol(String ident) {
        return SYMBOLS.containsKey(ident);
    }

    private TokenType getKeywordCode(String ident) {
        return KEYWORDS.get(ident);
    }

    private TokenType getSymbolCode(String ident) {
        return SYMBOLS.get(ident);
    }

    public void tokenize() throws IOException {
        nextChar();
        while (currentChar != '\0') {
            //处理单行注释和多行注释情况
            if (currentChar == '/') {
                nextChar();
                if (currentChar == '/') {
                    handleSingleLineComment();
                } else if (currentChar == '*') {
                    handleMultiLineComment();
                } else {
                    tokens.add(new Token(getSymbolCode("/"),"/",lineNumber));
                }
            }
            else if (Character.isWhitespace(currentChar) || currentChar == '\n') {
                nextChar();
                continue;
            }
            else if (currentChar == '"') {
                StringBuilder ident = new StringBuilder();
                do {
                    ident.append(currentChar);
                    nextChar();
                } while (currentChar != '"');
                ident.append(currentChar);
                String identStr = ident.toString();
                tokens.add(new Token(TokenType.STRCON,identStr,lineNumber));
                nextChar();
            } 
            else if (currentChar == '\'') {
                StringBuilder ident = new StringBuilder();
                ident.append(currentChar);
                nextChar();
                do {
                    ident.append(currentChar);
                    if (currentChar == '\\') {
                        nextChar();
                        ident.append(currentChar);
                    }
                    nextChar();
                } while (currentChar != '\'');
                ident.append(currentChar);
                String identStr = ident.toString();
                tokens.add(new Token(TokenType.CHRCON,identStr,lineNumber));
                nextChar();
            } 
            else if (Character.isLetter(currentChar) || currentChar == '_') {
                StringBuilder ident = new StringBuilder();
                int holdLine = lineNumber;
                do {
                    ident.append(currentChar);
                    nextChar();
                } while (Character.isLetterOrDigit(currentChar) || currentChar == '_');

                String identStr = ident.toString();
                if (isKeyword(identStr)) {
                    tokens.add(new Token(getKeywordCode(identStr) ,identStr,holdLine));
                } else {
                    tokens.add(new Token(TokenType.IDENFR , identStr,holdLine));
                }
            } 
            else if (Character.isDigit(currentChar)) {
                StringBuilder number = new StringBuilder();
                int holdline = lineNumber;
                do {
                    number.append(currentChar);
                    nextChar();
                } while (Character.isDigit(currentChar));

                tokens.add(new Token(TokenType.INTCON , number.toString() ,holdline));
            } 
            else if (isSymbol(String.valueOf(currentChar))) {
                getSymbol(currentChar);
            } 
            else {
                errors.put(lineNumber,new ErrorCode(ErrorType.ILLEGAL_SYMBOL,lineNumber));
                nextChar();
            }
        }
        reader.close();
    }

    private void handleMultiLineComment() {
        boolean found = false;
        nextChar();
        while (!found) {
            if (currentChar == '*') {
                nextChar();
                if (currentChar == '/') {
                    found = true;
                }
            }
            if (currentChar != '*') {
                nextChar();
            }
        }
    }

    private void handleSingleLineComment() {
        while (currentChar != '\n') {
            if (currentChar == '\0') {
                return;
            }
            nextChar();
        }
        nextChar();
    }

    private void getSymbol(char firstChar) {
        if (firstChar == '&') {
            int holdLine = lineNumber;
            nextChar();
            if (currentChar != '&') {
                errors.put(holdLine,new ErrorCode(ErrorType.ILLEGAL_SYMBOL,holdLine));
                tokens.add(new Token(getSymbolCode("&&") , String.valueOf(firstChar),lineNumber));
            } else {
                tokens.add(new Token(getSymbolCode("&&") , "&&",lineNumber));
                nextChar();
            }
        } else if (firstChar == '|') {
            int holdLine = lineNumber;
            nextChar();
            if (currentChar != '|') {
                errors.put(holdLine,new ErrorCode(ErrorType.ILLEGAL_SYMBOL,holdLine));
                tokens.add(new Token(getSymbolCode("||") ,String.valueOf(firstChar),lineNumber));
            } else {
                tokens.add(new Token(getSymbolCode("||") , "||",lineNumber));
                nextChar();
            }
        } else if (firstChar == '<' || firstChar == '>'
                || firstChar == '=' || firstChar == '!') {
            nextChar();
            if (currentChar != '=') {
                tokens.add(new Token(getSymbolCode(String.valueOf(firstChar)) , String.valueOf(firstChar),lineNumber));
            } else {
                StringBuilder str = new StringBuilder();
                str.append(firstChar);
                str.append(currentChar);
                String symStr = str.toString();
                tokens.add(new Token(getSymbolCode(symStr) , symStr,lineNumber));
                nextChar();
            }
        } else {
            tokens.add(new Token(getSymbolCode(String.valueOf(firstChar)) , String.valueOf(firstChar),lineNumber));
            nextChar();
        }
    }

    public List<Token> getTokens() {
        return this.tokens;
    }

    public Map<Integer,ErrorCode> getErrors() {
        return this.errors;
    }

    public void move() {
        cur++;
    }

    public boolean notEnd(int offset) {
        return cur + offset< tokens.size();
    }

    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer("testfile.txt");
        lexer.tokenize();
    }

    public Token getToken(int offset) {
        if (notEnd(offset)) {
            return tokens.get(cur + offset);
        }
        return null;
    }
}