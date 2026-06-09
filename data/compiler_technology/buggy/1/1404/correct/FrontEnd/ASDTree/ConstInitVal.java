package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class ConstInitVal implements ASDNode{
    private boolean isList=false;
    private ArrayList<ConstExp> constExpArrayList=null;
    StringConst stringConst=null;
    public ConstInitVal(boolean isList,ArrayList<ConstExp> constExpArrayList)
    {
        this.constExpArrayList=constExpArrayList;
        this.isList= isList;
    }
    public ConstInitVal(StringConst stringConst)
    {
        this.stringConst=stringConst;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        if(isList)
        {
            System.out.println("LBRACE {");
        }

        /*是一组表达式*/
        if(constExpArrayList!=null) {
            boolean OnlyOne = true;

            for (ConstExp constExp:constExpArrayList) {
                if(OnlyOne==false)
                {
                    System.out.println("COMMA ,");
                }
                constExp.printInfo();
                OnlyOne=false;

            }
        }
        /*是字符串常量*/
        else {
            stringConst.printInfo();
        }

        if(isList)
        {
            System.out.println("RBRACE }");
        }

        System.out.println("<ConstInitVal>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
