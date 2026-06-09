package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class PrimaryExp implements ASDNode{
    private Exp exp=null;
    private Lval lval=null;
    private Number number=null;
    private Character character=null;
    public PrimaryExp(Exp exp)
    {
        this.exp=exp;
    }
    public PrimaryExp(Lval lval)
    {
        this.lval=lval;
    }
    public PrimaryExp(Number number)
    {
        this.number=number;
    }
    public PrimaryExp(Character character)
    {
        this.character=character;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        if(this.exp!=null)
        {
            System.out.println("LPARENT (");
            this.exp.printInfo();
            System.out.println("RPARENT )");
        }

        else if(this.lval!=null)
        {
            this.lval.printInfo();
        }
        else if(this.number!=null)
        {
            this.number.printInfo();
        }
        else if(this.character!=null)
        {
            this.character.printInfo();
        }
        System.out.println("<PrimaryExp>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
