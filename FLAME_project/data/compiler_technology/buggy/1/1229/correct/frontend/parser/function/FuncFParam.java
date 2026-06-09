package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.BType;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.Ident;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class FuncFParam implements Node {
    private final String name = "<FuncFParam>";
    private BType btype;
    private Ident ident;
    private Token leftBracket = null; // '[' MAY exist
    private Token rightBracket = null; // ']' MAY exist
    private TokenList tokenList;

    public FuncFParam(TokenList tokenList) {
        this.tokenList = tokenList;
    }
    public void parseFuncFParam(){
        BType bType = new BType(tokenList);
        bType.parseBType();
        this.btype = bType;
        Ident ident1 = new Ident(tokenList);
        ident1.parseIdent();
        this.ident = ident1;
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.LBRACK)){
            this.leftBracket = tokenList.getNextToken();


            if (tokenList.seeAfterToken(0).getType().equals(TokenType.RBRACK)){
                this.rightBracket = tokenList.getNextToken();
            } else {
                //handle error k
                Token token1 = tokenList.seeAfterToken(-1);
                int lineNum = token1.getLineNum();
                middle.error.Error error = new Error(lineNum,"k");
                ErrorTable.addError(error);
                this.rightBracket = new Token(TokenType.RBRACK,lineNum,"]");
                //自己捏造个)放这，防止以后分析到这，再出错
            }
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.syntaxOutput());
        sb.append(this.ident.syntaxOutput());
        if (this.leftBracket != null && this.rightBracket != null) {
            sb.append(this.leftBracket.syntaxOutput());
            sb.append(this.rightBracket.syntaxOutput());
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
