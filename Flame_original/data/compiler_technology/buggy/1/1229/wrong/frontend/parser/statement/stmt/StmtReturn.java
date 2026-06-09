package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import middle.error.Error;
import middle.error.ErrorTable;

public class StmtReturn implements StmtIFace{
    private Token returnTk; // 'return'
    private Exp exp = null; // MAY exist
    private Token semicn; // ';'

    private TokenList tokenList;

    public StmtReturn(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtReturn(){
        this.returnTk = tokenList.getNextToken();
        //if (!tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
        // 结合错误处理的话，这里不能用;来判断是否有exp了
        // TODO  但是，这里要是不用分号判断，结合if，那就判断不出来了，之后可以是任何东西！！！!!!!!!!!!!!!!!!!!!
        if (!tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.exp = new Exp(tokenList);
            this.exp.parseExp();
        }
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.semicn = tokenList.getNextToken();
        } else {
            //handle error i
            Token token = tokenList.seeAfterToken(-1);
            int lineNum = token.getLineNum();
            middle.error.Error error = new Error(lineNum,"i");
            ErrorTable.addError(error);
            this.semicn = new Token(TokenType.SEMICN,lineNum,";");
            //自己捏造个；放这，防止以后分析到这，再出错
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.returnTk.syntaxOutput());
        if (exp != null) {
            sb.append(this.exp.syntaxOutput());
        }
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
