package frontend.ParserPart.state.stmt;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.expr.Cond;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class StmtCond implements StmtInterface{
    private TokenList tokenList;
    private Token ifToken;
    private Token leftPARENT;
    private Cond cond;
    private Token rightPARENT;
    private Stmt stmt;
    private Token elseToken;//可能存在
    private Stmt stmtLatter;//可能存在
    public StmtCond(TokenList tokenList){
        this.tokenList = tokenList;
        ifToken = new Token(TokenType.IFTK,"if");
        leftPARENT = new Token(TokenType.LPARENT,"(");
        cond = new Cond(tokenList);
        rightPARENT = new Token(TokenType.RPARENT,")");
        stmt = new Stmt(tokenList);
        elseToken = null;
        stmtLatter = null;
    }
    public void parseStmtCond(){
        //指向if
        tokenList.next();
        //指向(
        tokenList.next();
        cond.parseCond();
        //指向)
        if (tokenList.peek().getType().equals(TokenType.RPARENT)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.j,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
        stmt.parseStmt();
        if (tokenList.peek().getType().equals(TokenType.ELSETK)){
            //存在可选项
            elseToken = new Token(TokenType.ELSETK,"else");
            tokenList.next();
            stmtLatter = new Stmt(tokenList);
            stmtLatter.parseStmt();
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(ifToken.toString());
        sb.append(leftPARENT.toString());
        sb.append(cond.toString());
        sb.append(rightPARENT.toString());
        sb.append(stmt.toString());
        if (elseToken != null){
            sb.append(elseToken.toString());
            sb.append(stmtLatter.toString());
        }
        return sb.toString();
    }
}
