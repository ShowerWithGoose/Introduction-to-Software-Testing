package frontend.Tree;

import frontend.Lexer.LexType;
import frontend.Symbol.SymbolTree;

public class AddExp {
    private AddExp addExp;

    private LexType op;

    private MulExp mulExp;

    public AddExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public AddExp(AddExp addExp, LexType op, MulExp mulExp) {
        this.addExp = addExp;
        this.op = op;
        this.mulExp = mulExp;
    }
}
