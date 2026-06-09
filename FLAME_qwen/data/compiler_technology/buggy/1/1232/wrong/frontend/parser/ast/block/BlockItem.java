package frontend.parser.ast.block;

public class BlockItem {
    private String type = "<BlockItem>";
    private BItem item;

    public BlockItem(BItem item) {
        this.item = item;
    }

    public String getOutput() {
        return item.getOutput();
    }

    public String getError() {
        return item.getError();
    }
}
