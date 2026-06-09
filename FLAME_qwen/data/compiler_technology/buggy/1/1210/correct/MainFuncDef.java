import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MainFuncDef extends Father {
    private ArrayList<Father> list;

    public MainFuncDef() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        list.add(tokens.get(p));
        p++;
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
            list.add(tokens.get(p));
            p++;
        } else {
            //error
            ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'j');
            ERRORS.addError(error);
        }
        Block block = new Block();
        p = block.parser(p,tokens);
        list.add(block);
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof Block) {
                Block block = (Block) object;
                block.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "MainFuncDef" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
