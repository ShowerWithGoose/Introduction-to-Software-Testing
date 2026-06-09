package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.error.TokenError;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.error.Error;
import frontend.parser.Node;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.ArrayList;

public class StmtGetIntParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;
    public StmtGetIntParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtGetInt parseStmtGetInt() {
        LValParser lValParser = new LValParser(tokenList);
        LVal lVal = lValParser.parseLVal();
        this.nodes.add(lVal);
        Token assignTk = tokenList.getNextToken();
        this.nodes.add(assignTk);
        Token getIntTk = tokenList.getNextToken();
        this.nodes.add(getIntTk);
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);
        Token rParent = tokenList.getNextToken();
        if (rParent.getType() != TokenType.RPARENT){
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
            error.addTokenError(tokenError);
            rParent = new Token(TokenType.RPARENT, ")", token2.getLineNumber());
        }
        this.nodes.add(rParent);
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token.getLineNumber(), 'i');
            error.addTokenError(tokenError);
            semicn = new Token(TokenType.SEMICN, ";", token.getLineNumber());
        }
        this.nodes.add(semicn);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtGetInt stmtGetInt = new StmtGetInt(startLine, endLine, "", this.nodes);
        return stmtGetInt;
    }
}
