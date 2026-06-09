package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;

public class StmtNode {
    // Stmt -> LVal '=' Exp ';'
    //	| [Exp] ';'
    //	| Block
    //	| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    //  | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //	| 'break' ';' | 'continue' ';'
    //	| 'return' [Exp] ';'
    //	| LVal '=' 'getint' '(' ')'';'
    //  | LVal '=' 'getchar' '(' ')'';'
    //	| 'printf''('StringConst {','Exp}')'';'
    public enum StmtType {
        LValExp, Exp, Block, If, For, Break, Continue, Return, GetInt, GetChar,Printf
    }

    private StmtType type;
    private LValNode lValNode;
    private Token assignToken;
    private ExpNode expNode;
    private Token semicnToken;
    private BlockNode blockNode;
    private Token ifToken;
    private Token leftParentToken;
    private CondNode condNode;
    private Token rightParentToken;
    private StmtNode ifStmtNode;
    private StmtNode elseStmtNode;
    private Token elseToken;
    private Token forToken;
    private ForStmtNode forStmtNode1;
    private ForStmtNode forStmtNode2;
    private Token semicnToken1;
    private Token semicnToken2;
    private StmtNode stmtNode;
    private Token breakToken;
    private Token continueToken;
    private Token returnToken;
    private Token getintToken;
    private Token getcharToken;
    private Token printfToken;
    private Token stringConst;
    private ArrayList<Token> commas;
    private ArrayList<ExpNode> expNodes;

    public StmtNode() {
    }
    // Stmt -> LVal '=' Exp ';'
    //	| [Exp] ';'
    //	| Block
    //	| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    //  | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //	| 'break' ';' | 'continue' ';'
    //	| 'return' [Exp] ';'
    //	| LVal '=' 'getint' '(' ')'';'
    //  | LVal '=' 'getchar' '(' ')'';'
    //	| 'printf''('StringConst {','Exp}')'';'
    public void print() throws IOException {
        switch (type){
            case Continue:
                continueToken.print();
                semicnToken.print();
                break;
            case LValExp:
                lValNode.print();
                assignToken.print();
                expNode.print();
                semicnToken.print();
                break;
            case GetChar:
                lValNode.print();
                assignToken.print();
                getcharToken.print();
                leftParentToken.print();
                rightParentToken.print();
                semicnToken.print();
                break;
            case Return:
                returnToken.print();
                if (expNode!=null) {
                    expNode.print();
                }
                semicnToken.print();
                break;
            case Printf:
                printfToken.print();
                leftParentToken.print();
                stringConst.print();
                if (!expNodes.isEmpty()) {
                    for (int i=0;i<expNodes.size();i+=1) {
                        commas.get(i).print();
                        expNodes.get(i).print();
                    }
                }
                rightParentToken.print();
                semicnToken.print();
                break;
            case GetInt:
                lValNode.print();
                assignToken.print();
                getintToken.print();
                leftParentToken.print();
                rightParentToken.print();
                semicnToken.print();
                break;
            case Break:
                breakToken.print();
                semicnToken.print();
                break;
            case Block:
                blockNode.print();
                break;
            case If:
                ifToken.print();
                leftParentToken.print();
                condNode.print();
                rightParentToken.print();
                ifStmtNode.print();
                if (elseToken!=null) {
                    elseToken.print();
                    elseStmtNode.print();
                }
                break;
            case Exp:
                if (expNode!=null) {
                    expNode.print();
                }
                semicnToken.print();
                break;
            case For:
                forToken.print();
                leftParentToken.print();
                if (forStmtNode1!=null) {
                    forStmtNode1.print();
                }
                semicnToken1.print();
                if (condNode!=null) {
                    condNode.print();
                }
                semicnToken2.print();
                if (forStmtNode2!=null) {
                    forStmtNode2.print();
                }
                rightParentToken.print();
                stmtNode.print();
                break;
        }
        Io.Text.printWord("<Stmt>");
    }
    
    public void setType(StmtType type) {
        this.type = type;
    }
    
    
    public void setAssignToken(Token assignToken) {
        this.assignToken = assignToken;
    }
    
    public void setBlockNode(BlockNode blockNode) {
        this.blockNode = blockNode;
    }
    
    public void setBreakToken(Token breakToken) {
        this.breakToken = breakToken;
    }
    
    public void setCommas(ArrayList<Token> commas) {
        this.commas = commas;
    }
    
    public void setCondNode(CondNode condNode) {
        this.condNode = condNode;
    }
    
    public void setContinueToken(Token continueToken) {
        this.continueToken = continueToken;
    }
    
    public void setElseToken(Token elseToken) {
        this.elseToken = elseToken;
    }
    
    public void setExpNode(ExpNode expNode) {
        this.expNode = expNode;
    }
    
    public void setExpNodes(ArrayList<ExpNode> expNodes) {
        this.expNodes = expNodes;
    }
    
    public void setForStmtNode1(ForStmtNode forStmtNode1) {
        this.forStmtNode1 = forStmtNode1;
    }
    
    public void setForStmtNode2(ForStmtNode forStmtNode2) {
        this.forStmtNode2 = forStmtNode2;
    }
    
    public void setForToken(Token forToken) {
        this.forToken = forToken;
    }
    
    public void setGetcharToken(Token getcharToken) {
        this.getcharToken = getcharToken;
    }
    
    public void setGetintToken(Token getintToken) {
        this.getintToken = getintToken;
    }
    
    public void setIfToken(Token ifToken) {
        this.ifToken = ifToken;
    }
    
    public void setLeftParentToken(Token leftParentToken) {
        this.leftParentToken = leftParentToken;
    }
    
    public void setlValNode(LValNode lValNode) {
        this.lValNode = lValNode;
    }
    
    public void setPrintfToken(Token printfToken) {
        this.printfToken = printfToken;
    }
    
    public void setReturnToken(Token returnToken) {
        this.returnToken = returnToken;
    }
    
    public void setRightParentToken(Token rightParentToken) {
        this.rightParentToken = rightParentToken;
    }
    
    public void setStmtNode(StmtNode stmtNode) {
        this.stmtNode = stmtNode;
    }
    
    public void setIfStmtNode(StmtNode stmtNode) {
        this.ifStmtNode = stmtNode;
    }
    
    public void setElseStmtNode(StmtNode stmtNode) {
        this.elseStmtNode = stmtNode;
    }
    
    public void setSemicnToken(Token semicnToken) {
        this.semicnToken = semicnToken;
    }
    
    public void setSemicnToken1(Token semicnToken1) {
        this.semicnToken1 = semicnToken1;
    }
    
    public void setSemicnToken2(Token semicnToken2) {
        this.semicnToken2 = semicnToken2;
    }
    
    public void setStringConst(Token stringConst) {
        this.stringConst = stringConst;
    }
    
    
}
