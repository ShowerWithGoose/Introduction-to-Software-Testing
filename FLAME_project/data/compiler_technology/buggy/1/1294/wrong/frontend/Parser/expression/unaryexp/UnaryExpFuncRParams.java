package frontend.Parser.expression.unaryexp;

import frontend.Lexer.Token;
import frontend.Parser.expression.FuncRParams;
import frontend.Parser.terminal.Ident;

public class UnaryExpFuncRParams implements UnaryExpPort{
    private Ident ident;
    private Token lParent;
    private FuncRParams funcRParams;
    private Token rParent;
    public UnaryExpFuncRParams(Ident ident, Token lParent, FuncRParams funcRParams, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.funcRParams = funcRParams;
        this.rParent = rParent;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.getToken().grammarOutput());
        sb.append(this.lParent.grammarOutput());
        if(this.funcRParams != null) {
            sb.append(this.funcRParams.grammarOutput());
        }
        sb.append(this.rParent.grammarOutput());
        return sb.toString();
    }
}
