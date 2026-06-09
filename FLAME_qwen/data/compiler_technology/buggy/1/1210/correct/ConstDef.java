import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstDef extends Father {
    private ArrayList<Father> list;

    public ConstDef() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.LBRACK)) {
            list.add(tokens.get(p));
            p++;
            ConstExp constExp = new ConstExp();
            p = constExp.parser(p,tokens);
            list.add(constExp);
            if (tokens.get(p).getCate().equals(Cate.RBRACK)) {
                list.add(tokens.get(p));
                p++;
            } else {
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'k');
                ERRORS.addError(error);
            }
        }
        list.add(tokens.get(p));
        p++;
        ConstInitVal constInitVal = new ConstInitVal();
        p = constInitVal.parser(p,tokens);
        list.add(constInitVal);
        return p;
    }

    public boolean isConstDef(int p, ArrayList<Token> tokensIn) {
        return tokensIn.get(p).getCate().equals(Cate.IDENFR);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof ConstExp) {
                ConstExp constExp = (ConstExp) object;
                constExp.Print();
            } else if (object instanceof ConstInitVal) {
                ConstInitVal constInitVal = (ConstInitVal) object;
                constInitVal.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "ConstDef" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
