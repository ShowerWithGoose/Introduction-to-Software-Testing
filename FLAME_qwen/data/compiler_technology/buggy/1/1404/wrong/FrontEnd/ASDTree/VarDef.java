package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class VarDef implements ASDNode{
    private Ident ident;
    private boolean isInitialized=false;
    ConstExp constExp=null;
    private InitVal initVal=null;
    public VarDef(Ident ident,ConstExp constExp,InitVal initVal)
    {
        this.ident=ident;
        this.constExp=constExp;
        this.initVal=initVal;
    }
    public VarDef(Ident ident,InitVal initVal)
    {
        this.ident=ident;
        this.initVal=initVal;
    }
    public VarDef(Ident ident,ConstExp constExp)
    {
        this.ident=ident;
        this.constExp=constExp;
    }

    public VarDef(Ident ident)
    {
        this.ident=ident;
    }
    @Override
    public void printInfo() throws FileNotFoundException
    {
        this.ident.printInfo();

        if(this.constExp!=null)
        {
            System.out.println("LBRACK [");
            this.constExp.printInfo();
            System.out.println("RBRACK ]");

        }

        /*上边是变量定义的左边*/
        if(initVal!=null)
        {
            System.out.println("ASSIGN =");
            initVal.printInfo();
        }

    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
