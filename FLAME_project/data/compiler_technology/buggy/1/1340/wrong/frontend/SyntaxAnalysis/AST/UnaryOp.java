package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.WordType;

public class UnaryOp {
    public WordType op;

    public UnaryOp(WordType op) {
        if(op.equals(WordType.PLUS)
                ||op.equals(WordType.MINU)
                ||op.equals(WordType.NOT)) {
            this.op = op;
        }
        else{
            this.op = null;
        }
    }
}
