import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstDecl extends Father {
    private ArrayList<Father> list;

    public ConstDecl() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        list.add(tokens.get(p));
        p++;
        list.add(tokens.get(p));
        p++;
        ConstDef constDef = new ConstDef();
        p = constDef.parser(p,tokens);
        list.add(constDef);
        while (tokens.get(p).getCate().equals(Cate.COMMA)) {
            list.add(tokens.get(p));
            p++;
            constDef = new ConstDef();
            p = constDef.parser(p,tokens);
            list.add(constDef);
        }
        if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
            list.add(tokens.get(p));
            p++;
        } else {
            //error_i
            System.out.println(tokens.get(p).getCate());
            ERROR error = new ERROR(tokens.get(p - 1).getLineNum(),'i');
            ERRORS.addError(error);
        }
        return p;
    }

    public boolean isConstDecl(int p, ArrayList<Token> tokensIn) {
        return tokensIn.get(p).getCate().equals(Cate.CONSTTK) && (tokensIn.get(p + 1).getCate().equals(Cate.INTTK) ||
                tokensIn.get(p + 1).getCate().equals(Cate.CHARTK)) && new ConstDef().isConstDef(p + 2, tokensIn);
    }


    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof ConstDef) {
                ConstDef constDef = (ConstDef) object;
                constDef.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "ConstDecl" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
