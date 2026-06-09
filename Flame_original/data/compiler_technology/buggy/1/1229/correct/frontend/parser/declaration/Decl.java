package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.constant.ConstDecl;
import frontend.parser.declaration.variable.VarDecl;
import frontend.parser.statement.blockitem.BlockItem;
import frontend.parser.statement.blockitem.BlockItemIFace;

public class Decl implements BlockItemIFace {
    private final String name = "<Decl>";//这个不输出
    private DeclIFace declIFace;
    private TokenList tokenList;

    public Decl(TokenList tokenList){
        this.tokenList = tokenList;
        this.declIFace = null;
    }

    public void parseDecl(){
        Token first = tokenList.seeAfterToken(0);
        if (first.getType().equals(TokenType.CONSTTK)){
            ConstDecl constDecl = new ConstDecl(tokenList);
            constDecl.parseConstDecl();
            declIFace = constDecl;
        } else{//假设不出错，
            VarDecl varDecl = new VarDecl(tokenList);
            varDecl.parseVarDecl();
            declIFace = varDecl;
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        /* not output BType according to assignment requirement */
        sb.append(this.declIFace.syntaxOutput());
        return sb.toString();
    }
}
