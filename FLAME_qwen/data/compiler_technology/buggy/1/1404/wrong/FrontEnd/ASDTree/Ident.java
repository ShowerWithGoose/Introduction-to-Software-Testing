package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import FrontEnd.Token;
public class Ident implements ASDNode{
    private Token token;
    public Ident(Token token)
    {
        this.token=token;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println(token.getTokenCode()+" "+token.getOringinStr());
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
