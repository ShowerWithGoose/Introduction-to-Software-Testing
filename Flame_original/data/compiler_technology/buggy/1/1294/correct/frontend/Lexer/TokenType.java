package frontend.Lexer;

import java.util.regex.Pattern;

//类别码
//两个属性，是否贪婪匹配 & 正则表达式匹配规则
public enum TokenType {
    //保留字
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
    //标识符 & 常量
    IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
    INTCON(false, "[0-9]+"),
    CHRCON(false, "'.{1,2}'"),
    //CHRCON(false, "'\\'"),
    //CHRCON(false, "'.' | '\\a' | '\\b' | '\\t' | '\\n' | '\\v' | '\\f' | '\\0' "),
    STRCON(false, "\\\"([^\\\"]|\\.)*\\\""),
    //比较运算符
    LEQ(false,"<="),
    LSS(false, "<"),
    GEQ(false, ">="),
    GRE(false, ">"),
    EQL(false, "=="),
    NEQ(false, "!="),
    //逻辑运算符
    NOT(false, "!"),
    AND(false, "&&"),
    OR(false, "\\|\\|"),
    //算数运算符
    PLUS(false, "\\+"),
    MINU(false, "-"),
    MULT(false, "\\*"),
    DIV(false, "/"),
    MOD(false, "%"),
    //赋值
    ASSIGN(false, "="),
    //逗号、分号、各种括号
    SEMICN(false,";"),
    COMMA(false,","),
    LPARENT(false,"\\("),
    RPARENT(false,"\\)"),
    LBRACK(false,"\\["),
    RBRACK(false,"\\]"),
    LBRACE(false,"\\{"),
    RBRACE(false, "\\}"),
    //报错
    SINGLEAND(false, "&"),
    SINGLEOR(false, "\\|");

    private boolean isGreed;
    private String patternStr;
    private Pattern pattern;

    TokenType(boolean isGreed, String patternStr){
        this.isGreed = isGreed;
        this.patternStr = patternStr;
        if(this.isGreed){
            this.pattern = Pattern.compile("^" + this.patternStr + "(?![_A-Za-z0-9])");
        } else {
            this.pattern = Pattern.compile("^" + this.patternStr);
        }
    }

    public Pattern getPattern(){
        return this.pattern;
    }

    @Override
    public String toString(){
        return this.name();
    }
}
