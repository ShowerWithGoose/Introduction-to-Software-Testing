package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class FuncRParams implements ASDNode{
    ArrayList<Exp> expArrayList;
    public FuncRParams(ArrayList<Exp> expArrayList)
    {
        this.expArrayList=expArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
//        System.out.println("实参的个数 "+this.expArrayList.size());
        boolean onlyOne=true;
        for(Exp exp:expArrayList)
        {
            if(onlyOne==false)
            {
                System.out.println("COMMA ,");
            }
            exp.printInfo();
            onlyOne=false;
        }
        System.out.println("<FuncRParams>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
