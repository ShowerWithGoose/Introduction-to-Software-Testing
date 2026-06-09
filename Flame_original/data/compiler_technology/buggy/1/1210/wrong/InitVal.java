import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class InitVal extends Father {
    private ArrayList<Father> list;

    public InitVal() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        if (tokens.get(p).getCate().equals(Cate.STRCON)) {
            list.add(tokens.get(p));
            p++;
        } else if (tokens.get(p).getCate().equals(Cate.LBRACE)) {
            list.add(tokens.get(p));
            p++;
            if (!tokens.get(p).getCate().equals(Cate.RBRACE)) {
                Exp exp = new Exp();
                p = exp.parser(p,tokens);
                list.add(exp);
                while(tokens.get(p).getCate().equals(Cate.COMMA)) {
                    list.add(tokens.get(p));
                    p++;
                    exp = new Exp();
                    p = exp.parser(p,tokens);
                    list.add(exp);
                }
            }
            list.add(tokens.get(p));
            p++;
        } else {
            Exp exp = new Exp();
            p = exp.parser(p,tokens);
            list.add(exp);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof Exp) {
                Exp exp = (Exp) object;
                exp.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "InitVal" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
