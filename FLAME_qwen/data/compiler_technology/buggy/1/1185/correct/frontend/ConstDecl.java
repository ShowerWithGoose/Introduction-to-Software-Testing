package frontend;

import java.util.ArrayList;

public class ConstDecl {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token consttk;
    private Token btype;
    private ArrayList<ConstDef> constDefs;
    private ArrayList<Token> commas;

    public ConstDecl(TokenItaretor itaretor, Token consstk, ParserFile file) {
        this.file = file;
        this.constDefs = new ArrayList<>();
        this.consttk = consstk;
        this.itaretor = itaretor;
        this.commas = new ArrayList<>();
    }

    public void getConstDecl() {

        file.addToken(consttk);
        Token next = itaretor.getNext();
        if (next.getType().equals("INTTK") || next.getType().equals("CHARTK")) {
            file.addToken(next);
            btype = next;
        }
        ConstDef constDef = new ConstDef(itaretor,file);
        constDef.getConstDef();
        constDefs.add(constDef);
        Token token = itaretor.getNext();
        while(token.getString().equals(",")) {
            file.addToken(token);
            commas.add(token);
            ConstDef constDef1 = new ConstDef(itaretor,file);
            constDef1.getConstDef();
            constDefs.add(constDef1);
            token = itaretor.getNext();
        }
        if(token.getString().equals(";")) {
            file.addToken(token); //;
        } else {
            itaretor.getPrevious(2);
            Token token1 = itaretor.getNext();
            Wrong wrong = new Wrong("WrongSEMIN", token1.getPosLine(), "i");
            WrongFile.getInstance().addWrong(wrong);
        }
        file.addToken(new Token("<ConstDecl>"));
    }


}
