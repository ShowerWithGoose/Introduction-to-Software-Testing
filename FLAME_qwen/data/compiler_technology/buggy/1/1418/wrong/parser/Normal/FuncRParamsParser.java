package parser.Normal;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;
import parser.Var.ExpParser;

import java.util.ArrayList;
import java.util.List;

public class FuncRParamsParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        LeafParser leafParser = new LeafParser();
        ExpParser expParser = new ExpParser();
        children.add(expParser.run(iterator));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.COMMA) {
            children.add(leafParser.run(tt));
            children.add(expParser.run(iterator));
            tt = iterator.next();
        }
        iterator.unread(1);

        return new SyntaxTreeNode("<FuncRParams>", null, children);
    }
}
