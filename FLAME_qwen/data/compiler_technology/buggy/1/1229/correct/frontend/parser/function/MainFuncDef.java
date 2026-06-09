package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.statement.Block;
import middle.error.Error;
import middle.error.ErrorTable;

public class MainFuncDef implements Node {
    private final String name = "<MainFuncDef>";
    private Token intTk; // 'int'
    private Token mainTk; // 'main'
    private Token leftParent; // '('
    private Token rightParent; // ')'
    private Block block;

    private TokenList tokenList;

    public MainFuncDef(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseMainFuncDef(){
        this.intTk = tokenList.getNextToken();
        this.mainTk = tokenList.getNextToken();
        this.leftParent = tokenList.getNextToken();
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.RPARENT)){
            this.rightParent = tokenList.getNextToken();
        } else {
            //handle error j
            Token token1 = tokenList.seeAfterToken(-1);
            int lineNum = token1.getLineNum();
            middle.error.Error error = new Error(lineNum,"j");
            ErrorTable.addError(error);
            this.rightParent = new Token(TokenType.RPARENT,lineNum,")");
            //自己捏造个)放这，防止以后分析到这，再出错
        }
        Block block1 = new Block(tokenList);
        block1.parseBlock();
        this.block = block1;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.intTk.syntaxOutput());
        sb.append(this.mainTk.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.block.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
