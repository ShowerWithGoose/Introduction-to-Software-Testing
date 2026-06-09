package frontend.Symbol;

import frontend.Parser.GrammarTreeNode;

public class SingleIntVar implements SymbolExtend
{
    public GrammarTreeNode valueNode;
    public int value;
    public SingleIntVar(GrammarTreeNode node) {
        valueNode = node;
    }
}
