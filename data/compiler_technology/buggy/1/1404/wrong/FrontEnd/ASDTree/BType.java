package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class BType implements ASDNode{
    private String Btype;
    public BType(String a)
    {
        this.Btype=a;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        if(this.Btype.equals("int")) {
            System.out.println("INTTK int");
        }

        else {
            System.out.println("CHARTK char");
        }
    }
    public void setBtype(String btype)
    {
        this.Btype=btype;
    }
    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
