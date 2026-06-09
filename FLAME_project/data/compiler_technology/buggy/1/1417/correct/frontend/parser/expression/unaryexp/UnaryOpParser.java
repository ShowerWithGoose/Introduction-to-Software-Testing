package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class UnaryOpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;
    public UnaryOpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public UnaryOp parseUnaryOp() {
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.PLUS || token.getType() == TokenType.MINU || token.getType() == TokenType.NOT) {
            this.nodes.add(token);
            int startLine = nodes.get(0).getStarttLine();
            int endLine = nodes.get(nodes.size() - 1).getEndLine();
            UnaryOp unaryOp = new UnaryOp(startLine, endLine, "<UnaryOp>", this.nodes);
            return unaryOp;
        } else {
            // TODO: something wrong
            return null;
        }
    }
}
