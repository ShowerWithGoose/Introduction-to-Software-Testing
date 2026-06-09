package frontend;

import java.util.ArrayList;

public class FuncType implements Node{

    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();
    public Token parser(Token token){
        if(token.getTokenType() == TokenType.INTTK||token.getTokenType() == TokenType.CHARTK||token.getTokenType() == TokenType.VOIDTK){
            nodes.add(token);
            return getAToken();
        }else{
            //error!!!
            return getAToken();
        }
    }

    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,"k "+lineno+"\n");
    }
    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<FuncType>" + "\n");
    }


    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
