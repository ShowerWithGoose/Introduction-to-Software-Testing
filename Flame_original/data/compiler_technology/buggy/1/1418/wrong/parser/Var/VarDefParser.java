package parser.Var;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.Const.ConstExpParser;
import parser.LeafParser;
import model.SyntaxTreeNode;
import util.ErrorSave;

import java.util.ArrayList;
import java.util.List;

public class VarDefParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        //处理 Ident
        LeafParser leafParser = new LeafParser();
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

        //处理剩下的 '=' InitVal
        if(tt.getType() == TokenType.ASSIGN) {
            //处理 '='
            children.add(leafParser.run(tt));

            //处理InitVal
            InitValParser InitValParser = new InitValParser();
            children.add(InitValParser.run(iterator));
        }
        else iterator.unread(1);

        return new SyntaxTreeNode("<VarDef>", null, children);
    }
}
