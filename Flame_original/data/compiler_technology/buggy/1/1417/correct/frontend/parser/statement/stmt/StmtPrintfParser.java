package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.StringConst;
import frontend.parser.terminal.StringConstParser;

import java.util.ArrayList;

public class StmtPrintfParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtPrintfParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtPrintf parseStmtPrintf() {
        Token printfTk = tokenList.getNextToken();
        this.nodes.add(printfTk);
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);
        StringConstParser stringConstParser = new StringConstParser(tokenList);
        StringConst stringConst = stringConstParser.parseStringConst();
        this.nodes.add(stringConst);
        Token token = tokenList.getNextToken();
        Token rParent = null;
        // Stmt -> 'printf' '(' StringConst , Exp , Exp ...
        if (token.getType() == TokenType.COMMA) {
            while (token.getType() == TokenType.COMMA) {
                this.nodes.add(token);
                ExpParser expParser = new ExpParser(tokenList);
                Exp exp = expParser.parseExp();
                this.nodes.add(exp);
                token = tokenList.getNextToken();
            }
            rParent = token;
        } else {
            rParent = token;
        }
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
            Token token2 = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token2.getLineNumber(), 'i');
            error.addTokenError(tokenError);
            semicn = new Token(TokenType.SEMICN, ";", token2.getLineNumber());
        }
        this.nodes.add(semicn);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtPrintf stmtPrintf = new StmtPrintf(startLine, endLine, "", this.nodes);
        return stmtPrintf;
    }
}
