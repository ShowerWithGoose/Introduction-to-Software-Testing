package frontend;

public class ForStmt {
    private TokenItaretor itaretor;
    private ParserFile file;
    private LVal lVal = null;
    private Token equals = null;
    private Exp exp = null;
    public ForStmt(TokenItaretor itaretor, ParserFile parserFile) {
        this.file = parserFile;
        this.itaretor = itaretor;
    }

    public void getForStmt() {

        lVal = new LVal(itaretor,file);
        Token token = itaretor.getNext();
        lVal.getLVal(token);
        equals = itaretor.getNext();
        file.addToken(equals);
        exp = new Exp(file,itaretor);
        exp.getExp();
        file.addToken(new Token("<ForStmt>"));
    }
}
