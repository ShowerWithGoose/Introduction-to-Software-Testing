import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class RelExp extends Father {
    private ArrayList<Father> list;

    public RelExp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        AddExp addExp = new AddExp();
        p = addExp.parser(p,tokens);
        list.add(addExp);
        while (tokens.get(p).getCate().equals(Cate.LSS)
                || tokens.get(p).getCate().equals(Cate.LEQ)
                || tokens.get(p).getCate().equals(Cate.GRE)
                || tokens.get(p).getCate().equals(Cate.GEQ)) {
            list.add(tokens.get(p));
            p++;
            addExp = new AddExp();
            p = addExp.parser(p,tokens);
            list.add(addExp);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof AddExp) {
                AddExp addExp = (AddExp) object;
                addExp.Print();
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "RelExp" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }
        }
    }
}
