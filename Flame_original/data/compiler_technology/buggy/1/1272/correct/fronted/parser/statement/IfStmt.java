package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Cond;
import fronted.parser.others.Block;

public class IfStmt {
    //自定义
    //'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j

    private Token If;

    private Cond cond;

    private Stmt stmt;

    private Token Else;

    private Stmt elseStmt;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    public IfStmt(Token anIf,Cond cond,Stmt stmt,Token anElse,Stmt elseStmt) {
        this.If = anIf;
        this.cond = cond;
        this.stmt = stmt;
        this.Else = anElse;
        this.elseStmt = elseStmt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(If.toString());
        sb.append(leftParent);
        sb.append(cond.toString());
        sb.append(rightParent);
        sb.append(stmt.toString());
        if (Else != null) {
            sb.append(Else.toString());
            sb.append(elseStmt.toString());
        }
        return sb.toString();
    }

    public static IfStmt parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.IFTK)) {
            Token IF = list.now();
            list.next();
            list.next();//(
            Cond cond = Cond.parse(list);
            if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'j');
            }
            Stmt stmt = Stmt.parse(list);
            Token ELSE = null;
            Stmt elseStmt = null;
            if (list.now().getType().equals(TokenType.Type.ELSETK)) {
                ELSE = list.now();
                list.next();
                elseStmt = Stmt.parse(list);
            }
            return new IfStmt(IF,cond,stmt,ELSE,elseStmt);
        } else {
            System.err.println("Error:IfStmt cannot find if");
            return null;
        }
    }
}
