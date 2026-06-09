package frontend.Lexer;

import java.util.regex.Pattern;

public enum TokenType {
        CHARTK(0,"char"),
        MAINTK(0,"main"),
        CONSTTK(0,"const"),
        INTTK(0,"int"),
        BREAKTK(0,"break"),
        CONTINUETK(0,"continue"),
        IFTK(0,"if"),
        ELSETK(0,"else"),
        FORTK(0,"for"),
        GETINTTK(0,"getint"),
        GETCHARTK(0,"getchar"),
        PRINTFTK(0,"printf"),
        RETURNTK(0,"return"),
        VOIDTK(0,"void"),
        /* ---------- specific elements end ---------- */
        /* ----------- begin ---------- */
        IDENFR(1,"[_A-Za-z][_A-Za-z0-9]*"),
        INTCON(1,"[0-9]+"),
        STRCON(1,"\\\"[^\\\"]*\\\""),
            CHRCON(1,"'(.*?)'"),//TODO 匹配单引号

        /* ---------- end ---------- */
        /* ----------- comparison operation begin ---------- */
        LEQ(1,"<="),
        LSS(1,"<"),
        GEQ(1,">="),
        GRE(1,">"),
        EQL(1,"=="),
        NEQ(1,"!="),
        /* ---------- comparison operation end ---------- */
        /* ---------- arithmetic operation begin ---------- */
        PLUS(1,"\\+"),
        MINU(1,"-"),
        MULT(1,"\\*"),
        DIV(1,"/"),
        /* ---------- arithmetic operation end ---------- */
        /* ---------- logical operation begin ---------- */
        NOT(1,"!"),
        AND(1,"&&"),
        OR(1,"\\|\\|"),
        MOD(1,"%"),
        /* ---------- logical operation end ---------- */
        ASSIGN(1,"="),
        SEMICN(1,";"),
        COMMA(1,","),
        /* ---------- brackets begin ---------- */
        LPARENT(1,"\\("),
        RPARENT(1,"\\)"),
        LBRACK(1,"\\["),
        RBRACK(1,"]"),
        LBRACE(1,"\\{"),
        RBRACE(1,"}");
        /* ---------- brackets end ---------- */
        //used for distinguish const(CONSTYK) and const_int_a(IDENFR)
        private int flag;
        private String patternString;
        private Pattern pattern;
        TokenType(int flag, String patternString){
                this.flag = flag;
                this.patternString = patternString;
                if(flag==0){
                        this.pattern = Pattern.compile("^"+patternString+"(?![_A-Za-z0-9])");
                }else{
                        this.pattern = Pattern.compile("^"+patternString);
                }
        }

    public Pattern getPattern() {
        return pattern;
    }

    @Override
    public String toString() {
        //this.name()是枚举类中自带的方法，用于获取枚举常量的名字
        return this.name();
    }
}

