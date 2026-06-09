package src.AST.STMT;

import src.AST.LVal;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtLValGetint {
    private LVal lVal;
    private Word assign;
    private Word getint;
    private Word lParent;
    private Word rParent;
    private Word semicolon;

    public StmtLValGetint() {
    }

    public StmtLValGetint analyse() {
        this.lVal = new LVal().analyse();
        this.assign = utils.read("=");
//        if (this.assign == null) {
//            System.out.println("lack =   then we need to write it to");
//            return null;
//        }
        this.getint = utils.read("getint");
        this.lParent = utils.read("(");
        this.rParent = utils.tryReadnext(1, ")", Errortype.j);
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        return this;
    }
}
