package frontend;

import java.util.ArrayList;

public class StmtAssign implements Node{

    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token firstToken) {
        LVal lVal = new LVal();
        Token token = lVal.parser(firstToken);
        nodes.add(lVal);
        if (token == null) {
            //error!!!
            return null;
        }
        if (token.getTokenType() != TokenType.ASSIGN) {
            return token;
        }
        nodes.add(token);
        token = getAToken();
        if (token == null) {
            return null;
        }if(token.getTokenType() == TokenType.GETCHARTK || token.getTokenType() == TokenType.GETINTTK){
            int errorline =0;
            nodes.add(token);
            token = getAToken();
            if(token == null){
                return null;
            }
            if(token.getTokenType() != TokenType.LPARENT){
                return token;
            }
            errorline = token.getLineno();
            nodes.add(token);
            token = getAToken();
            if(token == null){
                return null;
            }
            if(token.getTokenType() !=TokenType.RPARENT){
                putBackAToken(token);
                reportErrorj(errorline);
            }else{
                nodes.add(token);
                errorline = token.getLineno();
            }
            token = getAToken();
            if(token == null){
                return null;
            }
            if(token.getTokenType() != TokenType.SEMICN){
                reportErrori(errorline);
                return token;
            }
            nodes.add(token);
            return getAToken();
        }else if(token.getTokenType() == TokenType.IDENFR||token.getTokenType() == TokenType.PLUS||token.getTokenType() == TokenType.MINU||token.getTokenType() == TokenType.LPARENT||token.getTokenType() == TokenType.INTCON||token.getTokenType() == TokenType.CHRCON|| token.getTokenType() == TokenType.NOT){
            int errorline = 0;
            Exp exp = new Exp();
            errorline = token.getLineno();
            Token token1 = exp.parser(token);
            nodes.add(exp);
            if(token1 == null){
                return null;
            }if(token1.getTokenType() != TokenType.SEMICN){
                reportErrori(errorline);
                return token1;
            }
            nodes.add(token1);
            return getAToken();
        }
        else{
            return token;
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
    public void reportErrorj(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.j+"\n");
    }
    public Token getAToken(){
        return GiveTokener.getInstance().getAToken();
    }

    public void putBackAToken(Token token){
        GiveTokener.getInstance().putBackAToken(token);
    }

}
