import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UnaryOp extends Father {
    private Token op;

    public UnaryOp() {
        op = null;
    }

    public int parser(int p, ArrayList<Token> tokens) {
        op = tokens.get(p);
        p++;
        return p;
    }

    public boolean isUnaryOp(int p, ArrayList<Token> tokens) {
        return tokens.get(p).getCate().equals(Cate.PLUS)
                || tokens.get(p).getCate().equals(Cate.MINU)
                || tokens.get(p).getCate().equals(Cate.NOT);
    }

    public void Print() throws IOException {
        op.Print();
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "UnaryOp" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
