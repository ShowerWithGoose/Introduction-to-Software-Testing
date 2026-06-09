package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;
import middle.error.Error;
import middle.error.ErrorTable;

public class StmtIf implements StmtIFace{
    private Token ifTk; // 'if'
    private Token leftParent; // '('
    private Cond cond;
    private Token rightParent; // ')'
    private Stmt ifStmt;
    private Token elseTk = null; // 'else' MAY exist
    private Stmt elseStmt = null; // MAY exist

    private TokenList tokenList;

    public StmtIf(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtIf(){
        this.ifTk = tokenList.getNextToken();
        this.leftParent = tokenList.getNextToken();
        this.cond = new Cond(tokenList);
        this.cond.parseCond();

        if (tokenList.seeAfterToken(0).getType().equals(TokenType.RPARENT)){
            this.rightParent = tokenList.getNextToken();
        } else {
            //handle error j
            Token token1 = tokenList.seeAfterToken(-1);
            int lineNum = token1.getLineNum();
            middle.error.Error error = new Error(lineNum,"j");
            ErrorTable.addError(error);
            this.rightParent = new Token(TokenType.RPARENT,lineNum,")");
            //自己捏造个)放这，防止以后分析到这，再出错
        }


        this.ifStmt = new Stmt(tokenList);
        this.ifStmt.parseStmt();

        if (tokenList.seeAfterToken(0).getType().equals(TokenType.ELSETK)){
            this.elseTk = tokenList.getNextToken();
            this.elseStmt = new Stmt(tokenList);
            this.elseStmt.parseStmt();
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ifTk.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.cond.syntaxOutput());
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.ifStmt.syntaxOutput());
        if (elseTk != null) {
            sb.append(this.elseTk.syntaxOutput());
            sb.append(this.elseStmt.syntaxOutput());
        }
        return sb.toString();
    }
}
