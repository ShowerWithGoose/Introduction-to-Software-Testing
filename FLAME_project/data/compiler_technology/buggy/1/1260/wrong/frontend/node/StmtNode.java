package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class StmtNode {
    public enum StmtCategory{
        LVal, Block, IF, FOR, BREAK, RETURN, PRINTF, CONTINUE, GETINT, GETCHAR, EXP
    }

    private BlockNode blockNode;
    StmtCategory category;
    public StmtNode(BlockNode blockNode, StmtCategory category){
        this.blockNode = blockNode;
        this.category = category;
    }
    
    private Token ifToken;
    private Token leftParentToken;
    private CondNode condNode;
    private Token rightParentToken;
    private StmtNode stmtNode;
    private Token elseToken;
    private StmtNode stmtNode1;
    public StmtNode(Token ifToken, Token lParent, CondNode condNode, Token rParent, StmtNode stmtNode, Token elseToken, StmtNode stmtNode1, StmtCategory category){
        this.ifToken = ifToken;
        this.leftParentToken = lParent;
        this.condNode = condNode;
        this.rightParentToken = rParent;
        this.stmtNode = stmtNode;
        this.elseToken = elseToken;
        this.stmtNode1 = stmtNode1;
        this.category = category;
    }
    
    private Token forToken;
    private ForStmtNode forStmtNode;
    private Token semicnToken;
    private Token semicn2;
    private ForStmtNode forStmtNode2;
    public StmtNode(Token forToken, Token lParent, ForStmtNode forStmtNode, Token semicn, CondNode condNode, Token semicn2, ForStmtNode forStmtNode2, Token rParent, StmtNode stmtNode, StmtCategory category){
        this.forToken = forToken;
        this.leftParentToken = lParent;
        this.forStmtNode = forStmtNode;
        this.semicnToken = semicn;
        this.condNode = condNode;
        this.semicn2 = semicn2;
        this.forStmtNode2 = forStmtNode2;
        this.rightParentToken = rParent;
        this.stmtNode = stmtNode;
        this.category = category;
    }
    
    private Token breakOrContinueToken;
    public StmtNode(Token breakToken, Token semicn, StmtCategory category){
        this.breakOrContinueToken = breakToken;
        this.semicnToken = semicn;
        this.category = category;
    }
    
    private Token returnToken;
    private ExpNode expNode;
    public StmtNode(Token returnToken, ExpNode expNode, Token semicn, StmtCategory category){
        this.returnToken = returnToken;
        this.expNode = expNode;
        this.semicnToken = semicn;
        this.category = category;
    }

    private Token printfToken;
    private Token strToken;
    private List<Token> commas;
    private List<ExpNode> expNodes;
    public StmtNode(Token printfToken, Token lParentToken, Token rToken, Token strConToken, List<Token> commas, List<ExpNode> expNodes, Token semicn, StmtCategory category){
        this.printfToken = printfToken;
        this.leftParentToken = lParentToken;
        this.rightParentToken = rToken;
        this.strToken = strConToken;
        this.commas = commas;
        this.expNodes = expNodes;
        this.semicnToken = semicn;
        this.category = category;
    }
    private LValNode lValNode;
    private Token getintOrCharToken;
    private Token assignToken;
    public StmtNode(LValNode lValNode, Token equalToken, Token getintToken, Token lParent, Token rParent, Token semicn, StmtCategory category){
            this.lValNode = lValNode;
            this.assignToken = equalToken;
            this.getintOrCharToken = getintToken;
            this.leftParentToken = lParent;
            this.rightParentToken = rParent;
            this.semicnToken = semicn;
            this.category = category;
    }
    public StmtNode(LValNode lValNode, Token equalToken, ExpNode expNode, Token semicn, StmtCategory category){
        this.lValNode = lValNode;
        this.assignToken = equalToken;
        this.expNode = expNode;
        this.semicnToken = semicn;
        this.category = category;
    }

    public StmtNode(ExpNode expNode, Token semicn, StmtCategory category){
        this.expNode = expNode;
        this.semicnToken = semicn;
        this.category = category;
    }
    public void print() {
        switch (category) {
            case LVal:
                // LVal '=' Exp ';'
                lValNode.print();
                assignToken.print();
                expNode.print();
                semicnToken.print();
                break;
            case EXP:
                // [Exp] ';'
                if (expNode != null) expNode.print();
                semicnToken.print();
                break;
            case Block:
                // Block
                blockNode.print();
                break;
            case IF:
                // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                ifToken.print();
                leftParentToken.print();
                condNode.print();
                rightParentToken.print();
                stmtNode.print();
                if (elseToken != null) {
                    elseToken.print();
                    stmtNode1.print();
                }
                break;
            case FOR:
                // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                forToken.print();
                leftParentToken.print();
                if(forStmtNode != null){
                    forStmtNode.print();
                }
                semicnToken.print();
                if(condNode != null) condNode.print();
                semicn2.print();
                if(forStmtNode2 != null) forStmtNode2.print();
                rightParentToken.print();
                stmtNode.print();
                break;
            case BREAK:
                // 'break' ';'
                breakOrContinueToken.print();
                semicnToken.print();
                break;
            case CONTINUE:
                // 'continue' ';'
                breakOrContinueToken.print();
                semicnToken.print();
                break;
            case RETURN:
                // 'return' [Exp] ';'
                returnToken.print();
                if (expNode != null) {
                    expNode.print();
                }
                semicnToken.print();
                break;
            case GETINT:
                // LVal '=' 'getint' '(' ')' ';'
                lValNode.print();
                assignToken.print();
                getintOrCharToken.print();
                leftParentToken.print();
                rightParentToken.print();
                semicnToken.print();
                break;
            case GETCHAR:
                // LVal '=' 'getchar' '(' ')' ';'
                lValNode.print();
                assignToken.print();
                getintOrCharToken.print();
                leftParentToken.print();
                rightParentToken.print();
                semicnToken.print();
                break;
            case PRINTF:
                // 'printf''('StringConst {','Exp}')'';' 
                printfToken.print();
                leftParentToken.print();
                strToken.print();
                for (int i = 0; i < commas.size(); i++) {
                    commas.get(i).print();
                    expNodes.get(i).print();
                }
                rightParentToken.print();
                semicnToken.print();
                break;
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<Stmt>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
