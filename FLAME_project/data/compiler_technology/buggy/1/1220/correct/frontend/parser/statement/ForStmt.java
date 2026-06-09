package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryExp.LVal;

public class ForStmt implements SyntaxUnit {
    private String name = "<ForStmt>";
    // ForStmt → LVal '=' Exp
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }


    @Override
    public String syntaxPrint() {
        //ForStmt → LVal '=' Exp
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.syntaxPrint());
        sb.append(assign.syntaxPrint());
        sb.append(exp.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
