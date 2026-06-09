package src.syntaxTree.enums;

/**
 * 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
 * 的枚举
 */
public enum ConstInitValType {
    CONST_EXP,
    BRACED_CONST_EXP,
    STRING_CONST
}
