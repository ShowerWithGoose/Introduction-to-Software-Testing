package parser.Normal;

import model.TokensIterator;
import parser.LeafParser;
import model.SyntaxTreeNode;
import parser.Var.ExpParser;

import java.util.ArrayList;
import java.util.List;

public class ForStmtParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();
        LValParser lValParser = new LValParser();
        ExpParser expParser = new ExpParser();
        LeafParser leafParser = new LeafParser();

        children.add(lValParser.run(iterator));
        children.add(leafParser.run(iterator.next()));
        children.add(expParser.run(iterator));

        return new SyntaxTreeNode("<ForStmt>", null, children);
    }
}
