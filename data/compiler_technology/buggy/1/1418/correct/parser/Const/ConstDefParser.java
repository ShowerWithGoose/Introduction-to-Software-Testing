package parser.Const;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class ConstDefParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        //处理Ident
        children.add(leafParser.run(iterator.next()));

        //处理 [ '[' ConstExp ']' ]
        Token tt = iterator.next();
        if(tt.getType() == TokenType.LBRACK) {
            //处理 '['
            children.add(leafParser.run(tt));

            //处理ConstExp
            ConstExpParser constExpParser = new ConstExpParser();
            children.add(constExpParser.run(iterator));

            //处理 ']'
            tt = iterator.next();
            if(tt.getType() != TokenType.RBRACK) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'k');
            }
            else children.add(leafParser.run(tt));

            tt = iterator.next();
        }

        //处理剩下的 '=' ConstInitVal
        children.add(leafParser.run(tt));
        ConstInitValParser constInitValParser = new ConstInitValParser();
        children.add(constInitValParser.run(iterator));

        return new SyntaxTreeNode("<ConstDef>", null, children);
    }
}
