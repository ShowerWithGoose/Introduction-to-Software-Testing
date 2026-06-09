package parser;

import enums.TokenType;
import model.SyntaxTreeNode;
import model.Token;
import model.TokensIterator;
import parser.Normal.BlockParser;
import parser.Normal.FuncFParamsParser;
import parser.Normal.FuncRParamsParser;
import parser.Normal.FuncTypeParser;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class FuncDefParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();

        //处理 FuncType
        FuncTypeParser funcTypeParser = new FuncTypeParser();
        children.add(funcTypeParser.run(iterator));

        //处理 Ident
        Token tt = iterator.next();
        children.add(leafParser.run(tt));

        //处理 '('
        children.add(leafParser.run(iterator.next()));
        //处理 [FuncFParams]
        tt = iterator.next();
        if(tt.getType() == TokenType.INTTK || tt.getType() == TokenType.CHARTK) {
            iterator.unread(1);
            FuncFParamsParser funcFParamsParser= new FuncFParamsParser();
            children.add(funcFParamsParser.run(iterator));
            tt = iterator.next();
        }

        // ')'
        if(tt.getType() != TokenType.RPARENT) {
            iterator.unread(2);
            tt = iterator.next();
            ErrorSave.error("Parser", tt.getLineno(), 'j');
        }
        else children.add(leafParser.run(tt));

        //处理 Block
        BlockParser blockParser = new BlockParser();
        children.add(blockParser.run(iterator));

        return new SyntaxTreeNode("<FuncDef>", null, children);
    }
}
