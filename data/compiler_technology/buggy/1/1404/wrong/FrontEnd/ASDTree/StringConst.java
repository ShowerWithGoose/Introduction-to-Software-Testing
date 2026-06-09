package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class StringConst implements ASDNode{
    private Token token;
    public StringConst(Token token)
    {
        this.token=token;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println(this.token.getTokenCode()+" "+this.token.getOringinStr());
//        System.out.println("<StringConst>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
