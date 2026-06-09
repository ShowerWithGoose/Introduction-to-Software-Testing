package frontend;

public class StmtExp implements StmtContent {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token semin;
    private Exp exp = null;

    public StmtExp(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtExp(Token token) {
        if (token.getString().equals(";")) {
            semin = token;
            file.addToken(semin);
        } else {
            itaretor.getPrevious(1);
            exp = new Exp(file, itaretor);
            exp.getExp();
            Token token1 = itaretor.getNext();
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
}
