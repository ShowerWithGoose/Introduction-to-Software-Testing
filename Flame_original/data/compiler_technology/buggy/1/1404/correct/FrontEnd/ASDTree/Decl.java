package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Decl implements ASDNode
{
    private ConstDecl constDecl=null;
    private VarDecl varDecl=null;
    private  ArrayList<ASDNode> ASDNodes = new ArrayList<>();
    public Decl(ConstDecl constDecl)
    {
        this.constDecl=constDecl;
        ASDNodes.add(constDecl);
    }
    public Decl(VarDecl varDecl)
    {
        this.varDecl=varDecl;
        ASDNodes.add(varDecl);
    }


    @Override
    public void printInfo() throws FileNotFoundException {

        if(constDecl!=null)
        {
            constDecl.printInfo();
        }

        else
        {
            varDecl.printInfo();
        }
//        System.out.println("<Decl>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
