package frontend.SyntaxUnits;

public class MainFuncDef implements SyntaxUnit{
    private Block block;

    public MainFuncDef(Block block) {
        this.block = block;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("INTTK" + " int" + "\n");
        stringBuilder.append("MAINTK" + " main" + "\n");
        stringBuilder.append("LPARENT" + " (" + "\n");
        stringBuilder.append("RPARENT" + " )" + "\n");
        stringBuilder.append(block.toPrint());
        stringBuilder.append("<MainFuncDef>\n");
        return stringBuilder.toString();
    }
}
