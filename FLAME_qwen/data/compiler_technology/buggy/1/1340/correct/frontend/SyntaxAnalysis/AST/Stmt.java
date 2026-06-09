package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class Stmt {
    public StmtType type;
    //公用
    public LVal lval;
    public Exp exp;

    public Block block;
    //cond if和for公用
    public Cond cond;
    public Stmt stmtIf;
    public Stmt stmtElse;

    public ForStmt forStmt1;
    public ForStmt forStmt2;
    public Stmt stmtFor;

    public Word stringConst;
    public ArrayList<Exp> expsPrintf= new ArrayList<>();



    public enum StmtType{
        LValEqualExp,
        expSemicn,
        block,
        _if,
        _for,
        _break,
        _continue,
        _return,
        _printf,
        _getint,
        _getchar,
    }
}
