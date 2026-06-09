import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncFParam extends Father {
    private ArrayList<Father> list;

    public FuncFParam() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.LBRACK)) {
            list.add(tokens.get(p));
            p++;
            if (tokens.get(p).getCate().equals(Cate.RBRACK)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'k');
                ERRORS.addError(error);
            }
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "FuncFParam" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
