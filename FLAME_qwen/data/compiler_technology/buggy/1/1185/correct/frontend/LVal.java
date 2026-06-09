package frontend;

import java.util.ArrayList;

public class LVal {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token ident;
    private Token lbrack = null;
    private Token rbrack = null;
    private Exp exp = null;

    public LVal(TokenItaretor itaretor, ParserFile file) {
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getLVal(Token token) {
        this.ident = token;
        file.addToken(ident);
        Token next = itaretor.getNext();
        if (next.getString().equals("[")) {
            this.lbrack = next;
            file.addToken(lbrack);
            exp = new Exp(file, itaretor);
            exp.getExp();
            next = itaretor.getNext();
            if (next.getString().equals("]")) {
                rbrack = next;
                file.addToken(rbrack);
            } else {
                itaretor.getPrevious(2);
                Token token2 = itaretor.getNext();
                Wrong wrong = new Wrong("MissRBrack", token2.getPosLine(), "k");
                WrongFile.getInstance().addWrong(wrong);
            }
        } else {
            itaretor.getPrevious(1);
        }
        file.addToken(new Token("<LVal>"));
    }


}
