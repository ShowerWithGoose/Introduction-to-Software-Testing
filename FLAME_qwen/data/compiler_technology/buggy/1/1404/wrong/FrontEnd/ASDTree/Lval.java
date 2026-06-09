package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Lval implements ASDNode{
    private Ident ident;
    private Exp exp=null;
    public Lval(Ident ident)
    {
        this.ident=ident;
    }
    public Lval(Ident ident,Exp exp)
    {
        this.ident=ident;
        this.exp=exp;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.ident.printInfo();
        if(this.exp!=null)
        {
            System.out.println("LBRACK [");
            this.exp.printInfo();
            System.out.println("RBRACK ]");
        }
        System.out.println("<LVal>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
