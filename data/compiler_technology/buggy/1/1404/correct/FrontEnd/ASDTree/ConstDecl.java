package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

import static java.lang.Boolean.TRUE;

public class ConstDecl implements ASDNode{

    private BType  bType;
    private ArrayList<ConstDef>constDefArrayList;
    private ArrayList<ASDNode> nodeArrayList=new ArrayList<>();
    /*这个重复几次问题不大，都在List里边*/
    public  ConstDecl(BType bType,ArrayList<ConstDef>constDefArrayList)
    {
        this.bType=bType;
        this.constDefArrayList=constDefArrayList;
        this.nodeArrayList.add(bType);
        this.nodeArrayList.addAll(constDefArrayList);
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println("CONSTTK const");
        /*打印类型*/
        bType.printInfo();
        /*打印def信息*/
         boolean OnlyOne=true;
//        System.out.println("ConstDefSize "+constDefArrayList.size());
        for (ConstDef constDef: constDefArrayList) {
            if (!OnlyOne) {
                System.out.println("COMMA ,");
            }
            constDef.printInfo();
//            System.out.println("One constDeclOver");
            OnlyOne= false;
        }
        System.out.println("SEMICN ;");
        System.out.println("<ConstDecl>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
