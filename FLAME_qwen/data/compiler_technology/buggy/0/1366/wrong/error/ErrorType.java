package error;

public enum ErrorType {
    ILLEGAL_AND_OR("a"),
    NAME_REDEFINE_VAR("b"),
    UNDEFINED_NAME_VAR("c"),
    MISMATCH_NUM_PARAMETER("d"),
    MISMATCH_TYPE_PARAMETER("e"),
    EXTRA_RETURN("f"),
    LACK_OF_RETURN("g"),
    CONST_CHANGE("h"),
    LACK_OF_SEMICN("i"),
    LACK_OF_RPARENT("j"),
    LACK_OF_RBRACK("k"),
    MISMATCH_NUM_OF_VAR_IN_PRINTF("l"),
    EXTRA_BREAK_OR_CONTINUE("m");

    private final String error_type;

    ErrorType(String a) {
        error_type = a;
    }

    public String getError_type() {
        return error_type;
    }
}
