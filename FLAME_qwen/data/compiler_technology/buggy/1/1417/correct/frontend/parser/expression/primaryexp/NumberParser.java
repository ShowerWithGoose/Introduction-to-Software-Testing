package frontend.parser.expression.primaryexp;

import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.terminal.IntConst;
import frontend.parser.terminal.IntConstParser;

import java.util.ArrayList;

public class NumberParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public NumberParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Number parseNumber() {
        IntConstParser intConstParser = new IntConstParser(tokenList);
        IntConst intConst = intConstParser.parseIntConst();
        this.nodes.add(intConst);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        Number number = new Number(startLine, endLine, "<Number>", this.nodes);
        return number;
    }
}
