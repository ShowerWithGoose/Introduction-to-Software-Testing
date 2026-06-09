package frontend;

import java.util.ArrayList;

public class RelExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> comps = new ArrayList<>();
    private ArrayList<AddExp> addExps = new ArrayList<>();
    public RelExp(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getRelExp() {

        AddExp addExp = new AddExp(file,itaretor);
        addExp.getAddExp();
        addExps.add(addExp);
        Token token = itaretor.getNext();
        while(token.getString().equals(">") || token.getString().equals(">=")
                || token.getString().equals("<") || token.getString().equals("<=")) {
            file.addToken(new Token("<RelExp>"));
            comps.add(token);
            file.addToken(token);
            AddExp addExp1 = new AddExp(file,itaretor);
            addExp1.getAddExp();
            addExps.add(addExp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<RelExp>"));
    }

}
