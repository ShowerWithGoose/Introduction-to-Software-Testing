package src.syntaxTree.enums;

/**
 * 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
 * 的枚举
 */
public enum UnaryExpType {
    PRIMARY_EXP,
    IDENT,
    UNARY_OP
}
