import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class PrimaryExp extends Father {
    private ArrayList<Father> list;

    public PrimaryExp() {
        list = new ArrayList<>();
    }

    public int parser(int p, ArrayList<Token> tokens) {
        if (tokens.get(p).getCate().equals(Cate.LPARENT)) {
            list.add(tokens.get(p));
            p++;
            Exp exp = new Exp();
            p = exp.parser(p, tokens);
            list.add(exp);
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            } else {
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'j');
                ERRORS.addError(error);
            }
        } else if (new LVal().isLVal(p, tokens)) {
            LVal lval = new LVal();
            p = lval.parser(p, tokens);
            list.add(lval);
        } else if (tokens.get(p).getCate().equals(Cate.INTCON) || tokens.get(p).getCate().equals(Cate.CHRCON)) {
            list.add(tokens.get(p));
            p++;
        }
        return p;
    }

    public int tryParser(int p, ArrayList<Token> tokens) {
        if (tokens.get(p).getCate().equals(Cate.LPARENT)) {
            list.add(tokens.get(p));
            p++;
            Exp exp = new Exp();
            p = exp.tryParser(p, tokens);
            list.add(exp);
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            }
        } else if (new LVal().isLVal(p, tokens)) {
            LVal lval = new LVal();
            p = lval.tryParser(p, tokens);
            list.add(lval);
        } else if (tokens.get(p).getCate().equals(Cate.INTCON) || tokens.get(p).getCate().equals(Cate.CHRCON)) {
            list.add(tokens.get(p));
            p++;
        }
        return p;
    }

    public boolean isPrimaryExp(int p, ArrayList<Token> tokens) {
        return tokens.get(p).getCate().equals(Cate.LPARENT)
                || new LVal().isLVal(p, tokens)
                || tokens.get(p).getCate().equals(Cate.INTCON)
                || tokens.get(p).getCate().equals(Cate.CHRCON);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof Exp) {
                Exp exp = (Exp) object;
                exp.Print();
            } else if (object instanceof LVal) {
                LVal lVal = (LVal) object;
                lVal.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "PrimaryExp" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
