package frontend;

public class Initial {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token Stringconst = null;
    private IniExps iniExps = null;
    private int type; //1:exp 2:exps 3:string
    private Exp exp = null;
    public Initial(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getConsInitial() {

        Token token = itaretor.getNext();
        if(token.getType().equals("STRCON")) {
            Stringconst = token;
            file.addToken(Stringconst);
            type = 3;
        } else if(token.getString().equals("{")) {
            iniExps = new IniExps(itaretor,file);
            iniExps.getIniExps(token);
            type = 2;
        } else {
            exp = new Exp(file, itaretor);
            type = 1;
            itaretor.getPrevious(1);
            exp.getExp();
        }
        file.addToken(new Token("<InitVal>"));
    }
}
