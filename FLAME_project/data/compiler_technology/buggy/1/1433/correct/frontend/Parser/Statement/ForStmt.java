package frontend.Parser.Statement;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Expression.LVal;

public class ForStmt implements ASTNode {
    private LVal lVal;
    private Token assignToken;
    private Exp exp;


    public ForStmt(LVal lVal, Token assignToken, Exp exp) {
        this.lVal = lVal;
        this.assignToken = assignToken;
        this.exp = exp;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.printString());
        sb.append(assignToken);
        sb.append(exp.printString());
        sb.append("<" + "ForStmt" + ">\n");
        return sb.toString();
    }
}
