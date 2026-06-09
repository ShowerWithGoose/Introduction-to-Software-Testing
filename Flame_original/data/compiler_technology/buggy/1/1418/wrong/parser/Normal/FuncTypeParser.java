package parser.Normal;

import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class FuncTypeParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        Token tt = iterator.next();
        LeafParser leafParser = new LeafParser();
        children.add(leafParser.run(tt));

        return new SyntaxTreeNode("<FuncType>", null, children);
    }
}
