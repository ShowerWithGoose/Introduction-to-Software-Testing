package parser.Normal;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class BlockParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        // '{'
        children.add(leafParser.run(iterator.next()));
        Token tt = iterator.next();
        while(tt.getType() != TokenType.RBRACE) {
            iterator.unread(1);
            BlockItemParser blockItemParser = new BlockItemParser();
            children.add(blockItemParser.run(iterator));
            tt = iterator.next();
        }
        children.add(leafParser.run(tt));

        return new SyntaxTreeNode("<Block>", null, children);
    }
}
