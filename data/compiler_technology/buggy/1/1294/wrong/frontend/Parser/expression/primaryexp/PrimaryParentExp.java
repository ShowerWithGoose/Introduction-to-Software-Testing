package frontend.Parser.expression.primaryexp;

import frontend.Lexer.Token;
import frontend.Parser.expression.Exp;

//  '('Exp')'
public class PrimaryParentExp implements PrimaryExpPort{
    private Token lParent;
    private Exp exp;
    private Token rParent;
    public PrimaryParentExp(Token lBrace, Exp exp, Token rBrace) {
        this.lParent = lBrace;
        this.exp = exp;
        this.rParent = rBrace;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lParent.grammarOutput());
        sb.append(exp.grammarOutput());
        sb.append(rParent.grammarOutput());
        return sb.toString();
    }
}
