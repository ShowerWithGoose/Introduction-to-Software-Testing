package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class LAndExp extends TreeNode {
    private EqExp eqExp= null;
    private LAndExp lAndExp= null;
    private Token opToken = null;

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public void setOpToken(Token opToken) {
        this.opToken = opToken;
    }

    public LAndExp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
