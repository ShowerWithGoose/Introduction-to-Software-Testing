package frontend;

public class StmtGet implements StmtContent {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token gettk;
    private Token semin;
    private Token lparent;
    private Token rparent;
    private Token equals;
    private LVal lVal;
    private int type; //1:getint 2:getchar

    public StmtGet(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtGet(LVal lVal) {
        this.lVal = lVal;
        equals = itaretor.getNext();
        file.addToken(equals);
        gettk = itaretor.getNext();
        if (gettk.getString().equals("getint")) {
            type = 1;
        } else {
            type = 2;
        }
        file.addToken(gettk);
        lparent = itaretor.getNext();
        file.addToken(lparent);
        Token next = itaretor.getNext();
        if (next.getString().equals(")")) {
            rparent = next;
            file.addToken(rparent);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token2.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }
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
