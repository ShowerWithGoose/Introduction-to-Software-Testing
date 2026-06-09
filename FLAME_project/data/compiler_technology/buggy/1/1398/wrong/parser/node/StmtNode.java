package parser.node;

import lexer.Token;
import parser.NodeType;

import java.util.ArrayList;

public class StmtNode {
    int choose;
    /*
    choose 1 : LVal '=' Exp ';'
    choose 2 : LVal '=' 'getint''('')'';'
    choose 3 : LVal '=' 'getchar''('')'';'
    choose 4 :  [Exp] ';'
    choose 5 : Block
    choose 6 : 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    choose 7 : 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    choose 8 : 'break' ';'
    choose 9 : 'continue' ';'
    choose 10 :  'return' [Exp] ';'
    choose 11 :  'printf''('StringConst {','Exp}')'';'
     */
    LValNode lValNode;
    Token assignTK;
    ArrayList<ExpNode> expNodes;
    ArrayList<Token> commas;
    Token semicnTK;
    Token lParentTK, rParentTK;
    CondNode condNode;
    ForStmtNode forStmtNode1, forStmtNode2;
    StmtNode stmtNode1, stmtNode2;
    BlockNode blockNode;
    Token ifTK, elseTK, forTK, breakOrContinueTK, returnTK, printTK, getintOrgetcharTK;
    Token stringTK;


    public StmtNode(int choose, LValNode lValNode, Token assignTK, ArrayList<ExpNode> expNodes, Token semicnTK) {
        this.choose = choose;
        this.lValNode = lValNode;
        this.assignTK = assignTK;
        this.expNodes = expNodes;
        this.semicnTK = semicnTK;
    }

    public StmtNode(int choose, ArrayList<ExpNode> expNodes, Token semicnTK) {
        this.choose = choose;
        this.expNodes = expNodes;
        this.semicnTK = semicnTK;
    }

    public StmtNode(int choose, BlockNode blockNode) {
        this.choose = choose;
        this.blockNode = blockNode;
    }

    public StmtNode(int choose, Token ifTK, Token lParentTK, Token rParentTK, CondNode condNode, StmtNode stmtNode1,
                    StmtNode stmtNode2, Token elseTK) {
        this.choose = choose;
        this.lParentTK = lParentTK;
        this.rParentTK = rParentTK;
        this.condNode = condNode;
        this.stmtNode1 = stmtNode1;
        this.stmtNode2 = stmtNode2;
        this.ifTK = ifTK;
        this.elseTK = elseTK;
    }

    public StmtNode(int choose, Token forTK, Token semicnTK, Token lParentTK, Token rParentTK, CondNode condNode,
                    ForStmtNode forStmtNode1, ForStmtNode forStmtNode2, StmtNode stmtNode1) {
        this.choose = choose;
        this.semicnTK = semicnTK;
        this.lParentTK = lParentTK;
        this.rParentTK = rParentTK;
        this.condNode = condNode;
        this.forStmtNode1 = forStmtNode1;
        this.forStmtNode2 = forStmtNode2;
        this.stmtNode1 = stmtNode1;
        this.forTK = forTK;
    }

    public StmtNode(int choose, Token breakOrContinueTK, Token semicnTK) {
        this.choose = choose;
        this.semicnTK = semicnTK;
        this.breakOrContinueTK = breakOrContinueTK;
    }

    public StmtNode(int choose, Token returnTK, ArrayList<ExpNode> expNodes, Token semicnTK) {
        this.choose = choose;
        this.expNodes = expNodes;
        this.semicnTK = semicnTK;
        this.returnTK = returnTK;
    }

    public StmtNode(int choose, LValNode lValNode, Token assignTK, Token getintOrgetcharTK, Token lParentTK, Token rParentTK, Token semicnTK) {
        this.choose = choose;
        this.lValNode = lValNode;
        this.assignTK = assignTK;
        this.semicnTK = semicnTK;
        this.lParentTK = lParentTK;
        this.rParentTK = rParentTK;
        this.getintOrgetcharTK = getintOrgetcharTK;
    }

    public StmtNode(int choose, Token printTK, Token lParentTK, Token stringTK, ArrayList<Token> commas, ArrayList<ExpNode> expNodes,
                    Token rParentTK, Token semicnTK) {
        this.choose = choose;
        this.expNodes = expNodes;
        this.commas = commas;
        this.semicnTK = semicnTK;
        this.lParentTK = lParentTK;
        this.rParentTK = rParentTK;
        this.printTK = printTK;
        this.stringTK = stringTK;
    }
    /*
        choose 1 : LVal '=' Exp ';'
        choose 2 : LVal '=' 'getint''('')'';'
        choose 3 : LVal '=' 'getchar''('')'';'
        choose 4 :  [Exp] ';'
        choose 5 : Block
        choose 6 : 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        choose 7 : 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        choose 8 : 'break' ';'
        choose 9 : 'continue' ';'
        choose 10 :  'return' [Exp] ';'
        choose 11 :  'printf''('StringConst {','Exp}')'';'
         */
    public void print() {
        switch (choose)
        {
            case 1:
            {
                lValNode.print();
                assignTK.print();
                expNodes.get(0).print();
                semicnTK.print();
                break;
            }
            case 2, 3:
            {
                lValNode.print();
                assignTK.print();
                getintOrgetcharTK.print();
                lParentTK.print();
                rParentTK.print();
                semicnTK.print();
                break;
            }
            case 4:
            {
                if (!expNodes.isEmpty())
                {
                    expNodes.get(0).print();
                    semicnTK.print();
                }
                break;
            }
            case 5:
            {
                blockNode.print();
                break;
            }
            case 6:
            {
                ifTK.print();
                lParentTK.print();
                condNode.print();
                rParentTK.print();
                stmtNode1.print();
                if (elseTK != null)
                {
                    elseTK.print();
                    stmtNode2.print();
                }
                break;
            }
            case 7:
            {
                forTK.print();
                lParentTK.print();
                if (forStmtNode1 != null)
                {
                    forStmtNode1.print();
                }
                semicnTK.print();
                if (condNode != null)
                {
                    condNode.print();
                }
                semicnTK.print();
                if (forStmtNode2 != null)
                {
                    forStmtNode2.print();
                }
                rParentTK.print();
                stmtNode1.print();
                break;
            }
            case 8, 9:
            {
                breakOrContinueTK.print();
                semicnTK.print();
                break;
            }
            case 10:
            {
                returnTK.print();
                if (!expNodes.isEmpty())
                {
                    expNodes.get(0).print();
                }
                semicnTK.print();
                break;
            }
            case 11:
            {
                printTK.print();
                lParentTK.print();
                stringTK.print();
                for (int i = 0; i < commas.size(); i++)
                {
                    commas.get(i).print();
                    expNodes.get(i).print();
                }
                rParentTK.print();
                semicnTK.print();
                break;
            }
            default:
                System.out.println("error in stmt");
        }
        System.out.println(NodeType.Stmt);
    }
}
