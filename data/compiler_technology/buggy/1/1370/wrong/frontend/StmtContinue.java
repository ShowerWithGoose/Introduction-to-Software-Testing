package frontend;

import java.util.ArrayList;

public class StmtContinue implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;
    public Token parser(Token token){
        errorline = token.getLineno();
        nodes.add(token);
        Token token1 = getAToken();
        if(token1 == null){
            return null;
        }
        else if(token1.getTokenType() != TokenType.SEMICN){
            reportErrori(errorline);
            return token1;
        }
        nodes.add(token1);
        return getAToken();
    }
    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Stmt>" + "\n");
    }
    public void reportErrori(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.i+"\n");
    }
    public Token getAToken(){
        return GiveTokener.getInstance().getAToken();
    }

    public void putBackAToken(Token token){
        GiveTokener.getInstance().putBackAToken(token);
    }
}
