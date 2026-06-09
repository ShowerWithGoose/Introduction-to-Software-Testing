package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

import java.util.ArrayList;

public class StmtIfParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtIfParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtIf parseStmtIf() {
        Token ifTk = tokenList.getNextToken();
        this.nodes.add(ifTk);
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);
        CondParser condParser = new CondParser(tokenList);
        Cond cond = condParser.parseCond();
        this.nodes.add(cond);
        Token rParent = tokenList.getNextToken();
        if (rParent.getType() != TokenType.RPARENT) {
            Error error = new Error();
            tokenList.fallbackToken(2);
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'j');
            error.addTokenError(tokenError);
            rParent = new Token(TokenType.RPARENT, ")", token2.getLineNumber());
        }
        this.nodes.add(rParent);
        StmtParser stmtParser = new StmtParser(tokenList);
        Stmt ifStmt = stmtParser.parseStmt();
        this.nodes.add(ifStmt);
        Token token = tokenList.getNextToken();
        // if - else
        if (token.getType() == TokenType.ELSETK) {
            Token elseTk = token;
            this.nodes.add(elseTk);
            StmtParser stmtParser2 = new StmtParser(tokenList);
            Stmt elseStmt = stmtParser2.parseStmt();
            this.nodes.add(elseStmt);
        }
        // if
        else {
            tokenList.fallbackToken(1);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtIf stmtIf = new StmtIf(startLine, endLine, "", this.nodes);
        return stmtIf;
    }
}
