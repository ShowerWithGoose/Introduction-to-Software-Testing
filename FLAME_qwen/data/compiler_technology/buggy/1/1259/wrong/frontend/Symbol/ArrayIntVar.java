package frontend.Symbol;

import frontend.Parser.GrammarTreeNode;

public class ArrayIntVar implements SymbolExtend
{
    public GrammarTreeNode valueNode;
    public int[] value;
    public GrammarTreeNode sizeNode;
    public int size;
    public ArrayIntVar(GrammarTreeNode valueNode,GrammarTreeNode sizeNode){
        this.valueNode = valueNode;
        this.sizeNode = sizeNode;
    }
}
