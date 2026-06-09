package frontend;

import java.util.ArrayList;

public class FuncDef implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token token){
        FuncType funcType = new FuncType();
        Token token1 =funcType.parser(token);
        nodes.add(funcType);
        if(token1 == null){
            return null;
        }
        if(token1.getTokenType()!=TokenType.IDENFR){
            return token1;
        }
        nodes.add(token1);
        Token token2 = getAToken();
        if(token2 == null){
            return null;
        }
        if(token2.getTokenType()!=TokenType.LPARENT){
            return token2;
        }
        errorline = token2.getLineno();
        nodes.add(token2);
        token2 = getAToken();
        if(token2 == null){
            return null;
        }
        if(token2.getTokenType()!=TokenType.RPARENT){
            if(token2.getTokenType()!=TokenType.INTTK&&token2.getTokenType()!=TokenType.CHARTK){
                reportError(errorline);
                if(token2.getTokenType()!=TokenType.LBRACE){
                    return token2;
                }
                Block block = new Block();
                block.parser(token2);
                nodes.add(block);
                return getAToken();
            }
            FuncFParams funcFParams = new FuncFParams();
            errorline = token2.getLineno();
            token2 = funcFParams.parser(token2);
            nodes.add(funcFParams);
            if(token2 == null){
                return null;
            }

        }
        if(token2.getTokenType()!=TokenType.RPARENT){
            reportError(errorline);
            return token2;
        }
        nodes.add(token2);
        Token token3 = getAToken();
        if(token3 == null){
            return null;
        }
        if(token3.getTokenType()!=TokenType.LBRACE){
            return token3;
        }
        Block block = new Block();
        block.parser(token3);
        nodes.add(block);
        return getAToken();
    }


    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.j+"\n");
    }
    public void printToFile() {
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<FuncDef>" + "\n");
    }


    public Token getAToken(){
        return giveTokener.getAToken();
    }

    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
