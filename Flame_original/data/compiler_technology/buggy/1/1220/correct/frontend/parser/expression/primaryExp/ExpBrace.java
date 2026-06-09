package frontend.parser.expression.primaryExp;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

public class ExpBrace implements PrimaryExpUnit{
    //  '(' Exp ')'
    private Token leftParent;
    private Token rightParent;
    private Exp exp;

    public ExpBrace(Token leftParent, Token rightParent,
                    Exp exp) {
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.exp = exp;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftParent.syntaxPrint());
        sb.append(exp.syntaxPrint());
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        return sb.toString();
    }
}
