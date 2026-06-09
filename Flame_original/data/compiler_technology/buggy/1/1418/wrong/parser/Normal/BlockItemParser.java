package parser.Normal;

import enums.TokenType;
import model.Token;
import model.TokensIterator;
import parser.DeclParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class BlockItemParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        Token tt = iterator.next();
        iterator.unread(1);
        if(tt.getType() == TokenType.CONSTTK || tt.getType() == TokenType.INTTK || tt.getType() == TokenType.CHARTK) {
            DeclParser declParser = new DeclParser();
            children.add(declParser.run(iterator));
        }
        else {
            StmtParser stmtParser = new StmtParser();
            children.add(stmtParser.run(iterator));
        }

        return new SyntaxTreeNode("<BlockItem>", null, children);
    }
}
