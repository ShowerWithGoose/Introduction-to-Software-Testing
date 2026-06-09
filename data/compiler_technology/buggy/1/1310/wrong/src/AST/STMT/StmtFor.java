package src.AST.STMT;

import src.AST.Cond;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtFor {
    private Word wordFor;
    private Word lParent;
    private boolean haveStmt1;
    private ForStmt forStmt1;
    private Word semicolon1;
    private boolean haveCond;
    private Cond cond;
    private Word semicolon2;
    private boolean haveStmt2;
    private ForStmt forStmt2;
    private Stmt stmt;
    private Word rParent;

    public StmtFor() {
        this.haveStmt1 = false;
        this.haveCond = false;
        this.haveStmt2 = false;
    }

    public StmtFor analyse() {
        this.wordFor = utils.read("for");
        this.lParent = utils.read("(");
        if (utils.preRead(1) != WordType.SEMICN) {
            this.haveStmt1 = true;
            this.forStmt1 = new ForStmt().analyse();
        }
        this.semicolon1 = utils.read(";");
        if (utils.preRead(1) != WordType.SEMICN) {
            this.haveCond = true;
            this.cond = new Cond().analyse();
        }
        this.semicolon2 = utils.read(";");
        if (utils.preRead(1) != WordType.RPARENT) {
            this.haveStmt2 = true;
            this.forStmt2 = new ForStmt().analyse();
        }
        this.rParent = utils.tryReadnext(1, ")", Errortype.j);
        //注意报错
        this.stmt = new Stmt().analyse();
        return this;
    }
}
