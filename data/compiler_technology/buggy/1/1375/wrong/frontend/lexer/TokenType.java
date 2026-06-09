package frontend.lexer;

import java.util.regex.Pattern;

public enum TokenType {
        MAINTK(true, "main"),
        CONSTTK(true, "const"),
        INTTK(true, "int"),
        CHARTK(true, "char"),
        BREAKTK(true, "break"),
        CONTINUETK(true, "continue"),
        IFTK(true, "if"),
        ELSETK(true, "else"),
        FORTK(true, "for"),
        GETINTTK(true, "getint"),
        GETCHARTK(true, "getchar"),
        PRINTFTK(true, "printf"),
        RETURNTK(true, "return"),
        VOIDTK(true, "void"),
        IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
        INTCON(false, "[0-9]+"),
        STRCON(false, "(\\\"[^\\\"]*\\\")"),
        CHRCON(false, "('([ !#$%&()*+,\\-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\]\\[^_abcdefghijklmnopqrstuvwxyz{|}~])'|'(\\\\[\\\\abtn\"vf'0])')"),
        LEQ(false, "<="),
        LSS(false, "<"),
        GEQ(false, ">="),
        GRE(false, ">"),
        EQL(false, "=="),
        NEQ(false, "!="),
        PLUS(false, "\\+"),
        MINU(false, "-"),
        MULT(false, "\\*"),
        DIV(false, "/"),
        NOT(false, "!"),
        AND(false, "&&"),
        OR(false, "\\|\\|"),
        MOD(false, "%"),
        ASSIGN(false, "="),
        SEMICN(false, ";"),
        COMMA(false, ","),
        LPARENT(false, "\\("),
        RPARENT(false, "\\)"),
        LBRACK(false, "\\["),
        RBRACK(false, "]"),
        LBRACE(false, "\\{"),
        RBRACE(false, "}"),
        ERROR_A(false,"[&|]");
    TokenType(boolean isGreed, String patternString){
        this.isGreed = isGreed;
        this.patternString = patternString;
        if(this.isGreed){
            this.pattern = Pattern.compile("^"+this.patternString+"(?![_A-Za-z0-9])");
        }else{
            this.pattern = Pattern.compile("^"+this.patternString);
        }
    }

    public boolean isGreed;
    public String patternString;
    public Pattern pattern;

    public Pattern getPattern(){
        return this.pattern;
    }

    @Override
    public String toString(){return this.name();}

}
