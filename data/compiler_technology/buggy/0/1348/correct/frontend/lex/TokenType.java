package frontend.lex;

import type.BasicType;
import type.CharType;
import type.IntType;
import type.VoidType;

public enum TokenType {
    MAINTK("main"),
    DIV("/"),
    CONSTTK("const"),
    VOIDTK("void"),
    INTTK("int"),
    CHARTK("char"),
    IFTK("if"),
    ELSETK("else"),
    BREAKTK("break"),
    CONTINUETK("continue"),
    FORTK("for"),
    RETURNTK("return"),
    IDENFR("Ident"),
    INTCON("IntConst"),
    CHRCON("CharConst"),
    STRCON("StringConst"),
    PLUS("+"),
    MINU("-"),
    MULT("*"),
    MOD("%"),
    ASSIGN("="),
    EQL("=="),
    NEQ("!="),
    NOT("!"),
    LEQ("<="),
    LSS("<"),
    GEQ(">="),
    GRE(">"),
    AND("&&"),
    OR("||"),
    SEMICN(";"),
    COMMA(","),
    LPARENT("("),
    RPARENT(")"),
    LBRACK("["),
    RBRACK("]"),
    LBRACE("{"),
    RBRACE("}"),
    GETINTTK("getint"),
    GETCHARTK("getchar"),
    PRINTFTK("printf"),
    ;
    public final String tokenValue;
    TokenType(String tokenValue) {
        this.tokenValue = tokenValue;
    }
    public BasicType toBasicType() {
        return switch (this) {
            case VOIDTK -> new VoidType();
            case INTTK -> new IntType();
            case CHARTK -> new CharType();
            default -> throw new RuntimeException("不可转换的token类型");
        };
    }
}
