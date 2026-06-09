package frontend;

import java.util.ArrayList;

public class VarDecl {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token btype;
    private ArrayList<VarDef> varDefs;
    private ArrayList<Token> commas;
    private Token semin = null;
    private Token first;

    public VarDecl(TokenItaretor itaretor, Token first, ParserFile file) {
        this.file = file;
        this.varDefs = new ArrayList<>();
        this.itaretor = itaretor;
        this.commas = new ArrayList<>();
        this.first = first;
    }

    public void getVarDecl() {

        if (first.getType().equals("INTTK") || first.getType().equals("CHARTK")) {
            file.addToken(first);
            btype = first;
        }
        VarDef varDef = new VarDef(itaretor, file);
        varDef.getVarDef();
        varDefs.add(varDef);
        Token token = itaretor.getNext();
        while (token.getString().equals(",")) {
            file.addToken(token);
            commas.add(token);
            VarDef varDef1 = new VarDef(itaretor, file);
            varDef1.getVarDef();
            varDefs.add(varDef1);
            token = itaretor.getNext();
        }
        if(token.getString().equals(";")) {
            semin = token;
            file.addToken(semin); //;
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissSemin", token2.getPosLine(), "i");
            WrongFile.getInstance().addWrong(wrong);
        }
        file.addToken(new Token("<VarDecl>"));
    }
}
