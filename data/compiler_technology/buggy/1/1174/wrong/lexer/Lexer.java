package lexer;

import token.Token;
import token.TokenType;

import java.util.Set;
import java.util.HashSet;

import java.util.List;
import java.util.ArrayList;

import error.Error;

public class Lexer {
    private String source;              
    private int curPos;                  
    private Token token;                 
    private Set<String> reserveWords;   
    private int lineNum;                
    private int colNum;                 
    private List<Token> tokens;         

    public Lexer() {}
    public Lexer(String source) {
        this.source = source;
        this.curPos = 0;
        this.token = null;
        this.reserveWords = new HashSet<>();
        this.lineNum = 1;
        this.colNum = 1;
        this.tokens = new ArrayList<>();

        initializeReserveWords();
    }

    /* initialize reaervewords list */
    private void initializeReserveWords() {
        reserveWords.add("main");
        reserveWords.add("const");
        reserveWords.add("int");
        reserveWords.add("char");
        reserveWords.add("break");
        reserveWords.add("continue");
        reserveWords.add("if");
        reserveWords.add("else");
        reserveWords.add("for");
        reserveWords.add("getint");
        reserveWords.add("getchar");
        reserveWords.add("printf");
        reserveWords.add("return");
        reserveWords.add("void");
    }

    /* get next token, update:curPos, lineNum, colNum */
    private char readNextChar() {
        if (curPos < source.length()) { // successful
            char ch = source.charAt(curPos++);
            if (ch == '\n') {
                lineNum++;
                colNum = 1;
            } else {
                colNum++;
            }
            return ch;
        } else {  // source is read out
            return '\0';
        }
    }

    /* output is successful or not */
    private boolean readNextToken() {
        /* initialize */
        token = new Token();
        String s = "";
        char ch;

        /* valid ch */
        while (true) {
            ch = readNextChar();
            // jump blank
            if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') { ; }
            // jump //
            else if (ch == '/' && source.charAt(curPos) == '/') {
                ch = readNextChar();  
                while (true) {
                    ch = readNextChar();
                    if (ch == '\n' || ch == '\0')
                        break;
                }
            } 
            // jump /* */
            else if (ch == '/' && source.charAt(curPos) == '*') {
                ch = readNextChar();
                while (true) {
                    ch = readNextChar();
                    if (ch == '*' && source.charAt(curPos) =='/') {
                        ch = readNextChar();
                        break;
                    }
                }
            }
            // read out source
            else if (ch == '\0') { return false; }
            // find valid 
            else { break; }
        };

        /* record token position */ 
        token.setPosition(lineNum, colNum);

        /* get token */
        s += ch;
        // Ident or ...TK
        if (Character.isLetter(ch) || ch == '_') {
            // Letter? digit? _?
            while (curPos < source.length() && (Character.isLetter(source.charAt(curPos)) || Character.isDigit(source.charAt(curPos)) || source.charAt(curPos) == '_')) {
                ch = readNextChar();
                s += ch;
            }
            if (reserveWords.contains(s)) { // ...TK
                token.setInfo(s, TokenType.valueOf(s.toUpperCase() + "TK"));
            } else { // ident
                token.setInfo(s, TokenType.IDENFR);   
            }
        }  
        // IntConst
        else if (Character.isDigit(ch)) {
            // next is digit?
            while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                ch = readNextChar();
                s += ch;
            }
            token.setInfo(s, TokenType.INTCON);
        } 
        // StringConst
        else if (ch == '\"') {
            while (true) {
                // if next is " not \"  -> break
                if (source.charAt(curPos) == '\"' && ch != '\\' ) { 
                    ch = readNextChar();
                    s += ch;
                    break;
                }
                ch = readNextChar();
                s += ch; 
            }
            token.setInfo(s, TokenType.STRCON);
        }
        // CharConst
        else if (ch == '\'') {
            ch = readNextChar();
            s += ch;
            // if \ read one more
            if (ch == '\\') {
                ch = readNextChar();
                s += ch;
            }
            // read '
            ch = readNextChar();
            s += ch;
            token.setInfo(s, TokenType.CHRCON);
        }
        // &&, error &
        else if (ch == '&') { 
            if (source.charAt(curPos) == '&') { // &&
                ch = readNextChar();
                s += ch;
                token.setInfo(s, TokenType.AND);
            } else { // -----错误&-----
                s += "&";
                token.setInfo(s, TokenType.AND);
                Error.addError(lineNum, 'a');
            }
        }
        // ||, error |
        else if (ch == '|') { // ||
            if (source.charAt(curPos) == '|') {
                ch = readNextChar();
                s += ch;
                token.setInfo(s, TokenType.OR);
            } else { // -----错误|-----
                s += "|";
                token.setInfo(s, TokenType.OR);
                Error.addError(lineNum, 'a');
            }
        }
        // other token
        else {
            switch (ch) {
                case '!':
                    if (source.charAt(curPos) == '=') {
                        ch = readNextChar();
                        s += ch;
                        token.setInfo(s, TokenType.NEQ);
                    } else {
                        token.setInfo(s, TokenType.NOT);
                    }
                    break;

                case '+':
                    token.setInfo(s, TokenType.PLUS);
                    break;

                case '-':
                    token.setInfo(s, TokenType.MINU);
                    break;

                case '*':
                    token.setInfo(s, TokenType.MULT);
                    break;

                case '/':
                    token.setInfo(s, TokenType.DIV);
                    break;

                case '%':
                    token.setInfo(s, TokenType.MOD);
                    break;

                case '<':
                    if (source.charAt(curPos) == '=') {
                        ch = readNextChar();
                        s += ch;
                        token.setInfo(s, TokenType.LEQ);
                    } else {
                        token.setInfo(s, TokenType.LSS);
                    }
                    break;

                case '>':
                    if (source.charAt(curPos) == '=') {
                        ch = readNextChar();
                        s += ch;
                        token.setInfo(s, TokenType.GEQ);
                    } else {
                        token.setInfo(s, TokenType.GRE);
                    }
                    break;

                case '=':
                    if (source.charAt(curPos) == '=') {
                        ch = readNextChar();
                        s += ch;
                        token.setInfo(s, TokenType.EQL);
                    } else {
                        token.setInfo(s, TokenType.ASSIGN);
                    }
                    break;

                case ';':
                    token.setInfo(s, TokenType.SEMICN);
                    break;
                
                case ',':
                    token.setInfo(s, TokenType.COMMA);
                    break;

                case '(':
                    token.setInfo(s, TokenType.LPARENT);
                    break;

                case ')':
                    token.setInfo(s, TokenType.RPARENT);
                    break;

                case '[':
                    token.setInfo(s, TokenType.LBRACK);
                    break;

                case ']':
                    token.setInfo(s, TokenType.RBRACK);
                    break;

                case '{':
                    token.setInfo(s, TokenType.LBRACE);
                    break;

                case '}':
                    token.setInfo(s, TokenType.RBRACE);
                    break;

                default:
            }
        }
        return true;
    }

    private void setTokens() {
        while (readNextToken()) {
            tokens.add(token);
        }
    }

    public List<Token> getTokens() {
        setTokens();
        return tokens;
    }
}
