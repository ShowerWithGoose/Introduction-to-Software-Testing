package frontend;

import frontend.nodes.*;
import frontend.nodes.Character;
import frontend.nodes.Number;

import java.util.function.Supplier;

public class NodeRegistry {
    public static final Supplier<Node> COMP_UNIT = CompUnit::parse;
    public static final Supplier<Node> DECL = Decl::parse;
    public static final Supplier<Node> CONST_DECL = ConstDecl::parse;
    public static final Supplier<Node> B_TYPE = BType::parse;
    public static final Supplier<Node> CONST_DEF = ConstDef::parse;
    public static final Supplier<Node> CONST_INIT_VAL = ConstInitVal::parse;
    public static final Supplier<Node> VAR_DECL = VarDecl::parse;
    public static final Supplier<Node> VAR_DEF = VarDef::parse;
    public static final Supplier<Node> INIT_VAL = InitVal::parse;
    public static final Supplier<Node> FUNC_DEF = FuncDef::parse;
    public static final Supplier<Node> MAIN_FUNC_DEF = MainFuncDef::parse;
    public static final Supplier<Node> FUNC_TYPE = FuncType::parse;
    public static final Supplier<Node> FUNC_F_PARAMS = FuncFParams::parse;
    public static final Supplier<Node> FUNC_F_PARAM = FuncFParam::parse;
    public static final Supplier<Node> BLOCK = Block::parse;
    public static final Supplier<Node> BLOCK_ITEM = BlockItem::parse;
    public static final Supplier<Node> STMT = Stmt::parse;
    public static final Supplier<Node> FOR_STMT = ForStmt::parse;
    public static final Supplier<Node> EXP = Exp::parse;
    public static final Supplier<Node> COND = Cond::parse;
    public static final Supplier<Node> L_VAL = LVal::parse;
    public static final Supplier<Node> PRIMARY_EXP = PrimaryExp::parse;
    public static final Supplier<Node> NUMBER = Number::parse;
    public static final Supplier<Node> CHARACTER = Character::parse;
    public static final Supplier<Node> UNARY_EXP = UnaryExp::parse;
    public static final Supplier<Node> UNARY_OP = UnaryOp::parse;
    public static final Supplier<Node> FUNC_R_PARAMS = FuncRParams::parse;
    public static final Supplier<Node> MUL_EXP = MulExp::parse;
    public static final Supplier<Node> ADD_EXP = AddExp::parse;
    public static final Supplier<Node> REL_EXP = RelExp::parse;
    public static final Supplier<Node> EQ_EXP = EqExp::parse;
    public static final Supplier<Node> L_AND_EXP = LAndExp::parse;
    public static final Supplier<Node> L_OR_EXP = LOrExp::parse;
    public static final Supplier<Node> CONST_EXP = ConstExp::parse;
    public static final Supplier<Node> TERMINAL = Terminal::parse;
}
