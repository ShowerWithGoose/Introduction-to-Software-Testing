package FrontEnd.ASDTree;

import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class IntConst implements ASDNode{
    Token token;
    public IntConst(Token token)
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
