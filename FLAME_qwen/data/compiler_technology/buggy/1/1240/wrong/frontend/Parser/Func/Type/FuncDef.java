package frontend.Parser.Func.Type;

import frontend.Lexer.LexType;
import frontend.Parser.Stmt.Type.BlockStmt;

import java.util.ArrayList;

public class FuncDef {
    // FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block
    private final LexType funcType;
    private final LexType ident;
    private final LexType left;
    private final LexType right;
    private final ArrayList<FuncFParam> funcFParams;
    private final ArrayList<LexType> seps;
    private final BlockStmt blockStmt;

    public FuncDef(LexType funcType, LexType ident, LexType left, ArrayList<FuncFParam> funcFParams,
                   LexType right, BlockStmt blockStmt, ArrayList<LexType> seps) {
        this.funcType = funcType;
        this.ident = ident;
        this.left = left;
        this.funcFParams = funcFParams;
        this.right = right;
        this.blockStmt = blockStmt;
        this.seps = seps;
    }

    public String print(boolean isMain) {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType);
        if (!isMain) {
            sb.append("<FuncType>\n");
        }
        sb.append(ident).append(left);
        if (!funcFParams.isEmpty()) {
            sb.append(funcFParams.get(0));
            int index = 1;
            for (LexType sep : seps) {
                sb.append(sep).append(funcFParams.get(index++));
            }
            sb.append("<FuncFParams>\n");
        }
        sb.append(right).append(blockStmt);
        return sb.toString();
    }

    @Override
    public String toString() {
        return print(false) + "<FuncDef>\n";
    }
}
