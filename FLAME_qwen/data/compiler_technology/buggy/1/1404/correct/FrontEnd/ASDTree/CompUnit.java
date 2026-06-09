package FrontEnd.ASDTree;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
public class CompUnit implements ASDNode{
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;
    private ArrayList<ASDNode> ASDNodes = new ArrayList<>();
    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) throws FileNotFoundException {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
        ASDNodes.addAll(decls);
        ASDNodes.addAll(funcDefs);
        ASDNodes.add(mainFuncDef);
    }
    @Override
    public void printInfo() throws FileNotFoundException {
        PrintStream out=new PrintStream("parser.txt");
        System.setOut(out);
        for(Decl decl:decls)
        {
            decl.printInfo();
        }

        for(FuncDef funcDef:funcDefs)
        {
            funcDef.printInfo();
        }

        this.mainFuncDef.printInfo();

        System.out.println("<CompUnit>");
    }
    /*这里进行一个信息的打印*/
    @Override
    public ArrayList<ASDNode> getChild() {
        return null;
    }

}
