package frontend.ParserPart.state.blockitem;

import frontend.Factor;
import frontend.ParserPart.decl.Decl;
import frontend.ParserPart.state.stmt.Stmt;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class BlockItem implements Factor {
    private String name = "<BlockItem>";
    private TokenList tokenList;
    private BlockItemInterface blockItemInterface;

    public BlockItem(TokenList tokenList){
        this.tokenList = tokenList;
        blockItemInterface = null;
    }
    public void parseBlockItem(){
        if (isDeclStart()){
            //如果情况是Decl
            Decl decl = new Decl(tokenList);
            decl.parseDecl();
            blockItemInterface = decl;
        }else {
            //如果情况是Stmt
            Stmt stmt = new Stmt(tokenList);
            stmt.parseStmt();
            blockItemInterface = stmt;
        }
    }
    public boolean isDeclStart(){
        return (tokenList.peek().getType().equals(TokenType.INTTK) ||
                tokenList.peek().getType().equals(TokenType.CHARTK) || tokenList.peek().getType().equals(TokenType.CONSTTK));
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(blockItemInterface.toString());
        return sb.toString();
    }
}
