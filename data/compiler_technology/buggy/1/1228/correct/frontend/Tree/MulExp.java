package frontend.Tree;

import frontend.Lexer.LexType;
import frontend.Symbol.SymbolTree;

public class MulExp {
    private UnaryExp unaryExp;

    private LexType op;

    private MulExp mulExp;

    public MulExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public MulExp(UnaryExp unaryExp, LexType op, MulExp mulExp) {
        this.unaryExp = unaryExp;
        this.op = op;
        this.mulExp = mulExp;
    }
}
