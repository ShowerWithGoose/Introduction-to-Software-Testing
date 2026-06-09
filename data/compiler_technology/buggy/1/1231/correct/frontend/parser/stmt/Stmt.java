package frontend.parser.stmt;

import frontend.TokenIterator;
import frontend.parser.block.Block;
import frontend.parser.block.BlockItemNode;
import nodes.Token;
import nodes.TokenType;

/*
* 语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
* | [Exp] ';' //有无Exp两种情况
* | Block
* | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
* | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt 
* | 'break' ';' | 'continue' ';'
* | 'return' [Exp] ';' // 1.有Exp 2.无Exp
* | LVal '=' 'getint''('')'';'
* | LVal '=' 'getchar''('')'';'
* | 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
 */

/*
* 
* Stmt == > MyAssignStmt | MyExpStmt | MyNopStmt | Block | MyCondStmt
* | MyForStmt | MyBreakStmt | MyContinueStmt | MyReturnStmt 
* | MyGetintStmt | MyGetcharStmt | MyPrintfStmt
*/
public class Stmt implements BlockItemNode {
    private static String name = "<Stmt>";
    private TokenIterator tokens;

    public Stmt(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private StmtNode stmtNode;

    @Override
    public String syntaxPrinter() {
        return stmtNode.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        Token token = tokens.next();
        tokens.stepBack(1);
        switch (token.getType()) {
            case LBRACE:
                stmtNode = new Block(tokens);
                break;
            case IFTK:
                stmtNode = new MyCondStmt(tokens);
                break;
            case FORTK:
                stmtNode = new MyForStmt(tokens);
                break;
            case BREAKTK:
                stmtNode = new MyBreakStmt(tokens);
                break;
            case CONTINUETK:
                stmtNode = new MyContinueStmt(tokens);
                break;
            case RETURNTK:
                stmtNode = new MyReturnStmt(tokens);
                break;
            case PRINTFTK:
                stmtNode = new MyPrintfStmt(tokens);
                break;
            case IDENFR:
                assignOrExp();
                break;
            case LPARENT:
            case INTCON:
            case CHRCON:
            case PLUS:
            case MINU:
                stmtNode = new MyExpStmt(tokens);
                break;
            default:
                stmtNode = new MyNopStmt(tokens);
                break;
        }
        return stmtNode.parse();
    }

    // match IDDNFR; distinguish between assign, getchar|getint and exp
    // solve: check if there is an '=' before hit ';'
    private void assignOrExp() {
        int count = 0;
        while (tokens.hasNext()) {
            Token token = tokens.next();
            count++;
            if (token.getType().equals(TokenType.ASSIGN)) {
                Token tokenAfterAssign = tokens.next();
                tokens.stepBack(count + 1);
                switch (tokenAfterAssign.getType()) {
                    case GETINTTK:
                        stmtNode = new MyGetintStmt(tokens);
                        break;
                    case GETCHARTK:
                        stmtNode = new MyGetcharStmt(tokens);
                        break;
                    default:
                        stmtNode = new MyAssignStmt(tokens);
                        break;
                }
                break;
            }
            if (token.getType().equals(TokenType.SEMICN)) {
                tokens.stepBack(count);
                stmtNode = new MyExpStmt(tokens);
                break;
            }
        }
    }
}
