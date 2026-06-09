package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class MulExp implements ASDNode{
    private ArrayList<Token> opList=null;
    private ArrayList<UnaryExp> unaryExpArrayList;
    public MulExp(ArrayList<UnaryExp> unaryExpArrayList)
    {
        this.unaryExpArrayList=unaryExpArrayList;
    }
    public MulExp(ArrayList<Token> opList,ArrayList<UnaryExp> unaryExpArrayList)
    {
        this.opList=opList;
        this.unaryExpArrayList=unaryExpArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        int i=0,j=0;
        for(i=0;i<unaryExpArrayList.size();i++)
        {
            this.unaryExpArrayList.get(i).printInfo();
            System.out.println("<MulExp>");
            if(opList!=null) {
                if (j < opList.size()) {
                    Token tmp = this.opList.get(j);
                    j++;
                    System.out.println(tmp.getTokenCode() + " " + tmp.getOringinStr());
                }
            }
        }
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
