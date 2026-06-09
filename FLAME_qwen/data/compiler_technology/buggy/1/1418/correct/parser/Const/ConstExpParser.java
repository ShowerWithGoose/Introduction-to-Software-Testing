package parser.Const;

import model.TokensIterator;
import parser.Exp.AddExpParser;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class ConstExpParser {
    public SyntaxTreeNode run(TokensIterator iterator) {
        List<SyntaxTreeNode> children = new ArrayList<>();

        AddExpParser addExpParser = new AddExpParser();
        children.add(addExpParser.run(iterator));

        return new SyntaxTreeNode("<ConstExp>", null, children);
    }
}
