package frontend;

import java.util.ArrayList;

public class ConstDecl implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private int errorline = 0;
    public Token parser(Token firstToken){
        errorline = firstToken.getLineno();
        if(firstToken.getTokenType()!=TokenType.CONSTTK){
            System.out.println("what!???Not CONST in ConstDecl in line 10");
        }
        nodes.add(firstToken);
        Token token = getAToken();
        if(token == null){
            return null;
        }if(token.getTokenType() != TokenType.INTTK && token.getTokenType() != TokenType.CHARTK){
            return token;
        }
        nodes.add(token);
        Token token1 = getAToken();
        if(token1 == null){
            return null;
        }
        if(token1.getTokenType() != TokenType.IDENFR){
            return token1;
        }
        ConstDef constDef = new ConstDef();
        nodes.add(constDef);
        errorline = token1.getLineno();
        Token token2 = constDef.parser(token1);
        if(token2 == null){
            return null;
        }
        while(token2.getTokenType() == TokenType.COMMA){
            nodes.add(token2);
            Token token3 = getAToken();
            if(token3 == null){
                return null;
            }if(token3.getTokenType() != TokenType.IDENFR){
            }
            errorline = token3.getLineno();
            ConstDef constDef1 = new ConstDef();
            nodes.add(constDef1);
            errorline = token3.getLineno();
            token2 = constDef1.parser(token3);
            if (token2 == null) {
                return null;
            }
        }
        if(token2.getTokenType() == TokenType.SEMICN){
            nodes.add(token2);
            return getAToken();
        }else {
            reportError(errorline);
            return token2;
        }
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<ConstDecl>" + "\n");
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
