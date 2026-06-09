package model;

import enums.TokenType;

public class Token {
    private String name;      // 名字
    private TokenType type;      // 类型
    private int lineno;  // 行号

    // 构造函数
    public Token(String name, TokenType type, int lineno) {
        this.lineno = lineno;
        this.type = type;
        this.name = name;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public TokenType getType() {
        return type;
    }
    public void setType(TokenType type) {
        this.type = type;
    }

    public int getLineno() {
        return lineno;
    }
    public void setLineno(int lineno) {
        this.lineno = lineno;
    }

    @Override
    public String toString() {
        return "Token{" +
                "lineno=" + lineno +
                ", type='" + type + '\'' +
                ", name='" + name + '\'' +
                '}';
    }
}
