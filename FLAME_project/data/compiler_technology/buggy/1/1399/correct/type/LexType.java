/// ********************************************************************************
// * @FileName     : LexType.java
// * @Author       :
// * @Description  : 单词类型枚举类
// * @Notice       : None
// * @Time         : 2024-10-03 19:51
// * @Version      : 0.0
// ********************************************************************************/

package type;

import java.util.HashMap;

public enum LexType {
    IDENFR("IDENFR", "Ident"),
    INTCON("INTCON", "IntConst"),
    STRCON("STRCON", "StringConst"),
    CHRCON("CHRCON", "CharConst"),
    MAINTK("MAINTK", "main"),
    CONSTTK("CONSTTK", "const"),
    INTTK("INTTK", "int"),
    CHARTK("CHARTK", "char"),
    BREAKTK("BREAKTK", "break"),
    CONTINUETK("CONTINUETK", "continue"),
    IFTK("IFTK", "if"),

    ELSETK("ELSETK", "else"),
    NOT("NOT", "!"),
    AND("AND", "&&"),
    OR("OR", "||"),
    FORTK("FORTK", "for"),
    GETINTTK("GETINTTK", "getint"),
    GETCHARTK("GETCHARTK", "getchar"),
    PRINTFTK("PRINTFTK", "printf"),
    RETURNTK("RETURNTK", "return"),
    PLUS("PLUS", "+"),
    MINU("MINU", "-"),

    VOIDTK("VOIDTK", "void"),
    MULT("MULT", "*"),
    DIV("DIV", "/"),
    MOD("MOD", "%"),
    LSS("LSS", "<"),
    LEQ("LEQ", "<="),
    GRE("GRE", ">"),
    GEQ("GEQ", ">="),
    EQL("EQL", "=="),
    NEQ("NEQ", "!="),
    ASSIGN("ASSIGN", "="),

    SEMICN("SEMICN", ";"),
    COMMA("COMMA", ","),
    LPARENT("LPARENT", "("),
    RPARENT("RPARENT", ")"),
    LBRACK("LBRACK", "["),
    RBRACK("RBRACK", "]"),
    LBRACE("LBRACE", "{"),
    RBRACE("RBRACE", "}"),

    // note 其他类型（不在给出的词法表内）
    ERROR("ERROR", "法分析错误"), // 词法分析错误
    ANNOTATION("ANNOTATION", "注释"); // 注释

    /**
     * ===========================================================
     */

    private final String type;
    private final String content;
    public static HashMap<String, LexType> keyTokenMap = new HashMap<String, LexType>();

    // 填充map
    static {
        for (LexType lexType : LexType.values()) {
            if (!lexType.isOtherType()
                    && lexType != IDENFR
                    && lexType != STRCON
                    && lexType != CHRCON
                    && lexType != INTCON) {
                keyTokenMap.put(lexType.content, lexType);
            }
        }
    }

    LexType(String type, String content) {
        this.type = type;
        this.content = content;
    }


    // 比较两个枚举对象是否相同
    public boolean equals(LexType other) {
        return this == other;
    }

    // 两个枚举对象不同
    public boolean notEquals(LexType other) {
        return this != other;
    }

    // 判断传入的对象是否是合法的枚举且不是其他类型的枚举对象
    public static boolean isValid(Object obj) {
        if (!(obj instanceof LexType)) {
            return false;
        }
        LexType lexType = (LexType) obj;
        return !lexType.isOtherType();
    }

    // 判断是否为其他类型的枚举对象
    public boolean isOtherType() {
        return this == ERROR || this == ANNOTATION;
    }

    // 判断是否为关键字
    public static boolean isKeyWord(LexType lexType) {
        if (!isValid(lexType)) return false;
        return lexType.equals(MAINTK) ||
                lexType.equals(CONSTTK) ||
                lexType.equals(INTTK) ||
                lexType.equals(CHARTK) ||
                lexType.equals(BREAKTK) ||
                lexType.equals(CONTINUETK) ||
                lexType.equals(IFTK) ||
                lexType.equals(ELSETK) ||
                lexType.equals(VOIDTK) ||
                lexType.equals(FORTK) ||
                lexType.equals(RETURNTK) ||
                lexType.equals(GETINTTK) ||
                lexType.equals(GETCHARTK) ||
                lexType.equals(PRINTFTK);
    }

    @Override
    public String toString() {
        return type;
    }
}
