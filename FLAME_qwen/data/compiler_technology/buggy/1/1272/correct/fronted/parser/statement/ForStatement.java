package fronted.parser.statement;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Cond;
import fronted.parser.others.Block;

public class ForStatement {
    //自定义，和ForStmt区分
    //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt

    private Token For;

    private ForStmt stmt1;

    private Cond cond;

    private ForStmt stmt2;

    private Stmt mainStmt;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public ForStatement(Token aFor,ForStmt stmt1,Cond cond,ForStmt stmt2,Stmt mainStmt) {
        this.For = aFor;
        this.stmt1 = stmt1;
        this.cond = cond;
        this.stmt2 = stmt2;
        this.mainStmt = mainStmt;
    }


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(For.toString());
        sb.append(leftParent);
        if (stmt1 != null) {
            sb.append(stmt1.toString());
        }
        sb.append(semicn);
        if (cond != null) {
            sb.append(cond.toString());
        }
        sb.append(semicn);
        if (stmt2 != null) {
            sb.append(stmt2.toString());
        }
        sb.append(rightParent);
        sb.append(mainStmt);
        return sb.toString();
    }
    //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt

    public static ForStatement parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.FORTK)) {
            Token For = list.now();
            list.next();
            list.next();//(
            ForStmt stmt1 = null;
            if (!list.now().getType().equals(TokenType.Type.SEMICN)) {
                stmt1 = ForStmt.parse(list);
            }
            list.next();//;
            Cond cond = null;
            if (!list.now().getType().equals(TokenType.Type.SEMICN)){
                cond = Cond.parse(list);   
            }
            list.next();//;
            ForStmt stmt2 = null;
            if (!list.now().getType().equals(TokenType.Type.RPARENT)) {
                stmt2 = ForStmt.parse(list); 
            }
            
            list.next();//)
            Stmt mainStmt = Stmt.parse(list);
            return new ForStatement(For,stmt1,cond,stmt2,mainStmt);
        } else {
            System.err.println("Error:ForStatement cannot find for");
            return null;
        }
    } //不做其他错误特判
}
