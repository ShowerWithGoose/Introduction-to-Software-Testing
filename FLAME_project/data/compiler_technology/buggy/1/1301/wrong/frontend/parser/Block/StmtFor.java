package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Cond;

public class StmtFor implements StmtElement {
    private Token forTk;
    private Token lparent;
    private ForStmt initForStmt; //可能没有
    private Token firstSemicn;
    private Cond cond; //可能没有
    private Token secondSemicn;
    private ForStmt iterForStmt; //可能没有
    private Token rparent;
    private Stmt stmt;
    private TokenList tokens;
    private int errorNum;

    public StmtFor(TokenList tokens) {
        this.forTk = null;
        this.lparent = null;
        this.initForStmt = null;
        this.firstSemicn = null;
        this.cond = null;
        this.secondSemicn = null;
        this.iterForStmt = null;
        this.rparent = null;
        this.stmt = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        forTk = tokens.nextToken();
        lparent = tokens.nextToken();
        Token token = tokens.nextToken();
        if (token.equals(LexType.SEMICN)) {
            firstSemicn = token;
        } else {
            tokens.rollBack(1);
            initForStmt = new ForStmt(tokens);
            errorNum += initForStmt.parse();
            firstSemicn = tokens.nextToken();
        }
        token = tokens.nextToken();
        if (token.equals(LexType.SEMICN)) {
            secondSemicn = token;
        } else {
            tokens.rollBack(1);
            cond = new Cond(tokens);
            errorNum += cond.parse();
            secondSemicn = tokens.nextToken();
        }
        token = tokens.nextToken();
        if (token.equals(LexType.RPARENT)) {
            rparent = token;
        } else {
            tokens.rollBack(1);
            iterForStmt = new ForStmt(tokens);
            errorNum += iterForStmt.parse();
            rparent = tokens.nextToken();
        }
        stmt = new Stmt(tokens);
        errorNum += stmt.parse();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(forTk).append(lparent);
        if (initForStmt != null) {
            sb.append(initForStmt.toSyntaxTree());
        }
        sb.append(firstSemicn);
        if (cond != null) {
            sb.append(cond.toSyntaxTree());
        }
        sb.append(secondSemicn);
        if (iterForStmt != null) {
            sb.append(iterForStmt.toSyntaxTree());
        }
        sb.append(rparent).append(stmt.toSyntaxTree());
        return sb.toString();
    }
}
