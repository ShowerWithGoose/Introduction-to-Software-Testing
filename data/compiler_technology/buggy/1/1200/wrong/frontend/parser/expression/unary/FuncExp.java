package frontend.parser.expression.unary;

import frontend.lexer.Token;
import frontend.parser.expression.FuncRParams;

public class FuncExp implements UExp {
    private Token ident;
    private Token lParent;
    private FuncRParams funcRParams = null;
    private Token rParent;
    private String errorLog = "";

    public FuncExp(Token ident, Token lParent, FuncRParams funcRParams, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.funcRParams = funcRParams;
        this.rParent = rParent;
        if (rParent == null) {
            errorLog = funcRParams.getLineno() + "\n";
        }
    }

    public FuncExp(Token ident, Token lParent, Token rParent) {
        this.ident = ident;
        this.lParent = lParent;
        this.rParent = rParent;
        if (rParent == null) {
            errorLog = lParent.getLineno() + "\n";
        }
    }

    @Override
    public int getLineno() {
        if (rParent != null) {
            return rParent.getLineno();
        } else if (funcRParams != null) {
            return funcRParams.getLineno();
        } else {
            return lParent.getLineno();
        }
    }

    @Override
    public String getOutPut() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.getOutPut());
        sb.append(lParent.getOutPut());
        if (funcRParams != null) {
            sb.append(funcRParams.getOutPut());
        }
        if (rParent != null) {
            sb.append(rParent.getOutPut());
        }
        return sb.toString();
    }

    @Override
    public String getError() {
        if (funcRParams != null) {
            return funcRParams.getError() + errorLog;
        } else {
            return errorLog;
        }
    }
}
