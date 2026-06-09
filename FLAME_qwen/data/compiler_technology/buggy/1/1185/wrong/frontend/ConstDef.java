package frontend;

public class ConstDef {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token Ident;
    private ConstExp constExp = null;
    private ConstInitial constInitial;
    private ConstDefExps constDefExps = null;
    private Token equals = null;

    public ConstDef(TokenItaretor itaretor, ParserFile file) {
        this.itaretor = itaretor;
        this.file = file;
    }

    public void getConstDef() {

        Ident = itaretor.getNext();
        file.addToken(Ident);
        Token token = itaretor.getNext();
        //file.addToken(token);
        if (token.getString().equals("[")) {
            constDefExps = new ConstDefExps(itaretor, file);
            constDefExps.getConstDefExps(token);
            token = itaretor.getNext();
            //file.addToken(token);
        }
        equals = token;
        file.addToken(equals);
        constInitial = new ConstInitial(itaretor, file);
        constInitial.getConsInitial();
        file.addToken(new Token("<ConstDef>"));
    }
}
