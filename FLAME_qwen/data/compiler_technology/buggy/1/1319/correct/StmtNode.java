import java.io.IOException;
import java.util.List;

public class StmtNode extends ASTNode{
    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return null;
    }
}

class AssignStmt extends StmtNode{
    private LValNode lval;
    private ExpNode exp;

    public AssignStmt (LValNode lval, ExpNode exp){
        this.lval = lval;
        this.exp = exp;
    }

    public ExpNode getExp() {
        return exp;
    }

    public LValNode getLval() {
        return lval;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitAssignStmt(this);
    }
}

class ExpStmt extends StmtNode{
    private ExpNode exp;
    public ExpStmt (ExpNode exp){
        this.exp = exp;
    }

    public ExpNode getExp() {
        return exp;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitExpStmt(this);
    }
}

class BlockStmt extends StmtNode{
    private BlockNode block;
    public BlockStmt (BlockNode block){
        this.block = block;
    }

    public BlockNode getBlock() {
        return block;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitBlockStmt(this);
    }
}

class IfStmt extends StmtNode{
    private CondNode cond;
    private StmtNode stmtNode1, stmtNode2;

    public IfStmt (CondNode cond, StmtNode stmtNode1, StmtNode stmtNode2){
        this.cond = cond;
        this.stmtNode1 = stmtNode1;
        this.stmtNode2 = stmtNode2;
    }

    public StmtNode getStmtNode1() {
        return stmtNode1;
    }

    public StmtNode getStmtNode2() {
        return stmtNode2;
    }

    public CondNode getCond() {
        return cond;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitIfStmt(this);
    }
}

class ForStmt extends StmtNode{
    private ForStmtNode forStmt;
    private CondNode cond;
    private ForStmtNode forStmt2;
    private StmtNode stmt;

    public ForStmt(ForStmtNode forStmt, CondNode cond, ForStmtNode forStmt2, StmtNode stmt){
        this.cond = cond;
        this.forStmt = forStmt;
        this.forStmt2 = forStmt2;
        this.stmt = stmt;
    }

    public ForStmtNode getForStmt() {
        return forStmt;
    }

    public ForStmtNode getForStmt2() {
        return forStmt2;
    }

    public CondNode getCond() {
        return cond;
    }

    public StmtNode getStmt() {
        return stmt;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitFORStmt(this);
    }
}

class BreakStmt extends StmtNode{
    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitBreakStmt(this);
    }
}

class ContinueStmt extends StmtNode{
    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitContinueStmt(this);
    }
}

class ReturnStmt extends StmtNode{
    private ExpNode exp;
    public ReturnStmt (ExpNode exp){
        this.exp = exp;
    }

    public ExpNode getExp() {
        return exp;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitRenturnStmt(this);
    }
}

class IntStmt extends StmtNode{
    private LValNode lval;

    public IntStmt(LValNode lval){
        this.lval =lval;
    }

    public LValNode getLval() {
        return lval;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitIntStmt(this);
    }
}

class CharStmt extends StmtNode{
    private LValNode lval;

    public CharStmt(LValNode lval){
        this.lval =lval;
    }

    public LValNode getLval() {
        return lval;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitCharStmt(this);
    }
}

class PrintStmt extends StmtNode{
    private String string;

    private List<ExpNode> expNodes;

    public PrintStmt(String string, List<ExpNode> expNodes) {
        this.string =string;
        this.expNodes = expNodes;
    }

    public String getString() {
        return string;
    }

    public List<ExpNode> getExpNodes() {
        return expNodes;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitPrintStmt(this);
    }
}