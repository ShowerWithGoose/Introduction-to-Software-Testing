package src.AST.DEF;

import src.AST.INIT.ConstInitVal;
import src.AST.EXP.ConstExp;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class ConstDef {
    private Word ident;
    private Word lBrack;
    private ConstExp constExp;
    private Word rBrack;
    private Word assign;
    private ConstInitVal constInitVal;

    public ConstDef() {

    }

    public ConstDef analyse() {
        this.ident = utils.read("Ident");
        if (utils.preRead(1) == WordType.LBRACK) {
            this.lBrack = utils.read("[");
            this.constExp = new ConstExp().analyse();
            this.rBrack = utils.tryReadnext(1, "]", Errortype.k);
        }
        this.assign = utils.read("=");
        this.constInitVal = new ConstInitVal().analyse();
        syntaxList.add("<" + SyntaxType.ConstDef + ">");
        return this;
    }
}
