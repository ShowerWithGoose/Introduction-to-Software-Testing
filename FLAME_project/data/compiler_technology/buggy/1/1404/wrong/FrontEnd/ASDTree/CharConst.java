package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class CharConst implements ASDNode{
    private Token token;
    @Override
    public void printInfo() throws FileNotFoundException {
        System.out.println(this.token.getTokenCode()+" "+this.token.getOringinStr());
    }
    public CharConst(Token token)
    {
        this.token=token;
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
