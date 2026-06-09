package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class LOrExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        LAndExpParser lAndExpParser = new LAndExpParser();
        LeafParser leafParser = new LeafParser();

        SyntaxTreeNode first = new SyntaxTreeNode("<LOrExp>", null, new ArrayList<>(Collections.singletonList(lAndExpParser.run(iterator))));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.OR) {
            SyntaxTreeNode second = leafParser.run(tt);
            SyntaxTreeNode third = lAndExpParser.run(iterator);
            first = new SyntaxTreeNode("<LOrExp>", null, new ArrayList<>(Arrays.asList(first, second, third)));

            tt = iterator.next();
        }
        iterator.unread(1);

        return first;
    }
}
