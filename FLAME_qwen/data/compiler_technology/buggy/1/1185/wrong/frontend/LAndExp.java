package frontend;

import java.util.ArrayList;

public class LAndExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> ands = new ArrayList<>();
    private ArrayList<EqExp> eqExps = new ArrayList<>();

    public LAndExp(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getLAndExp() {

        EqExp exp = new EqExp(itaretor,file);
        exp.getEqExp();
        eqExps.add(exp);
        Token token = itaretor.getNext();
        while(token.getString().equals("&&")) {
            file.addToken(new Token("<LAndExp>"));
            file.addToken(token);
            ands.add(token);
            EqExp exp1 = new EqExp(itaretor,file);
            exp1.getEqExp();
            eqExps.add(exp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<LAndExp>"));
    }
}
