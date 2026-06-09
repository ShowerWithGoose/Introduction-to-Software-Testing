import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Token {
    private String item;
    private Cate cate;

    public Token(String item, Cate cate) {
        this.item = item;
        this.cate = cate;
    }

    public void Print() throws IOException {
        //System.out.println(cate + " " + item.toString());

        FileWriter fileWriter = new FileWriter("lexer.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write(cate + " " + item + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
