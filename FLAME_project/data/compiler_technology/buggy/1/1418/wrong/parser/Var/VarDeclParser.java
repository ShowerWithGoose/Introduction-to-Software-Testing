package parser.Var;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.Normal.BTypeParser;
import parser.LeafParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class VarDeclParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        //处理 BType
        BTypeParser bTypeParser = new BTypeParser();
        children.add(bTypeParser.run(iterator));

        //处理 VarDef
        VarDefParser varDefParser = new VarDefParser();
        children.add(varDefParser.run(iterator));
        Token tt = iterator.next();
        while(tt.getType() == TokenType.COMMA) {
            children.add(leafParser.run(tt));
            children.add(varDefParser.run(iterator));
            tt = iterator.next();
        }
        //判断是不是 ';'
        if(tt.getType() != TokenType.SEMICN) {
            iterator.unread(2);
            tt = iterator.next();
            ErrorSave.error("Parser", tt.getLineno(), 'i');
        }
        else children.add(leafParser.run(tt));

        return new SyntaxTreeNode("<VarDecl>", null, children);
    }
}
