package frontend.parser.expression;

import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.multiexp.AddExp;
import frontend.parser.expression.multiexp.AddExpParser;

import java.util.ArrayList;

public class ExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public ExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public Exp parseExp(){
        AddExpParser addExpParser = new AddExpParser(tokenList);
        AddExp addExp = addExpParser.parseAddExp();
        this.nodes.add(addExp);
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        Exp exp = new Exp(startLine, endLine, "<Exp>", this.nodes);
        return exp;
    }
}
