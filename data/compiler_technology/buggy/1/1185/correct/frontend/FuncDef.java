package frontend;

import java.util.ArrayList;

public class FuncDef {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token funcType = null;
    private Token Ident = null;
    private Token lparent = null;
    private Token rparent = null;
    private Block block = null;
    private FuncFParams funcFParams = null;
    ;

    public FuncDef(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getFuncDef() {
        funcType = itaretor.getNext();
        file.addToken(funcType);
        file.addToken(new Token("<FuncType>"));
        Ident = itaretor.getNext();
        file.addToken(Ident);
        lparent = itaretor.getNext();
        file.addToken(lparent);
        Token token = itaretor.getNext();
        if (!token.getString().equals(")")) {
            if(!token.getString().equals("{")) {
                itaretor.getPrevious(1);
                funcFParams = new FuncFParams(itaretor, file);
                funcFParams.getFuncFParams();
                token = itaretor.getNext();
            }
        }
        if(token.getString().equals(")")) {
            rparent = token;
            file.addToken(rparent);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token2.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }
        block = new Block(itaretor, file);
        block.getBlock();
        file.addToken(new Token("<FuncDef>"));
    }

}
