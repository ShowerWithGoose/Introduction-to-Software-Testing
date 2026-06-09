package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:59
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:59
 */
public class Stmt {
/*     Stmt → LVal '=' Exp ';' // h i
       | [Exp] ';' // i
       | Block
       | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
       | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
       | 'break' ';' | 'continue' ';' // i m
       | 'return' [Exp] ';' // f i
       | LVal '=' 'getint''('')'';' // h i j
       | LVal '=' 'getchar''('')'';' // h i j
       | 'printf''('StringConst {','Exp}')'';' // i j l
 */
    public enum StmtType{LValExp, Exp, Block, If, For, BC, Return, LValGetIC, Printf}
    private StmtType type;
    private LVal lVal;
    private Token assign;
    private Exp exp;

    private Token semicn;

    private Block block;

    private Token iftk;
    private Token lparent;
    private Cond cond;
    private Token rparent;
    private Token elsetk;
    private List<Stmt> stmtList;

    private Token fortk;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private List<Token> semicnList;
    private Stmt stmt;

    private Token bctk;

    private Token returntk;

    private Token getictk;

    private Token printftk;
    private Token strcon;

    private List<Token> commaList;
    private List<Exp> expList;

//    Stmt → LVal '=' Exp ';'
    public Stmt(StmtType type, LVal lVal, Token assign, Exp exp, Token semicn) {
        this.type=type;
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
        this.semicn = semicn;
    }
//    | [Exp] ';'
    public Stmt(StmtType type, Exp exp, Token semicn) {
        this.type=type;
        this.exp = exp;
        this.semicn = semicn;
    }
//    | Block
    public Stmt(StmtType type, Block block) {
        this.type=type;
        this.block = block;
    }
//    | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    public Stmt(StmtType type, Token iftk, Token lparent, Cond cond, Token rparent, Token elsetk, List<Stmt> stmtList) {
        this.type=type;
        this.iftk = iftk;
        this.lparent = lparent;
        this.cond = cond;
        this.rparent = rparent;
        this.elsetk = elsetk;
        this.stmtList = stmtList;
    }
//    | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    public Stmt(StmtType type, Token fortk,Token lparent,ForStmt forStmt1,List<Token> semicnList,Cond cond,ForStmt forStmt2, Token rparent,Stmt stmt){
        this.type=type;
        this.fortk=fortk;
        this.lparent=lparent;
        this.forStmt1=forStmt1;
        this.forStmt2=forStmt2;
        this.semicnList=semicnList;
        this.cond=cond;
        this.rparent=rparent;
        this.stmt=stmt;
    }
//    | 'break' ';' | 'continue' ';'
    public Stmt(StmtType type, Token bctk, Token semicn) {
        this.type=type;
        this.semicn = semicn;
        this.bctk = bctk;
    }
//    | 'return' [Exp] ';'
    public Stmt(StmtType type, Token returntk, Exp exp, Token semicn) {
        this.type=type;
        this.exp = exp;
        this.semicn = semicn;
        this.returntk = returntk;
    }
//    | LVal '=' 'getint''('')'';'
//    | LVal '=' 'getchar''('')'';'
    public Stmt(StmtType type, LVal lVal, Token assign, Token getictk, Token lparent, Token rparent, Token semicn) {
        this.type=type;
        this.lVal = lVal;
        this.assign = assign;
        this.semicn = semicn;
        this.lparent = lparent;
        this.rparent = rparent;
        this.getictk = getictk;
    }
//    | 'printf''('StringConst {','Exp}')'';'
    public Stmt(StmtType type, Token printftk, Token lparent, List<Token> commaList, List<Exp> expList, Token strcon, Token rparent, Token semicn) {
        this.type=type;
        this.lparent = lparent;
        this.rparent = rparent;
        this.printftk = printftk;
        this.strcon = strcon;
        this.commaList = commaList;
        this.expList = expList;
        this.semicn=semicn;
    }

    public void print(){
        switch (type){
            case LValExp -> {
                lVal.print();
                IO.parser_output(assign.toString());
                exp.print();
                IO.parser_output(semicn.toString());
            }
            case Exp -> {
                if(exp!=null){
                    exp.print();
                }
                IO.parser_output(semicn.toString());
            }
            case Block -> {
                block.print();
            }
            case If -> {
                IO.parser_output(iftk.toString());
                IO.parser_output(lparent.toString());
                cond.print();
                IO.parser_output(rparent.toString());
                stmtList.get(0).print();
                if(elsetk!=null){
                    IO.parser_output(elsetk.toString());
                    stmtList.get(1).print();
                }
            }
            case For -> {
                IO.parser_output(fortk.toString());
                IO.parser_output(lparent.toString());
                if(forStmt1!=null){
                    forStmt1.print();
                }
                IO.parser_output(semicnList.get(0).toString());
                if(cond!=null){
                    cond.print();
                }
                IO.parser_output(semicnList.get(1).toString());
                if(forStmt2!=null){
                    forStmt2.print();
                }
                IO.parser_output(rparent.toString());
                stmt.print();
            }
            case BC -> {
                IO.parser_output(bctk.toString());
                IO.parser_output(semicn.toString());
            }
            case Return -> {
                IO.parser_output(returntk.toString());
                if(exp!=null){
                    exp.print();
                }
                IO.parser_output(semicn.toString());
            }
            case LValGetIC -> {
                lVal.print();
                IO.parser_output(assign.toString());
                IO.parser_output(getictk.toString());
                IO.parser_output(lparent.toString());
                IO.parser_output(rparent.toString());
                IO.parser_output(semicn.toString());
            }
            case Printf -> {
                IO.parser_output(printftk.toString());
                IO.parser_output(lparent.toString());
                IO.parser_output(strcon.toString());
                for(int i=0;i<commaList.size();i++){
                    IO.parser_output(commaList.get(i).toString());
                    expList.get(i).print();
                }
                IO.parser_output(rparent.toString());
                IO.parser_output(semicn.toString());
            }
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.Stmt));
    }

    public StmtType getType() {
        return type;
    }

    public LVal getlVal() {
        return lVal;
    }

    public Token getAssign() {
        return assign;
    }

    public Exp getExp() {
        return exp;
    }

    public Token getSemicn() {
        return semicn;
    }

    public Block getBlock() {
        return block;
    }

    public Token getIftk() {
        return iftk;
    }

    public Token getLparent() {
        return lparent;
    }

    public Cond getCond() {
        return cond;
    }

    public Token getRparent() {
        return rparent;
    }

    public Token getElsetk() {
        return elsetk;
    }

    public List<Stmt> getStmtList() {
        return stmtList;
    }

    public Token getFortk() {
        return fortk;
    }

    public ForStmt getForStmt1() {
        return forStmt1;
    }

    public ForStmt getForStmt2() {
        return forStmt2;
    }

    public List<Token> getSemicnList() {
        return semicnList;
    }

    public Stmt getStmt() {
        return stmt;
    }

    public Token getBctk() {
        return bctk;
    }

    public Token getReturntk() {
        return returntk;
    }

    public Token getGetictk() {
        return getictk;
    }

    public Token getPrintftk() {
        return printftk;
    }

    public Token getStrcon() {
        return strcon;
    }

    public List<Token> getCommaList() {
        return commaList;
    }

    public List<Exp> getExpList() {
        return expList;
    }
}
