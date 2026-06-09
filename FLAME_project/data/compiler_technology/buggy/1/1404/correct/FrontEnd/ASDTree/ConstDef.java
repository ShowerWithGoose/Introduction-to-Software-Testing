package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class ConstDef implements ASDNode{
    private Ident ident;
    /*这个是常量定义里边是否有数组*/
    private ConstExp constExp=null;
    private ConstInitVal constInitVal;
    public  ConstDef(Ident ident,ConstExp constExp, ConstInitVal constInitVal)
    {
        this.ident=ident;
        this.constExp=constExp;
        this.constInitVal=constInitVal;
    }
    public ConstDef(Ident ident,ConstInitVal constInitVal)
    {
        this.ident=ident;
        this.constInitVal=constInitVal;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.ident.printInfo();
        if(this.constExp!=null)
        {
            System.out.println("LBRACK [");
            this.constExp.printInfo();
            System.out.println("RBRACK ]");
        }

        System.out.println("ASSIGN =");

        this.constInitVal.printInfo();

//        System.out.println("SEMICN ;");
        System.out.println("<ConstDef>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
