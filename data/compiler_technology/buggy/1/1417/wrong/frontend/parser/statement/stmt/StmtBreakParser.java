package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class StmtBreakParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtBreakParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtBreak parseStmtBreak() {
        Token breakTk = tokenList.getNextToken();
        this.nodes.add(breakTk);
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'i');
            error.addTokenError(tokenError);
            semicn = new Token(TokenType.SEMICN, ";", token2.getLineNumber());
        }
        this.nodes.add(semicn);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtBreak stmtBreak = new StmtBreak(startLine, endLine, "", this.nodes);
        return stmtBreak;
    }
}
