package frontend.lexer;

import frontend.error.Error;
import frontend.error.TokenError;

import java.util.ArrayList;

public class TokenLexer { //词法分析器
    // lines就是输入的一行行内容
    private ArrayList<String> lines;
    private ArrayList<Token> tokens;

    public TokenLexer(ArrayList<String> lines) {
        this.lines = lines;
        this.tokens = new ArrayList<>();
        readLines();
    }

    public void readLines() {
        // row代表第几行
        // pos代表在该行的第几个位置
        boolean isComment = false;
        for (int row = 0; row < lines.size(); row++) {
            int pos = 0;
            String curLine = lines.get(row);
            while (pos < curLine.length()) {
                // 检查是否在多行注释中
                if (isComment) {
                    if (peekChar(curLine, pos) == '*') {
                        pos++;
                        if (peekChar(curLine, pos) == '/') {
                            isComment = false;
                            // 跳过 /
                            pos++;
                        }
                    } else {
                        pos++;
                    }
                } else {
                    if (isComment) {
                        if (peekChar(curLine, pos) == '*') {
                            pos++;
                            if (peekChar(curLine, pos) == '/') {
                                isComment = false;
                                // 跳过 /
                                pos++;
                            }
                        } else {
                            pos++;
                        }
                    }
                    // sb用来存储字符
                    StringBuilder sb = new StringBuilder();

                    // 读取Ident 和 main const int break continue ...
                    if (isLetter(peekChar(curLine, pos)) || peekChar(curLine, pos) == '_') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        while (isLetter(peekChar(curLine, pos)) || isDigit(peekChar(curLine, pos)) || peekChar(curLine, pos) == '_') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                        }
                        Token token = new Token(classifier(sb.toString()), sb.toString(), row);
                        tokens.add(token);
                    }
                    //读取IntConst
                    else if (isDigit(peekChar(curLine, pos))) {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        while (isDigit(peekChar(curLine, pos))) {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                        }
                        Token token = new Token(TokenType.INTCON, sb.toString(), row);
                        tokens.add(token);
                    }
                    //读取StirngConst
                    else if (peekChar(curLine, pos) == '"') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        while (peekChar(curLine, pos) != '"') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                        }
                        // 把后一个 " 也读进去
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.STRCON, sb.toString(), row);
                        tokens.add(token);
                    }
                    //读取CharConst
                    else if (peekChar(curLine, pos) == '\'') {
                        // 第一个 '
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        // 如果是转义字符
                        if (peekChar(curLine, pos) == '\\') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                        }
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        // 将后一个 ' 也读进去
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.CHRCON, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 ! 和 !=
                    else if (peekChar(curLine, pos) == '!') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '=') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                            Token token = new Token(TokenType.NEQ, sb.toString(), row);
                            tokens.add(token);
                        } else {
                            Token token = new Token(TokenType.NOT, sb.toString(), row);
                            tokens.add(token);
                        }
                    }
                    // 读取 &&
                    else if (peekChar(curLine, pos) == '&') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '&') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                            Token token = new Token(TokenType.AND, sb.toString(), row);
                            tokens.add(token);
                        } else {
                            //TODO: ERROR
                            Token token = new Token(TokenType.AND, sb.toString(), row);
                            tokens.add(token);
                            Error error = new Error();
                            TokenError tokenError = new TokenError(token.getLineNumber(), 'a');
                            error.addTokenError(tokenError);
                        }
                    }
                    // 读取 ||
                    else if (peekChar(curLine, pos) == '|') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '|') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                            Token token = new Token(TokenType.OR, sb.toString(), row);
                            tokens.add(token);
                        } else {
                            //TODO: ERROR
                            Token token = new Token(TokenType.OR, sb.toString(), row);
                            tokens.add(token);
                            Error error = new Error();
                            TokenError tokenError = new TokenError(token.getLineNumber(), 'a');
                            error.addTokenError(tokenError);
                        }
                    }
                    // 读取 +
                    else if (peekChar(curLine, pos) == '+') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.PLUS, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 -
                    else if (peekChar(curLine, pos) == '-') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.MINU, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 *
                    else if (peekChar(curLine, pos) == '*') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.MULT, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 /
                    else if (peekChar(curLine, pos) == '/') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '/') {
                            // 直接跳过当前行 // 后的部分
                            break;
                        } else if (peekChar(curLine, pos) == '*') {
                            isComment = true;
                            pos++;
                        } else {
                            Token token = new Token(TokenType.DIV, sb.toString(), row);
                            tokens.add(token);
                        }
                    }
                    // 读取 %
                    else if (peekChar(curLine, pos) == '%') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.MOD, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 < 和 <=
                    else if (peekChar(curLine, pos) == '<') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '=') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                            Token token = new Token(TokenType.LEQ, sb.toString(), row);
                            tokens.add(token);
                        } else {
                            Token token = new Token(TokenType.LSS, sb.toString(), row);
                            tokens.add(token);
                        }
                    }
                    // 读取 > 和 >=
                    else if (peekChar(curLine, pos) == '>') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '=') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                            Token token = new Token(TokenType.GEQ, sb.toString(), row);
                            tokens.add(token);
                        } else {
                            Token token = new Token(TokenType.GRE, sb.toString(), row);
                            tokens.add(token);
                        }
                    }
                    // 读取 = 和 ==
                    else if (peekChar(curLine, pos) == '=') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        if (peekChar(curLine, pos) == '=') {
                            sb.append(peekChar(curLine, pos));
                            pos++;
                            Token token = new Token(TokenType.EQL, sb.toString(), row);
                            tokens.add(token);
                        } else {
                            Token token = new Token(TokenType.ASSIGN, sb.toString(), row);
                            tokens.add(token);
                        }
                    }
                    // 读取 ;
                    else if (peekChar(curLine, pos) == ';') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.SEMICN, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 ;
                    else if (peekChar(curLine, pos) == ',') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.COMMA, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 (
                    else if (peekChar(curLine, pos) == '(') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.LPARENT, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 )
                    else if (peekChar(curLine, pos) == ')') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.RPARENT, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取 [
                    else if (peekChar(curLine, pos) == '[') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.LBRACK, sb.toString(), row);
                        tokens.add(token);
                    }// 读取 ]
                    else if (peekChar(curLine, pos) == ']') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.RBRACK, sb.toString(), row);
                        tokens.add(token);
                    }// 读取 {
                    else if (peekChar(curLine, pos) == '{') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.LBRACE, sb.toString(), row);
                        tokens.add(token);
                    }// 读取 }
                    else if (peekChar(curLine, pos) == '}') {
                        sb.append(peekChar(curLine, pos));
                        pos++;
                        Token token = new Token(TokenType.RBRACE, sb.toString(), row);
                        tokens.add(token);
                    }
                    // 读取空白符
                    else if (peekChar(curLine, pos) == ' ') {
                        pos++;
                    }
                    // 其他
                    else {
                        pos++;
                    }
                }
            }
        }
    }

    public boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    public boolean isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    public char peekChar(String curline, int pos) {
        if (pos < curline.length()) {
            return curline.charAt(pos);
        } else {
            return ' ';
        }
    }

    // 对于字符串的TokenType的判定
    public TokenType classifier(String s) {
        if (s.equals("main")) {
            return TokenType.MAINTK;
        } else if (s.equals("const")) {
            return TokenType.CONSTTK;
        } else if (s.equals("int")) {
            return TokenType.INTTK;
        } else if (s.equals("char")) {
            return TokenType.CHARTK;
        } else if (s.equals("break")) {
            return TokenType.BREAKTK;
        } else if (s.equals("continue")) {
            return TokenType.CONTINUETK;
        } else if (s.equals("if")) {
            return TokenType.IFTK;
        } else if (s.equals("else")) {
            return TokenType.ELSETK;
        } else if (s.equals("for")) {
            return TokenType.FORTK;
        } else if (s.equals("getint")) {
            return TokenType.GETINTTK;
        } else if (s.equals("getchar")) {
            return TokenType.GETCHARTK;
        } else if (s.equals("printf")) {
            return TokenType.PRINTFTK;
        } else if (s.equals("return")) {
            return TokenType.RETURNTK;
        } else if (s.equals("void")) {
            return TokenType.VOIDTK;
        } else {
            return TokenType.IDENFR;
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < tokens.size(); i++) {
            sb.append(tokens.get(i).toString() + "\n");
        }
        return sb.toString();

    }

    public void outputInfo(){
        for (int i = 0; i < tokens.size(); i++){
            System.out.print(tokens.get(i).getLineNumber() + " " +tokens.get(i).toString());
        }
    }


    public ArrayList<Token> getTokens() {
        return this.tokens;
    }

}
