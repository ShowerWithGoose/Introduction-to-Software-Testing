package error;

public enum MyErrorType {
    // 词法分析错误
    A_ILLEGAL_SYMBOL('a'),

    // 语法分析错误
    I_MISSING_SEMICOLON('i'),
    J_MISSING_RIGHT_PARENTHESIS('j'),
    K_MISSING_RIGHT_BRACKET('k'),

    // 语义分析错误
    B_NAME_REDEFINITION('b'),
    C_UNDEFINED_NAME('c'),
    D_FUNC_PARAM_COUNT_MISMATCH('d'),
    E_FUNC_PARAM_TYPE_MISMATCH('e'),
    F_RETURN_IN_VOID_FUNC('f'),
    G_MISSING_RETURN_IN_NON_VOID_FUNC('g'),
    H_MODIFY_CONST_VALUE('h'),
    L_PRINTF_ARG_COUNT_MISMATCH('l'),
    M_BREAK_CONTINUE_OUTSIDE_LOOP('m');

    private final char code;

    MyErrorType(char code) {
        this.code = code;
    }

    public char getCode() {
        return code;
    }
}