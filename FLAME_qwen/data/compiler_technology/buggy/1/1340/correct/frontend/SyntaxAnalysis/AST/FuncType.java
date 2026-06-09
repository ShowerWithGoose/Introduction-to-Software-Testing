package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.WordType;

public class FuncType {
    public WordType type;

    public FuncType(WordType type) {
        if(type.equals(WordType.VOIDTK)
                ||type.equals(WordType.INTTK)
                ||type.equals(WordType.CHARTK)) {
            this.type = type;
        }
        else{
            this.type = null;
        }
    }
}
