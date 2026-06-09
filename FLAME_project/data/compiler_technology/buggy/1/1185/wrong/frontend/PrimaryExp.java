package frontend;

public class PrimaryExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private int type = 0; //1:(Exp) 2ï¼šLVal 3:num 4:char
    private PriExp priExp = null;
    private LVal lVal = null;
    private Num num = null;
    private Charac charac = null;


    public PrimaryExp(ParserFile file, TokenItaretor itaretor) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getPrimaryExp() {

        Token token = itaretor.getNext();
        if (token.getString().equals("(")) {
            type = 1;
            priExp = new PriExp(file, itaretor);
            priExp.getPriExp(token);
        } else if (token.getType().equals("IDENFR")) {
            type = 2;
            lVal = new LVal(itaretor, file);
            lVal.getLVal(token);
        } else if (token.getType().equals("INTCON")) {
            type = 3;
            num = new Num(itaretor,file);
            num.getNum(token);
        } else {
            type = 4;
            charac = new Charac(itaretor,file);
            charac.getCharac(token);
        }
        file.addToken(new Token("<PrimaryExp>"));
    }
}
