package error;

public enum ErrorType {
    ILLEGAL_SYMBOL("a"),
    REDEFINED_NAME("b"),
    UNDEFINED_NAME("c"),
    PARAM_COUNT_MISMATCH("d"),
    PARAM_TYPE_MISMATCH("e"),
    RETURN_IN_NON_VOID_FUNC("f"),
    MISSING_RETURN_IN_FUNC("g"),
    CONST_MODIFICATION("h"),
    MISSING_SEMICOLON("i"),
    MISSING_PARENTHESIS("j"),
    MISSING_BRACKET("k"),
    PRINTF_FORMAT_MISMATCH("l"),
    BREAK_CONTINUE_OUTSIDE_LOOP("m");

    private final String code;

    ErrorType(String code) {
        this.code = code;
    }

    public String getCode() {
        return code;
    }
}