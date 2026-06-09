package frontend;

import java.util.ArrayList;

public class EqExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<RelExp> relExps = new ArrayList<>();

    public EqExp(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getEqExp() {

        RelExp relExp = new RelExp(itaretor,file);
        relExp.getRelExp();
        relExps.add(relExp);
        Token token = itaretor.getNext();
        while(token.getType().equals("EQL") || token.getType().equals("NEQ")) {
            file.addToken(new Token("<EqExp>"));
            ops.add(token);
            file.addToken(token);
            RelExp relExp1 = new RelExp(itaretor,file);
            relExp1.getRelExp();
            relExps.add(relExp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<EqExp>"));
    }

}
