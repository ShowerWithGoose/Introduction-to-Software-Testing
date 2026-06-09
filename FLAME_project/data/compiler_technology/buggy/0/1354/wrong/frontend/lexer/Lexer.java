package frontend.lexer;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.regex.Pattern;
import Utils.WrongError;

import javax.lang.model.type.TypeKind;

import static frontend.lexer.TokenType.*;



public class Lexer {
    public static final Lexer lexer = new Lexer();
    public final TokenList tokens = new TokenList();
    public ArrayList<WrongError> errors = new ArrayList<>();
    private static int lineIndex = 1;
    private Lexer(){

    }
    public static Lexer getInstance() {
        return lexer;
    }

    private int analysisType(String str) {
        for (TokenType tokenType : TokenType.values()) {
            Pattern p = tokenType.getPattern();
            if (p.matcher(str).matches()) {
                tokens.append(new Token(tokenType,str,lineIndex));
                return 0;
            }
        }
        return -1;
    }

    public int getChar(BufferedInputStream src) throws IOException {
        return src.read();
    }

    public TokenList lex(BufferedInputStream bis) throws IOException {
        int c = getChar(bis);
        while (c != -1) {
            c = skipSpace(bis,c);
            if (c == '/') {
                c = dealWithAnnotation(bis);
            } else if ( Character.isLowerCase(c) || Character.isUpperCase(c) || c == '_') {
                c = dealWithName(bis,c);
            } else if (Character.isDigit(c)) {
                c = dealWithDigit(bis,c);
            } else if (c == '\'') {
                c = dealWithChar(bis,c);
            } else if (c == '\"') {
                c = dealWithString(bis,c);
            } else if (isDoubleOperatorStart(c)) {
                c = dealWithDoubleOperator(bis,c);
            } else if (isSingleOperator(c)) {
                c = dealWithSingleOperator(bis,c);
            } else {
                System.out.println("runError: " + c);
            }
        }
        return tokens;
    }
    private int dealWithAnnotation(BufferedInputStream bis) throws IOException {
        int c = getChar(bis);
        if (c == '/') {
            c = getChar(bis);
            while (c != -1) {
                if (c == '\n') {
                    lineIndex++;
                    c = getChar(bis);
                    break;
                }
                c = getChar(bis);
            }
        } else if (c == '*') {
            c = getChar(bis);
            while (c != -1) {
                if (c == '*') {
                    c = getChar(bis);
                    if (c == '/') {
                        c = getChar(bis);
                        break;
                    } else {
                        continue;
                    }
                }
                c = getChar(bis);
                if (c == '\n') {
                    lineIndex++;
                }
            }
        } else {
            Token tk = new Token(DIV, "/",lineIndex);
            tokens.append(tk);
        }
        return c;
    }
    private int dealWithName(BufferedInputStream bis, int c) throws IOException {
        StringBuilder str = new StringBuilder();
        while (Character.isLetter((char) c) || (c <= '9' && c >= '0') || c == '_') {
            if (c != -1) {
                str.append((char) c);
            } else {
                if (c == '\n') {
                    lineIndex++;
                }
                break;
            }
            c = getChar(bis);
        }
        switch (str.toString())  {
            case "main": {
                Token tk = new Token(MAINTK,str.toString(),lineIndex);
                tokens.append(tk);
                break;
            }
            case "const": {
                Token tk = new Token(CONSTTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "int": {
                Token tk = new Token(INTTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "char": {
                Token tk = new Token(CHARTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "void": {
                Token tk = new Token(VOIDTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "break": {
                Token tk = new Token(BREAKTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "continue": {
                Token tk = new Token(CONTINUETK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "if": {
                Token tk = new Token(IFTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "else": {
                Token tk = new Token(ELSETK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "for": {
                Token tk = new Token(FORTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "getint": {
                Token tk = new Token(GETINTTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "getchar": {
                Token tk = new Token(GETCHARTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "printf": {
                Token tk = new Token(PRINTFTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
            case "return": {
                Token tk = new Token(RETURNTK, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }

            default: {
                Token tk = new Token(IDENFR, str.toString(), lineIndex);
                tokens.append(tk);
                break;
            }
        }
        return c;
    }
    private int dealWithDigit(BufferedInputStream bis, int c) throws IOException {
        StringBuilder str = new StringBuilder();
        while (Character.isDigit((char) c)) {
            if (c != -1) {
                str.append((char) c);
            } else {
                break;
            }
            c = getChar(bis);
        }
        Token tk = new Token(INTCON, str.toString(), lineIndex);
        tokens.append(tk);
        return c;
    }
    private int dealWithChar(BufferedInputStream bis, int c) throws IOException {
        StringBuilder str = new StringBuilder();

        // 添加首个字符
        str.append((char) c);
        int flag_escape = 0;
        c = getChar(bis);
        while (!(c == '\'' && flag_escape == 0)) {
            if (flag_escape == 0) {
                if (c == '\\') {
                    flag_escape = 1;
                }
                str.append((char) c);
                c = getChar(bis);
            } else {
                if ("abtnvf0\"'\\".indexOf(c) != -1) {
                    // 你的逻辑代码
                    flag_escape = 0;
                    str.append((char) c);
                    c = getChar(bis);
                } else {
                    System.out.println("escape error(lexer in lex in dealWithChar): " + c);
                }
            }

        }
        str.append((char) c);
        // 正则匹配合法字符
        String charSequence = str.toString();
        if (charSequence.matches("'([ -~]|\\\\['\"\\\\abtnvfn0])'")) {
            Token tk = new Token(CHRCON, charSequence, lineIndex);
            tokens.append(tk);
        }

        return getChar(bis); // 返回下一个字符
    }
    private int dealWithString(BufferedInputStream bis, int c) throws IOException {
        StringBuilder str = new StringBuilder();
        str.append((char) c);
        c = getChar(bis);
        if (c == -1) {
            return c;
        }
        if (c == '\"') {
            Token tk = new Token(STRCON, "", lineIndex);
            tokens.append(tk);
            c = getChar(bis);
            return c;
        }
        while (true) {
            if (c == '\\') {
                str.append("\\");
            } else {
                str.append((char) c);
            }
            c = getChar(bis);
            if (c == -1 || c == '\"') {
                break;
            }
        }
        if (c == -1) {
            return c;
        }
        str.append('\"');
        Token tk = new Token(STRCON, str.toString(), lineIndex);
        tokens.append(tk);
        c = getChar(bis);
        return c;
    }
    private boolean isSingleOperator(int c) {
        return "!+-*/%<>=;,()[]{}".indexOf(c) != -1;
    }
    private int dealWithSingleOperator(BufferedInputStream bis, int c) throws IOException {
        String operator = String.valueOf((char) c);  // 直接将当前字符转为字符串

        // 根据符号创建相应的Token
        Token tk = null;
        switch (operator) {
            case "!":
                tk = new Token(NOT, operator, lineIndex);
                break;
            case "+":
                tk = new Token(PLUS, operator, lineIndex);
                break;
            case "-":
                tk = new Token(MINU, operator, lineIndex);
                break;
            case "*":
                tk = new Token(MULT, operator, lineIndex);
                break;
            case "/":
                tk = new Token(DIV, operator, lineIndex);
                break;
            case "%":
                tk = new Token(MOD, operator, lineIndex);
                break;
            case "<":
                tk = new Token(LSS, operator, lineIndex);
                break;
            case ">":
                tk = new Token(GRE, operator, lineIndex);
                break;
            case "=":
                tk = new Token(ASSIGN, operator, lineIndex);
                break;
            case ";":
                tk = new Token(SEMICN, operator, lineIndex);
                break;
            case ",":
                tk = new Token(COMMA, operator, lineIndex);
                break;
            case "(":
                tk = new Token(LPARENT, operator, lineIndex);
                break;
            case ")":
                tk = new Token(RPARENT, operator, lineIndex);
                break;
            case "[":
                tk = new Token(LBRACK, operator, lineIndex);
                break;
            case "]":
                tk = new Token(RBRACK, operator, lineIndex);
                break;
            case "{":
                tk = new Token(LBRACE, operator, lineIndex);
                break;
            case "}":
                tk = new Token(RBRACE, operator, lineIndex);
                break;
            default:
                break;
        }

        if (tk != null) {
            tokens.append(tk);
        }

        return getChar(bis);  // 返回下一个字符
    }
    private boolean isDoubleOperatorStart(int c) {
        return "><=!&|".indexOf(c) != -1;
    }
    private int dealWithDoubleOperator(BufferedInputStream bis, int c) throws IOException {
        StringBuilder str = new StringBuilder();
        str.append((char) c);

        // 读取下一个字符来判断是否是双字符操作符
        int nextChar = getChar(bis);
        String operator = str.toString();

        Token tk = null;

        switch (operator) {
            case "&":
                if (nextChar == '&') {
                    tk = new Token(AND, "&&", lineIndex);
                } else {
                    tk = new Token(AND, operator, lineIndex);
                    tokens.append(tk);
                    dealWithError('&');
                    return nextChar;
                }
                break;
            case "|":
                if (nextChar == '|') {
                    tk = new Token(OR, "||", lineIndex);
                } else {
                    tk = new Token(OR, operator, lineIndex);
                    dealWithError('|');
                    tokens.append(tk);
                    return nextChar;
                }
                break;
            case "<":
                if (nextChar == '=') {
                    tk = new Token(LEQ, "<=", lineIndex);
                } else {
                    tk = new Token(LSS, "<", lineIndex);
                    tokens.append(tk);
                    return nextChar;
                }
                break;
            case ">":
                if (nextChar == '=') {
                    tk = new Token(GEQ, ">=", lineIndex);
                } else {
                    tk = new Token(GRE, ">", lineIndex);
                    tokens.append(tk);
                    return nextChar;
                }
                break;
            case "=":
                if (nextChar == '=') {
                    tk = new Token(EQL, "==", lineIndex);
                } else {
                    tk = new Token(ASSIGN, "=", lineIndex);
                    tokens.append(tk);
                    return nextChar;
                }
                break;
            case "!":
                if (nextChar == '=') {
                    tk = new Token(NEQ, "!=", lineIndex);
                } else {
                    tk = new Token(NOT, "!", lineIndex);
                    tokens.append(tk);
                    return nextChar;
                }
                break;
            default:
                System.out.println("error: "+ operator);
                // 如果不是双字符操作符，将第一个字符作为单字符操作符处理
                return dealWithSingleOperator(bis, c);
        }

        if (tk != null) {
            tokens.append(tk);
        }

        return getChar(bis);  // 返回下一个字符
    }
    private int dealWithError(char c){
        errors.add(new WrongError(""+c,lineIndex));
        return c;
    }
    private int skipSpace(BufferedInputStream bis,int c) throws IOException {
        while (Character.isWhitespace((char) c) || c == '\n') {
            if (c == '\n') {
                lineIndex++;
            }
            c = getChar(bis);
        }
        return c;
    }
}
