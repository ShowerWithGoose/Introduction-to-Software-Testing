import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDef extends Father {
    private ArrayList<Father> list;

    public VarDef() {
        this.list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        if (tokens.get(p).getCate().equals(Cate.LBRACK)) {
            list.add(tokens.get(p));
            p++;
            ConstExp constExp = new ConstExp();
            p = constExp.parser(p,tokens);
            list.add(constExp);
            if (tokens.get(p).getCate().equals(Cate.RBRACK)) {
                list.add(tokens.get(p));
                p++;
            } else {
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'k');
                ERRORS.addError(error);
            }
        }
        if (tokens.get(p).getCate().equals(Cate.ASSIGN)) {
            list.add(tokens.get(p));
            p++;
            InitVal initVal = new InitVal();
            p = initVal.parser(p,tokens);
            list.add(initVal);
        }
        return p;
    }

    public boolean isVarDef(int p, ArrayList<Token> tokens) {
        return tokens.get(p).getCate().equals(Cate.IDENFR);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof ConstExp) {
                ConstExp constExp = (ConstExp) object;
                constExp.Print();
            } else if (object instanceof InitVal) {
                InitVal initVal = (InitVal) object;
                initVal.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "VarDef" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
