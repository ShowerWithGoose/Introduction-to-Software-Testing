import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class EqExp extends Father {
    private ArrayList<Father> list;

    public EqExp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        RelExp relExp = new RelExp();
        p = relExp.parser(p,tokens);
        list.add(relExp);
        while (tokens.get(p).getCate().equals(Cate.EQL) || tokens.get(p).getCate().equals(Cate.NEQ)) {
            list.add(tokens.get(p));
            p++;
            relExp = new RelExp();
            p = relExp.parser(p,tokens);
            list.add(relExp);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof RelExp) {
                RelExp relExp = (RelExp) object;
                relExp.Print();
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "EqExp" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }
        }
    }
}
