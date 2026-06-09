package parser.Normal;

import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class BTypeParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        Token token = iterator.next();
        children.add(leafParser.run(token));
        return new SyntaxTreeNode("<BType>", null, children);
    }
}
