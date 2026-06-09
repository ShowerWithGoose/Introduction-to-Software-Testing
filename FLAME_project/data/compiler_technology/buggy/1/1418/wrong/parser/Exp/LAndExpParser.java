package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class LAndExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        EqExpParser eqExpParser = new EqExpParser();
        LeafParser leafParser = new LeafParser();

        SyntaxTreeNode first = new SyntaxTreeNode("<LAndExp>", null, new ArrayList<>(Collections.singletonList(eqExpParser.run(iterator))));

        Token tt = iterator.next();
        while(tt.getType() == TokenType.AND) {
            SyntaxTreeNode second = leafParser.run(tt);
            SyntaxTreeNode third = eqExpParser.run(iterator);
            first = new SyntaxTreeNode("<LAndExp>", null, new ArrayList<>(Arrays.asList(first, second, third)));

            tt = iterator.next();
        }
        iterator.unread(1);

        return first;
    }
}
