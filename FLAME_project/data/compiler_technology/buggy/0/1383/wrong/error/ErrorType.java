package error;

/**
 * @Description ErrorType
 */

public enum ErrorType {
    // 词法错误
    ILLEGAL_INTEGER("非法的整数字面值"),
    ILLEGAL_CHAR("非法的字符字面值"),
    ILLEGAL_STRING("非法的字符串字面值"),
    // 非法的符号，特指单个&或者|
    ILLEGAL_SYMBOL("a"),
    OTHER("其他错误");


    private String message;

    ErrorType(String message) {
        this.message = message;
    }

    @Override
    public String toString() {
        return message;
    }
}
