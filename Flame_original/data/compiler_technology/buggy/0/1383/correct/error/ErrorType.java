package error;

/**
 * @Description ErrorType
 */

public enum ErrorType {
    // 词法错误
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
