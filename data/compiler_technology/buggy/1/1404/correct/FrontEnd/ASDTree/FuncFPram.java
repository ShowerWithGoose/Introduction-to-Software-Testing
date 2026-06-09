package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class FuncFPram implements ASDNode{
    private BType bType;
    private Ident ident;
    private boolean isArray;
    public FuncFPram(BType bType, Ident ident, boolean isArray)
    {
        this.bType=bType;
        this.ident=ident;
        this.isArray=isArray;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
           this.bType.printInfo();
           this.ident.printInfo();
           if (this.isArray){
               System.out.println("LBRACK [");
               System.out.println("RBRACK ]");
           }
        System.out.println("<FuncFParam>");
    }
    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
