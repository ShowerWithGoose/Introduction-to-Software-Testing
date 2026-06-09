package frontend;

public class StmtContinue implements StmtContent {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token continuetk;
    private Token semin;

    public StmtContinue(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtContinue(Token token) {
        continuetk = token;
        Token token1 = itaretor.getNext();
        file.addToken(continuetk);
        if (token1.getString().equals(";")) {
            semin = token1;
            file.addToken(semin);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissSemin", token2.getPosLine(), "i");
            WrongFile.getInstance().addWrong(wrong);
        }
    }
}
