package parse;

public class FuncDef {
    private final String name = "<FuncDef>";
    private FuncType funcType;
    private Ident ident;
    private Token leftBraces; 
    private FuncFParams funcFParams = null; 
    private Token rightBraces; 
    private Block block;

    public String getName() {
        return name;
    }

    public FuncType getFuncType() {
        return funcType;
    }

    public void setFuncType(FuncType funcType) {
        this.funcType = funcType;
    }

    public Ident getIdent() {
        return ident;
    }

    public void setIdent(Ident ident) {
        this.ident = ident;
    }

    public Token getLeftBraces() {
        return leftBraces;
    }

    public void setLeftBraces(Token leftBraces) {
        this.leftBraces = leftBraces;
    }

    public FuncFParams getFuncFParams() {
        return funcFParams;
    }

    public void setFuncFParams(FuncFParams funcFParams) {
        this.funcFParams = funcFParams;
    }

    public Block getBlock() {
        return block;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public Token getRightBraces() {
        return rightBraces;
    }

    public void setRightBraces(Token rightBraces) {
        this.rightBraces = rightBraces;
    }

    public FuncDef(TokenList list,WrongList wrongs) {
        this.funcType = new FuncType(list,wrongs);
        this.ident = new Ident(list,wrongs);
        this.leftBraces = list.readNextToken();
        this.rightBraces = list.readNextToken();
        if (!this.rightBraces.getType().equals("RPARENT")) {
            list.unReadToken(1);
            Token x = list.readNextToken();
            list.unReadToken(1);
            if(x.getType() != "LBRACE" ){
                this.funcFParams = new FuncFParams(list,wrongs);
            }
            this.rightBraces = HandleError.handleJ(list.readNextToken(),list,wrongs);
            this.block = new Block(list,wrongs);
        } else {
            this.block = new Block(list,wrongs);
            this.funcFParams = null;
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcType.printout());
        sb.append(this.ident.printout());
        sb.append(this.leftBraces.printout());
        if (this.funcFParams != null) {
            sb.append(this.funcFParams.printout());
        }
        sb.append(this.rightBraces.printout());
        sb.append(this.block.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
