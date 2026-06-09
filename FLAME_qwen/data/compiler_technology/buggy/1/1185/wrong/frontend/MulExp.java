package frontend;

import java.util.ArrayList;

public class MulExp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> MulOps = new ArrayList<>();
    private ArrayList<UnaryExp> unaryExps = new ArrayList<>();

    public MulExp(ParserFile file, TokenItaretor itaretor) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getMulExp() {

        UnaryExp unaryExp = new UnaryExp(itaretor,file);
        unaryExp.getUnaryExp();
        unaryExps.add(unaryExp);
        Token token = itaretor.getNext();
        while(token.getString().equals("*") || token.getString().equals("/") || token.getString().equals("%")) {
            file.addToken(new Token("<MulExp>"));
            MulOps.add(token);
            file.addToken(token);
            UnaryExp unaryExp1 = new UnaryExp(itaretor,file);
            unaryExp.getUnaryExp();
            unaryExps.add(unaryExp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<MulExp>"));
    }



}
