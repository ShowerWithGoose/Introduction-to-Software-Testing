package frontend;

public class MainFuncDef {
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token inttk;
    private Token lparent;
    private Token rparent;
    private Token maintk;
    private Block block;

    public MainFuncDef(TokenItaretor itaretor, ParserFile parserFile) {
        this.file = parserFile;
        this.itaretor = itaretor;
    }

    public void getMainFuncDef() {
        inttk = itaretor.getNext();
        file.addToken(inttk);
        maintk = itaretor.getNext();
        file.addToken(maintk);
        lparent = itaretor.getNext();
        file.addToken(lparent);
        Token token = itaretor.getNext();
        if(token.getString().equals(")")) {
            rparent = token;
            file.addToken(rparent);
        } else {
            itaretor.getPrevious(2);
            Token token2 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token2.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }
        block = new Block(itaretor,file);
        block.getBlock();
        file.addToken(new Token("<MainFuncDef>"));
    }
}
