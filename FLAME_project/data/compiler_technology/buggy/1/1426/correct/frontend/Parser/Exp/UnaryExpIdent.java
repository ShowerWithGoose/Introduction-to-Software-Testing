package frontend.Parser.Exp;

import frontend.Token;
import frontend.Parser.Func.FuncRParams;
import frontend.Parser.solid.Ident;

//一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
public class UnaryExpIdent implements UnaryExpInf{
    private Ident ident;
    private Token lparent;
    private FuncRParams funcRParams = null;
    private Token rparent;

    public UnaryExpIdent(Ident ident, Token lparent, Token rparent) {
        this.ident = ident;
        this.lparent = lparent;
        this.rparent = rparent;
    }
    public UnaryExpIdent(Ident ident, Token lparent, FuncRParams funcRParams, Token rparent) {
        this.ident = ident;
        this.lparent = lparent;
        this.funcRParams = funcRParams;
        this.rparent = rparent;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ident.Parser_Output());
        sb.append(this.lparent.toString());
        if(funcRParams != null){
            sb.append(funcRParams.Parser_Output());
        }
        sb.append(this.rparent.toString());
        return sb.toString();
    }
}
