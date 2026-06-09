package frontend.Tree;

import frontend.Lexer.LexType;

public class EqExp {
    private EqExp eqExp;

    private LexType op;

    private RelExp relExp;

    public EqExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public EqExp(EqExp eqExp, LexType op, RelExp relExp) {
        this.eqExp = eqExp;
        this.op = op;
        this.relExp = relExp;
    }
}
