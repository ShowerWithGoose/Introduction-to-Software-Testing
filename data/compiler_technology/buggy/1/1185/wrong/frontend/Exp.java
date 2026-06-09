package frontend;

import java.util.ArrayList;

public class Exp {
    private TokenItaretor itaretor;
    private ParserFile file;
    private AddExp addExp;
    public Exp(ParserFile file, TokenItaretor itaretor) {
        this.file = file;
        this.itaretor = itaretor;
        this.addExp = null;
    }

    public void getExp() {
        addExp = new AddExp(file, itaretor);
        addExp.getAddExp();
        file.addToken(new Token("<Exp>"));
    }

}
