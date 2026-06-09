package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class FuncFParams implements ASDNode{
    private ArrayList<FuncFPram> funcfPramArrayList;
    public FuncFParams(ArrayList<FuncFPram> funcfPramArrayList)
    {
        this.funcfPramArrayList=funcfPramArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        boolean onlyOne=true;
        for(FuncFPram funcfPram:funcfPramArrayList)
        {
            if(!onlyOne)
            {
                System.out.println("COMMA ,");
            }
                funcfPram.printInfo();
                onlyOne=false;

        }
        System.out.println("<FuncFParams>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
