package frontend;

public class Cond {
    private TokenItaretor itaretor;
    private ParserFile file;
    private LOrExp lOrExp = null;
    public Cond(TokenItaretor itaretor,ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getCond() {

        lOrExp = new LOrExp(itaretor,file);
        lOrExp.getLOrExp();
        file.addToken(new Token("<Cond>"));
    }
}
