package frontend;

import java.util.ArrayList;

public class Stmt implements BlockItem {
    // LVal '=' Exp ';' // i
    //| [Exp] ';' // i
    //| Block
    //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    //| 'break' ';' | 'continue' ';' // i
    //| 'return' [Exp] ';' // i
    //| LVal '=' 'getint''('')'';' // i j
    //| LVal '=' 'getchar''('')'';' // i j
    //| 'printf''('StringConst {','Exp}')'';' // i j
    private int leibie; //1-10
    private int wrong = 0;
    private LVal lval;
    private ArrayList<Exp> exps = new ArrayList<>();
    private Block block;
    private ArrayList<Stmt> stmts = new ArrayList<>();
    private Cond cond;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private ArrayList<Word> words = new ArrayList<>();

    public Stmt() {
        forStmt1 = null;
        forStmt2 = null;
        cond = null;
    }

    public void setLeibie(int leibie) {
        this.leibie = leibie;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void addStmt(Stmt stmt) {
        stmts.add(stmt);
    }

    public void setForStmt1(ForStmt forStmt1) {
        this.forStmt1 = forStmt1;
    }

    public void setForStmt2(ForStmt forStmt2) {
        this.forStmt2 = forStmt2;
    }

    public void addExp(Exp exp) {
        exps.add(exp);
    }

    public void setLval(LVal lval) {
        this.lval = lval;
    }

    public void clearExp() {
        this.exps = new ArrayList<>();
    }

    public void setWrong(int wrong) { //是否会出现同时出现i，j的情况
        this.wrong = wrong;
        if (leibie == 1 || leibie == 2) {
            exps.get(0).setWordWrong(-1);
        } else if (leibie == 4) {
            cond.setWordWrong(-2);
        } else if (leibie == 6) {
            words.get(0).setRight(-1);
        } else if (leibie == 7) {
            if (exps.isEmpty()) {
                words.get(0).setRight(-1);
            } else {
                exps.get(0).setWordWrong(-1);
            }
        } else if (leibie == 8 || leibie == 9) {
            if (wrong == 1) {
                words.get(3).setRight(-1);
            } else {
                words.get(2).setRight(-2);
            }
        } else if (leibie == 10) {
            if (wrong == 1) {
                words.get(words.size() - 1).setRight(-1);
            } else {
                if (!exps.isEmpty()) {
                    exps.get(exps.size() - 1).setWordWrong(-2);
                } else {
                    words.get(2).setRight(-2);
                }
            }
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        if (leibie == 1) {
            sb.append(lval.toString());
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(exps.get(0).toString());
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        } else if (leibie == 2) {
            if (!exps.isEmpty()) {
                sb.append(exps.get(pos).toString());
            }
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        } else if (leibie == 3) {
            sb.append(block.toString());
        } else if (leibie == 4) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(cond.toString());
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
            sb.append(stmts.get(0).toString());
            if (stmts.size() == 2) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
                sb.append(stmts.get(1).toString());
            }
        } else if (leibie == 5) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (forStmt1 != null) {
                sb.append(forStmt1.toString());
            }
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (cond != null) {
                sb.append(cond.toString());
            }
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (forStmt2 != null) {
                sb.append(forStmt2.toString());
            }
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(stmts.get(0).toString());
        } else if (leibie == 6) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        } else if (leibie == 7) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (!exps.isEmpty()) {
                sb.append(exps.get(0).toString());
            }
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        } else if (leibie == 8 || leibie == 9) {
            sb.append(lval.toString());
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (wrong == 0) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            }
        } else if (leibie == 10) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            for (;pos < words.size();pos++) {
                sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos).getStr()).append("\n");
                if ((pos - 3) < exps.size()) {
                    sb.append(exps.get(pos - 3).toString());
                }
            }
        }
        sb.append("<Stmt>");
        sb.append("\n");
        return sb.toString();
    }
}
