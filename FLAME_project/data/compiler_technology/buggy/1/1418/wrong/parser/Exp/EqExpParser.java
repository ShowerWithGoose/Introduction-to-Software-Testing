package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class EqExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        RelExpParser relExpParser = new RelExpParser();
        LeafParser leafParser = new LeafParser();

        SyntaxTreeNode first = new SyntaxTreeNode("<EqExp>", null, new ArrayList<>(Collections.singletonList(relExpParser.run(iterator))));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.EQL || tt.getType() == TokenType.NEQ) {
            SyntaxTreeNode second = leafParser.run(tt);
            SyntaxTreeNode third = relExpParser.run(iterator);
            first = new SyntaxTreeNode("<EqExp>", null, new ArrayList<>(Arrays.asList(first, second, third)));

            tt = iterator.next();
        }
        iterator.unread(1);

        return first;
    }
}
