import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Stmt extends Father {
    private ArrayList<Father> list;

    public Stmt() {
        list = new ArrayList<>();
    }

    public int parser(int p,ArrayList<Token> tokens) {
        if (tokens.get(p).getCate().equals(Cate.LBRACE)) {
            Block block = new Block();
            p = block.parser(p,tokens);
            list.add(block);
        } else if (tokens.get(p).getCate().equals(Cate.IFTK)) {
            list.add(tokens.get(p));
            p++;
            list.add(tokens.get(p));
            p++;
            Cond cond = new Cond();
            p = cond.parser(p,tokens);
            list.add(cond);
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'j');
                ERRORS.addError(error);
            }
            Stmt stmt = new Stmt();
            p = stmt.parser(p,tokens);
            list.add(stmt);
            if (tokens.get(p).getCate().equals(Cate.ELSETK)) {
                list.add(tokens.get(p));
                p++;
                stmt = new Stmt();
                p = stmt.parser(p,tokens);
                list.add(stmt);
            }
        } else if (tokens.get(p).getCate().equals(Cate.FORTK)) {
            list.add(tokens.get(p));
            p++;
            list.add(tokens.get(p));
            p++;
            ForStmt forStmt;
            if (!tokens.get(p).getCate().equals(Cate.SEMICN)) {
                forStmt = new ForStmt();
                p = forStmt.parser(p,tokens);
                list.add(forStmt);
            }
            list.add(tokens.get(p));
            p++;
            if (!tokens.get(p).getCate().equals(Cate.SEMICN)) {
                Cond cond = new Cond();
                p = cond.parser(p,tokens);
                list.add(cond);
            }
            list.add(tokens.get(p));
            p++;
            if (!tokens.get(p).getCate().equals(Cate.RPARENT)) {
                forStmt = new ForStmt();
                p = forStmt.parser(p,tokens);
                list.add(forStmt);
            }
            list.add(tokens.get(p));
            p++;
            Stmt stmt = new Stmt();
            p = stmt.parser(p,tokens);
            list.add(stmt);
        } else if (tokens.get(p).getCate().equals(Cate.BREAKTK)
                || tokens.get(p).getCate().equals(Cate.CONTINUETK)) {
            list.add(tokens.get(p));
            p++;
            if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                System.out.println("break&continue_i");
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'i');
                ERRORS.addError(error);
            }
        } else if (tokens.get(p).getCate().equals(Cate.RETURNTK)) {
            list.add(tokens.get(p));
            p++;
            if (new Exp().isExp(p,tokens)) {
                Exp exp = new Exp();
                p = exp.parser(p,tokens);
                list.add(exp);
            }
            if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                System.out.println("return_i");
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'i');
                ERRORS.addError(error);
            }
        } else if (tokens.get(p).getCate().equals(Cate.PRINTFTK)) {
            list.add(tokens.get(p));
            p++;
            list.add(tokens.get(p));
            p++;
            list.add(tokens.get(p));
            p++;
            Exp exp;
            while (tokens.get(p).getCate().equals(Cate.COMMA)) {
                list.add(tokens.get(p));
                p++;
                exp = new Exp();
                p = exp.parser(p,tokens);
                list.add(exp);
            }
            if (tokens.get(p).getCate().equals(Cate.RPARENT)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'j');
                ERRORS.addError(error);
            }
            if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                System.out.println("print_i");
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'i');
                ERRORS.addError(error);
            }
        } else if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
            list.add(tokens.get(p));
            p++;
        }
        else {
            int q = p;
            Exp exp = new Exp();
            p = exp.tryParser(p,tokens);
            if (tokens.get(p).getCate().equals(Cate.ASSIGN)) {
                p = q;
                LVal lVal = new LVal();
                p = lVal.parser(p,tokens);
                list.add(lVal);
                list.add(tokens.get(p));
                p++;
                if (tokens.get(p).getCate().equals(Cate.GETINTTK)
                        || tokens.get(p).getCate().equals(Cate.GETCHARTK)) {
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
                }
                else {
                    exp = new Exp();
                    p = exp.parser(p,tokens);
                    list.add(exp);
                }
            } else {
                p = q;
                exp = new Exp();
                p = exp.parser(p,tokens);
                list.add(exp);
            }
            if (tokens.get(p).getCate().equals(Cate.SEMICN)) {
                list.add(tokens.get(p));
                p++;
            } else {
                //error
                System.out.println("exp_i");
                ERROR error = new ERROR(tokens.get(p-1).getLineNum(),'i');
                ERRORS.addError(error);
            }
        }
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
            } else if (object instanceof Cond) {
                Cond cond = (Cond) object;
                cond.Print();
            } else if (object instanceof Stmt) {
                Stmt stmt = (Stmt) object;
                stmt.Print();
            } else if (object instanceof ForStmt) {
                ForStmt forStmt = (ForStmt) object;
                forStmt.Print();
            }  else if (object instanceof Exp) {
                Exp exp = (Exp) object;
                exp.Print();
            } else if (object instanceof LVal) {
                LVal lVal = (LVal) object;
                lVal.Print();
            }
        }
        FileWriter fileWriter = new FileWriter("parser.txt", true);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
        bufferedWriter.write('<' + "Stmt" + '>' + '\n');
        bufferedWriter.flush();
        bufferedWriter.close();
    }
}
