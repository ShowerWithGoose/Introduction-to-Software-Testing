import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncRParams extends Father {
    private ArrayList<Father> list;

    public FuncRParams() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        Exp exp = new Exp();
        p = exp.parser(p,tokens);
        list.add(exp);
        while (tokens.get(p).getCate().equals(Cate.COMMA)) {
            list.add(tokens.get(p));
            p++;
            exp = new Exp();
            p = exp.parser(p,tokens);
            list.add(exp);
        }
        return p;
    }

    public int tryParser(int p,ArrayList<Token> tokens) {
        Exp exp = new Exp();
        p = exp.tryParser(p,tokens);
        list.add(exp);
        while (tokens.get(p).getCate().equals(Cate.COMMA)) {
            list.add(tokens.get(p));
            p++;
            exp = new Exp();
            p = exp.tryParser(p,tokens);
            list.add(exp);
        }
        return p;
    }

    public boolean isFuncRParams(int p,ArrayList<Token> tokens) {
        return !tokens.get(p).getCate().equals(Cate.RPARENT);
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
        bufferedWriter.write('<' + "FuncRParams" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
