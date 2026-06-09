import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class AddExp extends Father {
    private ArrayList<Father> list;

    public AddExp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        MulExp mulExp = new MulExp();
        p = mulExp.parser(p, tokens);
        list.add(mulExp);
        while (tokens.get(p).getCate().equals(Cate.PLUS) || tokens.get(p).getCate().equals(Cate.MINU)) {
            list.add(tokens.get(p));
            p++;
            mulExp = new MulExp();
            p = mulExp.parser(p, tokens);
            list.add(mulExp);
        }
        return p;
    }

    public int tryParser(int p,ArrayList<Token> tokens) {
        MulExp mulExp = new MulExp();
        p = mulExp.tryParser(p, tokens);
        list.add(mulExp);
        while (tokens.get(p).getCate().equals(Cate.PLUS) || tokens.get(p).getCate().equals(Cate.MINU)) {
            list.add(tokens.get(p));
            p++;
            mulExp = new MulExp();
            p = mulExp.tryParser(p, tokens);
            list.add(mulExp);
        }
        return p;
    }

    public boolean isAddExp(int p,ArrayList<Token> tokens) {
        return new MulExp().isMulExp(p,tokens);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof MulExp) {
                MulExp mulExp = (MulExp) object;
                mulExp.Print();
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "AddExp" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }
        }
    }
}
