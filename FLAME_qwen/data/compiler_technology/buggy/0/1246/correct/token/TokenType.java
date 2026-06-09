package token;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * @Description TokenType一一列举
 * @Author
 * @Date 2024/9/17
 */
public enum TokenType {
    // 标识符
    IDENFR("[a-zA-Z_][a-zA-Z_0-9]*"),
    // 整数
    INTCON("[1-9][0-9]*|0"),
    // 字符串
    STRCON("\"[^\"]*\""),
    // 字符
    CHRCON("\\'(.|[\f\n\t\b'\"])\\'"),

    // 保留字
    MAINTK("main"),
    CONSTTK("const"),
    INTTK("int"),
    CHARTK("char"),
    BREAKTK("break"),
    CONTINUETK("continue"),
    IFTK("if"),
    ELSETK("else"),
    FORTK("for"),
    GETINTTK("getint"),
    GETCHARTK("getchar"),
    PRINTFTK("printf"),
    RETURNTK("return"),
    VOIDTK("void"),

    // 运算符
    NOT("!"),
    AND("&&"),
    OR("||"),
    PLUS("+"),
    MINU("-"),
    MULT("*"),
    DIV("/"),
    MOD("%"),
    ASSIGN("="),

    LSS("<"),
    GRE(">"),
    LEQ("<="),
    GEQ(">="),
    EQL("=="),
    NEQ("!="),
    //  数制(可能用到)
    DEC_FLOAT("([0-9]*\\.[0-9]*((p|P|e|E)(\\+|\\-)?[0-9]+)?)|" +
            "([0-9]*[\\.]?[0-9]*(p|P|e|E)((\\+|\\-)?[0-9]+)?)"),
    HEX_FLOAT("(0(x|X)[0-9A-Fa-f]*\\.[0-9A-Fa-f]*((p|P|e|E)(\\+|\\-)?[0-9A-Fa-f]*)?)|" +
            "(0(x|X)[0-9A-Fa-f]*[\\.]?[0-9A-Fa-f]*(p|P|e|E)((\\+|\\-)?[0-9A-Fa-f]*)?)"),
    DEC_INT("0|([1-9][0-9]*)"),
    HEX_INT("0(x|X)[0-9A-Fa-f]+"),
    OCT_INT("0[0-7]+"),

    // 括号、逗号、分号
    LPARENT("("),
    RPARENT(")"),
    LBRACK("["),
    RBRACK("]"),
    LBRACE("{"),
    RBRACE("}"),
    SEMICN(";"),
    COMMA(","),
    ERROR("errorA");

    public static final List<Character> singleCharList = Arrays.asList(
            '+', '-', '*', '/', '%', '>', '<', '=', '!', ',', ';', '(', ')', '[', ']', '{', '}');
    // 双字符分界符中 首字符的列表
    // && || <= >= == !=
    public static final List<Character> doubleCharList = Arrays.asList(
            '&', '|', '<', '>', '=', '!');

    private final String str;

    TokenType(String str) {
        this.str = str;
    }

    private static final HashMap<String, TokenType> tokenTypeMap = new HashMap<>();

    static {
        for (TokenType tokenType : TokenType.values()) {
            tokenTypeMap.put(tokenType.getStr(), tokenType);
        }
    }

    public String getStr() {
        return str;
    }

    public static TokenType getTokenType(String str) {
        return tokenTypeMap.get(str);
    }

    // 保留字列表
    public static final List<String> reservedTokenList = Arrays.asList(
            "int", "char", "main", "break", "continue",
            "for", "return", "const", "getint", "getchar",
            "if", "else", "void", "printf");

    public static TokenType isReserved(String str) {
        if (reservedTokenList.contains(str)) {
            return getTokenType(str);
        }
        return null;
    }

}
