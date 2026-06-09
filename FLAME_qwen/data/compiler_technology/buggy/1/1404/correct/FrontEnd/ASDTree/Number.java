package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Number implements ASDNode{
    private IntConst intConst;
    public Number(IntConst intConst)
    {
        this.intConst=intConst;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.intConst.printInfo();
        System.out.println("<Number>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
