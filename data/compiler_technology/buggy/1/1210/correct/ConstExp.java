import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstExp extends Father {
    private AddExp addExp;

    public ConstExp() {
        this.addExp = new AddExp();
    }

    public int parser(int p, ArrayList<Token> tokens) {
        p = addExp.parser(p,tokens);
        return p;
    }

    public void Print() throws IOException {
        addExp.Print();
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "ConstExp" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
