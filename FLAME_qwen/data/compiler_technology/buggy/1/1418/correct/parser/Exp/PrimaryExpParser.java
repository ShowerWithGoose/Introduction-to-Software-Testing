package parser.Exp;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.Normal.CharacterParser;
import parser.LeafParser;
import parser.Normal.LValParser;
import parser.Normal.NumberParser;
import model.SyntaxTreeNode;
import parser.Var.ExpParser;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class PrimaryExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        Token tt = iterator.next();
        //处理 '(' Exp ')'
        if(tt.getType() == TokenType.LPARENT) {
            LeafParser leafParser = new LeafParser();
            // '(' Exp
            children.add(leafParser.run(tt));
            ExpParser expParser = new ExpParser();
            children.add(expParser.run(iterator));
            // ')'
            tt = iterator.next();
            if(tt.getType() != TokenType.RPARENT) {
                iterator.unread(2);
                tt = iterator.next();
                ErrorSave.error("Parser", tt.getLineno(), 'j');
            }
            else children.add(leafParser.run(tt));
        }
        //处理 LVal
        else if(tt.getType() == TokenType.IDENFR) {
            LValParser lValParser = new LValParser();
            iterator.unread(1);
            children.add(lValParser.run(iterator));
        }
        //处理 Number
        else if(tt.getType() == TokenType.INTCON) {
            NumberParser numberParser = new NumberParser();
            children.add(numberParser.run(tt));
        }
        //处理 Character
        else {
            CharacterParser characterParser = new CharacterParser();
            children.add(characterParser.run(tt));
        }

        return new SyntaxTreeNode("<PrimaryExp>", null, children);
    }
}
