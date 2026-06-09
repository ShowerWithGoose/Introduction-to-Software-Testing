package frontend;

public class Num {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token intConst;

    public Num(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getNum(Token token) {

        intConst = token;
        file.addToken(token);
        file.addToken(new Token("<Number>"));
    }
}
