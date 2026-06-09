package src.AST.PARAMS;

import src.AST.BType;
import src.AST.Ident;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class FuncFParam {
    private int dim;
    private BType btype;
    private Word ident;
    private Word lBrack;
    private Word rBrack;

    public FuncFParam() {
        this.dim = 0;
    }

    public FuncFParam analyse() {
        this.btype = new BType().analyse();
        this.ident = new Ident().analyse();
        if (utils.preRead(1) == WordType.LBRACK) {
            this.dim = 1;
            this.lBrack = utils.read("[");
            this.rBrack = utils.tryReadnext(1, "]", Errortype.k);
        }
        //注意错误处理
        syntaxList.add("<" + SyntaxType.FuncFParam + ">");
        return this;
    }
}
