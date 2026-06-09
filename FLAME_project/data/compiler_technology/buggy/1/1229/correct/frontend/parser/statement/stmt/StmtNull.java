package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
/**
 * 仅有分号
 * Stmt -> ';'
 */
public class StmtNull implements StmtIFace{
    private Token semicn;

    private TokenList tokenList;

    public StmtNull(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtNull(){
        this.semicn = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
