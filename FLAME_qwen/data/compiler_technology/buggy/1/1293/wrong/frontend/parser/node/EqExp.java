package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class EqExp extends TreeNode {
    private RelExp relExp = null;

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public void setOpToken(Token opToken) {
        this.opToken = opToken;
    }

    private EqExp eqExp = null;
    private Token opToken = null;
    public EqExp(ParserType parserType, Token token) {
        super(parserType, token);
    }

}
