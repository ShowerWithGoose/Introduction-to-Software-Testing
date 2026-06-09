package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class InitVal implements ASDNode {
    private boolean isList=false;
    private ArrayList<Exp> expArrayList=null;
    private StringConst stringConst;

    public InitVal(ArrayList<Exp> expArrayList,boolean isList)
    {
        this.isList=isList;
        this.expArrayList=expArrayList;
    }
    public InitVal(StringConst stringConst)
    {
        this.stringConst=stringConst;
    }
    @Override
    public void printInfo() throws FileNotFoundException
    {
        /*由exp序列构成的*/
        /*但你注意可能是没有Exp的*/
        if(expArrayList!=null)
        {
            if(this.isList)
            {
                System.out.println("LBRACE {");
            }
            boolean onlyOne=true;
            for(Exp exp:expArrayList)
            {
                if(!onlyOne){
                    System.out.println("COMMA ,");
                }
                    exp.printInfo();
                    onlyOne=false;
            }
            if(this.isList)
            {
                System.out.println("RBRACE }");
            }
        }

        else if(this.stringConst!=null)
        {
            this.stringConst.printInfo();
        }

        System.out.println("<InitVal>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
