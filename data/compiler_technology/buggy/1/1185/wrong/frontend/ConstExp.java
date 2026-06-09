package frontend;

public class ConstExp {
    public TokenItaretor itaretor;
    public ParserFile file;
    public AddExp addExp;

    public ConstExp(TokenItaretor itaretor, ParserFile file) {
        this.itaretor = itaretor;
        this.file = file;
        addExp = new AddExp(file, itaretor);
    }

    public void getConstExp() {

        addExp.getAddExp();
        file.addToken(new Token("<ConstExp>"));
    }
}
