package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class LOrExp implements ASDNode{
    private ArrayList<LAndExp> lAndExpArrayList=null;
    public LOrExp(ArrayList<LAndExp> lAndExpArrayList)
    {
        this.lAndExpArrayList=lAndExpArrayList;
    }

    @Override
    public void printInfo() throws FileNotFoundException {
        lAndExpArrayList.get(0).printInfo();
        System.out.println("<LOrExp>");
        for(int i=1;i<lAndExpArrayList.size();i++)
        {
            System.out.println("OR ||");
            lAndExpArrayList.get(i).printInfo();
            System.out.println("<LOrExp>");
        }
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
