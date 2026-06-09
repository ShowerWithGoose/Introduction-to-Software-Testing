package parse;

public class UnaryExpFunc implements UnaryExpEle {
    private Ident ident;
    private FuncRParams funcRParams = null;
    private Token leftBraces;
    private Token rightBraces;

    public Ident getIdent() {
        return ident;
    }

    public void setIdent(Ident ident) {
        this.ident = ident;
    }

    public FuncRParams getFuncRParams() {
        return funcRParams;
    }

    public void setFuncRParams(FuncRParams funcRParams) {
        this.funcRParams = funcRParams;
    }

    public Token getLeftBraces() {
        return leftBraces;
    }

    public void setLeftBraces(Token leftBraces) {
        this.leftBraces = leftBraces;
    }

    public Token getRightBraces() {
        return rightBraces;
    }

    public void setRightBraces(Token rightBraces) {
        this.rightBraces = rightBraces;
    }

    public UnaryExpFunc(TokenList list,WrongList wrongs) {
        this.ident = new Ident(list,wrongs);
        this.leftBraces = list.readNextToken();
        this.rightBraces = list.readNextToken();
        if (!this.rightBraces.getType().equals("RPARENT")) {
            list.unReadToken(1);
            this.funcRParams = new FuncRParams(list,wrongs);
            this.rightBraces = HandleError.handleJ(list.readNextToken(),list,wrongs);
        } else {
            this.funcRParams = null;
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printout());
        sb.append(leftBraces.printout());
        if (funcRParams != null) {
            sb.append(this.funcRParams.printout());
        }
        sb.append(rightBraces.printout());
        return sb.toString();
    }
}
