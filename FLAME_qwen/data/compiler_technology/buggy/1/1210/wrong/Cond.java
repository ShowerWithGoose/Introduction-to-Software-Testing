import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Cond extends Father {
    private ArrayList<Father> list;

    public Cond() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        LOrExp lOrExp = new LOrExp();
        p = lOrExp.parser(p,tokens);
        list.add(lOrExp);
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof LOrExp) {
                LOrExp lOrExp = (LOrExp) object;
                lOrExp.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "Cond" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
