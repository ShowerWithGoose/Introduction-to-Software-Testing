package src.AST;

import src.fronted.LexicAnalysis.Word;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class PCharacter {
    private Word CharConst;

    public PCharacter() {
    }

    public PCharacter analyse() {
        this.CharConst = utils.read("CharConst");
        syntaxList.add("<" + SyntaxType.Character + ">");
        return this;
    }
}
