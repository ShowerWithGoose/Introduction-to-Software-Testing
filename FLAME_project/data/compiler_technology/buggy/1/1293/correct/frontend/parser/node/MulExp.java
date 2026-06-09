package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class MulExp extends TreeNode {
    private MulExp mulExp= null;
    private UnaryExp unaryExp= null;
    private Token opToken = null;

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setOpToken(Token opToken) {
        this.opToken = opToken;
    }

    public MulExp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
