package frontend;

public class ConstDefExps {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token lbrack;
    private Token rbrack;
    private ConstExp constExp = null;

    public ConstDefExps(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getConstDefExps(Token token) {
        this.lbrack = token;
        file.addToken(lbrack);
        constExp = new ConstExp(itaretor, file);
        constExp.getConstExp();
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
    }
}
