package frontend;

import java.util.ArrayList;

public class StmtFor implements StmtContent{
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token fortk;
    private ArrayList<Token> semins = new ArrayList<>();
    private Cond cond = null;
    private ForStmt forStmt1 = null;
    private ForStmt forStmt2 = null;
    private Token lparent;
    private Token rparent;
    private Stmt stmt;
    public StmtFor(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getStmtFor(Token token) {
        fortk = token;
        lparent = itaretor.getNext();
        file.addToken(fortk);
        file.addToken(lparent);
        Token next = itaretor.getNext();
        if(!next.getString().equals(";")) {
            itaretor.getPrevious(1);
            forStmt1 = new ForStmt(itaretor,file);
            forStmt1.getForStmt();
            next = itaretor.getNext();
        }
        semins.add(next);
        file.addToken(next);
        next = itaretor.getNext();
        if(!next.getString().equals(";")) {
            itaretor.getPrevious(1);
            cond = new Cond(itaretor,file);
            cond.getCond();
            next = itaretor.getNext();
        }
        semins.add(next);
        file.addToken(next);
        next = itaretor.getNext();
        if(!next.getString().equals(")")) {
            itaretor.getPrevious(1);
            forStmt2 = new ForStmt(itaretor,file);
            forStmt2.getForStmt();
            next = itaretor.getNext();
        }
        rparent = next;
        file.addToken(rparent);
        stmt = new Stmt(itaretor,file);
        stmt.getStmt();
    }

}
