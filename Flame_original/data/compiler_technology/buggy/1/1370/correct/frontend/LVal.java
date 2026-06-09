package frontend;

import java.util.ArrayList;

public class LVal implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private int errorline = 0;

    ArrayList<Node> nodes = new ArrayList<>();
    public Token parser(Token token){
        nodes.add(token);
        Token token1 = getAToken();
        if(token1 == null){
            return null;
        }
        if(token1.getTokenType() != TokenType.LBRACK){
            return token1;
        }
        nodes.add(token1);
        Token token2 = getAToken();
        if(token2 == null){
            return null;
        }
        if(!(Exp.isFirstExp(token2))){
            return token2;
        }
        Exp exp = new Exp();
        errorline = token2.getLineno();
        Token token3 = exp.parser(token2);
        nodes.add(exp);
        if(token3.getTokenType() != TokenType.RBRACK){
            reportError(errorline);
            return token3;
        }
        nodes.add(token3);
        return getAToken();
    }


    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.k+"\n");
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<LVal>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
