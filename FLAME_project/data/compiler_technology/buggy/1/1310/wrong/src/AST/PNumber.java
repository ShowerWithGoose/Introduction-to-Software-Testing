package src.AST;

import src.fronted.LexicAnalysis.Word;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class PNumber {
    private Word IntConst;

    public PNumber() {
    }

    public PNumber analyse() {
        this.IntConst = utils.read("IntConst");
        syntaxList.add("<" + SyntaxType.Number + ">");
        return this;
    }
}
