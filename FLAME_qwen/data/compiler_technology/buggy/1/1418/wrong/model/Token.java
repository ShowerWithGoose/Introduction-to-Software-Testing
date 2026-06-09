package model;

import enums.TokenType;

public class Token {
    private String name;      // 名字
    private TokenType type;      // 类型
    private int lineno;     // 行号
    private int colno;      //列号，以一个单词为单位排序

    // 构造函数
    public Token(){}
    public Token(String name, TokenType type, int lineno, int colno) {
        this.name = name;
        this.type = type;
        this.lineno = lineno;
        this.colno = colno;
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

    public int getColno() {
        return lineno;
    }
    public void setColno(int colno) {
        this.colno = colno;
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
