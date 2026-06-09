package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.primaryexp.PrimaryExp;

import java.security.PublicKey;

public class UnaryExp implements Node {
    private final String name = "<UnaryExp>";
    private UnaryExpIFace unaryExpIFace;

    private TokenList tokenList;

    public UnaryExp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseUnaryExp(){
        Token first = tokenList.seeAfterToken(0);
        Token second = tokenList.seeAfterToken(1);
        if (first.getType().equals(TokenType.IDENFR) &&
            second.getType().equals(TokenType.LPARENT)){
            //func
            UnaryExpFunc unaryExpFunc = new UnaryExpFunc(tokenList);
            unaryExpFunc.parseUnaryExpFunc();
            this.unaryExpIFace = unaryExpFunc;
        }else if (first.getType().equals(TokenType.LPARENT) ||
            first.getType().equals(TokenType.IDENFR) ||
            first.getType().equals(TokenType.INTCON) ||
            first.getType().equals(TokenType.CHRCON)){
            //primaryExp
            PrimaryExp primaryExp = new PrimaryExp(tokenList);
            primaryExp.parsePrimaryExp();
            this.unaryExpIFace = primaryExp;
        } else if (first.getType().equals(TokenType.PLUS) ||
                first.getType().equals(TokenType.MINU) ||
                first.getType().equals(TokenType.NOT)){
            //UnaryOp
            UnaryExpOp unaryExpOp = new UnaryExpOp(tokenList);
            unaryExpOp.parseUnaryExpOp();
            this.unaryExpIFace = unaryExpOp;
        } else {
            //System.out.println("error");
        }
    }
    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpIFace.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
