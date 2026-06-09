package frontend;

import java.util.ArrayList;

public class LOrExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> ors = new ArrayList<>();
    private ArrayList<LAndExp> lAndExps = new ArrayList<>();

    public LOrExp(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getLOrExp() {

        LAndExp exp = new LAndExp(itaretor,file);
        exp.getLAndExp();
        lAndExps.add(exp);
        Token token = itaretor.getNext();
        while(token.getString().equals("||")) {
            file.addToken(new Token("<LOrExp>"));
            file.addToken(token);
            ors.add(token);
            LAndExp exp1 = new LAndExp(itaretor,file);
            exp1.getLAndExp();
            lAndExps.add(exp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<LOrExp>"));
    }

}
