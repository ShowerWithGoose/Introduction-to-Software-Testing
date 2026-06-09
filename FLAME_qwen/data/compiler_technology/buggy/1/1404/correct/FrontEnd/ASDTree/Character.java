package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Character implements ASDNode{
    private CharConst charConst;
    public Character(CharConst charConst)
    {
        this.charConst=charConst;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        this.charConst.printInfo();
        System.out.println("<Character>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
