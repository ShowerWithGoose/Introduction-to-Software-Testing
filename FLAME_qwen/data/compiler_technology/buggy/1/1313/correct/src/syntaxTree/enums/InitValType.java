package src.syntaxTree.enums;

/**
 * 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
 * 的枚举
 */
public enum InitValType {
    EXP,
    BRACED_EXP,
    STRING_CONST
}
