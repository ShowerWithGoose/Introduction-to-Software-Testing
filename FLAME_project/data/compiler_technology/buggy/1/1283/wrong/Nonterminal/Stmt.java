package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - Stmt
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class Stmt implements Node{
    //Stmt â†’ LVal '=' Exp ';'
    //| [Exp] ';'
    //| Block
    //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //| 'break' ';' | 'continue' ';'
    //| 'return' [Exp] ';'
    //| LVal '=' 'getint''('')'';'
    //| LVal '=' 'getchar''('')'';'
    //| 'printf''('StringConst {','Exp}')'';'
    public LVal lVal;
    public List<Exp> exp;
    public Block block;
    public Cond cond;
    public List<Stmt> stmt;
    public ForStmt forStmt1;
    public ForStmt forStmt2;
    public Token StringConst;
    public Token BCToken;
    public Token reToken;
    public int type;
    public Stmt(Token reToken,Token BCToken,LVal lVal,List<Exp> exp,Block block,Cond cond,List<Stmt> stmt,ForStmt forStmt1,ForStmt forStmt2,Token StringConst,int type){
        this.lVal=lVal;
        this.exp=exp;
        this.block=block;
        this.cond=cond;
        this.stmt=stmt;
        this.forStmt1=forStmt1;
        this.forStmt2=forStmt2;
        this.StringConst=StringConst;
        this.type=type;
        this.BCToken=BCToken;
        this.reToken=reToken;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        //Block
        if(type==3) block.output(writer);
        //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        else if(type==4){
            writer.write("IFTK if\n");
            writer.write("LPARENT (\n");
            cond.output(writer);
            writer.write("RPARENT )\n");
            stmt.get(0).output(writer);
            if(stmt.size()>1){
                writer.write("ELSETK else\n");
                stmt.get(1).output(writer);
            }
        }
        //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if(type==5){
            writer.write("FORTK for\n");
            writer.write("LPARENT (\n");
            if(forStmt1!=null) forStmt1.output(writer);
            writer.write("SEMICN ;\n");
            if(cond!=null) cond.output(writer);
            writer.write("SEMICN ;\n");
            if(forStmt2!=null) forStmt2.output(writer);
            writer.write("RPARENT )\n");
            stmt.get(0).output(writer);
        }
        //LVal '=' Exp ';'
        else if(type==1){
            lVal.output(writer);
            writer.write("ASSIGN =\n");
            exp.get(0).output(writer);
            writer.write("SEMICN ;\n");
        }
        //'printf''('StringConst {','Exp}')'';'
        else if(type==11){
            writer.write("PRINTFTK printf\n");
            writer.write("LPARENT (\n");
            writer.write(StringConst.getOutput());
            for(int i=0;i<exp.size();i++){
                writer.write("COMMA ,\n");
                exp.get(i).output(writer);
            }
            writer.write("RPARENT )\n");
            writer.write("SEMICN ;\n");
        }
        //[Exp] ';'
        else if(type==2){
            if(exp.size()>0) exp.get(0).output(writer);
            writer.write("SEMICN ;\n");
        }
        //'break' ';'
        else if(type==6){
            writer.write("BREAKTK break\n");
            writer.write("SEMICN ;\n");
        }
        //'continue' ';'
        else if(type==7){
            writer.write("CONTINUETK continue\n");
            writer.write("SEMICN ;\n");
        }
        //'return' [Exp] ';'
        else if(type==8){
            writer.write("RETURNTK return\n");
            if(exp.size()>0) exp.get(0).output(writer);
            writer.write("SEMICN ;\n");
        }
        //LVal '=' 'getint''('')'';'
        else if(type==9){
            lVal.output(writer);
            writer.write("ASSIGN =\n");
            writer.write("GETINTTK getint\n");
            writer.write("LPARENT (\n");
            writer.write("RPARENT )\n");
            writer.write("SEMICN ;\n");
        }
        //LVal '=' 'getchar''('')'';'
        else{
            lVal.output(writer);
            writer.write("ASSIGN =\n");
            writer.write("GETCHARTK getchar\n");
            writer.write("LPARENT (\n");
            writer.write("RPARENT )\n");
            writer.write("SEMICN ;\n");
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.Stmt));
    }
}
