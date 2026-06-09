package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class RelExp extends TreeNode {
    private RelExp relExp = null;
    private Token opToken = null;
    private AddExp addExp = null;

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setOpToken(Token opToken) {
        this.opToken = opToken;
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public RelExp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
