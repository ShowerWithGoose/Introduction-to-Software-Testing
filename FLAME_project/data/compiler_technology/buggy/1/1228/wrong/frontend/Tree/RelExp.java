package frontend.Tree;

import frontend.Lexer.LexType;

public class RelExp {
    private RelExp relExp;
    private LexType op;
    private AddExp addExp;

    public RelExp(RelExp relExp, LexType op, AddExp addExp) {
        this.relExp = relExp;
        this.op = op;
        this.addExp = addExp;
    }

    public RelExp(AddExp addExp) {
        this.addExp = addExp;
    }
}
