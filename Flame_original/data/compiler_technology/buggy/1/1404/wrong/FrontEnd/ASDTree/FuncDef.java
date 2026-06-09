package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class FuncDef implements ASDNode{
    private FuncType funcType;
    private Ident ident;
    private FuncFParams funcFParams=null;
    private Block block;
    public FuncDef(FuncType funcType,Ident ident,FuncFParams funcFParams,Block block)
    {
        this.funcType=funcType;
        this.ident=ident;
        this.funcFParams=funcFParams;
        this.block=block;
    }
    public FuncDef(FuncType funcType,Ident ident,Block block)
    {
        this.funcType=funcType;
        this.ident=ident;
        this.block=block;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.funcType.printInfo();
        this.ident.printInfo();
        System.out.println("LPARENT (");
        if(this.funcFParams!=null)
        {
            this.funcFParams.printInfo();
        }
        System.out.println("RPARENT )");
        this.block.printInfo();
        System.out.println("<FuncDef>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
