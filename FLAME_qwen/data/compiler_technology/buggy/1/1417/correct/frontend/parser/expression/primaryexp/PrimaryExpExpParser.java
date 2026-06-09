package frontend.parser.expression.primaryexp;

import frontend.error.Error;
import frontend.error.TokenError;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

// PrimaryExpExp -> '(' Exp ')'
public class PrimaryExpExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public PrimaryExpExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public PrimaryExpExp parsePrimaryExpExp() {
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);
        ExpParser expParser = new ExpParser(tokenList);
        Exp exp = expParser.parseExp();
        this.nodes.add(exp);
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
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        // 因为PrimaryExpExp属于我自己定义的节点类型，所以不会输出
        PrimaryExpExp primaryExpExp = new PrimaryExpExp(startLine, endLine, "", this.nodes);
        return primaryExpExp;
    }
}
