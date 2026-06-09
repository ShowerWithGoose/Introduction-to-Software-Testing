package frontend.parser.expression;

import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.multiexp.LOrExp;
import frontend.parser.expression.multiexp.LOrExpParser;

import java.util.ArrayList;

public class CondParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public CondParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Cond parseCond() {
        LOrExpParser lOrExpParser = new LOrExpParser(tokenList);
        LOrExp lOrExp = lOrExpParser.parseLOrExp();
        this.nodes.add(lOrExp);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        Cond cond = new Cond(startLine, endLine, "<Cond>", this.nodes);
        return cond;
    }
}
