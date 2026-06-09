package parser.Normal;

import model.TokensIterator;
import parser.Exp.LOrExpParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class CondParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        LOrExpParser lOrExpParser = new LOrExpParser();
        children.add(lOrExpParser.run(iterator));

        return new SyntaxTreeNode("<Cond>", null, children);
    }
}
