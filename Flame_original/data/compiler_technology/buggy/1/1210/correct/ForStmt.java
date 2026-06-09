import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ForStmt extends Father {
    private ArrayList<Father> list;

    public ForStmt() {
        this.list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        LVal lVal = new LVal();
        p = lVal.parser(p,tokens);
        list.add(lVal);
        list.add(tokens.get(p));
        p++;
        Exp exp = new Exp();
        p = exp.parser(p,tokens);
        list.add(exp);
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof LVal) {
                LVal lVal = (LVal) object;
                lVal.Print();
            } else if (object instanceof Exp) {
                Exp exp = (Exp) object;
                exp.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "ForStmt" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
