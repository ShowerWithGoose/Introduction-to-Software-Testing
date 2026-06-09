package parser.Var;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class InitValParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        Token first = iterator.next();

        //处理字符串常量
        if(first.getType() == TokenType.STRCON) {
            LeafParser leafParser = new LeafParser();
            children.add(leafParser.run(first));
        }
        //处理 '{' [Exp { ',' Exp }] '}'
        else if(first.getType() == TokenType.LBRACE) {
            //处理 '{'
            LeafParser leafParser = new LeafParser();
            children.add(leafParser.run(first));

            //处理 [Exp { ',' Exp }] 和 '}'
            first = iterator.next();
            if(first.getType() != TokenType.RBRACE) {
                iterator.unread(1);
                ExpParser expParser = new ExpParser();
                children.add(expParser.run(iterator));
                first = iterator.next();
                while(first.getType() == TokenType.COMMA) {
                    children.add(leafParser.run(first));
                    children.add(expParser.run(iterator));
                    first = iterator.next();
                }
                //处理 '}'
                children.add(leafParser.run(first));
            }
            //处理 '}'
            else children.add(leafParser.run(first));
        }
        //处理 Exp
        else {
            iterator.unread(1);
            ExpParser expParser = new ExpParser();
            children.add(expParser.run(iterator));
        }

        return new SyntaxTreeNode("<InitVal>", null, children);
    }
}
