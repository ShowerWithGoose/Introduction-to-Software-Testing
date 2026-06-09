package frontend.lexer;

/**
 * @author
 * 错误类别枚举类
 */
public enum ErrorType {
    /* ---------- lexer errors begin ---------- */
    ILLEGALCHAR('a');
    /* ---------- lexer errors end ---------- */
    private char typeCode; // 错误类别码

    ErrorType(char typeCode) {
        this.typeCode = typeCode;
    }

    /**
     * 获取错误对应的错误类别码
     * @return 错误类别码
     */
    public char getTypeCode() {
        return this.typeCode;
    }
}
