package src.AST.STMT;

import src.AST.EXP.Exp;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtReturn {
    private boolean haveReturnValue;
    private Word wordReturn;
    private Exp exp;
    private Word semicolon;

    public StmtReturn() {
        this.haveReturnValue = false;
    }

    public StmtReturn analyse() {
        this.wordReturn = utils.read("return");
        if (utils.returnHasExp()) {
            this.haveReturnValue = true;
            this.exp = new Exp().analyse();
        }
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        return this;
    }
}
