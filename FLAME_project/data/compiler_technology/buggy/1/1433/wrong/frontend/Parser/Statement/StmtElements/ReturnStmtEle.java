package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Statement.StmtEle;

public class ReturnStmtEle implements StmtEle {
    private Token returnToken;
    private Exp exp;          // 可选
    private Token semicnToken;

    public ReturnStmtEle(Token returnToken, Exp exp, Token semicnToken) {
        this.returnToken = returnToken;
        this.exp = exp;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(returnToken);
        if (exp != null) {
            sb.append(exp.printString());
        }
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        return sb.toString();
    }
    
}
