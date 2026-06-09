package frontend;

public class FuncFParam {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token btype = null;
    private Token Ident = null;
    private Token lbrack = null;
    private Token rbrack = null;
    public FuncFParam(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getFuncFParam() {

        btype = itaretor.getNext();
        Ident = itaretor.getNext();
        file.addToken(btype);
        file.addToken(Ident);
        Token token = itaretor.getNext();
        if(token.getString().equals("[")) {
            lbrack = token;
            file.addToken(lbrack);
            Token token1 = itaretor.getNext();
            if(token1.getString().equals("]")) {
                rbrack = token1;
                file.addToken(rbrack);
            } else {
                itaretor.getPrevious(2);
                Token token2 = itaretor.getNext();
                Wrong wrong = new Wrong("MissRBrack", token2.getPosLine(), "k");
                WrongFile.getInstance().addWrong(wrong);
            }
        } else {
            itaretor.getPrevious(1);
        }
        file.addToken(new Token("<FuncFParam>"));
    }

}
