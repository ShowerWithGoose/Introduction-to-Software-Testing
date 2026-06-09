package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.DeclIFace;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class ConstDecl implements DeclIFace {
    private final String name = "<ConstDecl>";
    private Token constTk; // 'const',必须传进来，不然不知道行数
    private BType btype;
    private ConstDef first;
    private ArrayList<Token> commas; // commas,即,
    private ArrayList<ConstDef> constDefs; // constDefs
    private Token semicn; // ';'

    private TokenList tokenList;

    public ConstDecl(TokenList tokenList) {
        this.tokenList = tokenList;
        this.commas = new ArrayList<>();
        this.constDefs = new ArrayList<>();
    }

    public void parseConstDecl(){
        Token token = tokenList.getNextToken();
        constTk = token;
        BType bType = new BType(tokenList);
        bType.parseBType();
        this.btype = bType;
        ConstDef constDef = new ConstDef(tokenList);
        constDef.parseConstDef();
        first = constDef;
        token = tokenList.getNextToken();
        while (token.getType().equals(TokenType.COMMA)){
            //is ,
            this.commas.add(token);
            ConstDef constDef1 = new ConstDef(tokenList);
            constDef1.parseConstDef();
            this.constDefs.add(constDef1);
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
        sb.append(constTk.syntaxOutput());
        sb.append(btype.syntaxOutput());
        sb.append(first.syntaxOutput());
        if (commas != null && constDefs != null && commas.size() == constDefs.size()) {
            int len = commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).syntaxOutput());
                sb.append(this.constDefs.get(i).syntaxOutput());
            }
        }
        sb.append(this.semicn.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
