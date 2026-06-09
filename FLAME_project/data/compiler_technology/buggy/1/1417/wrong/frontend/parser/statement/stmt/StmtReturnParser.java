package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

public class StmtReturnParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtReturnParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtReturn parseStmtReturn() {
        Token returnTk = tokenList.getNextToken();
        this.nodes.add(returnTk);
        Token token = tokenList.getNextToken();
        int preLine = returnTk.getLineNumber();
        int curLine = token.getLineNumber();
        // Stmt -> 'return' ';'
        if (token.getType() == TokenType.SEMICN) {
            Token semicn = token;
            this.nodes.add(semicn);
        }
        // Stmt -> 'return' exp ';'
        else {
            // Stmt -> 'return' exp ';'
            Token semicn = null;
            if (preLine == curLine) {
                tokenList.fallbackToken(1);
                ExpParser expParser = new ExpParser(tokenList);
                Exp exp = expParser.parseExp();
                this.nodes.add(exp);
                semicn = tokenList.getNextToken();
                // Stmt -> 'return' exp
                // 遗漏 ';'
                if (semicn.getType() != TokenType.SEMICN) {
                    Error error = new Error();
                    tokenList.fallbackToken(2);
                    Token token2 = tokenList.getNextToken();
                    TokenError tokenError = new TokenError(token2.getLineNumber(), 'i');
                    error.addTokenError(tokenError);
                    semicn = new Token(TokenType.SEMICN, ";", token2.getLineNumber());
                }

            } else {
                Error error = new Error();
                tokenList.fallbackToken(2);
                Token token2 = tokenList.getNextToken();
                TokenError tokenError = new TokenError(token2.getLineNumber(), 'i');
                error.addTokenError(tokenError);
                semicn = new Token(TokenType.SEMICN, ";", token2.getLineNumber());
            }
            this.nodes.add(semicn);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtReturn stmtReturn = new StmtReturn(startLine, endLine, "", this.nodes);
        return stmtReturn;
    }
}
