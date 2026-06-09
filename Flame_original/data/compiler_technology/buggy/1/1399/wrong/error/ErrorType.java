package error;

public enum ErrorType {
    ILLEGAL_SYM("a"),// 非法符号
    SEMICN_MISSING("i"),// 缺少分号
    RPARENT_MISSING("j"),// 缺少右小括号
    RBRACK_MISSING("k"),// 缺少右中括号
    OVER_RANGE("over_range"),// 超出范围
    OTHER_ERROR("other"); // 其他错误

    private final String type;

    ErrorType(String type) {
        this.type = type;
    }

    // 比较两个枚举对象是否相同
    public boolean equals(ErrorType other) {
        return this.type.equals(other.type);
    }

    @Override
    public String toString() {
        return type;
    }
}
