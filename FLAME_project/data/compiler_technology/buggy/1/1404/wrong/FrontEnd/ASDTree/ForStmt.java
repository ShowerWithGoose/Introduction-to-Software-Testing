package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class ForStmt implements ASDNode{
    private Lval lval;
    private Exp exp;
    public ForStmt(Lval lval,Exp exp)
    {
        this.lval=lval;
        this.exp=exp;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.lval.printInfo();
        System.out.println("ASSIGN =");
        this.exp.printInfo();
        System.out.println("<ForStmt>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
