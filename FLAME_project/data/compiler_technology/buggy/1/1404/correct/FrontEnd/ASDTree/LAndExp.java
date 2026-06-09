package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class LAndExp implements ASDNode{
    private ArrayList<EqExp> expArrayList=null;
    public LAndExp(ArrayList<EqExp> expArrayList)
    {
        this.expArrayList=expArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException
    {
         expArrayList.get(0).printInfo();
         System.out.println("<LAndExp>");
         for(int i=1;i<expArrayList.size();i++)
         {
             System.out.println("AND &&");
             expArrayList.get(i).printInfo();
             System.out.println("<LAndExp>");
         }
//        for(EqExp eqExp:expArrayList)
//        {
//            if(!OnlyOne)
//            {
//                System.out.println("AND &&");
//            }
//            eqExp.printInfo();
//            System.out.println("<LAndExp>");
//            OnlyOne=false;
//        }
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
