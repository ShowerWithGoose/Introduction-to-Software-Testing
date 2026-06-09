import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Exp extends Father {
    private ArrayList<Father> list;

    public Exp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        AddExp addExp = new AddExp();
        p = addExp.parser(p,tokens);
        list.add(addExp);
        return p;
    }

    public int tryParser(int p,ArrayList<Token> tokens) {
        AddExp addExp = new AddExp();
        p = addExp.tryParser(p,tokens);
        list.add(addExp);
        return p;
    }

    public boolean isExp(int p,ArrayList<Token> tokens) {
        return new AddExp().isAddExp(p,tokens);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof AddExp) {
                AddExp addExp = (AddExp) object;
                addExp.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "Exp" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
