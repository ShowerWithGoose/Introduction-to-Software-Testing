package frontend.parser.declaration.variable;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.DeclIFace;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class VarDecl implements DeclIFace {
    private final String name = "<VarDecl>";
    private BType btype;
    private VarDef first;
    private ArrayList<Token> commas; // ','
    private ArrayList<VarDef> varDefs;
    private Token semicn; // ';'

    private TokenList tokenList;

    public VarDecl(TokenList tokenList) {
        this.tokenList = tokenList;
        this.commas = new ArrayList<>();
        this.varDefs = new ArrayList<>();
    }

    public void parseVarDecl(){
        Token token;
        BType bType = new BType(tokenList);
        bType.parseBType();
        this.btype = bType;
        VarDef varDef = new VarDef(tokenList);
        varDef.parseVarDef();
        first = varDef;
        token = tokenList.getNextToken();
        while (token.getType().equals(TokenType.COMMA)){
            //is ,
            this.commas.add(token);
            VarDef varDef1 = new VarDef(tokenList);
            varDef1.parseVarDef();
            this.varDefs.add(varDef1);
            token = tokenList.getNextToken();
        }
        //this.semicn = token;
        this.tokenList.locationSubOne();
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.semicn = tokenList.getNextToken();
        } else {
            //handle error i
            Token token1 = tokenList.seeAfterToken(-1);
            int lineNum = token1.getLineNum();
            middle.error.Error error = new Error(lineNum,"i");
            ErrorTable.addError(error);
            this.semicn = new Token(TokenType.SEMICN,lineNum,";");
            //自己捏造个；放这，防止以后分析到这，再出错
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.btype.syntaxOutput());
        sb.append(this.first.syntaxOutput());
        if (this.commas != null && this.varDefs != null &&
                this.commas.size() == this.varDefs.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).syntaxOutput());
                sb.append(this.varDefs.get(i).syntaxOutput());
            }
        }
        sb.append(this.semicn.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
