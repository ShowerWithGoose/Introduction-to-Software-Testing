package src.AST;

import src.fronted.LexicAnalysis.Word;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class Ident {
    public Ident() {
    }

    public Word analyse() {
        return utils.read("Ident");
    }
}
