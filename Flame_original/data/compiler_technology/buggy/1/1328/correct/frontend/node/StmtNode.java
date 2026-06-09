package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;

public class StmtNode {
    // 语句 Stmt -> LVal '=' Exp ';'
    //	| [Exp] ';'
    //	| Block
    //	| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    //	| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //	| 'break' ';' | 'continue' ';'
    //	| 'return' [Exp] ';'
    //	| LVal '=' 'getint' '(' ')' ';'
    //  | LVal '=' 'getchar''('')'';'
    //	| 'printf' '(' StringConst { ',' Exp } ')' ';'

    private StmtType type;
    private LValNode lValNode;
    private Token assignToken;
    private ExpNode expNode;
    private Token semicnToken;
    private BlockNode blockNode;
    private Token ifToken;
    private Token lparentToken;
    private CondNode condNode;
    private Token rparentToken;
    private ArrayList<StmtNode> stmtNodes;
    private Token elseToken;
    private Token forToken;
    private ForStmtNode forStmtNode1;
    private ForStmtNode forStmtNode2;
    private StmtNode stmtNode;
    private Token breakOrContinueToken;
    private Token returnToken;
    private Token getIntOrCharToken;
    private Token printfToken;
    private Token stringConstToken;
    private Token commaToken;
    private ArrayList<ExpNode> expNodes;

