package frontend;

import java.util.ArrayList;

public class ConstInitial {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token Stringconst = null;
    private ConstIniExps constIniExps = null;
    private int type; //1:constexp 2:exps 3:string
    private ConstExp constExp = null;
    public ConstInitial(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getConsInitial() {
        Token token = itaretor.getNext();
        if(token.getType().equals("STRCON")) {
            Stringconst = token;
            file.addToken(Stringconst);
            type = 3;
        } else if(token.getString().equals("{")) {
            constIniExps = new ConstIniExps(itaretor,file);
            constIniExps.getConstIniExps(token);
            type = 2;
        } else {
            constExp = new ConstExp(itaretor, file);
            type = 1;
            itaretor.getPrevious(1);
            constExp.getConstExp();
        }
        file.addToken(new Token("<ConstInitVal>"));
    }
}
