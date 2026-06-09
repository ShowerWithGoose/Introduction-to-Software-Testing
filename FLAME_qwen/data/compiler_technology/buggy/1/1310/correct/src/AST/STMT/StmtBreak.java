package src.AST.STMT;

import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtBreak {
    private Word wordBreak;
    private Word semicolon;

    public StmtBreak() {
    }

    public StmtBreak analyse() {
        this.wordBreak = utils.read("break");
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        return this;
    }
}
