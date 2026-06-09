package src.AST.EXP;

import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;

public class Exp {
    private AddExp addExp;

    public Exp() {
    }

    public Exp analyse() {
        this.addExp = new AddExp().analyse();
        syntaxList.add("<" + SyntaxType.Exp + ">");
        return this;
    }
}
