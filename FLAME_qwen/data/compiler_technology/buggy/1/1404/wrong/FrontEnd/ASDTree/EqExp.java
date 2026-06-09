package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class EqExp implements ASDNode{
    private ArrayList<RelExp> relExpArrayList=null;
    private ArrayList<Token> tokenArrayList=null;
    public EqExp(ArrayList<RelExp> relExpArrayList)
    {
        this.relExpArrayList=relExpArrayList;
    }
    public EqExp(ArrayList<RelExp> relExpArrayList,ArrayList<Token> tokenArrayList)
    {
        this.tokenArrayList=tokenArrayList;
        this.relExpArrayList=relExpArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        int i=0,j=0;
        for(i=0;i<relExpArrayList.size();i++)
        {
            relExpArrayList.get(i).printInfo();
            System.out.println("<EqExp>");
            if(j< tokenArrayList.size())
            {
                System.out.println(tokenArrayList.get(j).getTokenCode() + " " + tokenArrayList.get(j).getOringinStr());
                j++;
            }
        }
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
