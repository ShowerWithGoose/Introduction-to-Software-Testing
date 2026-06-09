import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LOrExp extends Father {
    private ArrayList<Father> list;

    public LOrExp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        LAndExp lAndExp = new LAndExp();
        p = lAndExp.parser(p,tokens);
        list.add(lAndExp);
        while (tokens.get(p).getCate().equals(Cate.OR)) {
            list.add(tokens.get(p));
            p++;
            lAndExp = new LAndExp();
            p = lAndExp.parser(p,tokens);
            list.add(lAndExp);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof LAndExp) {
                LAndExp lAndExp = (LAndExp) object;
                lAndExp.Print();
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "LOrExp" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }
        }
    }
}
