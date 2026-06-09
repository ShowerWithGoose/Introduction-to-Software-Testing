package frontend.error;

/**
 * 错误类型枚举类
 * 每个错误有一个属性：错误码errorCode
 */
public enum ErrorType {
    IEALGAL_CHAR("a");

    private String errorCode;
    ErrorType(String errorCode) {
        this.errorCode = errorCode;
    }

    public String getErrorCode() {
        return errorCode;
    }
}
