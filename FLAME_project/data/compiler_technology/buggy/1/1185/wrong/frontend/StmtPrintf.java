package frontend;

import java.util.ArrayList;

public class StmtPrintf implements StmtContent{
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token printftk;
    private Token lparent;
    private Token stringConst;
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<Token> commas = new ArrayList<>();
    private Token rparent;
    private Token semin;
    public StmtPrintf(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtPrintf(Token token) {
        printftk = token;
        lparent = itaretor.getNext();
        file.addToken(printftk);
        file.addToken(lparent);
        stringConst = itaretor.getNext();
        file.addToken(stringConst);
        Token next = itaretor.getNext();
        while(next.getString().equals(",")) {
            commas.add(next);
            file.addToken(next);
            Exp exp = new Exp(file,itaretor);
            exp.getExp();
            exps.add(exp);
            next = itaretor.getNext();
        }
        if(next.getString().equals(")")) {
            rparent = next;
            file.addToken(rparent);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token2.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }
        Token token1 = itaretor.getNext();
        if(token1.getString().equals(";")) {
            semin = token1;
            file.addToken(semin);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissSemin", token2.getPosLine(), "i");
            WrongFile.getInstance().addWrong(wrong);
        }

    }
}
