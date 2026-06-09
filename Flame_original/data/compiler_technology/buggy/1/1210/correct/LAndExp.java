import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LAndExp extends Father {
    private ArrayList<Father> list;

    public LAndExp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        EqExp eqExp = new EqExp();
        p = eqExp.parser(p,tokens);
        list.add(eqExp);
        while (tokens.get(p).getCate().equals(Cate.AND)) {
            list.add(tokens.get(p));
            p++;
            eqExp = new EqExp();
            p = eqExp.parser(p,tokens);
            list.add(eqExp);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof EqExp) {
                EqExp eqExp = (EqExp) object;
                eqExp.Print();
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "LAndExp" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }
        }
    }
}
