package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryexp.LVal;
import middle.error.Error;
import middle.error.ErrorTable;

public class StmtAssign implements StmtIFace{
    private LVal lval;
    private Token eq; // '='
    private Exp exp = null;
    private Token semicn;

    private Token getint = null;
    private Token getchar = null;
    private Token leftParent; // '('
    private Token rightParent; // ')'

    //TODO  = exp getint getchar

    private TokenList tokenList;

    public StmtAssign(TokenList tokenList) {
        this.tokenList = tokenList;
    }
    public void parseStmtAssign(){
        LVal lVal = new LVal(tokenList);
        lVal.parseLVal();
        this.lval = lVal;
        this.eq = tokenList.getNextToken();
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.GETINTTK)){
            this.getint = tokenList.getNextToken();
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
        } else if (tokenList.seeAfterToken(0).getType().equals(TokenType.GETCHARTK)) {
            this.getchar = tokenList.getNextToken();
            this.leftParent = tokenList.getNextToken();

            //TODO 这里同样不该用）判读是否有形参的
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
        } else {
            Exp exp1 = new Exp(tokenList);
            exp1.parseExp();
            this.exp = exp1;
        }
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.semicn = tokenList.getNextToken();
        } else {
            //handle error i
            Token token = tokenList.seeAfterToken(-1);
            int lineNum = token.getLineNum();
            Error error = new Error(lineNum,"i");
            ErrorTable.addError(error);
            this.semicn = new Token(TokenType.SEMICN,lineNum,";");
            //自己捏造个；放这，防止以后分析到这，再出错
        }
    }
    @Override
    public String syntaxOutput() {
        //TODO 修改
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.syntaxOutput());
        sb.append(this.eq.syntaxOutput());

        if (this.getint != null) {
            sb.append(this.getint.syntaxOutput());
            sb.append(this.leftParent.syntaxOutput());
            sb.append(this.rightParent.syntaxOutput());
        } else if (this.getchar != null){
            sb.append(this.getchar.syntaxOutput());
            sb.append(this.leftParent.syntaxOutput());
            sb.append(this.rightParent.syntaxOutput());
        }else {
            sb.append(this.exp.syntaxOutput());
        }
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
