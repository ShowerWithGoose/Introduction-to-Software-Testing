package frontend.ParserPart.decl.variable;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.decl.BType;
import frontend.ParserPart.decl.DeclInterface;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class VarDecl implements DeclInterface {
    private String name = "<VarDecl>";
    private TokenList tokenList;
    private BType bType;
    private VarDef varDef;
    private ArrayList<Token> commas;//可能存在逗号
    private ArrayList<VarDef> varDefArrayList;//可能存在一堆vardef
    private Token semicn;//末尾的;号
    public VarDecl(TokenList tokenList){
        this.tokenList = tokenList;
        bType = new BType(tokenList);
        varDef = new VarDef(tokenList);
        commas = new ArrayList<>();
        varDefArrayList = new ArrayList<>();
        semicn = new Token(TokenType.SEMICN,";");
    }
    public void parserVarDecl(){
        bType.parseBType();
        varDef.parseVarDef();
        while (tokenList.peek().getType().equals(TokenType.COMMA)){
            Token token = new Token(TokenType.COMMA,",");
            commas.add(token);
            tokenList.next();
            VarDef tem = new VarDef(tokenList);
            tem.parseVarDef();
            varDefArrayList.add(tem);
        }
        //指向;号
        if (tokenList.peek().getType().equals(TokenType.SEMICN)){
            tokenList.next(); }
        else {
            Error error = new Error(ErrorType.i,tokenList.preRead(-1).getLineNum());
            ErrorList.addError(error);
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString());
        sb.append(varDef.toString());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).toString());
            sb.append(varDefArrayList.get(i).toString());
        }
        sb.append(semicn.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
