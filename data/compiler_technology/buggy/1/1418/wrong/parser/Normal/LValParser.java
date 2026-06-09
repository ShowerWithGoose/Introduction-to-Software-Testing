package parser.Normal;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.Var.ExpParser;
import parser.LeafParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class LValParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        LeafParser leafParser = new LeafParser();
        Token tt = iterator.next();
        children.add(leafParser.run(tt));

        //处理 [ '[' Exp ']' ]
        tt = iterator.next();
        if(tt.getType() == TokenType.LBRACK) {
            children.add(leafParser.run(tt));
            ExpParser expParser = new ExpParser();
            children.add(expParser.run(iterator));
            // ']'
            tt = iterator.next();
            if(tt.getType() != TokenType.RBRACK) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'k');
            }
            else children.add(leafParser.run(tt));
        }
        else iterator.unread(1);

        return new SyntaxTreeNode("<LVal>", null, children);
    }
}
