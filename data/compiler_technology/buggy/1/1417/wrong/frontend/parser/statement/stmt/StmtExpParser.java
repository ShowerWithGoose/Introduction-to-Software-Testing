package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.error.TokenError;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.error.Error;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

// Stmt -> [ Exp ] ';'
public class StmtExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtExp parseStmtExp(){
        Token token = tokenList.getNextToken();
        // Stmt -> ';'
        if (token.getType() == TokenType.SEMICN){
            this.nodes.add(token);
        }
        // Stmt -> Exp ';'
        else {
            tokenList.fallbackToken(1);
            ExpParser expParser = new ExpParser(tokenList);
            Exp exp = expParser.parseExp();
            this.nodes.add(exp);
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
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtExp stmtExp = new StmtExp(startLine, endLine, "", this.nodes);
        return stmtExp;
    }
}
