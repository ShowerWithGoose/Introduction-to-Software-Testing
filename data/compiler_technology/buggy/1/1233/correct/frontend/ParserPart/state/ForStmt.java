package frontend.ParserPart.state;

import frontend.Factor;
import frontend.ParserPart.expr.Exp;
import frontend.ParserPart.expr.primaryexp.LVal;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class ForStmt implements Factor {
    private String name = "<ForStmt>";
    private TokenList tokenList;
    private LVal lVal;
    private Token equal;
    private Exp exp;
    public ForStmt(TokenList tokenList){
        this.tokenList = tokenList;
        lVal = new LVal(tokenList);
        equal = new Token(TokenType.ASSIGN,"=");
        exp = new Exp(tokenList);
    }
    public void parseForStmt(){
        lVal.parseLVal();
        //指向=
        tokenList.next();
        exp.parseExp();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(equal.toString());
        sb.append(exp.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
