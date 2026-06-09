package src.AST.STMT;

import src.AST.Cond;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtIf {
    private Word WordIf;
    private Word lParent;
    private Cond cond;
    private Word rParent;
    private Stmt stmt1;
    private boolean haveElse;
    private Word WordElse;
    private Stmt Stmt2;

    public StmtIf() {
        this.haveElse = false;
    }

    public StmtIf analyse() {
        this.WordIf = utils.read("if");
        this.lParent = utils.read("(");
        this.cond = new Cond().analyse();
        this.rParent = utils.tryReadnext(1, ")", Errortype.j);
        // j
        //注意报错
        this.stmt1 = new Stmt().analyse();
        if (utils.preRead(1) == WordType.ELSETK) {
            this.haveElse = true;
            this.WordElse = utils.read("else");
            this.Stmt2 = new Stmt().analyse();
        }
        return this;
    }
}
