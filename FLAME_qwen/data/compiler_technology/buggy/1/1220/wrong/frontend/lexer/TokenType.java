package frontend.lexer;

import java.util.regex.Pattern;

public enum TokenType {
    /* ---------- specific elements begin ---------- */
    /*
    MAINTK(true, "main"),
    CONSTTK(true, "const"),
    INTTK(true, "int"),
    BREAKTK(true, "break"),
    CONTINUETK(true, "continue"),
    IFTK(true, "if"),
    ELSETK(true, "else"),
    WHILETK(true, "while"),
    GETINTTK(true, "getint"),
    PRINTFTK(true, "printf"),
    RETURNTK(true, "return"),
    VOIDTK(true, "void"),
    /* ---------- specific elements end ---------- */
    /* ----------- begin ---------- */
    /*
    IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
    INTCON(false, "[0-9]+"),
    STRCON(false, "\\\"[^\\\"]*\\\""),
    CHRCON(false,
            "'\\\\.'|'[^\\\\\']'"),
    /* ---------- end ---------- */
    /* ----------- comparison operation begin ---------- */
    /*
    LEQ(false, "<="),
    LSS(false, "<"),
    GEQ(false, ">="),
    GRE(false, ">"),
    EQL(false, "=="),
    NEQ(false, "!="),
    /* ---------- comparison operation end ---------- */
    /* ---------- arithmetic operation begin ---------- */
    /*
    PLUS(false, "\\+"),
    MINU(false, "-"),
    MULT(false, "\\*"),
    DIV(false, "/"),
    /* ---------- arithmetic operation end ---------- */
    /* ---------- logical operation begin ---------- */
    /*
    NOT(false, "!"),
    AND(false, "&&"),
    OR(false, "\\|\\|"),
    MOD(false, "%"),
    /* ---------- logical operation end ---------- */
    /*
    ASSIGN(false, "="),
    SEMICN(false, ";"),
    COMMA(false, ","),
    /* ---------- brackets begin ---------- */
    /*
    LPARENT(false, "\\("),
    RPARENT(false, "\\)"),
    LBRACK(false, "\\["),
    RBRACK(false, "]"),
    LBRACE(false, "\\{"),
    RBRACE(false, "}");
    /* ---------- brackets end ---------- */

    //注意优先级
    //优先级指导书有定义吗？
    //怎么处理int，inta？--通过isStrict来限制正则匹配
    /*---------------strict word-------------*/

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
    /*----------------------------------------------*/
    /*--------------------symbol--------------------*/

    AND(false, "&&"),
    OR(false, "\\|\\|"),
    PLUS(false, "\\+"),
    MINU(false, "-"),
    MULT(false, "\\*"),
    DIV(false, "/"),
    MOD(false, "%"),
    LEQ(false, "<="),
    LSS(false, "<"),
    GEQ(false, ">="),
    GRE(false, ">"),
    EQL(false, "=="),
    ASSIGN(false, "="),
    NEQ(false, "!="),
    NOT(false, "\\!"),
    SEMICN(false, ";"),
    COMMA(false, ","),
    LPARENT(false, "\\("),
    RPARENT(false, "\\)"),
    LBRACK(false, "\\["),
    RBRACK(false, "\\]"),
    LBRACE(false, "\\{"),
    RBRACE(false, "\\}"),
    /*-----------------------------------------*/
    /*--------------identifier-----------------*/

    IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
    //注意：[]表示匹配里面的任何一个字符，而()表示一个捕获组
    /*-----------------------------------------*/
    /*--------------const----------------------*/

    INTCON(false, "[0-9]+"),
    //(0|[1-9][0-9]*)
    STRCON(false, "\\\"([^\\\"])*\\\""),
    //StringConst → '"' {ASCII} '"'
    //可以匹配“\""
    CHRCON(false,
            "('\\\\.')|('[^(\\\\)(\\\')]')");
    //注意，两种情况的，一定要加总体的大括号！！
    //java正则表达式种，匹配一个反斜杠要用4个反斜杠！！
    //CharConst → '\''ASCII'\'' \\这里的 '\'' 表示单引号 '
    //还有转义字符！其实是两个字符
    //"\'.|\\a|\\b|\\t|\\n|\\v|\\f|\\\"|\\\'|\\\\|\\0\'"，这个会有问题、、

    /*
    IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK, NOT, AND, OR,
    FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU, VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
    SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE;
    */
    private boolean isStrict;
    /*表示是否严格按照patternString来匹配
     即后面不能跟新的字符*/
    private String patternString;
    private Pattern pattern;

    TokenType(boolean isStrict, String patternString) {
        //通过patternString与greedy的判断得到pattern
        this.isStrict = isStrict;
        this.patternString = patternString;
        if (isStrict) {
            pattern = Pattern.compile("^(" + patternString + ")" + "(?![_A-Za-z0-9])");
            //负向前瞻断言，表示其后不能有_0-9A-Za-z
        } else {
            pattern = Pattern.compile("^(" + patternString + ")");
        }
    }

    public Pattern getPattern() {
        return pattern;
    }
}
