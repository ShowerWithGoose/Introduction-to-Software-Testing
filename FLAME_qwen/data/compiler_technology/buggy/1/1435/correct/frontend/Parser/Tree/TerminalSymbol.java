package frontend.Parser.Tree;


public class TerminalSymbol {
    private String type;
    private SyntaxSymbol synNode;

    public TerminalSymbol(SyntaxSymbol synNode){
        this.type = synNode.getType();
        this.synNode =  synNode;
    }

    public String getType(){
        return this.type;
    }

    public SyntaxSymbol getSynNode(){
        return this.synNode;
    }
}
