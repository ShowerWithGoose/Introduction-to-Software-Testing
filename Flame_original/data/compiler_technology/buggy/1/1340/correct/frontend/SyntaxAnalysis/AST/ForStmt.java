package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class ForStmt {
    public LVal lval;
    public Word assign;
    public Exp exp;
}
