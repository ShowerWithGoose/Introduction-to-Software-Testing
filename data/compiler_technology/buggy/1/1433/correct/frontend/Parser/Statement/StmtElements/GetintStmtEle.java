package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.LVal;
import frontend.Parser.Statement.StmtEle;

public class GetintStmtEle implements StmtEle {
    private LVal lVal;
    private Token assignToken;
    private Token getintToken;
    private Token lparentToken;
    private Token rparentToken;
    private Token semicnToken;

    public GetintStmtEle(LVal lVal,
                        Token assignToken,
                        Token getintToken, 
                        Token lparentToken, 
                        Token rparentToken,
                        Token semicnToken) {
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.getintToken = getintToken;
        this.lparentToken = lparentToken;
        this.rparentToken = rparentToken;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.printString());
        sb.append(assignToken);
        sb.append(getintToken);
        sb.append(lparentToken);
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        return sb.toString();
    }

    
}