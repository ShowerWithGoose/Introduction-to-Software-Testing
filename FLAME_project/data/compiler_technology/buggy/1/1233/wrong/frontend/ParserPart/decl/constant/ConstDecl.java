package frontend.ParserPart.decl.constant;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.decl.BType;
import frontend.ParserPart.decl.DeclInterface;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class ConstDecl implements DeclInterface {
    private String name = "<ConstDecl>";
    private TokenList tokenList;
    private Token constToken;//代表了前面的const
    private BType bType;
    private ConstDef constDef;//代表了前面唯一的一个
    private ArrayList<ConstDef> constDefArrayList;//代表了后面的可能存在的东西的constdef部分
    private ArrayList<Token> commas;//代表了后面的可能存在的东西的comma部分
    private Token semicn;//代表了后面的;
    public ConstDecl(TokenList tokenList){
        this.tokenList = tokenList;
        constToken = new Token(TokenType.CONSTTK,"const");
        bType = new BType(tokenList);
        constDef = new ConstDef(tokenList);
        constDefArrayList = new ArrayList<>();
        commas = new ArrayList<>();
        semicn = new Token(TokenType.SEMICN,";");
    }

    public void parserConstDecl(){
        //指向const
        tokenList.next();
        bType.parseBType();
        constDef.parserConstDef();
        while (tokenList.peek().getType().equals(TokenType.COMMA)){
            Token token = new Token(TokenType.COMMA,",");
            commas.add(token);
            tokenList.next();
            ConstDef tem = new ConstDef(tokenList);
            tem.parserConstDef();
            constDefArrayList.add(tem);
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
       sb.append(constToken.toString());
       sb.append(bType.toString());
       sb.append(constDef.toString());
        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i).toString());
            sb.append(constDefArrayList.get(i).toString());
        }
        sb.append(semicn.toString());
        sb.append(name);
        sb.append("\n");
       return sb.toString();
    }
}
