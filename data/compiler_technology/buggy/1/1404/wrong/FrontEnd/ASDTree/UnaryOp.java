package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class UnaryOp implements ASDNode{

    private Token token;
    public UnaryOp(Token token)
    {
        this.token=token;
    }
    @Override
    public void printInfo() throws FileNotFoundException
    {
        System.out.println(this.token.getTokenCode()+" "+this.token.getOringinStr());
        System.out.println("<UnaryOp>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
