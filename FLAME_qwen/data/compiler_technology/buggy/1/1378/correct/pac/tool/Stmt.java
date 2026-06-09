package pac.tool;

import java.io.PrintStream;

public class Stmt extends LabelList implements Label {
    public Stmt(Lex lex) {
        int pre = lex.getP();
        Label tmp;
        boolean flag = true;
        tmp = new LVal(lex);
        if (tmp.isErr() || lex.getFirst() != TOKEN.ASSIGN) {
            flag = false;
            lex.returnTo(pre);
        }
        if (flag) {
            addList(tmp);
            tmp = new Others(lex);
            addList(tmp);
            if (lex.getFirst() == TOKEN.GETINTTK || lex.getFirst() == TOKEN.GETCHARTK) {
                addList(new Others(lex));
                if (lex.getFirst() != TOKEN.LPARENT) {
                    lex.returnTo(pre);
                    err = true;
                    return;
                }
                tmp = new Others(lex);
                addList(tmp);
                if (lex.getFirst() != TOKEN.RPARENT) {
                    error.put(tmp.getLine(), 'j');
                } else {
                    tmp = new Others(lex);
                    addList(tmp);
                }
                if (lex.getFirst() != TOKEN.SEMICN) {
                    error.put(tmp.getLine(), 'i');
                } else {
                    tmp = new Others(lex);
                    addList(tmp);
                }
            } else {
                tmp = new Exp(lex);
                if (tmp.isErr()) {
                    lex.returnTo(pre);
                    err = true;
                    return;
                }
                addList(tmp);
                if (lex.getFirst() != TOKEN.SEMICN) {
                    error.put(tmp.getLine(), 'i');
                } else {
                    tmp = new Others(lex);
                    addList(tmp);
                }
            }
        } else if (lex.getFirst() == TOKEN.IFTK) {
            addList(new Others(lex));
            if (lex.getFirst() != TOKEN.LPARENT) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(new Others(lex));
            tmp = new Cond(lex);
            if (tmp.isErr()) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(tmp);
            if (lex.getFirst() != TOKEN.RPARENT) {
                error.put(tmp.getLine(), 'j');
            } else {
                addList(new Others(lex));
            }
            tmp = new Stmt(lex);
            if (tmp.isErr()) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(tmp);
            if (lex.getFirst() == TOKEN.ELSETK) {
                tmp = new Others(lex);
                Label tmp1 = new Stmt(lex);
                if (tmp1.isErr()) {
                    lex.pre();
                } else {
                    addList(tmp);
                    addList(tmp1);
                }
            }
        } else if (lex.getFirst() == TOKEN.FORTK) {
            addList(new Others(lex));
            if (lex.getFirst() != TOKEN.LPARENT) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(new Others(lex));
            tmp = new ForStmt(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
            addList(new Others(lex));
            tmp = new Cond(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
            addList(new Others(lex));
            tmp = new ForStmt(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
            if (lex.getFirst() != TOKEN.RPARENT) {
                error.put(line.get(line.size() - 1), 'j');
            } else {
                addList(new Others(lex));
            }
            tmp = new Stmt(lex);
            if (tmp.isErr()) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(tmp);
        } else if (lex.getFirst() == TOKEN.BREAKTK || lex.getFirst() == TOKEN.CONTINUETK) {
            addList(new Others(lex));
            if (lex.getFirst() != TOKEN.SEMICN) {
                error.put(line.get(line.size() - 1), 'i');
            } else {
                addList(new Others(lex));
            }
        } else if (lex.getFirst() == TOKEN.RETURNTK) {
            addList(new Others(lex));
            tmp = new Exp(lex);
            if (!tmp.isErr()) {
                addList(tmp);
            }
            if (lex.getFirst() != TOKEN.SEMICN) {
                error.put(line.get(line.size() - 1), 'i');
            } else {
                addList(new Others(lex));
            }
        } else if (lex.getFirst() == TOKEN.PRINTFTK) {
            addList(new Others(lex));
            if (lex.getFirst() != TOKEN.LPARENT) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(new Others(lex));
            if (lex.getFirst() != TOKEN.STRCON) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(new Others(lex));
            while (lex.getFirst() == TOKEN.COMMA) {
                tmp = new Others(lex);
                Label tmp1 = new Exp(lex);
                if (tmp1.isErr()) {
                    lex.pre();
                    break;
                }
                addList(tmp);
                addList(tmp1);
            }
            if (lex.getFirst() != TOKEN.RPARENT) {
                error.put(line.get(line.size() - 1), 'j');
            } else {
                addList(new Others(lex));
            }
            if (lex.getFirst() != TOKEN.SEMICN) {
                error.put(line.get(line.size() - 1), 'i');
            } else {
                addList(new Others(lex));
            }
        } else {
            tmp = new Block(lex);
            if (!tmp.isErr()) {
                addList(tmp);
                return;
            }
            tmp = new Exp(lex);
            if (!tmp.isErr()) {
                addList(tmp);
                if (lex.getFirst() != TOKEN.SEMICN) {
                    error.put(line.get(line.size() - 1), 'i');
                } else {
                    addList(new Others(lex));
                }
                return;
            }
            if (lex.getFirst() != TOKEN.SEMICN) {
                lex.returnTo(pre);
                err = true;
                return;
            }
            addList(new Others(lex));
        }
    }

    @Override
    public void print(PrintStream out) {
        for (Label val : list) {
            val.print(out);
        }
        out.println("<Stmt>");
    }
}
