package frontend;

public class StmtReturn implements StmtContent {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token returntk;
    private Token semin;
    private Exp exp = null;

    public StmtReturn(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtReturn(Token token) {
        returntk = token;
        file.addToken(returntk);
        Token token1 = itaretor.getNext();
        if(token1.getString().equals("(") || token1.getString().equals("+") || token1.getString().equals("-")
                ||token1.getString().equals("!") || token1.getType().equals("IDENFR")
                || token1.getType().equals("INTCON") || token1.getType().equals("CHRCON")) {
            itaretor.getPrevious(1);
            exp = new Exp(file,itaretor);
            exp.getExp();
            token1 = itaretor.getNext();
        }
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
