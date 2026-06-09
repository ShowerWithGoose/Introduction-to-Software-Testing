package frontend.SyntaxUnits;

public class BlockItem implements SyntaxUnit{
    private final BlockItemUnit blockItemUnit;

    public BlockItem(BlockItemUnit blockItemUnit) {
        this.blockItemUnit = blockItemUnit;
    }

    public String toPrint() {
        return blockItemUnit.toPrint();
    }
}
