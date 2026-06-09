package error;

/**
 * 错误类别枚举类
 */
public enum ErrorType {
    ILLEGAL_CHAR("a"),      // 非法符号
    MISSING_SEMICN("i"),     // 缺少分号
    MISSING_R_PARENT("j"),   // 缺少右小括号
    MISSING_R_BRACKET("k");  // 缺少右中括号

    private String code;

    ErrorType(String code) {
        this.code = code;
    }

    public String getCode() {
        return this.code;
    }
}
