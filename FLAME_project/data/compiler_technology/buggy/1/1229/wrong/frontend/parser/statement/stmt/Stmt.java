package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.statement.blockitem.BlockItemIFace;

public class Stmt implements BlockItemIFace {
    private final String name = "<Stmt>";
    private StmtIFace stmtIFace;

    private TokenList tokenList;

    public Stmt(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmt(){
        Token token = tokenList.seeAfterToken(0);
        switch ((token.getType())){
            case IFTK://if
                StmtIf stmtIf = new StmtIf(tokenList);
                stmtIf.parseStmtIf();
                this.stmtIFace = stmtIf;
                break;
            case FORTK://for
                StmtFor stmtFor = new StmtFor(tokenList);
                stmtFor.parseStmtFor();
                this.stmtIFace = stmtFor;
                break;
            case BREAKTK://break
                StmtBreak stmtBreak = new StmtBreak(tokenList);
                stmtBreak.parseStmtBreak();
                this.stmtIFace = stmtBreak;
                break;
            case CONTINUETK://continue
                StmtContinue stmtContinue = new StmtContinue(tokenList);
                stmtContinue.parseStmtContinue();
                this.stmtIFace = stmtContinue;
                break;
            case RETURNTK://return
                StmtReturn stmtReturn = new StmtReturn(tokenList);
                stmtReturn.parseStmtReturn();
                this.stmtIFace = stmtReturn;
                break;
            case PRINTFTK://printf
                StmtPrintf stmtPrintf = new StmtPrintf(tokenList);
                stmtPrintf.parseStmtPrintf();
                this.stmtIFace = stmtPrintf;
                break;
            case SEMICN://;
                StmtNull stmtNull = new StmtNull(tokenList);
                stmtNull.parseStmtNull();
                this.stmtIFace = stmtNull;
                break;
            case IDENFR://exp,assign = exp/getint/getchar
                //TODO
                solveIdent();
                break;
            case LBRACE://'{'
                StmtBlock stmtBlock = new StmtBlock(tokenList);
                stmtBlock.parseStmtBlock();
                this.stmtIFace = stmtBlock;
                break;
            case LPARENT:case INTCON:case PLUS: case MINU :case CHRCON:
                StmtExp stmtExp = new StmtExp(tokenList);
                stmtExp.parseStmtExp();
                this.stmtIFace = stmtExp;
                break;
            default:
                System.out.println("error in Stmt " + token.getLineNum());
        }
    }
    public void solveIdent(){
        int i = 0;
        Token token = tokenList.seeAfterToken(i);
        while (!token.getType().equals(TokenType.SEMICN)){
            if (token.getType().equals(TokenType.ASSIGN)){
                //一定是赋值语句，lval = exp/getint/getchar
                StmtAssign stmtAssign = new StmtAssign(tokenList);
                stmtAssign.parseStmtAssign();
                this.stmtIFace = stmtAssign;
                return;
            }
            i++;
            token = tokenList.seeAfterToken(i);
        }
        StmtExp stmtExp = new StmtExp(tokenList);
        stmtExp.parseStmtExp();
        this.stmtIFace = stmtExp;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.stmtIFace.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
