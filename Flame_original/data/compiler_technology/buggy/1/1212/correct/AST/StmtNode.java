package AST;
import IO.*;

import java.io.IOException;

//语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
//| [Exp] ';' //有无Exp两种情况
//| Block
//| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
//| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
//ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部
//缺省，1种情况
//| 'break' ';' | 'continue' ';'
//| 'return' [Exp] ';' // 1.有Exp 2.无Exp
//| LVal '=' 'getint''('')'';'
//| LVal '=' 'getchar''('')'';'
//| 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
public class StmtNode extends ASTNode {
    
    ASTNodes type = ASTNodes.Stmt;
    
    LValStmt lValStmt;

    GetIntStmt getint;

    GetCharStmt getCharStmt;

    ExprNode exprNode;

    NullStmt nullStmt;

    IfElseStmtNode ifElseStmtNode;

    IfStmtNode ifStmtNode;

    ForNode forNode;

    BreakStmt breakStmt;

    ContinueStmt continueStmt;

    ReturnStmt returnStmt;

    PrintfStmt printfStmt;

    BlockNode blockNode;
    int t;

    public int getT() {
        return t;
    }

    public StmtNode(LValStmt lValStmt) {
        this.lValStmt = lValStmt;
        this.t = 1;
    }

    public StmtNode(GetIntStmt getint) {
        this.getint = getint;
        this.t = 2;
    }

    public StmtNode(GetCharStmt getchar) {
        this.getCharStmt = getchar;
        this.t = 3;
    }

    public StmtNode(ExprNode exprNode) {
        this.exprNode = exprNode;
        this.t = 4;
    }

    public StmtNode(NullStmt nullStmt) {
        this.nullStmt = nullStmt;
        this.t = 5;
    }

    public StmtNode(IfElseStmtNode ifElseStmtNode) {
        this.ifElseStmtNode = ifElseStmtNode;
        this.t = 6;
    }

    public StmtNode(IfStmtNode ifStmtNode) {
        this.ifStmtNode = ifStmtNode;
        this.t = 7;
    }

    public StmtNode(ForNode forNode) {
        this.forNode = forNode;
        this.t = 8;
    }

    public StmtNode(BreakStmt breakStmt) {
        this.breakStmt = breakStmt;
        this.t = 9;
    }

    public StmtNode(ContinueStmt continueStmt) {
        this.continueStmt = continueStmt;
        this.t = 10;
    }

    public StmtNode(ReturnStmt returnStmt) {
        this.returnStmt = returnStmt;
        this.t = 11;
    }

    public StmtNode(PrintfStmt printfStmt) {
        this.printfStmt = printfStmt;
        this.t = 12;
    }

    public StmtNode(BlockNode blockNode) {
        this.blockNode = blockNode;
        this.t = 13;
    }

    public ASTNodes getType() {
        return type;
    }

    public Object getValue() {
        if (t == 1) {
            return lValStmt;
        }
        else if (t == 2) {
            return getint;
        }
        else if (t == 3) {
            return getCharStmt;
        }
        else if (t == 4) {
            return exprNode;
        }
        else if (t == 5) {
            return nullStmt;
        }
        else if (t == 6) {
            return ifElseStmtNode;
        }
        else if (t == 7) {
            return ifStmtNode;
        }
        else if (t == 8) {
            return forNode;
        }
        else if (t == 9) {
            return breakStmt;
        }
        else if (t == 10) {
            return continueStmt;
        }
        else if (t == 11) {
            return returnStmt;
        }
        else if (t == 12) {
            return printfStmt;
        }
        else if (t == 13) {
            return blockNode;
        }
        else {
            return null;
        }
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        if (t == 1) {
            lValStmt.postOrderTraversal(io);
        }
        else if (t == 2) {
            getint.postOrderTraversal(io);
        }
        else if (t == 3) {
            getCharStmt.postOrderTraversal(io);
        }
        else if (t == 4) {
            exprNode.postOrderTraversal(io);
            io.getParserWriter().write("SEMICN ;\n");
        }
        else if (t == 5) {
            nullStmt.postOrderTraversal(io);
            io.getParserWriter().write("SEMICN ;\n");
        }
        else if (t == 6) {
            ifElseStmtNode.postOrderTraversal(io);
        }
        else if (t == 7) {
            ifStmtNode.postOrderTraversal(io);
        }
        else if (t == 8) {
            forNode.postOrderTraversal(io);
        }
        else if (t == 9) {
            breakStmt.postOrderTraversal(io);
        }
        else if (t == 10) {
            continueStmt.postOrderTraversal(io);
        }
        else if (t == 11) {
            returnStmt.postOrderTraversal(io);
        }
        else if (t == 12) {
            printfStmt.postOrderTraversal(io);
        }
        else if (t == 13) {
            blockNode.postOrderTraversal(io);
        }
        io.getParserWriter().write("<Stmt>\n");
    }

    
    public void postOrderNoPrint() {
        if (t == 1) {
            lValStmt.postOrderNoPrint();
        }
        else if (t == 2) {
            getint.postOrderNoPrint();
        }
        else if (t == 3) {
            getCharStmt.postOrderNoPrint();
        }
        else if (t == 4) {
            exprNode.postOrderNoPrint();
        }
        else if (t == 5) {
            nullStmt.postOrderNoPrint();
        }
        else if (t == 6) {
            ifElseStmtNode.postOrderNoPrint();
        }
        else if (t == 7) {
            ifStmtNode.postOrderNoPrint();
        }
        else if (t == 8) {
            forNode.postOrderNoPrint();
        }
        else if (t == 9) {
            breakStmt.postOrderNoPrint();
        }
        else if (t == 10) {
            continueStmt.postOrderNoPrint();
        }
        else if (t == 11) {
            returnStmt.postOrderNoPrint();
        }
        else if (t == 12) {
            printfStmt.postOrderNoPrint();
        }
        else if (t == 13) {
            blockNode.postOrderNoPrint();
        }
    }
}
