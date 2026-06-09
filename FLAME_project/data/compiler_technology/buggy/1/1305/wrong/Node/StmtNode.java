package Node;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Token.*;
import Utils.OutputUtils;

public class StmtNode {
    public enum types{
        LVal,
        Exp,
        Block,
        If,
        For,
        Break,
        Return,
        Get,
        Printf
    }
    public types type;
    public LValNode lValNode;
    public ExpNode expNode;
    public Token equal;
    public Token semicolon1;
    public Token semicolon2;
    public Token if1;
    public Token else1 = null;
    public Token for1;
    public Token leftParent;
    public Token rightParent;
    public Token break1;
    public StmtNode stmtNode1;
    public StmtNode stmtNode2;
    public BlockNode blockNode;
    public CondNode condNode;
    public ForStmtNode forStmtNode1;
    public ForStmtNode forStmtNode2;
    public Token get1;
    public Token return1;
    public Token printf1;
    public Token stringConst;
    public List<Token> commas = new ArrayList<>();
    public List<ExpNode> expNodes = new ArrayList<>();
    public StmtNode(types type, LValNode lValNode, Token equal, ExpNode expNode, Token semicolon1){ //LVal
        this.type = type;
        this.lValNode = lValNode;
        this.expNode = expNode;
        this.equal = equal;
        this.semicolon1 = semicolon1;
    }
    public StmtNode(types type, ExpNode expNode, Token semicolon1){ //Exp
        this.type = type;
        this.expNode = expNode;
        this.semicolon1 = semicolon1;
    }
    public StmtNode(types type, BlockNode blockNode){ //Block
        this.type = type;
        this.blockNode = blockNode;
    }
    public StmtNode(types type, Token if1, Token leftParent, CondNode condNode, Token rightParent, StmtNode stmtNode1, Token else1, StmtNode stmtNode2){ //If
        this.type = type;
        this.if1 = if1;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.stmtNode1 = stmtNode1;
        this.else1 = else1;
        this.stmtNode2 = stmtNode2;
        this.condNode = condNode;
    }
    public StmtNode(types type, Token for1, Token leftParent, ForStmtNode forStmtNode1, Token semicolon1, CondNode condNode, Token semicolon2, ForStmtNode forStmtNode2, Token rightParent, StmtNode stmtNode1){ //For
        this.type = type;
        this.for1 = for1;
        this.leftParent = leftParent;
        this.forStmtNode1 = forStmtNode1;
        this.semicolon1 = semicolon1;
        this.condNode = condNode;
        this.semicolon2 = semicolon2;
        this.forStmtNode2 = forStmtNode2;
        this.rightParent = rightParent;
        this.stmtNode1 = stmtNode1;
    }
    public StmtNode(types type, Token break1, Token semicolon1){ //Break and Continue
        this.type = type;
        this.break1 = break1;
        this.semicolon1 = semicolon1;
    }
    public StmtNode(types type, Token return1, ExpNode expNode, Token semicolon1){ //Return
        this.type = type;
        this.return1 = return1;
        this.expNode = expNode;
        this.semicolon1 = semicolon1;
    }
    public StmtNode(types type, LValNode lValNode, Token equal, Token get1, Token leftParent, Token rightParent, Token semicolon1){ //GetInt and GetChar
        this.type = type;
        this.lValNode = lValNode;
        this.equal = equal;
        this.get1 = get1;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicolon1 = semicolon1;
    }
    public StmtNode(types type, Token printf1, Token leftParent, Token stringConst, List<Token> commas, List<ExpNode> expNodes, Token rightParent, Token semicolon1){
        this.type = type;
        this.printf1 = printf1;
        this.leftParent = leftParent;
        this.stringConst = stringConst;
        this.commas = commas;
        this.expNodes = expNodes;
        this.rightParent = rightParent;
        this.semicolon1 = semicolon1;
    }
    public void print() throws IOException {
        switch (type){
            case LVal -> {
                lValNode.print();
                OutputUtils.parserOutput(equal.toString());
                expNode.print();
                OutputUtils.parserOutput(semicolon1.toString());
            }
            case Exp -> {
                if(expNode != null){
                    expNode.print();
                }
                OutputUtils.parserOutput(semicolon1.toString());
            }
            case Block -> {
                blockNode.print();
            }
            case If -> {
                OutputUtils.parserOutput(if1.toString());
                OutputUtils.parserOutput(leftParent.toString());
                condNode.print();
                OutputUtils.parserOutput(rightParent.toString());
                stmtNode1.print();
                if(else1 != null){
                    OutputUtils.parserOutput(else1.toString());
                    stmtNode2.print();
                }
            }
            case For -> {
                OutputUtils.parserOutput(for1.toString());
                OutputUtils.parserOutput(leftParent.toString());
                if(forStmtNode1 != null){
                    forStmtNode1.print();
                }
                OutputUtils.parserOutput(semicolon1.toString());
                if(condNode != null){
                    condNode.print();
                }
                OutputUtils.parserOutput(semicolon1.toString());
                if(forStmtNode2 != null){
                    forStmtNode2.print();
                }
                OutputUtils.parserOutput(rightParent.toString());
                stmtNode1.print();
            }
            case Break -> {
                OutputUtils.parserOutput(break1.toString());
                OutputUtils.parserOutput(semicolon1.toString());
            }
            case Return -> {
                OutputUtils.parserOutput(return1.toString());
                if(expNode != null){
                    expNode.print();
                }
                OutputUtils.parserOutput(semicolon1.toString());
            }
            case Get -> {
                lValNode.print();
                OutputUtils.parserOutput(equal.toString());
                OutputUtils.parserOutput(get1.toString());
                OutputUtils.parserOutput(leftParent.toString());
                OutputUtils.parserOutput(rightParent.toString());
                OutputUtils.parserOutput(semicolon1.toString());
            }
            case Printf -> {
                OutputUtils.parserOutput(printf1.toString());
                OutputUtils.parserOutput(leftParent.toString());
                OutputUtils.parserOutput(stringConst.toString());
                for(int i = 0; i < commas.size(); i++){
                    OutputUtils.parserOutput(commas.get(i).toString());
                    expNodes.get(i).print();
                }
                OutputUtils.parserOutput(rightParent.toString());
                OutputUtils.parserOutput(semicolon1.toString());
            }
        }
        OutputUtils.parserOutput("<Stmt>\n");
    }
}
