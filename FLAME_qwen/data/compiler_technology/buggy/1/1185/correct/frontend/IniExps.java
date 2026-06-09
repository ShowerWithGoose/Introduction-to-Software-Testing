package frontend;

import java.util.ArrayList;

public class IniExps {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token lbrace;
    private Token rbrace;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    public IniExps(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
        this.exps = new ArrayList<>();
        this.commas = new ArrayList<>();
    }

    public void getIniExps(Token token) {
        this.lbrace = token;
        file.addToken(lbrace);
        Token next = itaretor.getNext();
        if (!next.getString().equals("}")) {
            itaretor.getPrevious(1);
            Exp exp = new Exp(file, itaretor);
            exp.getExp();
            exps.add(exp);
            Token token1 = itaretor.getNext();
            //file.addToken(token1);
            while (token1.getString().equals(",")) {
                file.addToken(token1);
                commas.add(token1);
                Exp exp1 = new Exp(file,itaretor);
                exp1.getExp();
                exps.add(exp1);
                token1 = itaretor.getNext();
            }
            file.addToken(token1); //}
            rbrace = token1;
        } else {
            rbrace = next;
        }
    }
}
