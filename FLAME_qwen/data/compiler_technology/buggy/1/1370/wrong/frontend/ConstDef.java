package frontend;

import java.util.ArrayList;

public class ConstDef implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();

    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token token) {
        nodes.add(token);
        Token token1 = getAToken();
        if(token1 == null){
            return null;
        }
        if (token1.getTokenType() == TokenType.LBRACK) {
            nodes.add(token1);
            Token token2 = getAToken();
            if(token2 == null){
                return null;
            }
            if(token2.getTokenType()== TokenType.LPARENT || token2.getTokenType() == TokenType.IDENFR || token2.getTokenType() ==TokenType.INTCON || token2.getTokenType() ==TokenType.CHRCON || token2.getTokenType() == TokenType.MINU||token2.getTokenType() == TokenType.PLUS||token2.getTokenType() == TokenType.NOT){
                ConstExp constExp = new ConstExp();
                errorline = token2.getLineno();
                Token token3 = constExp.parser(token2);
                nodes.add(constExp);
                if(token3 == null){
                    return null;
                }
                if(token3.getTokenType() != TokenType.RBRACK){
                    putBackAToken(token3);
                    reportError(errorline);
                }else{
                    nodes.add(token3);
                }
                token1 = getAToken();
                if(token1 == null){
                    return null;
                }
            }else{
                return token2;
            }

        } if (token1.getTokenType() != TokenType.ASSIGN) {
            return token1;
        }
        nodes.add(token1);
        token1 = getAToken();
        if(token1 == null){
            return null;
        }
        if(token1.getTokenType() == TokenType.LBRACE||token1.getTokenType() == TokenType.STRCON||token1.getTokenType()== TokenType.LPARENT || token1.getTokenType() == TokenType.IDENFR || token1.getTokenType() ==TokenType.INTCON || token1.getTokenType() ==TokenType.CHRCON || token1.getTokenType() == TokenType.MINU||token1.getTokenType() == TokenType.PLUS){
            ConstInitVal constInitVal = new ConstInitVal();
            Token token2 = constInitVal.parser(token1);
            nodes.add(constInitVal);
            return token2;

        }else{
            return token1;
        }
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<ConstDef>" + "\n");
    }

    public void reportError(int lineno){
        WriteIntoF.getInstance().writeToFile(false,lineno+" "+ErrorType.k+"\n");
    }

    public Token getAToken(){
        return giveTokener.getAToken();
    }


    public void putBackAToken(Token token){
        giveTokener.putBackAToken(token);
    }
}
