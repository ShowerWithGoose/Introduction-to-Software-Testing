package parser_part.statement.StmtComponent;

import lexer_part.Token;
import lexer_part.TokenList;

public class StmtSemicnParser {
    private TokenList tokenList;

    public StmtSemicnParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public StmtSemicn parseStmtSemicn() {
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != Token.TokenType.SEMICN) {
            //System.err.println("expect semicn in parseStmtAssign");
        }
        return new StmtSemicn(semicn);
    }
}
