package fronted.lexer;

import java.util.Locale;

public class TokenType {

    public enum Type{
        IDENFR("identifier"),
        INTCON("intConst"),
        STRCON("stringConst"),
        CHRCON("charConst"),
        NOTE("note"),
        MAINTK("main"),
        CONSTTK("const"),
        INTTK("int"),
        CHARTK("char"),
        BREAKTK("break"),
        CONTINUETK("continue"),
        IFTK("if"),
        ELSETK("else"),
        NOT("!"),
        AND("&&"),
        OR("||"),
        FORTK("for"),
        GETINTTK("getint"),
        GETCHARTK("getchar"),
        PRINTFTK("printf"),
        RETURNTK("return"),
        PLUS("+"),
        MINU("-"),
        VOIDTK("void"),
        MULT("*"),
        DIV("/"),
        MOD("%"),
        LSS("<"),
        LEQ("<="),
        GRE(">"),
        GEQ(">="),
        EQL("=="),
        NEQ("!="),
        ASSIGN("="),
        SEMICN(";"),
        COMMA(","),
        LPARENT("("),
        RPARENT(")"),
        LBRACK("["),
        RBRACK("]"),
        LBRACE("{"),
        RBRACE("}");

        private final String name;
        Type(String name) {
            this.name = name;
        }

        public String getName() {
            return name;
        }

        @Override
        public String toString(){
            return this.name().toUpperCase(Locale.ROOT);
        }
    }
}
