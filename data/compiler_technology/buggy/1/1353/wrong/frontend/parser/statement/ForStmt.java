package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryexp.LVal;

/**
 * ForStmt for语句类
 * <ForStmt> -> <LVal> '=' <Exp>
 */
public class ForStmt implements SyntaxNode {
    private LVal lVal;
    private Token assignTK; // '='
    private Exp exp;

    public ForStmt(LVal lVal, Token assignTK, Exp exp) {
        this.lVal = lVal;
        this.assignTK = assignTK;
        this.exp = exp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.syntaxOutput());
        sb.append(assignTK.syntaxOutput());
        sb.append(exp.syntaxOutput());
        return sb.toString();
    }
}
