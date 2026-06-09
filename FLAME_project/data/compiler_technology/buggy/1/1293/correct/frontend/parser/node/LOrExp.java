package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class LOrExp extends TreeNode {
    private LOrExp lOrExp= null;
    private LAndExp lAndExp= null;
    private Token opToken = null;

    public void setlOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public void setOpToken(Token opToken) {
        this.opToken = opToken;
    }

    public LOrExp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
