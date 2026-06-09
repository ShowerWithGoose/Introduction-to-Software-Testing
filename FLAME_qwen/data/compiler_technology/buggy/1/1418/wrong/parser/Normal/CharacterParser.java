package parser.Normal;

import model.Token;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class CharacterParser {
    public SyntaxTreeNode run(Token tt) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        LeafParser leafParser = new LeafParser();
        children.add(leafParser.run(tt));

        return new SyntaxTreeNode("<Character>", null, children);
    }
}
