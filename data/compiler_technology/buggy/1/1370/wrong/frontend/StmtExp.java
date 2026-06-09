package frontend;

import java.util.ArrayList;

public class StmtExp implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token firstToken){
        TokenType type = firstToken.getTokenType();
        if(type == TokenType.SEMICN){
            //DONE!!!
            nodes.add(firstToken);
            return getAToken();
        }else if (type == TokenType.IDENFR||type == TokenType.PLUS||type == TokenType.MINU||type == TokenType.LPARENT||type == TokenType.INTCON||type == TokenType.CHRCON|| type == TokenType.NOT){
            Exp exp = new Exp();
            errorline = firstToken.getLineno();
            Token token = exp.parser(firstToken);
            nodes.add(exp);
            if(token.getTokenType() != TokenType.SEMICN){
                reportErrori(errorline);
                return token;
            }
            nodes.add(token);
            return getAToken();
        }else{
            //error!!
            return firstToken;
        }
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
