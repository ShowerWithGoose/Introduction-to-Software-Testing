package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class AddExp implements ASDNode{
    private ArrayList<Token> opList;
    private ArrayList<MulExp> mulExpArrayList;
    public AddExp(ArrayList<Token> opList,ArrayList<MulExp> mulExpArrayList)
    {
        this.opList=opList;
        this.mulExpArrayList=mulExpArrayList;
    }

    /*这个是只有单值的情况*/
    public AddExp(ArrayList<MulExp> mulExpArrayList)
    {
        this.mulExpArrayList=mulExpArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        if(opList!=null)
        {
            int count1=0,count2=0;
            while(count1<mulExpArrayList.size())
            {
                MulExp m=mulExpArrayList.get(count1);
                m.printInfo();
                System.out.println("<AddExp>");
                count1++;
                if(count2<opList.size())
                {
                    Token n = opList.get(count2);
                    System.out.println(n.getTokenCode() + " " + n.getOringinStr());
                    count2++;
                }

            }
        }
        else {
            MulExp m= mulExpArrayList.get(0);
            m.printInfo();
            System.out.println("<AddExp>");
        }
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
