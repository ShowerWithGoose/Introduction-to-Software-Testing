package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Stmt {
    private int type;

    private LVal lVal;
    private Token equalTk;
    private Exp exp;

    private Token semicn;
    private Block block;
    private Token ifTk;
    private Token leftB;
    private Cond cond;
    private Token rightB;
    private Stmt stmtIf;
    private Token elseTk;
    private Stmt stmtElse;

    private Token forTk;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private Stmt stmtFor;


    private Token breakTk;

    private Token continueTk;

    private Token returnTk;

    private Token getintTk;

    private Token getCharTk;

    private Token printfTk;
    private StringConst stringConst;
    private ArrayList<Exp> exps = new ArrayList<>();

    public void setType(int type) {
        this.type = type;
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setEqualTk(Token equalTk) {
        this.equalTk = equalTk;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setSemicn(Token semicn) {
        this.semicn = semicn;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public void setIfTk(Token ifTk) {
        this.ifTk = ifTk;
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void setStmtIf(Stmt stmtIf) {
        this.stmtIf = stmtIf;
    }

    public void setElseTk(Token elseTk) {
        this.elseTk = elseTk;
    }

    public void setStmtElse(Stmt stmtElse) {
        this.stmtElse = stmtElse;
    }

    public void setForTk(Token forTk) {
        this.forTk = forTk;
    }

    public void setForStmt1(ForStmt forStmt1) {
        this.forStmt1 = forStmt1;
    }

    public void setForStmt2(ForStmt forStmt2) {
        this.forStmt2 = forStmt2;
    }

    public void setStmtFor(Stmt stmtFor) {
        this.stmtFor = stmtFor;
    }

    public void setBreakTk(Token breakTk) {
        this.breakTk = breakTk;
    }

    public void setContinueTk(Token continueTk) {
        this.continueTk = continueTk;
    }

    public void setReturnTk(Token returnTk) {
        this.returnTk = returnTk;
    }

    public void setGetintTk(Token getintTk) {
        this.getintTk = getintTk;
    }

    public void setGetCharTk(Token getCharTk) {
        this.getCharTk = getCharTk;
    }

    public void setPrintfTk(Token printfTk) {
        this.printfTk = printfTk;
    }

    public void setStringConst(StringConst stringConst) {
        this.stringConst = stringConst;
    }

    public void addExp(Exp exp) {
        exps.add(exp);
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (type == 1) {
            fileWriter.write(printfTk.toString() + "\n");
            fileWriter.write(leftB.toString() + "\n");
            stringConst.output(fileWriter);
            for (Exp value : exps) {
                fileWriter.write("COMMA ,\n");
                value.output(fileWriter);
            }
            fileWriter.write(rightB.toString() + "\n");
            fileWriter.write(semicn.toString() + "\n");
        } else if (type == 2) {
            fileWriter.write(returnTk.toString() + "\n");
            if (exp != null) exp.output(fileWriter);
            fileWriter.write(semicn.toString() + "\n");
        } else if (type == 3) {
            if (breakTk != null) {
                fileWriter.write(breakTk.toString() + "\n");
                fileWriter.write(semicn.toString() + "\n");
            } else {
                fileWriter.write(continueTk.toString() + "\n");
                fileWriter.write(semicn.toString() + "\n");
            }
        } else if (type == 4) {
            fileWriter.write(forTk.toString() + "\n");
            fileWriter.write(leftB.toString() + "\n");
            if (forStmt1 != null) forStmt1.output(fileWriter);
            fileWriter.write(semicn.toString() + "\n");
            if (cond != null) cond.output(fileWriter);
            fileWriter.write(semicn.toString() + "\n");
            if (forStmt2 != null) forStmt2.output(fileWriter);
            fileWriter.write(rightB.toString() + "\n");
            stmtFor.output(fileWriter);
        } else if (type == 5) {
            fileWriter.write(ifTk.toString() + "\n");
            fileWriter.write(leftB.toString() + "\n");
            cond.output(fileWriter);
            fileWriter.write(rightB.toString() + "\n");
            stmtIf.output(fileWriter);
            if (elseTk != null) {
                fileWriter.write(elseTk.toString() + "\n");
                stmtElse.output(fileWriter);
            }
        } else if (type == 6) {
            block.output(fileWriter);
        } else if (type == 7 || type == 8) {
            lVal.output(fileWriter);
            fileWriter.write(equalTk.toString() + "\n");
            if (type == 7) fileWriter.write(getintTk.toString() + "\n"); else fileWriter.write(getCharTk.toString() + "\n");
            fileWriter.write(leftB.toString() + "\n");
            fileWriter.write(rightB.toString() + "\n");
            fileWriter.write(semicn.toString() + "\n");
        } else if (type == 9) {
            lVal.output(fileWriter);
            fileWriter.write(equalTk.toString() + "\n");
            exp.output(fileWriter);
            fileWriter.write(semicn.toString() + "\n");
        } else {
            if (exp != null) exp.output(fileWriter);
            fileWriter.write(semicn.toString() + "\n");
        }
        fileWriter.write("<Stmt>\n");
    }
}
