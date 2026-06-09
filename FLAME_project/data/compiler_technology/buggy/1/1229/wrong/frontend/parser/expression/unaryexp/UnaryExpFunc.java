package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.terminal.Ident;
import middle.error.Error;
import middle.error.ErrorTable;

public class UnaryExpFunc implements UnaryExpIFace{
    private Ident ident;
    private FuncRParams funcRParams = null; // MAY exist
    private Token leftParent;
    private Token rightParent;

    private TokenList tokenList;

    public UnaryExpFunc(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseUnaryExpFunc(){
        this.ident = new Ident(tokenList);
        this.ident.parseIdent();
        this.leftParent = tokenList.getNextToken();
        if (!tokenList.seeAfterToken(0).getType().equals(TokenType.RPARENT)){
            this.funcRParams = new FuncRParams(tokenList);
            this.funcRParams.parseFuncRParams();
        }
        //TODO  这里前面不该用）判断是否有实参的，但是没办法，先留着
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.RPARENT)){
            this.rightParent = tokenList.getNextToken();
        } else {
            //handle error j
            Token token = tokenList.seeAfterToken(-1);
            int lineNum = token.getLineNum();
            Error error = new Error(lineNum,"j");
            ErrorTable.addError(error);
            this.rightParent = new Token(TokenType.RPARENT,lineNum,")");
            //自己捏造个)放这，防止以后分析到这，再出错
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        sb.append(leftParent.syntaxOutput());
        if (funcRParams != null) {
            sb.append(this.funcRParams.syntaxOutput());
        }
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
}
