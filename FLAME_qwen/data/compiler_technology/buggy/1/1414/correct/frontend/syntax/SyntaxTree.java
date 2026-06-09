package frontend.syntax;

import frontend.lexer.TokenType;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class SyntaxTree {
    public interface CompileUnit {
    }

    public interface Declaration extends BlockItem {
    }

    public interface Statement extends BlockItem {
    }

    public interface BlockItem extends CompileUnit {}

    public static class Block implements Statement {
        private List<BlockItem> items;
        public Block(List<BlockItem> items) {
            this.items = items;
        }
    }

    public static class FuncDecl implements Declaration {
        private final String name;
        private final List<FuncParamDecl> params;
        private final TokenType returnType;
        private final Block body;
        public FuncDecl(String name, List<FuncParamDecl> params, TokenType returnType, Block body) {
            this.name = name;
            this.params = params;
            this.returnType = returnType;
            this.body = body;
        }
    }

    public static class VarDef implements CompileUnit {
        private final String name;
        private final TokenType type;
        private final InitValue value;
        private final AddExpr index;
        public VarDef(String name, TokenType type, AddExpr index) {
            this.name = name;
            this.type = type;
            this.value = null;
            this.index = index;
        }
        public VarDef(String name, TokenType type, AddExpr index, InitValue value) {
            this.name = name;
            this.type = type;
            this.index = index;
            this.value = value;
        }
    }

    public static class VarDecl implements Declaration {
        private boolean isConst;
        private TokenType type;
        private List<VarDef> vars;
        public VarDecl(boolean isConst, TokenType type, List<VarDef> vars) {
            this.isConst = isConst;
            this.type = type;
            this.vars = vars;
        }
    }

    public interface ConstDecl extends Declaration {}

    public static class IntNum implements CompileUnit {
        private BigInteger value;
        public IntNum(BigInteger value) {
            this.value = value;
        }
    }

    public static class CharNum implements CompileUnit {
        private Character value;
        public CharNum(Character value) {
            this.value = value;
        }
    }

    public static class PrimaryExpr implements CompileUnit {
        Object value;
        public PrimaryExpr(Object value) {
            this.value = value;
        }
    }

    public static class UnaryExpr implements CompileUnit {
        private List<TokenType> operators;
        private Object value;
        public UnaryExpr(List<TokenType> operators, Object value) {
            this.operators = operators;
            this.value = value;
        }
    }

    public static class ForExpr implements CompileUnit {
        LValue lValue;
        AddExpr expr;
        public ForExpr(LValue lValue, AddExpr expr) {
            this.lValue = lValue;
            this.expr = expr;
        }
    }

    public static class GetInStream implements CompileUnit {
        private TokenType type;
        public GetInStream(TokenType type) {
            this.type = type;
        }
    }

    public static class MulExpr implements CompileUnit {
        private UnaryExpr unaryExpr;
        List<ExprWithLeading<UnaryExpr>> follows;
        public MulExpr(UnaryExpr unaryExpr, List<ExprWithLeading<UnaryExpr>> follows) {
            this.unaryExpr = unaryExpr;
            this.follows = follows;
        }
    }

    public static class AddExpr implements CompileUnit {
        private MulExpr mulExpr;
        List<ExprWithLeading<MulExpr>> follows;
        public AddExpr(MulExpr mulExpr, List<ExprWithLeading<MulExpr>> follows) {
            this.mulExpr = mulExpr;
            this.follows = follows;
        }
    }

    public static class FuncCall implements CompileUnit {
        private String funcName;
        private List<AddExpr> args;
        public FuncCall(String funcName, List<AddExpr> args) {
            this.funcName = funcName;
            this.args = args;
        }
    }

    public static class BranchStmt implements Statement {
        private LOrExpr condition;
        private Statement thenBlock, elseBlock;
        public BranchStmt(LOrExpr condition, Statement thenBlock, Statement elseBlock) {
            this.condition = condition;
            this.thenBlock = thenBlock;
            this.elseBlock = elseBlock;
        }
    }

    public static class ForStmt implements Statement {
        private Statement thenBlock;
        private ForExpr init, move;
        private LOrExpr condition;
        public ForStmt(Statement thenBlock, ForExpr init, ForExpr move, LOrExpr condition) {
            this.thenBlock = thenBlock;
            this.init = init;
            this.move = move;
            this.condition = condition;
        }
    }

    public static class ReturnStmt implements Statement {
        private AddExpr retValue;
        public ReturnStmt(AddExpr retValue) {
            this.retValue = retValue;
        }
    }

    public static class CtrlStmt implements Statement {
        private TokenType type;
        public CtrlStmt(TokenType type) {
            this.type = type;
        }
    }

    public static class PrintStmt implements Statement {
        private String ctrlString;
        private List<AddExpr> indexes;
        public PrintStmt(String ctrlString, List<AddExpr> indexes) {
            this.ctrlString = ctrlString;
            this.indexes = indexes;
        }
    }

    public static class ExprStmt implements Statement {
        private AddExpr expr;
        public ExprStmt(AddExpr expr) {
            this.expr = expr;
        }
    }

    public static class AssignStmt implements Statement {
        private LValue lValue;
        private AddExpr expr;
        private boolean isInput;
        private GetInStream in;
        public AssignStmt(LValue lValue, AddExpr expr) {
            this.lValue = lValue;
            this.expr = expr;
            isInput = false;
        }
        public AssignStmt(LValue lValue, GetInStream in) {
            this.lValue = lValue;
            this.in = in;
            isInput = true;
        }
    }

    public static class LOrExpr implements CompileUnit {
        private LAndExpr leading;
        private List<ExprWithLeading<LAndExpr>> items;
        public LOrExpr(LAndExpr leading, List<ExprWithLeading<LAndExpr>> items) {
            this.items = items;
            this.leading = leading;
        }
    }

    public static class LAndExpr implements CompileUnit {
        private EqExpr leading;
        private List<ExprWithLeading<EqExpr>> items;
        public LAndExpr(EqExpr leading, List<ExprWithLeading<EqExpr>> items) {
            this.items = items;
            this.leading = leading;
        }
    }

    public static class EqExpr implements CompileUnit {
        private RelExpr leading;
        private List<ExprWithLeading<RelExpr>> follows;
        public EqExpr(RelExpr leading, List<ExprWithLeading<RelExpr>> follows) {
            this.leading = leading;
            this.follows = follows;
        }
    }

    public static class RelExpr implements CompileUnit {
        private AddExpr leading;
        private List<ExprWithLeading<AddExpr>> follows;
        public RelExpr(AddExpr leading, List<ExprWithLeading<AddExpr>> follows) {
            this.leading = leading;
            this.follows = follows;
        }
    }

    public static class FuncParamDecl implements CompileUnit {
        private final String name;
        private final TokenType type;
        List<AddExpr> indexex;
        public FuncParamDecl(String name, TokenType type, List<AddExpr> indexex) {
            this.name = name;
            this.type = type;
            this.indexex = indexex;
        }
    }

    public static class InitValue implements CompileUnit {
        private AddExpr expr;
        private List<InitValue> values;
        private String stringConst;
        public InitValue(AddExpr expr) {
            this.expr = expr;
            this.values = null;
            this.stringConst = null;
        }
        public InitValue(List<InitValue> values) {
            this.values = values;
            this.expr = null;
            this.stringConst = null;
        }
        public InitValue(String stringConst) {
            this.stringConst = stringConst;
            this.values = null;
            this.expr = null;
        }
    }

    public static class LValue implements CompileUnit {
        private String name;
        private AddExpr index;
        public LValue(String name, AddExpr index) {
            this.name = name;
            this.index = index;
        }
    }

    public record ExprWithLeading<T>(TokenType leading, T expr) {
    }
}
