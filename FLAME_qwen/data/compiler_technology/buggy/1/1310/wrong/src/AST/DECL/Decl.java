package src.AST.DECL;

import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class Decl {
    private boolean isConstDecl;
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public Decl() {
        this.isConstDecl = true;
    }

    public Decl analyse() {
        if (utils.preRead(1) == WordType.CONSTTK) {
            this.constDecl = new ConstDecl().analyse();
        } else {
            this.isConstDecl = false;
            this.varDecl = new VarDecl().analyse();
        }
        //暂时就不用管错误了
        return this;
    }
}
