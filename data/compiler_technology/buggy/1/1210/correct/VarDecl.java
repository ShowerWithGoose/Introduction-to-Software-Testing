import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDecl extends Father {
    private ArrayList<Father> list;

    public VarDecl() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        VarDef varDef = new VarDef();
        p = varDef.parser(p,tokens);
        list.add(varDef);
        while (tokens.get(p).getCate().equals(Cate.COMMA)) {
            list.add(tokens.get(p));
            p++;
            varDef = new VarDef();
            p = varDef.parser(p,tokens);
            list.add(varDef);
        }
        if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
            list.add(tokens.get(p));
            p++;
        } else {
            //error_i
            System.out.println("varDecl_i");
            ERROR error = new ERROR(tokens.get(p - 1).getLineNum(),'i');
            ERRORS.addError(error);
        }
        return p;
    }

    public boolean isVarDecl(int p,ArrayList<Token> tokens) {
        return (tokens.get(p).getCate().equals(Cate.INTTK) ||
                tokens.get(p).getCate().equals(Cate.CHARTK) ||
                tokens.get(p).getCate().equals(Cate.VOIDTK))
                && new VarDef().isVarDef(p + 1, tokens);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof VarDef) {
                VarDef varDef = (VarDef) object;
                varDef.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "VarDecl" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
