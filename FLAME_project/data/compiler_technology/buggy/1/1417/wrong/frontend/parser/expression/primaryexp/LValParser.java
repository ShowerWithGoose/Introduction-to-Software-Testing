package frontend.parser.expression.primaryexp;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.Ident;
import frontend.parser.terminal.IdentParser;

import java.util.ArrayList;

public class LValParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public LValParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public LVal parseLVal() {
        // 递归下降法，将解析Ident的任务交给下一层去做
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        this.nodes.add(ident);
        Token token = tokenList.getNextToken();
        while (token.getType() == TokenType.LBRACK) {
            this.nodes.add(token);
            ExpParser expParser = new ExpParser(tokenList);
            Exp exp = expParser.parseExp();
            this.nodes.add(exp);
            token = tokenList.getNextToken();
            if (token.getType() != TokenType.RBRACK) {
                Error error = new Error();
                tokenList.fallbackToken(2);
                Token token2 = tokenList.getNextToken();
                TokenError tokenError = new TokenError(token2.getLineNumber(), 'k');
                error.addTokenError(tokenError);
                token = new Token(TokenType.RBRACK, "]", token2.getLineNumber());
            }
            this.nodes.add(token);
            token = tokenList.getNextToken();
        }
        tokenList.fallbackToken(1);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        LVal lVal = new LVal(startLine, endLine, "<LVal>", this.nodes);
        return lVal;
    }
}
