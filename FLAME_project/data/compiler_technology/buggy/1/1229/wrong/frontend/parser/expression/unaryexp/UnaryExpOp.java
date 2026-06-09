package frontend.parser.expression.unaryexp;

import frontend.lexer.TokenList;

public class UnaryExpOp implements UnaryExpIFace{
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    private TokenList tokenList;

    public UnaryExpOp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseUnaryExpOp(){
        this.unaryOp = new UnaryOp(tokenList);
        this.unaryOp.parseUnaryOp();
        this.unaryExp = new UnaryExp(tokenList);
        this.unaryExp.parseUnaryExp();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryOp.syntaxOutput());
        sb.append(this.unaryExp.syntaxOutput());
        return sb.toString();
    }
}
