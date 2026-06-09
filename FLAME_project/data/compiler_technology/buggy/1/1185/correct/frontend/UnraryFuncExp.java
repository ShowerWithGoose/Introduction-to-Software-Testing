package frontend;

public class UnraryFuncExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token ident;
    private Token lParent;
    private Token rParent;
    private FuncRParam funcRParam;
    public UnraryFuncExp(TokenItaretor itaretor, ParserFile parserFile) {
        this.file = parserFile;
        this.itaretor = itaretor;
        this.lParent = null;
        this.rParent = null;
        this.ident = null;
        this.funcRParam = null;
    }

    public void getFuncExp(Token ident, Token lParent) {
        this.ident = ident;
        this.lParent = lParent;
        file.addToken(this.ident);
        file.addToken(this.lParent);
        Token token = itaretor.getNext();
        while(!token.getString().equals(")")) {
            if(token.getString().equals(";")) {
                break;
            }
            itaretor.getPrevious(1);
            funcRParam = new FuncRParam(file,itaretor);
            funcRParam.getFuncRParam();
            file.addToken(new Token("<FuncRParams>"));
            token = itaretor.getNext();
        }
        if(token.getString().equals(")")) {
            rParent = token;
            file.addToken(rParent);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token2.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }
    }
}
