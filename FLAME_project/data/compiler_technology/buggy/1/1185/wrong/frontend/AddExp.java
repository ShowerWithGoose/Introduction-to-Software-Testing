package frontend;

import java.util.ArrayList;

public class AddExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> addOps = new ArrayList<>();
    private ArrayList<MulExp> mulExps = new ArrayList<>();

    public AddExp(ParserFile file, TokenItaretor itaretor) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getAddExp() {
        MulExp mulExp = new MulExp(file, itaretor);
        mulExp.getMulExp();
        mulExps.add(mulExp);
        Token token = itaretor.getNext();
        while (token.getString().equals("+") || token.getString().equals("-")) {
            file.addToken(new Token("<AddExp>"));
            addOps.add(token);
            file.addToken(token);
            MulExp mulExp1 = new MulExp(file, itaretor);
            mulExp1.getMulExp();
            mulExps.add(mulExp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<AddExp>"));
    }

}
