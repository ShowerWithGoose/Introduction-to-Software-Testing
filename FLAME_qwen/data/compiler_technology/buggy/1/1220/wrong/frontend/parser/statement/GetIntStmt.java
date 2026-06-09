package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;
import frontend.parser.expression.primaryExp.LVal;

public class GetIntStmt implements StmtUnit {
    //LVal '=' 'getint''('')'';'
    private LVal lVal;
    private Token assign;
    private Token getInt;
    private Token leftParent;
    private Token rightParent;
    private Token semicn;

    public GetIntStmt(LVal lVal, Token assign, Token getInt, Token leftParent, Token rightParent, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.getInt = getInt;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.syntaxPrint());
        sb.append(assign.syntaxPrint());
        sb.append(getInt.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
