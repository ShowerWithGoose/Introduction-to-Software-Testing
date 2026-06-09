package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Cond;
import frontend.Parser.SyntaxNode.LOrExp;
/*
 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
 */
public class StmtIf extends Stmt {
    private Token ifTk;
    private Token lParent;
    private Cond cond;
    private Token rParent;
    private Stmt stmt1;
    private Token elseTk;
    private Stmt stmt2;

    public StmtIf(Token ifTk, Token lParent, Cond cond,
                  Token rParent, Stmt stmt1, Token elseTk, Stmt stmt2) {
        this.ifTk = ifTk;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.stmt1 = stmt1;
        this.elseTk = elseTk;
        this.stmt2 = stmt2;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ifTk);
        sb.append(lParent);
        sb.append(cond);
        sb.append(rParent);
        sb.append(stmt1);
        if (elseTk != null) {
            sb.append(elseTk);
            sb.append(stmt2);
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
