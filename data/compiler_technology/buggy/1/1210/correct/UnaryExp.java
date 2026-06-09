import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UnaryExp extends Father {
    private ArrayList<Father> list;

    public UnaryExp() {
        list = new ArrayList<>();
    }

    public int parser(int p, ArrayList<Token> tokens) {
        if (new PrimaryExp().isPrimaryExp(p, tokens)) {
            PrimaryExp primaryExp = new PrimaryExp();
            p = primaryExp.parser(p, tokens);
            list.add(primaryExp);
        } else if (tokens.get(p).getCate().equals(Cate.IDENFR) && tokens.get(p+1).getCate().equals(Cate.LPARENT)) {
            list.add(tokens.get(p));
            p++;
            list.add(tokens.get(p));
            p++;
            if (new FuncRParams().isFuncRParams(p,tokens)) {
                FuncRParams funcRParams = new FuncRParams();
                p = funcRParams.parser(p,tokens);
                list.add(funcRParams);
                while (tokens.get(p).getCate().equals(Cate.COMMA)) {
                    list.add(tokens.get(p));
                    p++;
                    funcRParams = new FuncRParams();
                    p = funcRParams.parser(p,tokens);
                    list.add(funcRParams);
                }
            }
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            } else {
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'j');
                ERRORS.addError(error);
            }
        } else if (new UnaryOp().isUnaryOp(p, tokens)) {
            UnaryOp unaryOp = new UnaryOp();
            p = unaryOp.parser(p, tokens);
            list.add(unaryOp);
            UnaryExp unaryExp = new UnaryExp();
            p = unaryExp.parser(p, tokens);
            list.add(unaryExp);
        }
        return p;
    }

    public int tryParser(int p, ArrayList<Token> tokens) {
        if (new PrimaryExp().isPrimaryExp(p, tokens)) {
            PrimaryExp primaryExp = new PrimaryExp();
            p = primaryExp.tryParser(p, tokens);
            list.add(primaryExp);
        } else if (tokens.get(p).getCate().equals(Cate.IDENFR) && tokens.get(p+1).getCate().equals(Cate.LPARENT)) {
            list.add(tokens.get(p));
            p++;
            list.add(tokens.get(p));
            p++;
            if (new FuncRParams().isFuncRParams(p,tokens)) {
                FuncRParams funcRParams = new FuncRParams();
                p = funcRParams.tryParser(p,tokens);
                list.add(funcRParams);
                while (tokens.get(p).getCate().equals(Cate.COMMA)) {
                    list.add(tokens.get(p));
                    p++;
                    funcRParams = new FuncRParams();
                    p = funcRParams.tryParser(p,tokens);
                    list.add(funcRParams);
                }
            }
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            }
        } else if (new UnaryOp().isUnaryOp(p, tokens)) {
            UnaryOp unaryOp = new UnaryOp();
            p = unaryOp.parser(p, tokens);
            list.add(unaryOp);
            UnaryExp unaryExp = new UnaryExp();
            p = unaryExp.tryParser(p, tokens);
            list.add(unaryExp);
        }
        return p;
    }

    public boolean isUnaryExp(int p,ArrayList<Token> tokens) {
        return new PrimaryExp().isPrimaryExp(p, tokens)
                || (tokens.get(p).getCate().equals(Cate.IDENFR) && tokens.get(p+1).getCate().equals(Cate.LPARENT))
                || new UnaryOp().isUnaryOp(p, tokens);
    }

    public void Print() throws IOException {
        for (Father object : list) {
            if (object instanceof Token) {
                Token token = (Token) object;
                token.Print();
            } else if (object instanceof PrimaryExp) {
                PrimaryExp primaryExp = (PrimaryExp) object;
                primaryExp.Print();
            } else if (object instanceof FuncRParams) {
                FuncRParams funcRParams = (FuncRParams) object;
                funcRParams.Print();
            } else if (object instanceof UnaryOp) {
                UnaryOp unaryOp = (UnaryOp) object;
                unaryOp.Print();
            } else if (object instanceof UnaryExp) {
                UnaryExp unaryExp = (UnaryExp) object;
                unaryExp.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "UnaryExp" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
