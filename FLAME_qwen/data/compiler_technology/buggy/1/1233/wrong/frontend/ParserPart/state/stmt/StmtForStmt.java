package frontend.ParserPart.state.stmt;

import frontend.ParserPart.expr.Cond;
import frontend.ParserPart.state.ForStmt;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtForStmt implements StmtInterface{
    private TokenList tokenList;
    private Token forToken;
    private Token leftPARENT;
    private ForStmt forStmt1;//可能存在
    private Token secimn1;
    private Cond cond;//可能存在
    private Token secimn2;
    private ForStmt forStmt2;//可能存在
    private Token rightPARENT;
    private Stmt stmt;
    public StmtForStmt(TokenList tokenList){
        this.tokenList = tokenList;
        forToken = new Token(TokenType.FORTK,"for");
        leftPARENT = new Token(TokenType.LPARENT,"(");
        forStmt1 = null;
        secimn1 = new Token(TokenType.SEMICN,";");
        cond = null;
        secimn2 = new Token(TokenType.SEMICN,";");
        forStmt2 = null;
        rightPARENT = new Token(TokenType.RPARENT,")");
        stmt = new Stmt(tokenList);
    }
    public void parseStmtForStmt(){
        //指向for
        tokenList.next();
        //指向(
        tokenList.next();
        if (!tokenList.peek().getType().equals(TokenType.SEMICN)){
            forStmt1 = new ForStmt(tokenList);
            forStmt1.parseForStmt();
        }
        //指向;
        tokenList.next();
        if (!tokenList.peek().getType().equals(TokenType.SEMICN)){
            cond = new Cond(tokenList);
            cond.parseCond();
        }
        //指向;
        tokenList.next();
        if (!tokenList.peek().getType().equals(TokenType.RPARENT)){
            forStmt2 = new ForStmt(tokenList);
            forStmt2.parseForStmt();
        }
        //指向)
        tokenList.next();
        stmt.parseStmt();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(forToken.toString());
        sb.append(leftPARENT.toString());
        if (forStmt1 != null){
            sb.append(forStmt1.toString());
        }
        sb.append(secimn1.toString());
        if (cond != null){
            sb.append(cond.toString());
        }
        sb.append(secimn2.toString());
        if (forStmt2 != null){
            sb.append(forStmt2.toString());
        }
        sb.append(rightPARENT.toString());
        sb.append(stmt.toString());
        return sb.toString();
    }
}
