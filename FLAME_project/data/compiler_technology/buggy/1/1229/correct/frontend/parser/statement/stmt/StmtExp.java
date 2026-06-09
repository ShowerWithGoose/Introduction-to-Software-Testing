package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import middle.error.Error;
import middle.error.ErrorTable;

public class StmtExp implements StmtIFace{
    //空语句情况在其他类里处理过了
    private Exp exp;
    private Token semicn; // ';'

    private TokenList tokenList;

    public StmtExp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseStmtExp(){
        Exp exp1 = new Exp(tokenList);
        exp1.parseExp();
        this.exp = exp1;
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
        sb.append(this.exp.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
