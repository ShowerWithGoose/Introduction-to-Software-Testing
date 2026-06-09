package FrontEnd.ASDTree;
import FrontEnd.Token;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class UnaryExp implements ASDNode{
    private ArrayList<UnaryOp> opArrayList=new ArrayList<>();
    private UnaryOp unaryOp=null;
    private UnaryExp unaryExp=null;
    private PrimaryExp primaryExp=null;
    private Ident ident=null;
    private FuncRParams funcRParams=null;
    public enum Type {
        PrimaryExp, FuncCall, mulUnaryExp
    }
    public UnaryExp(PrimaryExp primaryExp)
    {
        this.primaryExp=primaryExp;
    }
    public UnaryExp(Ident ident,FuncRParams funcRParams)
    {
        this.ident=ident;
        this.funcRParams=funcRParams;
    }
    public UnaryExp(UnaryOp unaryOp,UnaryExp unaryExp)
    {
        this.unaryOp=unaryOp;
        this.unaryExp=unaryExp;
    }
    public UnaryExp(ArrayList<ASDNode> asdNodes) {
        for (ASDNode asdNode : asdNodes) {
            if (asdNode instanceof UnaryOp) {
                opArrayList.add((UnaryOp) asdNode);
            }
            else if (asdNode instanceof UnaryExp)
            {
                this.unaryExp=(UnaryExp) asdNode;
            }else if (asdNode instanceof PrimaryExp) {
                this.primaryExp = (PrimaryExp) asdNode;
            } else if (asdNode instanceof Ident) {
                this.ident = (Ident) asdNode;
            } else if (asdNode instanceof FuncRParams) {
                this.funcRParams = (FuncRParams) asdNode;
            }
        }
    }

    /*op留下的是一个数组*/
    @Override
    public void printInfo() throws FileNotFoundException
    {
        if(this.opArrayList!=null)
        {
            for(UnaryOp op:opArrayList)
            {
                op.printInfo();
            }
        }
        if(this.unaryExp!=null)
        {
            this.unaryOp.printInfo();
            this.unaryExp.printInfo();
        }
        if(this.primaryExp!=null)
        {
            this.primaryExp.printInfo();
        }
        else if(this.ident!=null)
        {
            this.ident.printInfo();
            System.out.println("LPARENT (");
            if(this.funcRParams!=null)
            {
                this.funcRParams.printInfo();
            }
            System.out.println("RPARENT )");
        }

        System.out.println("<UnaryExp>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
