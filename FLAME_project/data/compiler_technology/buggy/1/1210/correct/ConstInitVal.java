import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstInitVal extends Father {
    private ArrayList<Father> list;

    public ConstInitVal() {
        this.list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        if (tokens.get(p).getCate().equals(Cate.LBRACE)) {
            list.add(tokens.get(p));
            p++;
            if (!tokens.get(p).getCate().equals(Cate.RBRACE)) {
                ConstExp constExp = new ConstExp();
                p = constExp.parser(p,tokens);
                list.add(constExp);
                while (tokens.get(p).getCate().equals(Cate.COMMA)) {
                    list.add(tokens.get(p));
                    p++;
                    constExp = new ConstExp();
                    p = constExp.parser(p,tokens);
                    list.add(constExp);
                }
            }
            list.add(tokens.get(p));
            p++;
        } else if (tokens.get(p).getCate().equals(Cate.STRCON)) {
            list.add(tokens.get(p));
            p++;
        } else {
            ConstExp constExp = new ConstExp();
            p = constExp.parser(p,tokens);
            list.add(constExp);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof ConstExp) {
                ConstExp constExp = (ConstExp) object;
                constExp.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "ConstInitVal" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
