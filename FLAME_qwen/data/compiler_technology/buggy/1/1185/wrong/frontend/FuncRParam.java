package frontend;

import java.beans.Expression;
import java.util.ArrayList;

public class FuncRParam {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    public FuncRParam(ParserFile file, TokenItaretor itaretor) {
        this.file = file;
        this.itaretor = itaretor;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
    }

    public void getFuncRParam() {
        Exp exp = new Exp(file, itaretor);
        exp.getExp();
        exps.add(exp);
        Token token = itaretor.getNext();
        while(token.getString().equals(",")) {
            commas.add(token);
            file.addToken(token);
            Exp exp1 = new Exp(file, itaretor);
            exp1.getExp();
            exps.add(exp1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
    }
}
