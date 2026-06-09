package frontend;

public class StmtAssign implements StmtContent{
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token equals;
    private Token semin;
    private Exp exp = null;
    private LVal lVal;

    public StmtAssign(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtAssign(LVal lVal) {
        this.lVal = lVal;
        equals = itaretor.getNext();
        file.addToken(equals);
        exp = new Exp(file,itaretor);
        exp.getExp();
        Token token1 = itaretor.getNext();
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
