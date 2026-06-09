import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncFParams extends Father {
    private ArrayList<Father> list;

    public FuncFParams() {
        this.list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        FuncFParam funcFParam = new FuncFParam();
        p = funcFParam.parser(p, tokens);
        list.add(funcFParam);
        while (tokens.get(p).getCate().equals(Cate.COMMA)) {
            list.add(tokens.get(p));
            p++;
            funcFParam = new FuncFParam();
            p = funcFParam.parser(p, tokens);
            list.add(funcFParam);
        }
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof FuncFParam) {
                FuncFParam funcFParam = (FuncFParam) object;
                funcFParam.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "FuncFParams" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
