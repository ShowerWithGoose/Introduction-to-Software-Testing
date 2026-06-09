package frontend.check;

public enum ErrorType {
    ILLEGAL_SYMBOL("a"),                 // 非法符号
    NAME_REDEFINITION("b"),               // 名字重定义
    UNDEFINED_NAME("c"),                  // 未定义的名字
    PARAMETER_COUNT_MISMATCH("d"),        // 函数参数个数不匹配
    PARAMETER_TYPE_MISMATCH("e"),         // 函数参数类型不匹配
    VOID_FUNCTION_RETURN_MISMATCH("f"),   // 无返回值的函数存在不匹配的return语句
    MISSING_RETURN("g"),                  // 有返回值的函数缺少return语句
    CONSTANT_MODIFICATION("h"),           // 不能改变常量的值
    MISSING_SEMICOLON("i"),               // 缺少分号
    MISSING_RIGHT_PAREN("j"),             // 缺少右小括号
    MISSING_RIGHT_BRACE("k"),             // 缺少右中括号
    PRINTF_MISMATCH("l"),                 // printf中格式字符串与表达式个数不匹配
    BREAK_CONTINUE_OUTSIDE_LOOP("m");     // 在非循环块中使用break和continue语句

    private final String type;

    ErrorType(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }
}
