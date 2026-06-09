package frontend.Parser.Tree;

public class NonTerminalSymbol {
    private final String type;
    private final SyntaxSymbol synNode;

    public NonTerminalSymbol(SyntaxSymbol synNode){
        this.type = synNode.getType();
        this.synNode =  synNode;
    }

    public String getType(){
        return this.type;
    }

    public SyntaxSymbol getSynNode(){
        return this.synNode;
    }

//    public String toString(){
//        return <%s>.
//    }
}
