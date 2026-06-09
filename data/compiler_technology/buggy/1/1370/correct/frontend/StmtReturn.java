package frontend;

import java.util.ArrayList;

public class StmtReturn implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token firstoken){
        nodes.add(firstoken);
        errorline=firstoken.getLineno();
        Token token = getAToken();
        if(token == null){
            return null;
        }
        else if(token.getTokenType() == TokenType.SEMICN){
            nodes.add(token);
            return getAToken();
        }else if(!(Exp.isFirstExp(token))){
            reportErrori(errorline);
            return token;
        }Exp exp = new Exp();
        errorline = token.getLineno();
        Token token1 = exp.parser(token);
        nodes.add(exp);
        if(token1 == null){
            return null;
        }else if(token1.getTokenType() != TokenType.SEMICN){
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
