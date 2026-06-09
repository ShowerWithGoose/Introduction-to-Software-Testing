package frontend;

import java.util.ArrayList;

public class MainFuncDef implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token token){
        nodes.add(token);
        Token tnow1 = getAToken();
        if(tnow1 == null){
            return null;
        }
        //if(tnow1.getTokenType() != TokenType.MAINTK){
            //tnow1 = tnow1;
        //}
        nodes.add(tnow1);
        tnow1 = getAToken();
        if(tnow1 == null){
            return null;
        }
        if(tnow1.getTokenType() != TokenType.LPARENT){
            //error!!!
        }
        errorline = tnow1.getLineno();
        nodes.add(tnow1);
        tnow1 = getAToken();
        if(tnow1 == null){
            return null;
        }
        if(tnow1.getTokenType() != TokenType.RPARENT){
            putBackAToken(tnow1);
            reportError(errorline);
            //error!!!
        }else{
            nodes.add(tnow1);
        }
        tnow1 = getAToken();
        if(tnow1 == null){
            return null;
        }if(tnow1.getTokenType()!=TokenType.LBRACE){
        }
        Block block = new Block();
        block.parser(tnow1);
        nodes.add(block);
        return getAToken();
    }

    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.j+"\n");
    }
    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<MainFuncDef>" + "\n");
    }


    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
