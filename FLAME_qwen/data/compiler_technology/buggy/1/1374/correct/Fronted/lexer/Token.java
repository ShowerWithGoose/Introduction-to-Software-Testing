package Fronted.lexer;

import java.math.BigInteger;

public class Token {
    private String token; //单词

    private LexerType type; //类别码

    private int line; //行号

    private long num; //值

    public Token(String token, LexerType type, int line, BigInteger num) {
        this.token = token;
        this.type = type;
        this.line = line;
        this.num = 0;
    }

    public String getToken() {
        return token;
    }

    public LexerType getType() {
        return type;
    }

    public int getLine() {
        return line;
    }

    public long getNum() {
        return num;
    }

    @Override
    public String toString() {
        return type + " " + token + "\n";
    }
}
