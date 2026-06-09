package src.AST.DEF;

import src.AST.BLOCK.Block;
import src.AST.Ident;
import src.AST.PARAMS.FuncFParams;
import src.AST.Type.FuncType;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class FuncDef {
    private boolean haveParams;
    private FuncType funcType;
    private Word ident;
    private Word lParent;
    private FuncFParams funcFParams;
    private Word rParent;
    private Block block;

    public FuncDef() {
        this.haveParams = false;
    }

    public FuncDef analyse() {
        this.funcType = utils.getFuncType();
        this.ident = new Ident().analyse();
        this.lParent = utils.read("(");
        if (utils.preRead(1) == WordType.INTTK
                || utils.preRead(1) == WordType.CHARTK) {
            this.haveParams = true;
            this.funcFParams = new FuncFParams().analyse();
        }
        this.rParent = utils.tryReadnext(1, ")", Errortype.j);
        //注意报错
        this.block = new Block().analyse();
        syntaxList.add("<" + SyntaxType.FuncDef + ">");
        return this;
    }
}