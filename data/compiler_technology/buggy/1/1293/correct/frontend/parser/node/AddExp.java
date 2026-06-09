package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class AddExp extends TreeNode {
    private MulExp mulExp= null;
    private AddExp addExp= null;
    private Token token = null;
    public AddExp(ParserType parserType, Token token) {
        super(parserType, token);
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setNodeToken(Token token) {
        this.token = token;
    }
}
