package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public interface ASDNode {
    public void printInfo() throws FileNotFoundException;
    ArrayList<ASDNode> getChild();
}
