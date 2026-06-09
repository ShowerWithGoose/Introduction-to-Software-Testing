import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Token extends Father {
    private String item;
    private Cate cate;
    private int lineNum;

    public Token(String item, Cate cate,int num) {
        this.item = item;
        this.cate = cate;
        this.lineNum = num;
    }

    public void Print() throws IOException {
        //System.out.println(cate + " " + item.toString());

        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write(cate + " " + item + '\n');
        if (cate.equals(Cate.INTCON)) {
            bufferedWriter.write('<' + "Number" + '>' + '\n');
        }
        if (cate.equals(Cate.CHRCON)) {
            bufferedWriter.write('<' + "Character" + '>' + '\n');
        }
        bufferedWriter.flush();
        bufferedWriter.close();
    }

    public Cate getCate() {
        return cate;
    }

    public boolean isMain() { return item.equals("main"); }

    public int getLineNum() { return lineNum; }
}
