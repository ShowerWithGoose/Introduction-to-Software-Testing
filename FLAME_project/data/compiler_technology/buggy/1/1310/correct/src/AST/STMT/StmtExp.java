package src.AST.STMT;

import src.AST.EXP.AddExp;
import src.AST.EXP.Exp;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtExp {
    private boolean haveExp;
    private Exp exp;
    private Word semicolon;

    public StmtExp() {
        this.haveExp = false;
    }

    public StmtExp analyse() {
        if (utils.preRead(1) != WordType.SEMICN) {
            this.haveExp = true;
            this.exp = new Exp().analyse();
        }
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        return this;
    }
}
