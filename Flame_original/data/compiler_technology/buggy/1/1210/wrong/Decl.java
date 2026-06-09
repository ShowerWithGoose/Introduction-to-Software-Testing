import java.io.IOException;
import java.util.ArrayList;

public class Decl extends Father {
    private ArrayList<Father> list;

    public Decl() {
        list = new ArrayList<>();
    }

    public int parser(int p, ArrayList<Token> tokens) {
        if (new ConstDecl().isConstDecl(p, tokens)) {
            ConstDecl constDecl = new ConstDecl();
            p = constDecl.parser(p,tokens);
            list.add(constDecl);
        } else {
            VarDecl varDecl = new VarDecl();
            p = varDecl.parser(p,tokens);
            list.add(varDecl);
        }
        return p;
    }

    public boolean isDecl(int p, ArrayList<Token> tokens) {
        return new ConstDecl().isConstDecl(p, tokens) || new VarDecl().isVarDecl(p, tokens);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof ConstDecl) {
                ConstDecl constDecl = (ConstDecl) object;
                constDecl.Print();
            } else if (object instanceof VarDecl) {
                VarDecl varDecl = (VarDecl) object;
                varDecl.Print();
            }
        }
        /*FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "Decl" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();*/
    }
}
