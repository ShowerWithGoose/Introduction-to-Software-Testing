package parse;

public class Stmt implements BlockItemEle {
    private final String name = "<Stmt>";
    private StmtEle stmtEle;

    public String getName() {
        return name;
    }

    public StmtEle getStmtEle() {
        return stmtEle;
    }

    public void setStmtEle(StmtEle stmtEle) {
        this.stmtEle = stmtEle;
    }

    public Stmt(TokenList list,WrongList wrongs) {
        Token x = list.readNextToken();
        switch (x.getType()) {
            case "IFTK":
                list.unReadToken(1);
                this.stmtEle = new StmtCond(list,wrongs);
                break;
            case "FORTK":
                list.unReadToken(1);
                this.stmtEle = new StmtFor(list,wrongs);
                break;
            case "BREAKTK":
                list.unReadToken(1);
                this.stmtEle = new StmtBreak(list,wrongs);
                break;
            case "CONTINUETK":
                list.unReadToken(1);
                this.stmtEle = new StmtContinue(list,wrongs);
                break;
            case "RETURNTK":
                list.unReadToken(1);
                this.stmtEle = new StmtReturn(list,wrongs);
                break;
            case "PRINTFTK":
                list.unReadToken(1);
                this.stmtEle = new StmtPrint(list,wrongs);
                break;
            case "SEMICN":
                list.unReadToken(1);
                this.stmtEle = new StmtNull(list,wrongs);
                break;
            case "IDENFR":
                int cnt = 1;
                int flag1 = 0;
                boolean flag2 = false;
                Token token = x;
                while (!token.getType().equals("SEMICN")) {
                    token = list.readNextToken();
                    cnt += 1;
                    if (token.getType().equals("ASSIGN")) {
                        flag2 = true;
                    }
                    if (token.getType().equals("GETINTTK")||token.getType().equals("GETCHARTK")) {
                        flag1 = 1;
                    }
                }
                list.unReadToken(cnt);
                if (flag2) {
                    if (flag1 == 0) {
                        this.stmtEle = new StmtAssign(list,wrongs);
                    } else if (flag1 == 1) {
                        this.stmtEle = new StmtGet(list,wrongs);
                    }
                } else {
                    this.stmtEle = new StmtExp(list,wrongs);
                }
                break;
            case "LBRACE":
                list.unReadToken(1);
                this.stmtEle = new Block(list,wrongs);
                break;
            case "LPARENT": case "CHRCON": case "INTCON": case "PLUS": case "MINU":
                list.unReadToken(1);
                this.stmtEle = new StmtExp(list,wrongs);
                break;
            default:
        }
    }

    @Override
    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.stmtEle.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
