package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Stmt {
    public LVal lVal;
    public String ASSIGN;
    public Exp exp;
    public String SEMICN;
    //
    public Block block;
    //
    public String IFTK;
    public String LPARENT;
    public Cond cond;
    public String RPARENT;
    public Stmt stmt;
    public String ELSETK;
    public Stmt else_stmt;
    //
    public String FORTK;
    public ForStmt First_forStmt;
    public String First_for_SEMICN;
    public String Second_for_SEMICN;
    public ForStmt Second_forStmt;
    //
    public String BREAKTK;
    public String CONTINUETK;
    public String RETURNTK;
    public String GETINTTK;
    public String GETCHARTK;
    public String PRINTFTK;
    public String StringConst;
    public ArrayList<Exp> exps = new ArrayList<Exp>();

    public void print(FileWriter lw) throws IOException {
        if(IFTK != null){
            lw.write("IFTK " + IFTK + "\n");
            if(LPARENT != null)
                lw.write("LPARENT " + LPARENT + "\n");
            if(cond != null)
                cond.print(lw);
            if(RPARENT != null)
                lw.write("RPARENT " + RPARENT + "\n");
            if(stmt != null)
                stmt.print(lw);
            if(ELSETK != null)
                lw.write("ELSETK " + ELSETK + "\n");
            if(else_stmt != null)
                else_stmt.print(lw);
        }
        else if(FORTK != null){
            lw.write("FORTK " + FORTK + "\n");
            if(LPARENT != null)
                lw.write("LPARENT " + LPARENT + "\n");
            if(First_forStmt != null)
                First_forStmt.print(lw);
            if(First_for_SEMICN != null)
                lw.write("SEMICN " + First_for_SEMICN + "\n");
            if(cond != null)
                cond.print(lw);
            if(Second_for_SEMICN != null)
                lw.write("SEMICN " + Second_for_SEMICN + "\n");
            if(Second_forStmt != null)
                Second_forStmt.print(lw);
            if(RPARENT != null)
                lw.write("RPARENT " + RPARENT + "\n");
            if(stmt != null)
                stmt.print(lw);
        }
        else if(BREAKTK != null){
            lw.write("BREAKTK " + BREAKTK + "\n");
            if(SEMICN != null)
                lw.write("SEMICN " + SEMICN + "\n");
        }
        else if(CONTINUETK != null){
            lw.write("CONTINUETK " + CONTINUETK + "\n");
            if(SEMICN != null)
                lw.write("SEMICN " + SEMICN + "\n");
        }
        else if(RETURNTK != null){
            lw.write("RETURNTK " + RETURNTK + "\n");
            if(exp != null)
                exp.print(lw);
            if(SEMICN != null)
                lw.write("SEMICN " + SEMICN + "\n");
        }
        else if(PRINTFTK != null){
            lw.write("PRINTFTK " + PRINTFTK + "\n");
            if(LPARENT != null)
                lw.write("LPARENT " + LPARENT + "\n");
            if(StringConst != null)
                lw.write("STRCON " + StringConst + "\n");
            for(Exp exp : exps) {
                lw.write("COMMA ,\n");
                exp.print(lw);
            }
            if(RPARENT != null)
                lw.write("RPARENT " + RPARENT + "\n");
            if(SEMICN != null)
                lw.write("SEMICN " + SEMICN + "\n");
        }
        else if(block != null){
            block.print(lw);
        }
        else if(lVal != null){
            lVal.print(lw);
            if(ASSIGN != null)
                lw.write("ASSIGN " + ASSIGN + "\n");
            if(GETINTTK != null) {
                lw.write("GETINTTK " + GETINTTK + "\n");
                if(LPARENT != null)
                    lw.write("LPARENT " + LPARENT + "\n");
                if(RPARENT != null)
                    lw.write("RPARENT " + RPARENT + "\n");
                if(SEMICN != null)
                    lw.write("SEMICN " + SEMICN + "\n");
            }
            else if(GETCHARTK != null) {
                lw.write("GETCHARTK " + GETCHARTK + "\n");
                if(LPARENT != null)
                    lw.write("LPARENT " + LPARENT + "\n");
                if(RPARENT != null)
                    lw.write("RPARENT " + RPARENT + "\n");
                if(SEMICN != null)
                    lw.write("SEMICN " + SEMICN + "\n");
            }
            else if(exp != null) {
                exp.print(lw);
                if(SEMICN != null)
                    lw.write("SEMICN " + SEMICN + "\n");
            }
        }
        else {
            if(exp != null)
                exp.print(lw);
            if(SEMICN != null)
                lw.write("SEMICN " + SEMICN + "\n");
        }
        lw.write("<Stmt>\n");
    }
}
