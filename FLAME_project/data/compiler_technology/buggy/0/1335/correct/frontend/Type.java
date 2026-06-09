package frontend;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public enum Type {
    // 标识符和关键字
    IDENFR("IDENFR", "[a-zA-Z_][a-zA-Z0-9_]*"),
    ELSETK("ELSETK", "else"),
    VOIDTK("VOIDTK", "void"),
    INTTK("INTTK", "int"),
    CHARTK("CHARTK", "char"),
    MAINTK("MAINTK", "main"),
    CONSTTK("CONSTTK", "const"),
    IFTK("IFTK", "if"),
    CONTINUETK("CONTINUETK", "continue"),
    BREAKTK("BREAKTK", "break"),
    RETURNTK("RETURNTK", "return"),
    PRINTFTK("PRINTFTK", "printf"),
    GETINTTK("GETINTTK", "getint"),
    GETCHARTK("GETCHARTK", "getchar"),
    // 数据类型
    INTCON("INTCON", "[0-9]+"),
    STRCON("STRCON", "\"[^\"]*\""),
    CHRCON("CHRCON", "'.'"),
    // 操作符
    NOT("NOT", "!"),
    MULT("MULT", "\\*"),
    DIV("DIV", "/"),
    AND("AND", "&&"),
    OR("OR", "\\|\\|"),
    MOD("MOD", "%"),
    PLUS("PLUS", "\\+"),
    MINU("MINU", "-"),
    ASSIGN("ASSIGN", "="),
    LSS("LSS", "<"),
    LEQ("LEQ", "<="),
    GRE("GRE", ">"),
    GEQ("GEQ", ">="),
    EQL("EQL", "=="),
    NEQ("NEQ", "!="),
    // 分隔符
    SEMICN("SEMICN", ";"),
    COMMA("COMMA", ","),
    LPARENT("LPARENT", "\\("),
    RPARENT("RPARENT", "\\)"),
    LBRACK("LBRACK", "\\["),
    RBRACK("RBRACK", "\\]"),
    LBRACE("LBRACE", "\\{"),
    RBRACE("RBRACE", "\\}"),
    FORTK("FORTK", "for");

    private final String code;
    private final String regex;

    // 直接定义保留字集合
    private static final Set<String> RESERVED_WORDS = new HashSet<>(Arrays.asList(
            "else", "void", "int", "char", "main", "const", "if", "continue",
            "break", "return", "printf", "getint", "getchar", "for"
    ));

    Type(String code, String regex) {
        this.code = code;
        this.regex = regex;
    }

    public String getCode() {
        return code;
    }

    public String getRegex() {
        return regex;
    }

    // 检查是否为保留字
    public static boolean isReservedWord(String word) {
        return RESERVED_WORDS.contains(word);
    }
}
