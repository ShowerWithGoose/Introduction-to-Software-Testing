package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.expression.primaryExp.LVal;

public class GetCharStmt implements StmtUnit{
    private LVal lVal;
    private Token assign;
    private Token getChar;
    private Token leftParent;
    private Token rightParent;
    private Token semicn;

    public GetCharStmt(LVal lVal, Token assign, Token getChar, Token leftParent, Token rightParent, Token semicn) {
        this.lVal = lVal;
        this.assign = assign;
        this.getChar = getChar;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        // LVal '=' 'getchar''('')'';'
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.syntaxPrint());
        sb.append(assign.syntaxPrint());
        sb.append(getChar.syntaxPrint());
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
