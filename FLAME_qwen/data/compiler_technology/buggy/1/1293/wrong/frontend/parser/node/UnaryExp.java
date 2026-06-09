package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class UnaryExp extends TreeNode {
    private PrimaryExp primaryExp= null;
    private Token identToken = null;
    private Token lToken = null;
    private Token rToken = null;
    private FuncRParams funcRParams = null;
    private UnaryExp unaryExp= null;
    private UnaryOp unaryOp = null;

    public void setPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public void setIdentToken(Token identToken) {
        this.identToken = identToken;
    }

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setFuncRParams(FuncRParams funcRParams) {
        this.funcRParams = funcRParams;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public UnaryExp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
