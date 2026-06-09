package parser.Const;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class ConstInitValParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        Token first = iterator.next();

        //处理字符串常量
        if(first.getType() == TokenType.STRCON) {
            LeafParser leafParser = new LeafParser();
            children.add(leafParser.run(first));
        }
        //处理 '{' [ConstExp { ',' ConstExp }] '}'
        else if(first.getType() == TokenType.LBRACE) {
            //处理 '{'
            LeafParser leafParser = new LeafParser();
            children.add(leafParser.run(first));

            //处理 [ConstExp { ',' ConstExp }] 和 '}'
            first = iterator.next();
            if(first.getType() != TokenType.RBRACE) {
                iterator.unread(1);
                ConstExpParser constExpParser = new ConstExpParser();
                children.add(constExpParser.run(iterator));
                first = iterator.next();
                while(first.getType() == TokenType.COMMA) {
                    children.add(leafParser.run(first));
                    children.add(constExpParser.run(iterator));
                    first = iterator.next();
                }
                //处理 '}'
                children.add(leafParser.run(first));
            }
            //处理 '}'
            else children.add(leafParser.run(first));
        }
        //处理 ConstExp
        else {
            iterator.unread(1);
            ConstExpParser constExpParser = new ConstExpParser();
            children.add(constExpParser.run(iterator));
        }
        return new SyntaxTreeNode("<ConstInitVal>", null, children);
    }
}
