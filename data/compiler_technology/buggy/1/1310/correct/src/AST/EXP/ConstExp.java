package src.AST.EXP;

import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;

public class ConstExp {
    private AddExp addExp;
    public ConstExp(){}
    public ConstExp analyse(){
        this.addExp = new AddExp().analyse();
        syntaxList.add("<" + SyntaxType.ConstExp + ">");
        return this;
    }
}
