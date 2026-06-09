package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryexp.LVal;

public class ForStmt implements Node {

    private String name = "<ForStmt>";
    private LVal lVal;
    private Token eq;
    Exp exp;

    private TokenList tokenList;

    public ForStmt(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseForStmt(){
        this.lVal = new LVal(tokenList);
        this.lVal.parseLVal();
        this.eq = tokenList.getNextToken();
        this.exp = new Exp(tokenList);
        this.exp.parseExp();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        //TODO more
        sb.append(lVal.syntaxOutput());
        sb.append(eq.syntaxOutput());
        sb.append(exp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
