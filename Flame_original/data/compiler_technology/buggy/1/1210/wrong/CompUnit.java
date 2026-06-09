import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Token> tokens;
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private ArrayList<MainFuncDef> mainFuncDefs;

    public CompUnit(ArrayList<Token> tokenIn) {
        this.tokens = tokenIn;
        decls = new ArrayList<>();
        funcDefs = new ArrayList<>();
        mainFuncDefs = new ArrayList<>();
    }

    public void parser() {
        int p = 0;
        int size = tokens.size();
        while (p < size) {
            //System.out.println(p);
            //if (new Decl().isDecl(p,tokens)) {
            if (!tokens.get(p + 2).getCate().equals(Cate.LPARENT)) {
                //Decl
                Decl decl = new Decl();
                p = decl.parser(p,tokens);
                decls.add(decl);
            } else if (tokens.get(p + 1).isMain()) {
                //MainFuncDef
                MainFuncDef mainFuncDef = new MainFuncDef();
                p = mainFuncDef.parser(p,tokens);
                mainFuncDefs.add(mainFuncDef);
            } else{
                //FuncDef
                FuncDef funcDef = new FuncDef();
                p = funcDef.parser(p,tokens);
                funcDefs.add(funcDef);
            }
        }
    }

    public void Print() throws IOException {
        if (!ERRORS.isEmpty()) {
            ERRORS.Print();
        } else {
            for (Decl decl : decls) {
                decl.Print();
            }
            /*if (!decls.isEmpty()) {
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "Decl" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }*/
            for (FuncDef funcDef : funcDefs) {
                funcDef.Print();
            }
            /*if (!funcDefs.isEmpty()) {
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "FuncDef" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }*/
            for (MainFuncDef mainFuncDef : mainFuncDefs) {
                mainFuncDef.Print();
            }
            FileWriter fileWriter = new FileWriter("parser.txt", true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write('<' + "CompUnit" + '>' + '\n');
            bufferedWriter.flush();
            bufferedWriter.close();
        }
    }
}
