package frontend;

import java.util.ArrayList;

public class FuncFParam implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token token){
        nodes.add(token);
        Token token1 = getAToken();
        if(token1 == null){
            return null;
        }else if(token1.getTokenType()!=TokenType.IDENFR){
            return token1;
        }nodes.add(token1);
        token1 = getAToken();
        if(token1 == null){
            return null;
        }else if(token1.getTokenType()!=TokenType.LBRACK){
            return token1;
        }
        errorline = token1.getLineno();
        nodes.add(token1);
        token1 = getAToken();
        if(token1 == null){
            return null;
        }else if(token1.getTokenType()!=TokenType.RBRACK){
            reportError(errorline);
            return token1;
        }
        nodes.add(token1);
        return getAToken();
    }

    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.k+"\n");
    }
    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<FuncFParam>" + "\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
