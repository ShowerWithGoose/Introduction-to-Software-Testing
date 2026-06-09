package frontend;

public class VarDef {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token Ident;
    private Exp exp = null;
    private Token equals = null;
    private Initial initial;
    private ConstDefExps constDefExps = null;

    public VarDef(TokenItaretor itaretor, ParserFile file) {
        this.itaretor = itaretor;
        this.file = file;
    }

    public void getVarDef() {

        Ident = itaretor.getNext();
        file.addToken(Ident);
        Token token = itaretor.getNext();
        if (token.getString().equals("[")) {
            //file.addToken(token);
            constDefExps = new ConstDefExps(itaretor, file);
            constDefExps.getConstDefExps(token);
            token = itaretor.getNext();
        }
        if (token.getString().equals("=")) {
            equals = token;
            file.addToken(equals);
            initial = new Initial(itaretor,file);
            initial.getConsInitial();
        } else {
            itaretor.getPrevious(1);
        }
        file.addToken(new Token("<VarDef>"));
    }
}
