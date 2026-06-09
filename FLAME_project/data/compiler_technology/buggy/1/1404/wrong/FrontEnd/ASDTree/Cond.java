package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Cond implements ASDNode{

    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp)
    {
        this.lOrExp=lOrExp;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.lOrExp.printInfo();
        System.out.println("<Cond>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
