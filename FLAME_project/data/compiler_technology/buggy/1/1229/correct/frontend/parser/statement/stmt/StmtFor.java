package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;

public class StmtFor implements StmtIFace{
    private Token forTk;
    private Token leftParent;
    private ForStmt forStmt1 = null;
    private Token semicn1;
    private Cond cond = null;
    private Token semicn2;
    private ForStmt forStmt2 = null;
    private Token rightParent;
    private Stmt stmt;


    private TokenList tokenList;

    public StmtFor(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtFor(){
        this.forTk = tokenList.getNextToken();
        this.leftParent = tokenList.getNextToken();
        if (!tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.forStmt1 = new ForStmt(tokenList);
            this.forStmt1.parseForStmt();
        }
        this.semicn1 = tokenList.getNextToken();
        if (!tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.cond = new Cond(tokenList);
            this.cond.parseCond();
        }
        this.semicn2 = tokenList.getNextToken();
        if (!tokenList.seeAfterToken(0).getType().equals(TokenType.RPARENT)){
            this.forStmt2 = new ForStmt(tokenList);
            this.forStmt2.parseForStmt();
        }
        this.rightParent = tokenList.getNextToken();
        this.stmt = new Stmt(tokenList);
        this.stmt.parseStmt();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(forTk.syntaxOutput());
        sb.append(leftParent.syntaxOutput());
        if (forStmt1 != null){
            sb.append(forStmt1.syntaxOutput());
        }
        sb.append(semicn1.syntaxOutput());
        if (cond != null){
            sb.append(cond.syntaxOutput());
        }
        sb.append(semicn2.syntaxOutput());
        if (forStmt2 != null){
            sb.append(forStmt2.syntaxOutput());
        }
        sb.append(rightParent.syntaxOutput());
        sb.append(stmt.syntaxOutput());
        return sb.toString();
    }
}
