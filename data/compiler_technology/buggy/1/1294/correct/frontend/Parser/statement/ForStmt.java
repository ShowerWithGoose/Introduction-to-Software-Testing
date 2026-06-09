package frontend.Parser.statement;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.LVal;

public class ForStmt implements GrammarNode {
    private final String grammarName = "<ForStmt>";
    private LVal lVal;
    private Token assignSign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assignSign, Exp exp) {
        this.lVal = lVal;
        this.assignSign = assignSign;
        this.exp = exp;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.grammarOutput());
        sb.append(assignSign.grammarOutput());
        sb.append(exp.grammarOutput());
        sb.append(this.grammarName).append("\n");
        return sb.toString();
    }
}
