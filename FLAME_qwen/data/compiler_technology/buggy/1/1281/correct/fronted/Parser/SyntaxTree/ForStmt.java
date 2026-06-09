package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import javax.security.auth.callback.LanguageCallback;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:33
 */
public class ForStmt implements SyntaxNode{
    private final String name = "<ForStmt>";
    private LVal lVal;
    private Token equal;
    private Exp exp;

    public ForStmt(LVal lVal, Token equal, Exp exp) {
        this.lVal = lVal;
        this.equal = equal;
        this.exp = exp;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lVal.output());
        sb.append(this.equal.output());
        sb.append(this.exp.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
