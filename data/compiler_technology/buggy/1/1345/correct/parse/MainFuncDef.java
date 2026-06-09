package parse;

public class MainFuncDef {
    private final String name = "<MainFuncDef>";
    private Token intTk; 
    private Token mainTk; 
    private Token leftbrace; 
    private Token rightbrace;
    private Block block;

    public String getName() {
        return name;
    }

    public Token getIntTk() {
        return intTk;
    }

    public void setIntTk(Token intTk) {
        this.intTk = intTk;
    }

    public Token getMainTk() {
        return mainTk;
    }

    public void setMainTk(Token mainTk) {
        this.mainTk = mainTk;
    }

    public Token getLeftbrace() {
        return leftbrace;
    }

    public void setLeftbrace(Token leftbrace) {
        this.leftbrace = leftbrace;
    }

    public Token getRightbrace() {
        return rightbrace;
    }

    public void setRightbrace(Token rightbrace) {
        this.rightbrace = rightbrace;
    }

    public Block getBlock() {
        return block;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public MainFuncDef(TokenList list,WrongList wrongs) {
        this.intTk = list.readNextToken();
        this.mainTk = list.readNextToken();
        this.leftbrace = list.readNextToken();
        this.rightbrace = HandleError.handleJ(list.readNextToken(),list,wrongs);
        this.block = new Block(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.printout());
        sb.append(this.mainTk.printout());
        sb.append(this.leftbrace.printout());
        sb.append(this.rightbrace.printout());
        sb.append(this.block.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