    public StmtNode(StmtType type, LValNode lValNode, Token assignToken, ExpNode expNode, Token semicnToken) {
        // LVal '=' Exp ';'
        this.type = type;
        this.lValNode = lValNode;
        this.assignToken = assignToken;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    public StmtNode(StmtType type, ExpNode expNode, Token semicnToken) {
        // [Exp] ';'
        this.type = type;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    public StmtNode(StmtType type, BlockNode blockNode) {
        // Block
        this.type = type;
        this.blockNode = blockNode;
    }

    public StmtNode(StmtType type, Token ifToken, Token lparentToken, CondNode condNode, Token rparentToken, ArrayList<StmtNode> stmtNodes, Token elseToken) {
        // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        this.type = type;
        this.ifToken = ifToken;
        this.lparentToken = lparentToken;
        this.condNode = condNode;
        this.rparentToken = rparentToken;
        this.stmtNodes = stmtNodes;
        this.elseToken = elseToken;
    }

    public StmtNode(StmtType type, Token forToken, Token lparentToken, ForStmtNode forStmtNode1, Token semicnToken, CondNode condNode, ForStmtNode forStmtNode2, Token rparentToken, StmtNode stmtNode) {
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        this.type = type;
        this.forToken = forToken;
        this.lparentToken = lparentToken;
        this.forStmtNode1 = forStmtNode1;
        this.semicnToken = semicnToken;
        this.condNode = condNode;
        this.forStmtNode2 = forStmtNode2;
        this.rparentToken = rparentToken;
        this.stmtNode = stmtNode;
    }

    public StmtNode(StmtType type, Token breakOrContinueToken, Token semicnToken) {
        // 'break' ';' | 'continue' ';'
        this.type = type;
        this.breakOrContinueToken = breakOrContinueToken;
        this.semicnToken = semicnToken;
    }

    public StmtNode(StmtType type, Token returnToken, ExpNode expNode, Token semicnToken) {
        // 'return' [Exp] ';'
        this.type = type;
        this.returnToken = returnToken;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    public StmtNode(StmtType type, LValNode lValNode, Token assignToken, Token getIntOrCharToken, Token lparentToken, Token rparentToken, Token semicnToken) {
        // LVal '=' 'getint' '(' ')' ';'
        // LVal '=' 'getchar' '(' ')' ';'
        this.type = type;
        this.lValNode = lValNode;
        this.assignToken = assignToken;
        this.getIntOrCharToken = getIntOrCharToken;
        this.lparentToken = lparentToken;
        this.rparentToken = rparentToken;
        this.semicnToken = semicnToken;
    }

    public StmtNode(StmtType type, Token printfToken, Token lparentToken, Token stringConstToken, Token commaToken, ArrayList<ExpNode> expNodes, Token rparentToken, Token semicnToken) {
        // 'printf' '(' stringConst { ',' Exp } ')' ';'
        this.type = type;
        this.printfToken = printfToken;
        this.lparentToken = lparentToken;
        this.stringConstToken = stringConstToken;
        this.commaToken = commaToken;
        this.expNodes = expNodes;
        this.rparentToken = rparentToken;
        this.semicnToken = semicnToken;
    }

    public StmtType getType() {
        return type;
    }

    public LValNode getLValNode() {
        return lValNode;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public BlockNode getBlockNode() {
        return blockNode;
    }

    public CondNode getCondNode() {
        return condNode;
    }

    public ArrayList<StmtNode> getStmtNodes() {
        return stmtNodes;
    }

    public Token getstringConstToken() {
        return stringConstToken;
    }

    public ArrayList<ExpNode> getExpNodes() {
        return expNodes;
    }

    public void print() {
        switch (type) {
            case LValAssignExp:
                // LVal '=' Exp ';'
                lValNode.print();
                MyIO.writeToken(assignToken.toString());
                expNode.print();
                MyIO.writeToken(semicnToken.toString());
                break;
            case Exp:
                // [Exp] ';'
                if (expNode != null) expNode.print();
                MyIO.writeToken(semicnToken.toString());
                break;
            case Block:
                // Block
                blockNode.print();
                break;
            case If:
                // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                MyIO.writeToken(ifToken.toString());
                MyIO.writeToken(lparentToken.toString());
                condNode.print();
                MyIO.writeToken(rparentToken.toString());
                stmtNodes.get(0).print();
                if (elseToken != null) {
                    MyIO.writeToken(elseToken.toString());
                    stmtNodes.get(1).print();
                }
                break;
            case For:
                // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                MyIO.writeToken(forToken.toString());
                MyIO.writeToken(lparentToken.toString());
                if(forStmtNode1 != null) forStmtNode1.print();
                MyIO.writeToken(semicnToken.toString());
                if(condNode != null) condNode.print();
                MyIO.writeToken(semicnToken.toString());
                if(forStmtNode2 != null) forStmtNode2.print();
                MyIO.writeToken(rparentToken.toString());
                stmtNode.print();
                break;
            case Break:
                // 'break' ';'
            case Continue:
                // 'continue' ';'
                MyIO.writeToken(breakOrContinueToken.toString());
                MyIO.writeToken(semicnToken.toString());
                break;
            case Return:
                // 'return' [Exp] ';'
                MyIO.writeToken(returnToken.toString());
                if (expNode != null) {
                    expNode.print();
                }
                MyIO.writeToken(semicnToken.toString());
                break;
            case LValAssignGetint:
                // LVal '=' 'getint' '(' ')' ';'
            case LValAssignGetchar:
                // LVal '=' 'getchar' '(' ')' ';'
                lValNode.print();
                MyIO.writeToken(assignToken.toString());
                MyIO.writeToken(getIntOrCharToken.toString());
                MyIO.writeToken(lparentToken.toString());
                MyIO.writeToken(rparentToken.toString());
                MyIO.writeToken(semicnToken.toString());
                break;
            case Printf:
                // 'printf' '(' stringConstToken { ',' Exp } ')' ';'
                MyIO.writeToken(printfToken.toString());
                MyIO.writeToken(lparentToken.toString());
                MyIO.writeToken(stringConstToken.toString());
                for (ExpNode node : expNodes) {
                    MyIO.writeToken(commaToken.toString());
                    node.print();
                }
                MyIO.writeToken(rparentToken.toString());
                MyIO.writeToken(semicnToken.toString());
                break;
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.Stmt));
    }
}
