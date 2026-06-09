package frontend;

import java.util.ArrayList;

public class StmtFor implements Node{
    private ArrayList<Node> nodes = new ArrayList<>();

    public Token parser(Token firstToken){
        nodes.add(firstToken);
        Token token = getAToken();
        if(token == null){
            //error!!!
            return null;
        }if(token.getTokenType()!=TokenType.LPARENT){
            //error!!!
            return token;
        }
        nodes.add(token);
        token = getAToken();
        if(token == null){
            //error!!!
            return null;
        }
        if(token.getTokenType() != TokenType.SEMICN){
            if(token.getTokenType()!=TokenType.IDENFR){
                //error!!!
                return token;
            }
            ForStmt forStmt = new ForStmt();
            token = forStmt.parser(token);
            nodes.add(forStmt);
            if(token == null){
                //error!!!
                return null;
            }if(token.getTokenType() != TokenType.SEMICN){
                //error!!!
                return token;
            }
        }
        nodes.add(token);
        token = getAToken();
        if(token == null){
            //error!!!
            return null;
        }
        if(token.getTokenType() != TokenType.SEMICN) {
            if (!(Exp.isFirstExp(token))) {
                //error!!!
                return token;
            }
            Cond cond = new Cond();
            token = cond.parser(token);
            nodes.add(cond);
            if(token == null){
                //error!!!
                return null;
            }
        }
        if(token.getTokenType() != TokenType.SEMICN){
            //error!!!
            return token;
        }
        nodes.add(token);
        token = getAToken();
        if(token == null){
            //error!!!
            return null;
        }
        if(token.getTokenType() !=TokenType.RPARENT){
            if(token.getTokenType()!=TokenType.IDENFR){
                //error!!!
                return token;
            }
            ForStmt forStmt = new ForStmt();
            token = forStmt.parser(token);
            nodes.add(forStmt);
            if(token == null){
                //error!!!
                return null;
            }
        }
        if(token.getTokenType() != TokenType.RPARENT){
            //error!!!
            return token;
        }
        nodes.add(token);
        Token token1 = getAToken();
        if(token1 == null){
            //error!!!
            return null;
        }
        if(Stmt.isStmtFirst(token1)){
            Node node= Stmt.parserStmt(token1);
            Token token3 = node.parser(token1);
            nodes.add(node);
            return token3;
        }
        //error!!!
        return token1;
    }
    public void printToFile(){
        for(int i=0;i<nodes.size();i++){
            nodes.get(i).printToFile();
        }
        WriteIntoF.getInstance().writeToFile(true, "" + "<Stmt>" + "\n");
    }
    public void reportErrori(int lineno){
        WriteIntoF.getInstance().writeToFile(false,ErrorType.i+" "+lineno+"\n");
    }
    public Token getAToken(){
        return GiveTokener.getInstance().getAToken();
    }

    public void putBackAToken(Token token){
        GiveTokener.getInstance().putBackAToken(token);
    }
}
