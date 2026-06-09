package parser.Const;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.Normal.BTypeParser;
import parser.LeafParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class ConstDeclParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        //处理const
        LeafParser leafParser = new LeafParser();
        SyntaxTreeNode CONST = leafParser.run(iterator.next());
        children.add(CONST);

        //处理BType
        BTypeParser bTypeParser = new BTypeParser();
        SyntaxTreeNode bType = bTypeParser.run(iterator);
        children.add(bType);

        //处理ConstDef { ',' ConstDef } 和 ';'
        ConstDefParser constDefParser = new ConstDefParser();
        children.add(constDefParser.run(iterator));
        Token tt = iterator.next();
        while(tt.getType() == TokenType.COMMA) {
            children.add(leafParser.run(tt));
            children.add(constDefParser.run(iterator));
            tt = iterator.next();
        }
        //判断是不是 ';'
        if(tt.getType() != TokenType.SEMICN) {
            iterator.unread(2);
            tt = iterator.next();
            ErrorSave.error("Parser", tt.getLineno(), 'i');
        }
        else children.add(leafParser.run(tt));

        return new SyntaxTreeNode("<ConstDecl>", null, children);
    }
}
