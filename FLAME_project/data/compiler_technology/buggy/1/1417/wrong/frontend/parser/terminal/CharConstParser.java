package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class CharConstParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public CharConstParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public CharConst parseCharConst() {
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.CHRCON) {
            this.nodes.add(token);
            int startLine = nodes.get(0).getStarttLine();
            int endLine = nodes.get(nodes.size() - 1).getEndLine();
            CharConst charConst = new CharConst(startLine, endLine, "", this.nodes);
            return charConst;
        } else {
            // TODO: something wrong
            return null;
        }
    }
}
