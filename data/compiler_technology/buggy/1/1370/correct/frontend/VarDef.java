package frontend;

import java.util.ArrayList;

public class VarDef implements Node{
    private GiveTokener giveTokener = GiveTokener.getInstance();
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token firstoken){
        nodes.add(firstoken);
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
            if(token2.getTokenType()== TokenType.LPARENT || token2.getTokenType() == TokenType.IDENFR || token2.getTokenType() ==TokenType.INTCON || token2.getTokenType() ==TokenType.CHRCON || token2.getTokenType() == TokenType.MINU||token2.getTokenType() == TokenType.PLUS|| token2.getTokenType() == TokenType.NOT){
                ConstExp constExp = new ConstExp();
                errorline = token2.getLineno();
                Token token = constExp.parser(token2);
                nodes.add(constExp);
                if(token == null){
                    return null;
                }
                if(token.getTokenType() != TokenType.RBRACK){
                    putBackAToken(token);
                    reportError(errorline);
                }else{
                    nodes.add(token);
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
        if(token1.getTokenType() == TokenType.LBRACE||token1.getTokenType() == TokenType.STRCON||token1.getTokenType()== TokenType.LPARENT || token1.getTokenType() == TokenType.IDENFR || token1.getTokenType() ==TokenType.INTCON || token1.getTokenType() ==TokenType.CHRCON || token1.getTokenType() == TokenType.MINU||token1.getTokenType() == TokenType.PLUS|| token1.getTokenType() == TokenType.NOT){

            InitVal initVal = new InitVal();
            Token token = initVal.parser(token1);
            nodes.add(initVal);
            return token;

        }else{
            return token1;
        }
    }

    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<VarDef>" + "\n");
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
