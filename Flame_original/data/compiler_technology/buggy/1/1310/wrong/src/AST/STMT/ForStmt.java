package src.AST.STMT;

import src.AST.EXP.Exp;
import src.AST.LVal;
import src.fronted.LexicAnalysis.Word;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class ForStmt {
    private LVal lVal;
    private Word assign;
    private Exp exp;

    public ForStmt() {
    }

    public ForStmt analyse() {
        this.lVal = new LVal().analyse();
        this.assign = utils.read("=");
        this.exp = new Exp().analyse();
        syntaxList.add("<" + SyntaxType.ForStmt + ">");
        return this;
    }
}
