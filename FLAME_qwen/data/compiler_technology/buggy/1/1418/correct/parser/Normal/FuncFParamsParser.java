package parser.Normal;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class FuncFParamsParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        FuncFParamParser funcFParamParser = new FuncFParamParser();
        children.add(funcFParamParser.run(iterator));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.COMMA) {
            children.add(leafParser.run(tt));
            children.add(funcFParamParser.run(iterator));
            tt = iterator.next();
        }
        iterator.unread(1);

        return new SyntaxTreeNode("<FuncFParams>", null, children);
    }
}
