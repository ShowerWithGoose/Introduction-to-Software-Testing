package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class BTypeParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public BTypeParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public BType parseBType() {
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.INTTK || token.getType() == TokenType.CHARTK) {
            int startLine = token.getStarttLine();
            int endLine = token.getEndLine();
            this.nodes.add(token);
            BType bType = new BType(startLine, endLine, "<BType>", nodes);
            return bType;
        } else {
            // TODO: something wrong
            return null;
        }
    }
}
