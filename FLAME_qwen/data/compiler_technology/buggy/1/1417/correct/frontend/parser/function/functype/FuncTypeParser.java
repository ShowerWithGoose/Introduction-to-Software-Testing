package frontend.parser.function.functype;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class FuncTypeParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public FuncTypeParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public FuncType parseFuncType() {
        Token token = tokenList.getNextToken();
        if (token.getType() == TokenType.VOIDTK || token.getType() == TokenType.INTTK || token.getType() == TokenType.CHARTK) {
            this.nodes.add(token);
            int startLine = this.nodes.get(0).getStarttLine();
            int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
            FuncType funcType = new FuncType(startLine, endLine, "<FuncType>", this.nodes);
            return funcType;
        } else {
            // TODO: something wrong
            return null;
        }
    }
}
