package frontend.ParserPart.state;

import frontend.Factor;
import frontend.ParserPart.state.blockitem.BlockItem;
import frontend.ParserPart.state.stmt.StmtInterface;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class Block implements Factor {
    private String name = "<Block>";
    private TokenList tokenList;
    private Token leftBRACE;
    private ArrayList<BlockItem> blockItemArrayList;//可能存在
    private Token rightBRACE;
    public Block(TokenList tokenList){
        this.tokenList = tokenList;
        leftBRACE = new Token(TokenType.LBRACE,"{");
        blockItemArrayList = new ArrayList<>();
        rightBRACE = new Token(TokenType.RBRACE,"}");
    }
    public void parseBlock(){
        //指向{符号
        tokenList.next();
        while (!tokenList.peek().getType().equals(TokenType.RBRACE)){
            //代表有可选项
            BlockItem tem = new BlockItem(tokenList);
            tem.parseBlockItem();
            blockItemArrayList.add(tem);
        }
        //指向}符号
        tokenList.next();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(leftBRACE.toString());
        for (int i = 0; i < blockItemArrayList.size(); i++) {
            sb.append(blockItemArrayList.get(i).toString());
        }
        sb.append(rightBRACE.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
