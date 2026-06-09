package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class RelExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        AddExpParser addExpParser = new AddExpParser();
        LeafParser leafParser = new LeafParser();

        SyntaxTreeNode first = new SyntaxTreeNode("<RelExp>", null, new ArrayList<>(Collections.singletonList(addExpParser.run(iterator))));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.GRE || tt.getType() == TokenType.LSS || tt.getType() == TokenType.GEQ || tt.getType() == TokenType.LEQ) {
            SyntaxTreeNode second = leafParser.run(tt);
            SyntaxTreeNode third = addExpParser.run(iterator);
            first = new SyntaxTreeNode("<RelExp>", null, new ArrayList<>(Arrays.asList(first, second, third)));

            tt = iterator.next();
        }
        iterator.unread(1);

        return first;
    }
}
