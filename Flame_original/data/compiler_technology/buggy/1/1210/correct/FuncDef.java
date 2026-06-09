import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncDef extends Father {
    private ArrayList<Father> list;

    public FuncDef() {
        this.list = new ArrayList<>();
    }

    public int parser(int p, ArrayList<Token> tokens) {
        /*list.add(tokens.get(p));
        p++;*/
        FuncType funcType = new FuncType();
        funcType.setToken(tokens.get(p));
        list.add(funcType);
        p++;
        list.add(tokens.get(p));
        p++;
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
            list.add(tokens.get(p));
            p++;
        } else if (tokens.get(p).getCate().equals(Cate.LBRACE)) {
            //error
            ERROR error = new ERROR(tokens.get(p - 1).getLineNum(), 'j');
            ERRORS.addError(error);
        } else {
            FuncFParams funcFParams = new FuncFParams();
            p = funcFParams.parser(p, tokens);
            list.add(funcFParams);
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            } else {
                ERROR error = new ERROR(tokens.get(p - 1).getLineNum(), 'j');
                ERRORS.addError(error);
            }
        }
        Block block = new Block();
        p = block.parser(p, tokens);
        list.add(block);
        return p;
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof FuncFParams) {
                FuncFParams funcFParams = (FuncFParams) object;
                funcFParams.Print();
            } else if (object instanceof Block) {
                Block block = (Block) object;
                block.Print();
            } else if (object instanceof FuncType) {
                FuncType funcType = (FuncType) object;
                funcType.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "FuncDef" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
