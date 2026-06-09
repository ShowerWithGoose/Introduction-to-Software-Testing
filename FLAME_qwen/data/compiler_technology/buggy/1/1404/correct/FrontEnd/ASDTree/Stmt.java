package FrontEnd.ASDTree;

import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Stmt implements ASDNode {
    public enum Type {
        Assign, Exp, Block, ifBranch, forBranch, breakStmt, continueStmt,
        returnStmt, inputInt,intputChar, print, None
    }
    private ArrayList<ASDNode> asdNodeArrayList;
    private Type type;
    private int printForstmtType=0;
    public Stmt(Type type,ArrayList<ASDNode> asdNodeArrayList)
    {
        this.type=type;
        this.asdNodeArrayList=asdNodeArrayList;
    }
    public Stmt(Type type,ArrayList<ASDNode> asdNodeArrayList,int printForstmtType)
    {
        this.printForstmtType=printForstmtType;
        this.type=type;
        this.asdNodeArrayList=asdNodeArrayList;
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        switch (type){
            case Assign:
                asdNodeArrayList.get(0).printInfo();
                System.out.println("ASSIGN =");
                asdNodeArrayList.get(1).printInfo();
                System.out.println("SEMICN ;");
                break;
            case Exp:
                if(asdNodeArrayList!=null)
                {
                    this.asdNodeArrayList.get(0).printInfo();
                }
                System.out.println("SEMICN ;");
                break;
            case Block:
                asdNodeArrayList.get(0).printInfo();
                break;
            case ifBranch:
                System.out.println("IFTK if");
                System.out.println("LPARENT (");
                asdNodeArrayList.get(0).printInfo();
                System.out.println("RPARENT )");
                asdNodeArrayList.get(1).printInfo();
                if(asdNodeArrayList.size()>2)
                {
                    System.out.println("ELSETK else");
                    asdNodeArrayList.get(2).printInfo();
                }
                break;
            case forBranch:
                /*这俩ForStmt顺序看一看就是了*/
                /*这个有点烦，再看看缺省情况吧？一共四个值，四种情况考虑一下*/
                System.out.println("FORTK for");
                System.out.println("LPARENT (");
                int k=0;
                /*这个就标识有没有第一个的意思*/
                if(k<asdNodeArrayList.size()&&asdNodeArrayList.get(k) instanceof ForStmt&&printForstmtType==1)
                {
                    this.asdNodeArrayList.get(k).printInfo();
                    k++;
                }
                System.out.println("SEMICN ;");
                if(k<asdNodeArrayList.size()&&asdNodeArrayList.get(k) instanceof Cond)
                {
                    this.asdNodeArrayList.get(k).printInfo();
                    k++;
                }
                System.out.println("SEMICN ;");
                if(k<asdNodeArrayList.size()&&asdNodeArrayList.get(k) instanceof ForStmt)
                {
                    this.asdNodeArrayList.get(k).printInfo();
                    k++;
                }
                System.out.println("RPARENT )");
                this.asdNodeArrayList.get(k).printInfo();
                break;
            case breakStmt:
                System.out.println("BREAKTK break");
                System.out.println("SEMICN ;");
                break;
            case continueStmt:
                System.out.println("CONTINUETK continue");
                System.out.println("SEMICN ;");
                break;
            case returnStmt:
                System.out.println("RETURNTK return");
                if (asdNodeArrayList.size()>=1) {
                    asdNodeArrayList.get(0).printInfo();
                }
                System.out.println("SEMICN ;");
                break;
            case inputInt:
                asdNodeArrayList.get(0).printInfo();
                System.out.println("ASSIGN =");
                System.out.println("GETINTTK getint");
                System.out.println("LPARENT (");
                System.out.println("RPARENT )");
                System.out.println("SEMICN ;");
                break;
            case intputChar:
                asdNodeArrayList.get(0).printInfo();
                System.out.println("ASSIGN =");
                System.out.println("GETCHARTK getchar");
                System.out.println("LPARENT (");
                System.out.println("RPARENT )");
                System.out.println("SEMICN ;");
                break;
            case print:
                System.out.println("PRINTFTK printf");
                System.out.println("LPARENT (");
                boolean onlyOne = true;
                for (ASDNode asdNode : asdNodeArrayList) {
                    if (!onlyOne) {
                        System.out.println("COMMA ,");
                    }
                    asdNode.printInfo();
                    onlyOne = false;
                }
                System.out.println("RPARENT )");
                System.out.println("SEMICN ;");
                break;
            case None:
                System.out.println("SEMICN ;");
            default:
                break;
        }
        System.out.println("<Stmt>");
    }

    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }
}
