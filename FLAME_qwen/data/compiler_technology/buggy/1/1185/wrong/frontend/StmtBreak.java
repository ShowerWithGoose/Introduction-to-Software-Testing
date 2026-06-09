package frontend;

public class StmtBreak implements StmtContent{
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token breaktk;
    private Token semin;
    public StmtBreak(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtBreak(Token token) {
        breaktk = token;
        Token token1 = itaretor.getNext();
        file.addToken(breaktk);
        if(token1.getString().equals(";")) {
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
