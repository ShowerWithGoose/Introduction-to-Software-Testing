package frontend;

public class PriExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token lparent;
    private Token rparent;
    private Exp exp;
    public PriExp(ParserFile file, TokenItaretor itaretor) {
        this.file = file;
        this.itaretor = itaretor;
        this.lparent = null;
        this.rparent = null;
        this.exp = null;
    }

    public void getPriExp(Token token) {
        this.lparent = token;
        file.addToken(lparent);
        exp = new Exp(file, itaretor);
        exp.getExp();
        Token token1= itaretor.getNext();
        if(token1.getString().equals(")")) {
            rparent = token1;
            file.addToken(rparent);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token2.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }

    }

}
