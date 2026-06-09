package Parser.Lexer;

import Parser.Syntax;

public class Token implements Syntax {
    private TokenType type; // this.TokenType
    private int lineNum; // this.lineNum
    private String content; // this.content
    private boolean used;
    private boolean error;

    public Token(TokenType type, int lineNum, String content) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
        this.used = false;
        this.error = false;
    }

    public Token(TokenType type, int lineNum, String content, int op) {
        this.type = type;
        this.lineNum = lineNum;
        this.content = content;
        this.used = false;
        this.error = true;
    }

    public String getContent() {
        return content;
    }

    public String getType() {
        return type.toString();
    }

    @Override
    public String getName() {
        StringBuilder sb = new StringBuilder();
        sb.append(getType() + " " + getContent() + "\n");
        return sb.toString();
    }

    @Override
    public String syntaxOutput() {
        return getName();
    }

    public enum TokenType {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK,
        ELSETK, NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU,
        VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
    }

    public void setUsed() {
        used = true;
    }

    public boolean isUsed() {
        return used;
    }

    public void setUnused() {
        used = false;
    }

    public int getLineNum() {
        return lineNum;
    }

    public boolean isError() {
        return error;
    }
}
