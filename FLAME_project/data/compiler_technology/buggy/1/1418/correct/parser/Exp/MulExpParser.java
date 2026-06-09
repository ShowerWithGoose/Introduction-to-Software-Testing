package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class MulExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        UnaryExpParser unaryExpParser = new UnaryExpParser();
        LeafParser leafParser = new LeafParser();

        SyntaxTreeNode first = new SyntaxTreeNode("<MulExp>", null, new ArrayList<>(Collections.singletonList(unaryExpParser.run(iterator))));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.MULT || tt.getType() == TokenType.DIV || tt.getType() == TokenType.MOD) {
            SyntaxTreeNode second = leafParser.run(tt);
            SyntaxTreeNode third = unaryExpParser.run(iterator);
            first = new SyntaxTreeNode("<MulExp>", null, new ArrayList<>(Arrays.asList(first, second, third)));

            tt = iterator.next();
        }
        iterator.unread(1);

        return first;
    }
}
