package frontend;

import java.util.ArrayList;

public class VarDecl implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token firstoken){
        nodes.add(firstoken);
        Token token1 = getAToken();
        if(token1 == null){
            return null;
        }
        if(token1.getTokenType() != TokenType.IDENFR){
            return token1;
        }
        VarDef varDef = new VarDef();
        nodes.add(varDef);
        Token token2 = varDef.parser(token1);
        if(token2 == null){
            return null;
        }
        while(token2.getTokenType() == TokenType.COMMA){
            nodes.add(token2);
            Token token3 = getAToken();
            if(token3 == null){
                return null;
            }if(token3.getTokenType() != TokenType.IDENFR){
                return token3;
            }
            errorline = token3.getLineno();
            VarDef varDef1 = new VarDef();
            nodes.add(varDef1);
            token2 = varDef1.parser(token3);
        }
        if(token2.getTokenType() == TokenType.SEMICN){
            nodes.add(token2);
            return getAToken();
        }else{
            reportError(errorline);
            return token2;
        }
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<VarDecl>" + "\n");
    }
    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.i+"\n");
    }
    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
