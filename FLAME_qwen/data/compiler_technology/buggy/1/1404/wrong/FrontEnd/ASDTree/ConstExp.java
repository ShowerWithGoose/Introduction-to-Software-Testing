package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class ConstExp implements ASDNode{
    private AddExp addExp;
    public ConstExp(AddExp addExp)
    {
        this.addExp=addExp;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.addExp.printInfo();
        System.out.println("<ConstExp>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
