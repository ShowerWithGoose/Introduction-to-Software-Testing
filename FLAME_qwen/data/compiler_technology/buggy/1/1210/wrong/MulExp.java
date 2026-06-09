import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MulExp extends Father {
    private ArrayList<Father> list;

    public MulExp() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        UnaryExp unaryExp = new UnaryExp();
        p = unaryExp.parser(p, tokens);
        list.add(unaryExp);
        while (tokens.get(p).getCate().equals(Cate.MULT) || tokens.get(p).getCate().equals(Cate.DIV) ||
        tokens.get(p).getCate().equals(Cate.MOD)) {
            list.add(tokens.get(p));
            p++;
            unaryExp = new UnaryExp();
            p = unaryExp.parser(p, tokens);
            list.add(unaryExp);
        }
        return p;
    }

    public int tryParser(int p,ArrayList<Token> tokens) {
        UnaryExp unaryExp = new UnaryExp();
        p = unaryExp.tryParser(p, tokens);
        list.add(unaryExp);
        while (tokens.get(p).getCate().equals(Cate.MULT) || tokens.get(p).getCate().equals(Cate.DIV) ||
                tokens.get(p).getCate().equals(Cate.MOD)) {
            list.add(tokens.get(p));
            p++;
            unaryExp = new UnaryExp();
            p = unaryExp.tryParser(p, tokens);
            list.add(unaryExp);
        }
        return p;
    }

    public boolean isMulExp(int p,ArrayList<Token> tokens) {
        return new UnaryExp().isUnaryExp(p,tokens);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof UnaryExp) {
                UnaryExp unaryExp = (UnaryExp) object;
                unaryExp.Print();
                FileWriter fileWriter = new FileWriter("parser.txt", true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
                bufferedWriter.write('<' + "MulExp" + '>' + '\n');
                bufferedWriter.flush();
                bufferedWriter.close();
            }
        }
    }
}
