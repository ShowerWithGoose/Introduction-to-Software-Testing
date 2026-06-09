package src.AST;

import src.AST.EXP.Exp;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class LVal {
    private int dim;
    private Word ident;
    private Word lBrack;
    private Exp exp;
    private Word rBrack;

    public LVal() {
        this.dim = 0;
    }

    public LVal analyse() {
        this.ident = new Ident().analyse();
        if (utils.preRead(1) == WordType.LBRACK) {
            this.dim = 1;
            this.lBrack = utils.read("[");
            this.exp = new Exp().analyse();
            this.rBrack = utils.tryReadnext(1, "]", Errortype.k);
            //注意报错
        }
        syntaxList.add("<" + SyntaxType.LVal + ">");
        return this;
    }
}
