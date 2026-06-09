package frontend.parser.block;


public class BlockItem {
    private final String name = "<BlockItem>";
    private BItem item;

    public BlockItem(BItem item) {
        this.item = item;
    }

    public String getOutPut() {
        return item.getOutPut();
    }

    public String getError() {
        return item.getError();
    }
}
