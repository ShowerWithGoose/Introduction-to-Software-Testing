package src.AST.STMT;

import src.AST.EXP.Exp;
import src.AST.LVal;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtLVal {
    private LVal lVal;
    private Word assign;
    private Exp exp;
    private Word semicolon;

    public StmtLVal() {
    }

    public StmtLVal analyse() {
        this.lVal = new LVal().analyse();
        this.assign = utils.read("=");
        this.exp = new Exp().analyse();
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        //注意报错
        return this;
    }
}
