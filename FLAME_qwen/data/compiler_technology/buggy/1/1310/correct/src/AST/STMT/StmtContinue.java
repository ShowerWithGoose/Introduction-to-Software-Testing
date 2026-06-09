package src.AST.STMT;

import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtContinue {
    private Word wordContinue;
    private Word semicolon;

    public StmtContinue() {
    }

    public StmtContinue analyse() {
        this.wordContinue = utils.read("continue");
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        return this;
    }
}
