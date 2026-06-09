package frontend.ParserPart.decl;

import frontend.Factor;
import frontend.ParserPart.decl.constant.ConstDecl;
import frontend.ParserPart.decl.variable.VarDecl;
import frontend.ParserPart.state.blockitem.BlockItemInterface;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class Decl implements BlockItemInterface {
    private String name = "<Decl>";
    private TokenList tokenList;
    private DeclInterface declInterface;//代表了constdecl或者vardecl
    public Decl(TokenList tokenList){
        this.tokenList = tokenList;
        declInterface = null;
    }
    public void parseDecl(){
        Token token = tokenList.peek();
        if (token.getType().equals(TokenType.CONSTTK)){
            //如果是const
            ConstDecl constDecl = new ConstDecl(tokenList);
            constDecl.parserConstDecl();
            declInterface = constDecl;
        }else {
            //如果是var
            VarDecl varDecl = new VarDecl(tokenList);
            varDecl.parserVarDecl();
            declInterface = varDecl;
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(declInterface.toString());
        //decl题目规定不需要输出name
        return sb.toString();
    }
}
