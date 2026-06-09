package frontend.lexer;

import output.MyStream;

import java.io.BufferedInputStream;
import java.io.IOException;

import static frontend.lexer.TokenType.*;

public class Lexer {
    private static final Lexer lexer = new Lexer();
    public static Lexer getInstance(){
        return lexer;
    }

    private int lineNo = 1;
    private int charNo = 1;
    private int curChar = -1;
    private final TokenList tokenList = new TokenList();

    private BufferedInputStream input = null;

    private void readCh() throws IOException {
        if (input != null) {
            curChar = input.read();
        } else {
            curChar = -1;
        }
    }

    public TokenList execute(BufferedInputStream input) throws IOException {
        this.input = input;
        readCh();
        while (curChar != -1) {
            readWhiteSpace();
            if (curChar == '/') {
                dealAnnotation();
            } else if (isIdent(curChar)) {
                dealIndent();
            } else if (isDigit(curChar)) {
                dealNumber();
            } else if (curChar == '\"') {
                dealString();
            } else if (curChar == '\'') {
                dealChar();
            } else {
                dealOthers();
            }
        }
        //anon: 在这里输出？
        tokenList.print();
        return tokenList;
    }

    private void dealChar() throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) curChar);
        readCh();
        if (curChar == '\\') {
            sb.append((char) curChar); //anon: 转义字符 \
            readCh();
            sb.append((char) curChar); //anon: 后一个字符 t
            readCh();
            sb.append((char) curChar); //anon: 第二个单引号 '
        } else {
            sb.append((char) curChar); //anon: 字符
            readCh();
            sb.append((char) curChar); //anon: 单引号
        }
        Token token = new Token(CHRCON, sb.toString(), lineNo);
        tokenList.addToken(token);
        readCh();
    }

    private void dealOthers() throws IOException {
        switch (curChar) {
            case '=': {
                readCh();
                if (curChar == '=') {
                    Token token = new Token(EQL, "==", lineNo);
                    tokenList.addToken(token);
                    readCh();
                } else {
                    Token token = new Token(ASSIGN, "=", lineNo);
                    tokenList.addToken(token);
                }
                break;
            }
            case '!': {
                readCh();
                if (curChar == '=') {
                    Token token = new Token(NEQ, "!=", lineNo);
                    tokenList.addToken(token);
                    readCh();
                } else {
                    Token token = new Token(NOT, "!", lineNo);
                    tokenList.addToken(token);
                }
                break;
            }
            case '<': {
                readCh();
                if (curChar == '=') {
                    Token token = new Token(LEQ, "<=", lineNo);
                    tokenList.addToken(token);
                    readCh();
                } else {
                    Token token = new Token(LSS, "<", lineNo);
                    tokenList.addToken(token);
                }
                break;
            }
            case '>': {
                readCh();
                if (curChar == '=') {
                    Token token = new Token(GEQ, ">=", lineNo);
                    tokenList.addToken(token);
                    readCh();
                } else {
                    Token token = new Token(GRE, ">", lineNo);
                    tokenList.addToken(token);
                }
                break;
            }
            case '&': {
                readCh();
                if (curChar == '&') {
                    Token token = new Token(AND, "&&", lineNo);
                    tokenList.addToken(token);
                    readCh();
                } else {
                    Token token = new Token(AND, "&&", lineNo);
                    tokenList.addToken(token);
                    //TODO: deal error
                    MyStream.errThrow(lineNo, "a");
                }
                break;
            }
            case '|': {
                readCh();
                if (curChar == '|') {
                    Token token = new Token(OR, "||", lineNo);
                    tokenList.addToken(token);
                    readCh();
                } else {
                    Token token = new Token(OR, "||", lineNo);
                    tokenList.addToken(token);
                    MyStream.errThrow(lineNo, "a");
                }
                break;
            }
            case '+': {
                Token token = new Token(PLUS, "+", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '-': {
                Token token = new Token(MINU, "-", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '*': {
                Token token = new Token(MULT, "*", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '/': {
                Token token = new Token(DIV, "/", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '%': {
                Token token = new Token(MOD, "%", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case ';': {
                Token token = new Token(SEMICN, ";", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case ',': {
                Token token = new Token(COMMA, ",", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '(': {
                Token token = new Token(LPARENT, "(", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case ')': {
                Token token = new Token(RPARENT, ")", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '[': {
                Token token = new Token(LBRACK, "[", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case ']': {
                Token token = new Token(RBRACK, "]", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '{': {
                Token token = new Token(LBRACE, "{", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            case '}': {
                Token token = new Token(RBRACE, "}", lineNo);
                tokenList.addToken(token);
                readCh();
                break;
            }
            default: {
                //TODO: 非法字符是否略过
                readCh();
            }
        }
    }

    private void dealString() throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) curChar);
        readCh();
        while (curChar != '\"') {
            if (curChar == -1) {
                throw new RuntimeException("no \" to match");
            }
            //"\n" => "\\n"
            /*if (curChar == '\\') {
                sb.append((char) "\\\\");
            } else {
                sb.append((char) curChar);
            }*/
            sb.append((char) curChar);
            readCh();
        }
        sb.append((char) curChar);
        Token token = new Token(STRCON, sb.toString(), lineNo);
        tokenList.addToken(token);
        readCh();
    }

    private void dealNumber() throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) curChar);
        readCh();
        while (isDigit(curChar)) {
            sb.append((char) curChar);
            readCh();
        }
        Token token = new Token(INTCON, sb.toString(), lineNo);
        tokenList.addToken(token);
    }

    private void dealIndent() throws IOException {
        StringBuilder sb = new StringBuilder();
        sb.append((char) curChar);
        readCh();
        while (isIdent(curChar) || isDigit(curChar)) {
            sb.append((char) curChar);
            readCh();
        }
        //anon: the last curchar is not ident
        dealKeyword(sb.toString());

    }

    private void dealKeyword(String str) {
        switch (str) {
            case "main": {
                Token token = new Token(MAINTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "const": {
                Token token = new Token(CONSTTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "int": {
                Token token = new Token(INTTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "char": {
                Token token = new Token(CHARTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "break": {
                Token token = new Token(BREAKTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "continue": {
                Token token = new Token(CONTINUETK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "if": {
                Token token = new Token(IFTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "else": {
                Token token = new Token(ELSETK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "for": {
                Token token = new Token(FORTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "getint": {
                Token token = new Token(GETINTTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "getchar": {
                Token token = new Token(GETCHARTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "printf": {
                Token token = new Token(PRINTFTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "return": {
                Token token = new Token(RETURNTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            case "void": {
                Token token = new Token(VOIDTK, str, lineNo);
                tokenList.addToken(token);
                break;
            }
            default: {
                Token token = new Token(IDENFR, str, lineNo);
                tokenList.addToken(token);
                break;
            }
        }
    }

    private void dealAnnotation() throws IOException {
        readCh();
        if (curChar == '/') {
            readCh();
            while (curChar != '\n' && curChar != -1) {
                readCh();
            }
            if (curChar == '\n') {
                lineNo++;
            }
            readCh();//anon: the next token char to deal withs
        } else if (curChar == '*') {
            readCh();
            while (curChar != -1) {
                if (curChar == '*') {
                    readCh();
                    if (curChar == '/') {
                        readCh();
                        break;
                    } else {
                        continue;
                    }
                }
                readCh();
            }
        } else {
            Token token = new Token(DIV, "/", lineNo);
            tokenList.addToken(token);
        }
    }

    private boolean isDigit(int curChar) {
        return Character.isDigit(curChar);
    }

    private boolean isIdent(int curChar) {
        return Character.isLetter(curChar) || curChar == '_';
    }

    /*
    * anon: 读完所有的空白符，返回第一个非空白符
    * */
    private void readWhiteSpace() throws IOException {
        while (Character.isWhitespace(curChar)) {
            if (curChar == '\n') {
                lineNo++;
//                charNo = 0;
            }
            readCh();
        }

    }
}
