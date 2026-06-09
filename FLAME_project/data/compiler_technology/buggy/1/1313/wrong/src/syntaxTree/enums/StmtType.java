package src.syntaxTree.enums;

/**
 * 语句 Stmt → LVal '=' Exp ';' // i
 * | [Exp] ';' // i
 * | Block
 * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
 * | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
 * | 'break' ';' | 'continue' ';' // i
 * | 'return' [Exp] ';' // i
 * | LVal '=' 'getint''('')'';' // i j
 * | LVal '=' 'getchar''('')'';' // i j
 * | 'printf''('StringConst {','Exp}')'';' // i j
 * 的枚举类
 */
public enum StmtType {
    LVAL_EXP,
    SEMICN, // 仅有 ';'
    EXP, // Exp ;
    BLOCK,
    IF,
    FOR,
    BREAK,
    CONTINUE,
    RETURN,
    LVAL_GETINT,
    LVAL_GETCHAR,
    PRINTF
}
