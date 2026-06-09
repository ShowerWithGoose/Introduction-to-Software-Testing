package frontend.parser.expression.unaryexp;

import frontend.lexer.TokenList;
import frontend.parser.Node;

import java.util.ArrayList;

public class UnaryOpExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public UnaryOpExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public UnaryOpExp parseUnaryOpExp() {
        UnaryOpParser unaryOpParser = new UnaryOpParser(tokenList);
        UnaryOp unaryOp = unaryOpParser.parseUnaryOp();
        this.nodes.add(unaryOp);
        UnaryExpParser unaryExpParser = new UnaryExpParser(tokenList);
        UnaryExp unaryExp = unaryExpParser.parseUnaryExp();
        this.nodes.add(unaryExp);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        UnaryOpExp unaryOpExp = new UnaryOpExp(startLine, endLine, "", this.nodes);
        return unaryOpExp;
    }
}
