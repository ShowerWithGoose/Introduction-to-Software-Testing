package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.security.PublicKey;
import java.util.ArrayList;

import static java.lang.Boolean.TRUE;

public class VarDecl implements ASDNode{
    private BType bType;
    private ArrayList<VarDef> varDefs;
    private final ArrayList<ASDNode> ASDNodes = new ArrayList<>();
    public  VarDecl(BType bType,ArrayList<VarDef> varDefs)
    {
        this.bType=bType;
        this.varDefs=varDefs;
        ASDNodes.addAll(varDefs);
    }

    @Override
    public void printInfo() throws FileNotFoundException {
        /*这个类型也全交给varDef吧就是*/
        /*先print一个类型出来，然后后边交给VarDecl*/
        bType.printInfo();
        boolean onlyOne=true;
//        System.out.println("VarDefSize "+varDefs.size());
        for(VarDef defs:varDefs)
        {
           if(!onlyOne)
           {
               System.out.println("COMMA ,");
           }
               defs.printInfo();
               onlyOne=false;
               System.out.println("<VarDef>");
        }
        System.out.println("SEMICN ;");
        System.out.println("<VarDecl>");

    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
