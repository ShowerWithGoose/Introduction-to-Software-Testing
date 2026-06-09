package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import middle.error.Error;
import middle.error.ErrorTable;

public class StmtContinue implements StmtIFace{
    private Token continueTk; // 'continue'
    private Token semicn; // ';'

    private TokenList tokenList;

    public StmtContinue(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtContinue(){
        this.continueTk = tokenList.getNextToken();
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
        sb.append(this.continueTk.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
