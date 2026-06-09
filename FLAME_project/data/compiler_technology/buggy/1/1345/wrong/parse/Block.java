package parse;

import java.util.ArrayList;

public class Block implements StmtEle{
    private final String name = "<Block>";
    private Token leftBrace;
    private ArrayList<BlockItem> blockItems;
    private Token rightBrace;

    public Block(TokenList list,WrongList wrongs) {
        this.leftBrace = list.readNextToken();
        this.blockItems = new ArrayList<>();
        Token token = list.readNextToken();
        while (!token.getType().equals("RBRACE")) {
            list.unReadToken(1);
            this.blockItems.add(new BlockItem(list,wrongs));
            token = list.readNextToken();
        }
        this.rightBrace = token;
    }

    public Token getLeftBrace() {
        return leftBrace;
    }

    public void setLeftBrace(Token leftBrace) {
        this.leftBrace = leftBrace;
    }

    public Token getRightBrace() {
        return rightBrace;
    }

    public void setRightBrace(Token rightBrace) {
        this.rightBrace = rightBrace;
    }

    public ArrayList<BlockItem> getBlockItems() {
        return blockItems;
    }

    public void setBlockItems(ArrayList<BlockItem> blockItems) {
        this.blockItems = blockItems;
    }

    public String getName() {
        return name;
    }


    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.printout());
        if (blockItems != null && blockItems.size() != 0) {
            int len = blockItems.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.blockItems.get(i).printout());
            }
        }
        sb.append(this.rightBrace.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
