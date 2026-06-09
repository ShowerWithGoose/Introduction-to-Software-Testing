package src.AST.DEF;

import src.AST.EXP.ConstExp;
import src.AST.Ident;
import src.AST.INIT.InitVal;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class VarDef {
    private int dim;
    private boolean assignFlag;
    private Word ident;
    private Word lBrack;
    private ConstExp constExp;
    private Word rBrack;
    private Word assign;
    private InitVal initVal;

    public VarDef() {
        this.dim = 0;
    }

    public VarDef analyse() {
        this.ident = new Ident().analyse();
        if (utils.preRead(1) == WordType.LBRACK) {
            this.dim = 1;
            this.lBrack = utils.read("[");
            this.constExp = new ConstExp().analyse();
            this.rBrack = utils.tryReadnext(1, "]", Errortype.k);
            //注意错误处理
        }
        if (utils.preRead(1) == WordType.ASSIGN) {
            this.assignFlag = true;
            this.assign = utils.read("=");
            this.initVal = new InitVal().analyse();
        }
        syntaxList.add("<" + SyntaxType.VarDef + ">");
        return this;
    }
}
