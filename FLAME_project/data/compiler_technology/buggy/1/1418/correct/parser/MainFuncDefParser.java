package parser;

import enums.TokenType;
import model.SyntaxTreeNode;
import model.Token;
import model.TokensIterator;
import parser.Normal.BlockParser;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class MainFuncDefParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LeafParser leafParser = new LeafParser();
        BlockParser blockParser = new BlockParser();

        //int main '('
        children.add(leafParser.run(iterator.next()));
        children.add(leafParser.run(iterator.next()));
        children.add(leafParser.run(iterator.next()));
        // ')'
        Token tt = iterator.next();
        if(tt.getType() != TokenType.RPARENT) {
            iterator.unread(2);
            tt = iterator.next();
            ErrorSave.error("Parser", tt.getLineno(), 'j');
        }
        else children.add(leafParser.run(tt));
        // Block
        children.add(blockParser.run(iterator));

        return new SyntaxTreeNode("<MainFuncDef>", null, children);
    }
}
