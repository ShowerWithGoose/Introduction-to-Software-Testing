package frontend;

public class Charac {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token c = null;

    public Charac(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getCharac(Token token) {

        c = token;
        file.addToken(c);
        file.addToken(new Token("<Character>"));
    }
}
