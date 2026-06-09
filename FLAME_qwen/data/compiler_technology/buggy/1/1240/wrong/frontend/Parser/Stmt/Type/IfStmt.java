package frontend.Parser.Stmt.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Exp.Type.Cond;

import java.util.ArrayList;

public class IfStmt implements StmtInter {
    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    private final LexType ifToken;
    private final LexType left;
    private final Cond cond;
    private final LexType right;
    private final ArrayList<Stmt> stmts;
    private final LexType elseToken;

    public IfStmt(LexType ifToken, LexType left, Cond cond, LexType right,
                  ArrayList<Stmt> stmts, LexType elseToken) {
        this.ifToken = ifToken;
        this.left = left;
        this.cond = cond;
        this.right = right;
        this.stmts = stmts;
        this.elseToken = elseToken;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ifToken).append(left).append(cond).append(right).append(stmts.get(0));
        if (elseToken != null) {
            stringBuilder.append(elseToken).append(stmts.get(1));
        }
        return stringBuilder.toString();
    }
}
