package frontend;

public class StmtIf implements StmtContent{
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token iftk = null;
    private Token elsetk = null;
    private Stmt ifStmt = null;
    private Token lparent = null;
    private Token rparent = null;
    private Stmt elseStmt = null;
    private Cond cond = null;
    public StmtIf(TokenItaretor itaretor, ParserFile parserFile) {
        this.file = parserFile;
        this.itaretor = itaretor;
    }

    public void getIfStmt(Token token) {
        iftk = token;
        lparent = itaretor.getNext();
        file.addToken(iftk);
        file.addToken(lparent);
        cond = new Cond(itaretor,file);
        cond.getCond();
        Token token2 = itaretor.getNext();
        if(token2.getString().equals(")")) {
            rparent = token2;
            file.addToken(rparent);
        } else {
            itaretor.getPrevious(2);
            Token token3 = itaretor.getNext();
            Wrong wrong = new Wrong("MissRParent", token3.getPosLine(), "j");
            WrongFile.getInstance().addWrong(wrong);
        }
        ifStmt = new Stmt(itaretor,file);
        ifStmt.getStmt();
        Token token1 = itaretor.getNext();
        if(token1.getString().equals("else")) {
            elsetk = token1;
            file.addToken(elsetk);
            elseStmt = new Stmt(itaretor,file);
            elseStmt.getStmt();
        } else {
            itaretor.getPrevious(1);
        }
    }


}
