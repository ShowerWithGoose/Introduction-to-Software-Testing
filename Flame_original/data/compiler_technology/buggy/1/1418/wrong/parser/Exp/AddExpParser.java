package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class AddExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        MulExpParser mulExpParser = new MulExpParser();
        LeafParser leafParser = new LeafParser();

        SyntaxTreeNode first = new SyntaxTreeNode("<AddExp>", null, new ArrayList<>(Collections.singletonList(mulExpParser.run(iterator))));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.PLUS || tt.getType() == TokenType.MINU) {
            SyntaxTreeNode second = leafParser.run(tt);
            SyntaxTreeNode third = mulExpParser.run(iterator);
            first = new SyntaxTreeNode("<AddExp>", null, new ArrayList<>(Arrays.asList(first, second, third)));

            tt = iterator.next();
        }
        iterator.unread(1);

        return first;
    }
}
