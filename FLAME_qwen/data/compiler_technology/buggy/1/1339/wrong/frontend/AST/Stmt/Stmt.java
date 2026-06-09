package frontend.AST.Stmt;

import frontend.AST.AST;
import frontend.AST.SyntaxNode;

//Stmt â†’ LVal '=' Exp ';' // i
//        | [Exp] ';' // i
//        | Block
//        | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
//        | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
//        | 'break' ';' | 'continue' ';' // i
//        | 'return' [Exp] ';' // i
//        | LVal '=' 'getint''('')'';' // i j
//        | LVal '=' 'getchar''('')'';' // i j
//        | 'printf''('StringConst {','Exp}')'';' // i j
// Stmt -> AssignStmt | ExpStmt | BlockStmt | IfStmt | For | BreakStmt | ContinueStmt | ReturnStmt | GetStmt | PrintStmt
public class Stmt implements SyntaxNode {
    @Override
    public void print() {
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<Stmt>";
    }
}
