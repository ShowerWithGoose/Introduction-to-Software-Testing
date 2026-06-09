package frontend;

import java.util.ArrayList;

public class StmtPrintf implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token firstoken){
        nodes.add(firstoken);
        Token token = getAToken();
        if(token == null){
            return null;
        }if(token.getTokenType()!=TokenType.LPARENT){
            return token;
        }
        nodes.add(token);
        token = getAToken();
        if(token == null){
            return null;
        }if(token.getTokenType()!=TokenType.STRCON){
            return token;
        }
        errorline = token.getLineno();
        nodes.add(token);
        token = getAToken();
        if(token == null){
            return null;
        }while(token.getTokenType()!=TokenType.RPARENT){
            if(!(token.getTokenType()==TokenType.COMMA)){
                reportErrorj(errorline);
                if(token == null){
                    return null;
                }if(token.getTokenType()!=TokenType.SEMICN){
                    reportErrori(errorline);
                    return token;//error!!!
                }
                nodes.add(token);
                return getAToken();
            }
            nodes.add(token);
            token = getAToken();
            if(token == null){
                return null;
            }if(!(Exp.isFirstExp(token))){
                return token;
            }
            Exp exp = new Exp();
            token = exp.parser(token);
            nodes.add(exp);
            if(token == null){
                return null;//error!!!
            }
        }
        errorline = token.getLineno();
        nodes.add(token);
        token = getAToken();
        if(token == null){
            return null;
        }if(token.getTokenType()!=TokenType.SEMICN){
            reportErrori(errorline);
            return token;//error!!!
        }
        nodes.add(token);
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
