package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class StmtNode {
    /**
语句 Stmt → LVal '=' Exp ';' // i
| [Exp] ';' // i
| Block
| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
| 'break' ';' | 'continue' ';' // i
| 'return' [Exp] ';' // i
| LVal '=' 'getint''('')'';' // i j
| LVal '=' 'getchar''('')'';' // i j
| 'printf''('StringConst {','Exp}')'';' // i j
    **/
    public enum StmtType {
        LvalAssignExp,Exp,Block,If,For,BreakOrContinue,Return,LvalAssignGetIntOrChar,Printf
    }

    private StmtType type;
    private LValNode lValNode;
    private Token assignToken;

    private ExpNode expNode;
    private Token semicnToken;

    private BlockNode blockNode;
    // if
    private Token ifToken;
    private Token leftParentToken;
    private CondNode condNode;
    private Token rightParentToken;
    private ArrayList<StmtNode> stmtNodes;
    private Token elseToken;
    // for
    private Token forToken;
    private ForStmtNode forStmt1;
    private ForStmtNode forStmt2;
    private Token forSemicn1;
    private Token forSemicn2;
    private StmtNode stmtNode;

    private Token breakOrContinueToken;

    private Token returnToken;

    private Token getIntOrCharToken;
    private Token printfToken;
    private Token stringConst;
    private ArrayList<Token> commas;
    private ArrayList<ExpNode> expNodes;

    // LVal '=' Exp ';'
    public StmtNode(StmtType type, LValNode lValNode, Token assignToken, ExpNode expNode, Token semicnToken) {
        this.type = type;
        this.lValNode = lValNode;
        this.assignToken = assignToken;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    // [Exp] ';'
    public StmtNode(StmtType type, ExpNode expNode, Token semicnToken) {
        this.type = type;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    // Block
    public StmtNode(StmtType type, BlockNode blockNode) {
        this.type = type;
        this.blockNode = blockNode;
    }

    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    public StmtNode(StmtType type, Token ifToken, Token leftParentToken,
                    CondNode condNode, Token rightParentToken, ArrayList<StmtNode> stmtNodes, Token elseToken) {
        this.type = type;
        this.ifToken = ifToken;
        this.leftParentToken = leftParentToken;
        this.condNode = condNode;
        this.rightParentToken = rightParentToken;
        this.stmtNodes = stmtNodes;
        this.elseToken = elseToken;
    }

    //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    public StmtNode(StmtType type, Token forToken, Token leftParentToken,ForStmtNode forStmt1,Token forSemicn1,
                    CondNode condNode,ForStmtNode forStmt2,Token forSemicn2,Token rightParentToken,StmtNode stmtNode) {
        this.type = type;
        this.forToken = forToken;
        this.leftParentToken = leftParentToken;
        this.forStmt1 = forStmt1;
        this.forSemicn1 = forSemicn1;
        this.condNode = condNode;
        this.forStmt2 = forStmt2;
        this.forSemicn2 = forSemicn2;
        this.rightParentToken = rightParentToken;
        this.stmtNode = stmtNode;
    }

    // 'break' ';'| 'continue' ';'
    public StmtNode(StmtType type, Token breakOrContinueToken, Token semicnToken) {
        this.type = type;
        this.breakOrContinueToken = breakOrContinueToken;
        this.semicnToken = semicnToken;
    }

    // 'return' [Exp] ';'
    public StmtNode(StmtType type, Token returnToken, ExpNode expNode, Token semicnToken) {
        this.type = type;
        this.returnToken = returnToken;
        this.expNode = expNode;
        this.semicnToken = semicnToken;
    }

    // LVal '=' 'getint' '(' ')' ';'| | LVal '=' 'getchar''('')'';'
    public StmtNode(StmtType type, LValNode lValNode, Token assignToken, Token getIntOrCharToken,
                    Token leftParentToken, Token rightParentToken, Token semicnToken) {
        this.type = type;
        this.lValNode = lValNode;
        this.assignToken = assignToken;
        this.getIntOrCharToken = getIntOrCharToken;
        this.leftParentToken = leftParentToken;
        this.rightParentToken = rightParentToken;
        this.semicnToken = semicnToken;
    }

    // 'printf' '(' FormatString { ',' Exp } ')' ';'
    public StmtNode(StmtType type, Token printfToken, Token leftParentToken, Token stringConst,
                    ArrayList<Token> commas, ArrayList<ExpNode> expNodes, Token rightParentToken, Token semicnToken) {
        this.type = type;
        this.printfToken = printfToken;
        this.leftParentToken = leftParentToken;
        this.stringConst = stringConst;
        this.commas = commas;
        this.expNodes = expNodes;
        this.rightParentToken = rightParentToken;
        this.semicnToken = semicnToken;
    }

    public void print() {
        switch (type) {
            case LvalAssignExp:
                lValNode.print();
                IO.ParserOutput(assignToken);
                expNode.print();
                IO.ParserOutput(semicnToken);
                break;
            case Exp:
                if (expNode != null) {
                    expNode.print();
                }
                IO.ParserOutput(semicnToken);
                break;
            case Block:
                blockNode.print();
                break;
            case If:
                IO.ParserOutput(ifToken);
                IO.ParserOutput(leftParentToken);
                condNode.print();
                IO.ParserOutput(rightParentToken);
                stmtNodes.get(0).print();
                if (elseToken != null) {
                    IO.ParserOutput(elseToken);
                    stmtNodes.get(1).print();
                }
                break;
            case For:
                IO.ParserOutput(forToken);
                IO.ParserOutput(leftParentToken);
                if (forStmt1 != null) {
                    forStmt1.print();
                }
                IO.ParserOutput(forSemicn1);
                if (condNode != null) {
                    condNode.print();
                }
                IO.ParserOutput(forSemicn2);
                if (forStmt2 != null) {
                    forStmt2.print();
                }
                IO.ParserOutput(rightParentToken);
                stmtNode.print();
                break;
            case BreakOrContinue:
                IO.ParserOutput(breakOrContinueToken);
                IO.ParserOutput(semicnToken);
                break;
            case Return:
                IO.ParserOutput(returnToken);
                if (expNode != null) {
                    expNode.print();
                }
                IO.ParserOutput(semicnToken);
                break;
            case LvalAssignGetIntOrChar:
                lValNode.print();
                IO.ParserOutput(assignToken);
                IO.ParserOutput(getIntOrCharToken);
                IO.ParserOutput(leftParentToken);
                IO.ParserOutput(rightParentToken);
                IO.ParserOutput(semicnToken);
                break;
            case Printf:
                IO.ParserOutput(printfToken);
                IO.ParserOutput(leftParentToken);
                IO.ParserOutput(stringConst);
                for (int i = 0; i < commas.size(); i++) {
                    IO.ParserOutput(commas.get(i));
                    expNodes.get(i).print();
                }
                IO.ParserOutput(rightParentToken);
                IO.ParserOutput(semicnToken);
                break;
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.Stmt));
    }
}
