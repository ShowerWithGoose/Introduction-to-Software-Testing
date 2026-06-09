package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class RelExp implements ASDNode{
    private ArrayList<Token> opList=null;
    private ArrayList<AddExp> addExps=null;

    public RelExp(ArrayList<AddExp> addExps,ArrayList<Token> opList)
    {
        this.opList=opList;
        this.addExps=addExps;
    }
    @Override
    public void printInfo() throws FileNotFoundException
    {
        int i,j=0;
        for(i=0;i < addExps.size(); i++)
        {
            addExps.get(i).printInfo();
            System.out.println("<RelExp>");
            if(j < opList.size())
            {
                System.out.println(opList.get(j).getTokenCode()+" "+opList.get(j).getOringinStr());
                j++;
            }
        }
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
