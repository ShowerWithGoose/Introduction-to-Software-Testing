import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LVal extends Father {
    private ArrayList<Father> list;

    public LVal() {
        this.list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.LBRACK)) {
            list.add(tokens.get(p));
            p++;
            Exp exp = new Exp();
            p = exp.parser(p,tokens);
            list.add(exp);
            if (tokens.get(p).getCate().equals(Cate.RBRACK)) {
                list.add(tokens.get(p));
                p++;
            } else {
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'k');
                ERRORS.addError(error);
            }
        }
        return p;
    }

    public int tryParser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.LBRACK)) {
            list.add(tokens.get(p));
            p++;
            Exp exp = new Exp();
            p = exp.tryParser(p,tokens);
            list.add(exp);
            if (tokens.get(p).getCate().equals(Cate.RBRACK)) {
                list.add(tokens.get(p));
                p++;
            }
        }
        return p;
    }

    public boolean isLVal(int p, ArrayList<Token> tokens) {
        return tokens.get(p).getCate().equals(Cate.IDENFR) && !tokens.get(p+1).getCate().equals(Cate.LPARENT);
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
        bufferedWriter.write('<' + "LVal" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
