package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class FuncType implements ASDNode{
    private Token token;
    public FuncType (Token token)
    {
        this.token=token;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println(this.token.getTokenCode()+" "+this.token.getOringinStr());

        System.out.println("<FuncType>");

    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
