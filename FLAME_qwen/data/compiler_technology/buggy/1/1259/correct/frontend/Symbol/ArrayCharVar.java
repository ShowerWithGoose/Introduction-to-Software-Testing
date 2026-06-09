package frontend.Symbol;

import frontend.Parser.GrammarTreeNode;

public class ArrayCharVar implements SymbolExtend
{
    public GrammarTreeNode valueNode;
    public char[] value;
    public GrammarTreeNode sizeNode;
    public int size;
    public ArrayCharVar(GrammarTreeNode valueNode,GrammarTreeNode sizeNode){
        this.valueNode = valueNode;
        this.sizeNode = sizeNode;
    }
}
