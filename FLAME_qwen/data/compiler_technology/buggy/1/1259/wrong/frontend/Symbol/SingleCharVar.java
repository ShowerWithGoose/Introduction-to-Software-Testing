package frontend.Symbol;

import frontend.Parser.GrammarTreeNode;

public class SingleCharVar implements SymbolExtend
{
    public GrammarTreeNode valueNode;
    public char value;
    public SingleCharVar(GrammarTreeNode node) {
        valueNode = node;
    }
}
