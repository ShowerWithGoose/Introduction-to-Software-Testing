package frontend;

public enum LexType {
    IDENFR("IDENFR"),       // 标识符
    ELSETK("ELSETK"),       // else
    VOIDTK("VOIDTK"),       // void
    SEMICN("SEMICN"),       // ;
    INTCON("INTCON"),       // 整数常量
    NOT("NOT"),          // !
    MULT("MULT"),         // *
    COMMA("COMMA"),        // ,
    STRCON("STRCON"),       // 字符串常量
    AND("AND"),          // &&
    DIV("DIV"),          // /
    LPARENT("LPARENT"),      // (
    CHRCON("CHRCON"),       // 字符常量
    OR("OR"),           // ||
    MOD("MOD"),          // %
    RPARENT("RPARENT"),      // )
    MAINTK("MAINTK"),       // main
    FORTK("FORTK"),        // for
    LSS("LSS"),          // <
    LBRACK("LBRACK"),       // [
    CONSTTK("CONSTTK"),      // const
    GETINTTK("GETINTTK"),     // getint
    LEQ("LEQ"),          // <=
    RBRACK("RBRACK"),       // ]
    INTTK("INTTK"),        // int
    GETCHARTK("GETCHARTK"),    // getchar
    GRE("GRE"),          // >
    LBRACE("LBRACE"),       // {
    CHARTK("CHARTK"),       // char
    PRINTFTK("PRINTFTK"),     // printf
    GEQ("GEQ"),          // >=
    RBRACE("RBRACE"),       // }
    BREAKTK("BREAKTK"),      // break
    RETURNTK("RETURNTK"),     // return
    EQL("EQL"),          // ==
    CONTINUETK("CONTINUETK"),   // continue
    PLUS("PLUS"),         // +
    NEQ("NEQ"),          // !=
    IFTK("IFTK"),         // if
    MINU("MINU"),         // -
    ASSIGN("ASSIGN")        // =
    ;
    private String typeValue;
    LexType(String v) {
        typeValue = v;
    }

    public String getTypeValue() {
        return typeValue;
    }

}
