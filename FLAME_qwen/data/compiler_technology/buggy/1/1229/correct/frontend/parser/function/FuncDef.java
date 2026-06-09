package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.statement.Block;
import frontend.parser.terminal.Ident;
import middle.error.Error;
import middle.error.ErrorTable;

public class FuncDef implements Node {
    private final String name = "<FuncDef>";
    private FuncType funcType;
    private Ident ident;
    private Token leftParent; // '('
    private FuncFParams funcFParams = null; // MAY exist
    private Token rightParent; // ')'
    private Block block;

    private TokenList tokenList;

    public FuncDef(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseFuncDef(){
        FuncType funcType1 = new FuncType(tokenList);
        funcType1.parseFuncType();
        this.funcType = funcType1;
        Ident ident1 = new Ident(tokenList);
        ident1.parseIdent();
        this.ident = ident1;
        this.leftParent = tokenList.getNextToken();
        Token token = tokenList.seeAfterToken(0);
        if (token.getType().equals(TokenType.INTTK) ||
            token.getType().equals(TokenType.CHARTK)){
            FuncFParams funcFParams1 = new FuncFParams(tokenList);
            funcFParams1.parseFuncFParams();
            this.funcFParams = funcFParams1;
        }

        //这里同样不该用）判读是否有形参的
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

        Block block1 =new Block(tokenList);
        block1.parseBlock();
        this.block = block1;

    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.funcType.syntaxOutput());
        sb.append(this.ident.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        if (this.funcFParams != null) {
            sb.append(this.funcFParams.syntaxOutput());
        }
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.block.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
