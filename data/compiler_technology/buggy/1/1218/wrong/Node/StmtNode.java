package Node;

import java.util.ArrayList;
import Token.*;
import frontend.Parser;

public class StmtNode {
    /* Stmt → LVal '=' Exp ';'
    | [Exp] ';'
    | Block
    | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
    | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    | 'break' ';' | 'continue' ';'
    | 'return' [Exp] ';' // 1.有Exp 2.无Exp
    | LVal '=' 'getint''('')'';'
    | LVal '=' 'getchar''('')'';'
    | 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
    */
    private enum StmtType{
        ValAssign,
        Exp,
        Block,
        If,
        For,
        Break,
        Continue,
        Return,
        GetInt,
        GetChar,
        Printf
    }
    private StmtType type;
    private LValNode lValNode;
    private ArrayList<ExpNode> expNodes;
    private ExpNode expNode;
    private BlockNode blockNode;
    private Token ifToken;
    private CondNode condNode;
    private ArrayList<StmtNode> stmtNodes;
    private Token forToken;
    private ForStmtNode forStmtNode_1;
    private ForStmtNode forStmtNode_3;
    private Token breakToken;
    private Token continueToken;
    private Token returnToken;
    private Token getIntToken;
    private Token getCharToken;
    private Token printfToken;
    private Token stringConstToken;

    Token eqToken;
    Token semicnToken;
    Token leftParent;
    Token rightParent;
    Token elseToken;
    ArrayList<Token> semicns;
    ArrayList<Token> commas;
    public StmtNode(LValNode lValNode, ExpNode expNode, Token eqToken, Token semicnToken){
        //LVal '=' Exp ';'
        type = StmtType.ValAssign;
        this.lValNode = lValNode;
        this.expNode = expNode;
        this.eqToken = eqToken;
        this.semicnToken = semicnToken;
    }

