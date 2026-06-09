package parser.Normal;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class FuncFParamParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        BTypeParser bTypeParser = new BTypeParser();
        children.add(bTypeParser.run(iterator));
        LeafParser leafParser = new LeafParser();
        children.add(leafParser.run(iterator.next()));

        Token tt = iterator.next();
        // [ '[' ']' ]
        if(tt.getType() == TokenType.LBRACK) {
            children.add(leafParser.run(tt));
            tt = iterator.next();
            if(tt.getType() != TokenType.RBRACK) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'k');
            }
            else children.add(leafParser.run(tt));
        }
        else iterator.unread(1);

        return new SyntaxTreeNode("<FuncFParam>", null, children);
    }
}
