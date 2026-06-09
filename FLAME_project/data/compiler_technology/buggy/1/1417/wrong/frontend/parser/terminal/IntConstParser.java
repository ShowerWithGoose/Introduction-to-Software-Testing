package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class IntConstParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public IntConstParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public IntConst parseIntConst() {
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.INTCON) {
            this.nodes.add(token);
            int startLine = nodes.get(0).getStarttLine();
            int endLine = nodes.get(nodes.size() - 1).getEndLine();
            IntConst intConst = new IntConst(startLine, endLine, "", this.nodes);
            return intConst;
        } else {
            // TODO: something wrong
            return null;
        }
    }
}
