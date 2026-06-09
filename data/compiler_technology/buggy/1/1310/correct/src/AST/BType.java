package src.AST;

import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class BType {
    private Word wordIntOrChar;

    public BType() {
    }


    public BType analyse() {
        if (utils.preRead(1) == WordType.INTTK) {
            this.wordIntOrChar = utils.read("int");
        } else {
            this.wordIntOrChar = utils.read("char");
        }
        return this;
    }
}
