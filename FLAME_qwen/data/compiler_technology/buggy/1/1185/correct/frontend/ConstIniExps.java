package frontend;

import java.util.ArrayList;

public class ConstIniExps {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token lbrace;
    private Token rbrace;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExps;

    public ConstIniExps(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
        this.constExps = new ArrayList<>();
        this.commas = new ArrayList<>();
    }

    public void getConstIniExps(Token token) {
        this.lbrace = token;
        file.addToken(lbrace);
        Token next = itaretor.getNext();
        if (!next.getString().equals("}")) {
            itaretor.getPrevious(1);
            ConstExp constExp = new ConstExp(itaretor, file);
            constExp.getConstExp();
            constExps.add(constExp);
            Token token1 = itaretor.getNext();
            //file.addToken(token1);
            while (token1.getString().equals(",")) {
                file.addToken(token1);
                commas.add(token1);
                ConstExp constExp1 = new ConstExp(itaretor, file);
                constExp1.getConstExp();
                constExps.add(constExp1);
                token1 = itaretor.getNext();
            }
            file.addToken(token1); //}
            rbrace = token1;
        } else {
            rbrace = next;
            file.addToken(rbrace);
        }
    }
}
