package frontend;

import java.util.ArrayList;

public class Block implements StmtContent{
    private TokenItaretor itaretor;
    private ParserFile file;
    private Token lbrace;
    private Token rbrace;
    private ArrayList<BlockItem> blockItems;

    public Block(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getBlock() {
        lbrace = itaretor.getNext();
        file.addToken(lbrace);
        Token token = itaretor.getNext();
        blockItems = new ArrayList<>();
        while(!token.getString().equals("}")) {
            itaretor.getPrevious(1);
            BlockItem blockItem = new BlockItem(itaretor,file);
            blockItem.getBlockItem();
            blockItems.add(blockItem);
            token = itaretor.getNext();
        }
        rbrace = token;
        file.addToken(rbrace);
        file.addToken(new Token("<Block>"));
    }
}
