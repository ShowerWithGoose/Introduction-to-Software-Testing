package parse;

public class BlockItem {
    private BlockItemEle blockItemEle;

    public BlockItemEle getBlockItemEle() {
        return blockItemEle;
    }

    public void setBlockItemEle(BlockItemEle blockItemEle) {
        this.blockItemEle = blockItemEle;
    }

    public BlockItem(TokenList list,WrongList wrongs) {
        Token token = list.readNextToken();
        if (token.getType().equals("CONSTTK") || token.getType().equals("INTTK") || token.getType().equals("CHARTK")) {
            list.unReadToken(1);
            this.blockItemEle = new Decl(list,wrongs);
        } else {
            list.unReadToken(1);
            this.blockItemEle = new Stmt(list,wrongs);
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.blockItemEle.printout());
        return sb.toString();
    }
}
