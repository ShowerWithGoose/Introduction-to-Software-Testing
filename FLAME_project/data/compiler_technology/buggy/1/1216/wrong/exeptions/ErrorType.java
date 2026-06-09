package exeptions;

public enum ErrorType {
    ILLEGAL_SYMBOL("a"),
    REDEFINED_TOKEN("b"), // 位置：<Ident>所在行数
    UNDEFINED_TOKEN("c"), // 同上
    MISMATCH_PARAM_COUNT("d"), // 位置：函数调用中的函数名<Ident>所在行数
    MISMATCH_PARAM_TYPE("e"), // 同上
    ILLEGAL_RETURN("f"), // void函数有返回值，报错
    MISS_RETURN("g"), // int, char函数没 有返回值，位置是函数结尾的'}'
    MODIFY_CONST("h"), // 给常量赋值
    MISS_SEMICN("i"),
    MISS_RPARENT("j"),
    MISS_RBRACK("k"),
    MISMATCH_PRINTF("l"),
    ILLEGAL_BREAK_CONTINUE("m");

    private final String code;

    ErrorType(String code) {
        this.code = code;
    }

    @Override
    public String toString() {
        return code;
    }
}
