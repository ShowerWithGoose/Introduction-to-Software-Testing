package src.syntaxTree.enums;

/**
 * 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
 * 的枚举
 */
public enum PrimaryExpType {
    EXP,
    LVAL,
    NUMBER,
    CHARACTER
}
