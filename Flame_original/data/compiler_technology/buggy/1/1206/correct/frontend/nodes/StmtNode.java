package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:17
 */
public class StmtNode {


    public enum stmtType{
        Lval,
        Exp,
        Block,
        If,
        For,
        Break,
        Continue,
        Return,
        Getint,
        Getchar,
        Printf
    }
    /*
       Stmt → LVal '=' Exp ';'
       | [Exp] ';'
       | Block
       | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
       | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
       | 'break' ';' | 'continue' ';'
       | 'return' [Exp] ';'
       | LVal '=' 'getint''('')'';'
       | LVal '=' 'getchar''('')'';'
       | 'printf''('StringConst {','Exp}')'';'
      */
    public void output() throws IOException {
        if(this.type.equals(stmtType.Lval)){
            lvalNode.output();
            out.write(assignToken.toString());
            expNode.output();
            out.write(semicnToken.toString());
        }else if(this.type.equals(stmtType.Exp)){
            if(expNode!=null){
                expNode.output();
            }
            out.write(semicnToken.toString());
        }else if(this.type.equals(stmtType.Block)){
            blockNode.output();
        }else if(this.type.equals(stmtType.If)){
            out.write(ifToken.toString());
            out.write(leftParentToken.toString());
            condNode.output();
            out.write(rightParentToken.toString());
            ifStmt.output();
            if(elseToken!=null){
                out.write(elseToken.toString());
                elseStmt.output();
            }
        }else if(this.type.equals(stmtType.For)){
            out.write(forToken.toString());
            out.write(leftParentToken.toString());
            if(condStmt1!=null)condStmt1.output();
            out.write(semicns.get(0).toString());
            if(condNode!=null)condNode.output();
            out.write(semicns.get(0).toString());
            if(condStmt2!=null)condStmt2.output();
            out.write(rightParentToken.toString());
            stmtNode.output();
        }else if(this.type.equals(stmtType.Break)||this.type.equals(stmtType.Continue)){
            out.write(breakOrContinueToken.toString());
            out.write(semicnToken.toString());
        }else if(this.type.equals(stmtType.Return)){
            out.write(returnToken.toString());
            if(expNode!=null){
                expNode.output();
            }
            out.write(semicnToken.toString());
        }else if(this.type.equals(stmtType.Getint)||this.type.equals(stmtType.Getchar)){
            lvalNode.output();
            out.write(assignToken.toString());
            out.write(getintOrcharToken.toString());
            out.write(leftParentToken.toString());
            out.write(rightParentToken.toString());
            out.write(semicnToken.toString());
        }else if(this.type.equals(stmtType.Printf)){
            out.write(printfToken.toString());
            out.write(leftParentToken.toString());
            out.write(formatString.toString());
            for(int i=0;i<commas.size();i++){
                out.write(commas.get(i).toString());
                expNodes.get(i).output();
            }
            out.write(rightParentToken.toString());
            out.write(semicnToken.toString());
        }
        out.write("<Stmt>");
    }
    public stmtType type;
    public LvalNode lvalNode;
    public token assignToken;

    public ExpNode expNode;

    public token semicnToken;//分号

    public BlockNode blockNode;

    public token ifToken;
    public token leftParentToken;
    public CondNode condNode;
    public token rightParentToken;
    public StmtNode ifStmt;
    public token elseToken;
    public StmtNode elseStmt;

    public token forToken;
    public ForStmtNode condStmt1,condStmt2;
    public ArrayList<token> semicns;
    public StmtNode stmtNode;

    public token breakOrContinueToken;

    public token returnToken;
    public token getintOrcharToken;
    public token printfToken;
    public token formatString;
    public ArrayList<token> commas;
    public ArrayList<ExpNode> expNodes;
    public StmtNode(stmtType type,LvalNode lvalNode,token assignToken,ExpNode expNode,token semicnToken){
        //LVal '=' Exp ';'
        this.type=type;//stmt的类型
        this.assignToken=assignToken;
        this.lvalNode=lvalNode;
        this.expNode=expNode;
        this.semicnToken=semicnToken;
    }
    public StmtNode(stmtType type,ExpNode expNode,token semicnToken){
        //[Exp] ';'
        this.type=type;
        this.expNode=expNode;
        this.semicnToken=semicnToken;
    }
    public StmtNode(stmtType type,BlockNode blockNode){
        //Block
        this.type=type;
        this.blockNode=blockNode;
    }
    public StmtNode(stmtType type,token ifToken,token leftParentToken,CondNode condNode,token rightParentToken,
                    StmtNode ifStmt,token elseToken,StmtNode elseStmt){
        //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        this.type=type;
        this.ifToken=ifToken;
        this.leftParentToken=leftParentToken;
        this.condNode=condNode;
        this.rightParentToken=rightParentToken;
        this.ifStmt=ifStmt;
        this.elseToken=elseToken;
        this.elseStmt=elseStmt;
    }
    public  StmtNode(stmtType type,token forToken,token leftParentToken,ForStmtNode condStmt1,ArrayList<token> semicns,CondNode condNode,
                     ForStmtNode condStmt2,token rightParentToken,StmtNode stmtNode){
        //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        this.type=type;
        this.forToken=forToken;
        this.leftParentToken=leftParentToken;
        this.condStmt1=condStmt1;
        this.condStmt2=condStmt2;
        this.condNode=condNode;
        this.semicns=semicns;
        this.rightParentToken=rightParentToken;
        this.stmtNode=stmtNode;
    }
    public  StmtNode(stmtType type,token breakOrContinueToken,token semicnToken){
        //'break' ';' | 'continue' ';'
        this.type=type;
        this.breakOrContinueToken=breakOrContinueToken;
        this.semicnToken=semicnToken;
    }
    public  StmtNode(stmtType type,token returnToken,ExpNode expNode,token semicnToken){
        //'return' [Exp] ';'
        this.type=type;
        this.returnToken=returnToken;
        this.expNode=expNode;
        this.semicnToken=semicnToken;
    }
    public StmtNode(stmtType type,LvalNode lvalNode,token assignToken,token getintOrcharToken,
                    token leftParentToken,token rightParentToken,token semicnToken){
        //LVal '=' 'getint''('')'';' | LVal '=' 'getchar''('')'';'
        this.type=type;
        this.lvalNode=lvalNode;
        this.assignToken=assignToken;
        this.getintOrcharToken=getintOrcharToken;
        this.leftParentToken=leftParentToken;
        this.rightParentToken=rightParentToken;
        this.semicnToken=semicnToken;
    }
    public StmtNode(stmtType type,token printfToken,token leftParentToken,token formatString,
                    ArrayList<token> commas,ArrayList<ExpNode> expNodes,token rightParentToken,token semicnToken){
        //'printf''('StringConst {','Exp}')'';'
        this.type=type;
        this.printfToken=printfToken;
        this.leftParentToken=leftParentToken;
        this.formatString=formatString;
        this.commas=commas;
        this.expNodes=expNodes;
        this.rightParentToken=rightParentToken;
        this.semicnToken=semicnToken;
    }

}
