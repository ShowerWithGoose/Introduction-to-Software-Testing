package src.AST;

import src.AST.EXP.LOrExp;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;

public class Cond {
    private LOrExp lOrExp;

    public Cond() {
    }

    public Cond analyse() {
        this.lOrExp = new LOrExp().analyse();
        syntaxList.add("<" + SyntaxType.Cond + ">");
        return this;
    }
}
