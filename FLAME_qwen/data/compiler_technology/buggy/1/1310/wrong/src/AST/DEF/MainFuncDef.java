package src.AST.DEF;

import src.AST.BLOCK.Block;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class MainFuncDef {
    private Word wordInt;
    private Word wordmain;
    private Word lParent;
    private Word rParent;
    private Block block;

    public MainFuncDef() {
    }

    public MainFuncDef analyse() {
        this.wordInt = utils.read("int");
        this.wordmain = utils.read("main");
        this.lParent = utils.read("(");
        this.rParent = utils.tryReadnext(1, ")", Errortype.j);
        this.block = new Block().analyse();
        syntaxList.add("<" + SyntaxType.MainFuncDef + ">");
        return this;
    }


}
