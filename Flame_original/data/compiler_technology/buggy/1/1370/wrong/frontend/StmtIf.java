package frontend;

import java.util.ArrayList;

public class StmtIf implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();
    private int errorline = 0;

    public Token parser(Token firstToken){
        nodes.add(firstToken);
        Token token = getAToken();
        if(token == null){
            return null;
        }
        if(token.getTokenType() != TokenType.LPARENT){
            return token;
        }
        nodes.add(token);
        token = getAToken();
        if(token == null){
            return null;
        }
        if(!(Exp.isFirstExp(token))){
            return token;
        }
        Cond cond =  new Cond();
        errorline = token.getLineno();
        Token token1 = cond.parser(token);
        nodes.add(cond);
        if(token1 == null){
            return null;
        }
        if(token1.getTokenType() != TokenType.RPARENT){
            putBackAToken(token1);
            reportErrorj(errorline);
        }else{
            nodes.add(token1);
        }
        token = getAToken();
        if(token == null){
            return null;
        }
        if(Stmt.isStmtFirst(token)){
            Node node = Stmt.parserStmt(token);
            Token token2 = node.parser(token);
            nodes.add(node);
            if(token2 == null){
                return null;
            }else if(token2.getTokenType() == TokenType.ELSETK){
                nodes.add(token2);
                token1 = getAToken();
                if(token1 == null){
                    return null;
                }
                if(Stmt.isStmtFirst(token1)){
                    Node node1 = Stmt.parserStmt(token1);
                    Token token3 = node1.parser(token1);
                    nodes.add(node1);
                    return token3;
                }
                return token2;
            }else{
                return token2;
            }
        }else{
            return token;
        }
    }
    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Stmt>" + "\n");
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
