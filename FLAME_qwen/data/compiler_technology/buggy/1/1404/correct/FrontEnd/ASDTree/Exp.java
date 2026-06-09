package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Exp implements ASDNode{
    private AddExp addExp;
    public Exp(AddExp addExp)
    {
        this.addExp=addExp;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.addExp.printInfo();
        System.out.println("<Exp>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
