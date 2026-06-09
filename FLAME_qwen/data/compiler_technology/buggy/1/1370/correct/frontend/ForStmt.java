package frontend;

import java.util.ArrayList;

public class ForStmt implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token token){
        LVal lVal = new LVal();
        Token token1 = lVal.parser(token);
        nodes.add(lVal);
        if(token1 == null){
            System.out.println("error!:inForStmt.parserForStmt in line 11");
            return null;
        }
        if(token1.getTokenType() != TokenType.ASSIGN){
            System.out.println("error!:inForStmt.parserForStmt in line 15");
            return token1;
        }
        nodes.add(token1);
        Token token2 = getAToken();
        if(token2 == null){
            System.out.println("error!:inForStmt.parserForStmt in line 20");
            return null;
        }
        if(!(Exp.isFirstExp(token2))){
            System.out.println("error!:inForStmt.parserForStmt in line 24");
            return token2;
        }
        Exp exp = new Exp();
        Token token3 = exp.parser(token2);
        nodes.add(exp);
        return token3;
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<ForStmt>" + "\n");
    }
    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