    public StmtNode(ExpNode expNode, Token semicnToken){
        // [Exp] ';'
        type = StmtType.Exp;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    public StmtNode(BlockNode blockNode){
        //Block
        type = StmtType.Block;
        this.blockNode = blockNode;
    }

    public StmtNode(Token ifToken, CondNode condNode, ArrayList<StmtNode> stmtNodes, Token leftParent, Token rightParent, Token elseToken){
        // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        type = StmtType.If;
        this.ifToken = ifToken;
        this.leftParent = leftParent;
        this.condNode = condNode;
        this.rightParent = rightParent;
        this.stmtNodes = stmtNodes;
        this.elseToken = elseToken;
    }

    public StmtNode(Token forToken, ForStmtNode forStmtNode_1, ForStmtNode forStmtNode_3, CondNode condNode, ArrayList<StmtNode> stmtNodes, Token leftParent, Token rightParent, ArrayList<Token> semicns){
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        type = StmtType.For;
        this.forToken = forToken;
        this.leftParent = leftParent;
        this.forStmtNode_1 = forStmtNode_1;
        this.forStmtNode_3 = forStmtNode_3;
        this.condNode = condNode;
        this.semicns = semicns;
        this.rightParent = rightParent;
        this.stmtNodes = stmtNodes;

    }

    public StmtNode(Token BOrCToken, Token semicnToken){
        // 'break' ';' | 'continue' ';'
        if(BOrCToken.getType() == TokenType.BREAKTK){
            type = StmtType.Break;
            this.breakToken = BOrCToken;
            this.semicnToken = semicnToken;
        }
        else if(BOrCToken.getType() == TokenType.CONTINUETK){
            type = StmtType.Continue;
            this.continueToken = BOrCToken;
            this.semicnToken = semicnToken;
        }
    }

    public StmtNode(Token returnToken, ExpNode expNode, Token semicnToken){
        //'return' [Exp] ';' // 1.有Exp 2.无Exp
        type = StmtType.Return;
        this.returnToken = returnToken;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    public StmtNode(Token getToken, LValNode lValNode, Token eqToken, Token leftParent, Token rightParent, Token semicnToken){
        // LVal '=' 'getint''('')'';' | LVal '=' 'getchar''('')'';'
        if(getToken.getType() == TokenType.GETINTTK){
            type = StmtType.GetInt;
            this.lValNode = lValNode;
            this.eqToken = eqToken;
            this.getIntToken = getToken;
            this.leftParent = leftParent;
            this.rightParent = rightParent;
            this.semicnToken = semicnToken;
        }
        else if(getToken.getType() == TokenType.GETCHARTK){
            type = StmtType.GetChar;
            this.lValNode = lValNode;
            this.eqToken = eqToken;
            this.getCharToken = getToken;
            this.leftParent = leftParent;
            this.rightParent = rightParent;
            this.semicnToken = semicnToken;
        }
    }

    public StmtNode(Token printfToken, Token stringConstToken, ArrayList<ExpNode> expNodes, Token leftParent, Token rightParent, ArrayList<Token> commas, Token semicnToken){
        //'printf''('StringConst {','Exp}')'';'
        type = StmtType.Printf;
        this.printfToken = printfToken;
        this.leftParent = leftParent;
        this.stringConstToken = stringConstToken;
        this.commas = commas;
        this.expNodes = expNodes;
        this.rightParent = rightParent;
        this.semicnToken = semicnToken;
    }

    public void print(){
        switch (type){
            case ValAssign:
                //LVal '=' Exp ';'
                lValNode.print();
                Parser.getInstance().output(eqToken);
                expNode.print();
                Parser.getInstance().output(semicnToken);
                break;
            case Exp:
                //[Exp] ';'
                if(expNode != null){
                    expNode.print();
                }
                Parser.getInstance().output(semicnToken);
                break;
            case Block:
                //Block
                blockNode.print();
                break;
            case If:
                //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                Parser.getInstance().output(ifToken);
                Parser.getInstance().output(leftParent);
                condNode.print();
                Parser.getInstance().output(rightParent);
                stmtNodes.get(0).print();
                if(elseToken != null){
                    Parser.getInstance().output(elseToken);
                    stmtNodes.get(1).print();
                }
                break;
            case For:
                //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                Parser.getInstance().output(forToken);
                Parser.getInstance().output(leftParent);
                if(forStmtNode_1 != null){
                    forStmtNode_1.print();
                }
                Parser.getInstance().output(semicns.get(0));
                if(condNode != null){
                    condNode.print();
                }
                Parser.getInstance().output(semicns.get(1));
                if(forStmtNode_3 != null){
                    forStmtNode_3.print();
                }
                Parser.getInstance().output(rightParent);
                stmtNodes.get(0).print();
                break;
            case Break:
                //'break' ';'
                Parser.getInstance().output(breakToken);
                Parser.getInstance().output(semicnToken);
                break;
            case Continue:
                // 'continue' ';'
                Parser.getInstance().output(continueToken);
                Parser.getInstance().output(semicnToken);
                break;
            case Return:
                //'return' [Exp] ';'
                Parser.getInstance().output(returnToken);
                if(expNode != null){
                    expNode.print();
                }
                Parser.getInstance().output(semicnToken);
                break;
            case GetInt:
                //LVal '=' 'getint''('')'';'
                lValNode.print();
                Parser.getInstance().output(eqToken);
                Parser.getInstance().output(getIntToken);
                Parser.getInstance().output(leftParent);
                Parser.getInstance().output(rightParent);
                Parser.getInstance().output(semicnToken);
                break;
            case GetChar:
                //LVal '=' 'getchar''('')'';'
                lValNode.print();
                Parser.getInstance().output(eqToken);
                Parser.getInstance().output(getCharToken);
                Parser.getInstance().output(leftParent);
                Parser.getInstance().output(rightParent);
                Parser.getInstance().output(semicnToken);
                break;
            case Printf:
                //'printf''('StringConst {','Exp}')'';'
                Parser.getInstance().output(printfToken);
                Parser.getInstance().output(leftParent);
                Parser.getInstance().output(stringConstToken);
                for(int i = 0; i < commas.size(); i++){
                    Parser.getInstance().output(commas.get(0));
                    expNodes.get(i).print();
                }
                Parser.getInstance().output(rightParent);
                Parser.getInstance().output(semicnToken);
                break;
            default:
                break;
        }
        Parser.getInstance().output(NodeType.Stmt);
    }

}
