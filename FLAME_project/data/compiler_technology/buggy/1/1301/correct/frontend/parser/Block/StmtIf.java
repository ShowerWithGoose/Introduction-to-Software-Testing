package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Cond;

import java.util.ArrayList;

public class StmtIf implements StmtElement {
    private Token ifTk;
    private Token lparent;
    private Cond cond;
    private Token rparent;
    private Stmt stmt;
    private Token elseTk; //可能没有
    private Stmt elseStmt; //可能没有
    private TokenList tokens;
    private int errorNum;

    public StmtIf(TokenList tokens) {
        this.ifTk = null;
        this.lparent = null;
        this.cond = null;
        this.rparent = null;
        this.stmt = null;
        this.elseTk = null;
        this.elseStmt = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        ifTk = tokens.nextToken();
        lparent = tokens.nextToken();
        cond = new Cond(tokens);
        errorNum += cond.parse();
        Token token = tokens.nextToken();
        if (token.equals(LexType.RPARENT)) {
            rparent = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'j');
            errorNum++;
            tokens.rollBack(1);
        }
        stmt = new Stmt(tokens);
        errorNum += stmt.parse();
        token = tokens.nextToken();
        if (token.equals(LexType.ELSETK)) {
            elseTk = token;
            elseStmt = new Stmt(tokens);
            errorNum += elseStmt.parse();
        } else {
            tokens.rollBack(1);
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(ifTk).append(lparent).append(cond.toSyntaxTree());
        if (rparent != null){
            sb.append(rparent);
        }
        sb.append(stmt.toSyntaxTree());
        if (elseTk != null) {
            sb.append(elseTk).append(elseStmt.toSyntaxTree());
        }
        return sb.toString();
    }
}
