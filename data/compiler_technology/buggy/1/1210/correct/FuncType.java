import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class FuncType extends Father{
    private Token token;

    public FuncType() {}

    public void setToken(Token tokenIn) {
        this.token = tokenIn;
    }
    public void Print() throws IOException {
        token.Print();
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "FuncType" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
