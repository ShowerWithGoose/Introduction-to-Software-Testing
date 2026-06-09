package frontend.syntax;

import frontend.IRBuilder.structure.*;
import type.BasicType;
import type.PointerType;

import java.util.ArrayList;

public class Ast {
    public ArrayList<CompUnit> nodes;

    public Ast(ArrayList<CompUnit> nodes) {
        this.nodes = nodes;
    }

    public interface CompUnit {
    }

    public static class Decl extends BlockItem implements CompUnit {
        public final boolean isConst;
        public final BasicType type;
        public final ArrayList<ValueDef> valueDefList;

        public Decl(boolean isConst, BasicType type, ArrayList<ValueDef> valueDefList) {
            this.isConst = isConst;
            this.type = type;
            this.valueDefList = valueDefList;
        }
    }

    public static class FuncDef implements CompUnit {
        public final BasicType type;
        public final String name;
        public final ArrayList<FuncFParam> paramList;
        public final Block block;

        public FuncDef(BasicType type, String name, ArrayList<FuncFParam> paramList, Block block) {
            this.type = type;
            this.name = name;
            this.paramList = paramList;
            this.block = block;
        }
    }

    public static class FuncFParam {
        public final BasicType type;
        public final String name;
        public final boolean isArray;

        public FuncFParam(BasicType type, String name, boolean isArray) {
            this.type = type;
            this.name = name;
            this.isArray = isArray;
        }
    }

    public static class ValueDef {
        public final String name;
        public final Exp exp;
        public final ValueInitVal valueInitVal;

        public ValueDef(String name, Exp exp, ValueInitVal valueInitVal) {
            this.name = name;
            this.exp = exp;
            this.valueInitVal = valueInitVal;
        }
    }

    public abstract static class Exp extends PrimaryExp {
        public abstract boolean checkConst(SymTab curSymTab);

        public abstract ConstInt getConstInt(SymTab curSymTab);
    }

    public static class ValueInitVal {
        public final boolean isString;
        public final ArrayList<Exp> valueList;
        public final StringConst stringConst;
        public final boolean isNoStringArray;

        public ValueInitVal(boolean isString, ArrayList<Exp> valueList, StringConst stringConst, boolean isNoStringArray) {
            this.isString = isString;
            this.valueList = valueList;
            this.stringConst = stringConst;
            this.isNoStringArray = isNoStringArray;
        }
    }

    public static class StringConst {
        public String string;

        public StringConst(String string) {
            this.string = string;
        }
    }

    public static class BinaryExp extends Exp {
        public final ArrayList<Exp> exps;
        public final ArrayList<String> ops;

        public BinaryExp(ArrayList<Exp> exps, ArrayList<String> ops) {
            this.exps = exps;
            this.ops = ops;
        }

        public boolean checkConst(SymTab curSymTab) {
            for (Exp exp : exps) {
                if (!exp.checkConst(curSymTab)) {
                    return false;
                }
            }
            return true;
        }

        public ConstInt getConstInt(SymTab curSymTab) {
            ConstInt res = exps.get(0).getConstInt(curSymTab);
            if (res == null) {
                return null;
            }
            int resValue = res.value;
            for (int i = 0; i < ops.size(); i++) {
                ConstInt next = exps.get(i + 1).getConstInt(curSymTab);
                if (next == null) {
                    return null;
                }
                int nextValue = next.value;
                switch (ops.get(i)) {
                    case "+":
                        resValue += nextValue;
                        break;
                    case "-":
                        resValue -= nextValue;
                        break;
                    case "*":
                        resValue *= nextValue;
                        break;
                    case "/":
                        resValue /= nextValue;
                        break;
                    case "%":
                        resValue %= nextValue;
                        break;
                    case "<":
                        resValue = resValue < nextValue ? 1 : 0;
                        break;
                    case ">":
                        resValue = resValue > nextValue ? 1 : 0;
                        break;
                    case "<=":
                        resValue = resValue <= nextValue ? 1 : 0;
                        break;
                    case ">=":
                        resValue = resValue >= nextValue ? 1 : 0;
                        break;
                    case "==":
                        resValue = resValue == nextValue ? 1 : 0;
                        break;
                    case "!=":
                        resValue = resValue != nextValue ? 1 : 0;
                        break;
                    case "&&":
                        resValue = resValue != 0 && nextValue != 0 ? 1 : 0;
                        break;
                    case "||":
                        resValue = resValue != 0 || nextValue != 0 ? 1 : 0;
                        break;
                    default:
                        throw new RuntimeException("未定义的二元运算符");
                }
            }
            return new ConstInt(resValue);
        }
    }

    public static class UnaryExp extends Exp {
        public final PrimaryExp primaryExp;
        private final ArrayList<String> ops;
        public boolean isPositive;
        public boolean isNot;

        public UnaryExp(PrimaryExp exp, ArrayList<String> ops) {
            this.primaryExp = exp;
            this.ops = ops;
            this.isPositive = true;
            this.isNot = false;
            decideSign();
        }

        public void decideSign() {
            for (String op : ops) {
                if (op.equals("!")) {
                    isNot = !isNot;
                }
                if (op.equals("-")) {
                    isPositive = !isPositive;
                }
            }
        }

        public boolean checkConst(SymTab curSymTab) {
            if (primaryExp instanceof Exp) {
                return ((Exp) primaryExp).checkConst(curSymTab);
            } else if (primaryExp instanceof FuncCall) {
                return false;
            } else if (primaryExp instanceof LVal lVal) {
                if (lVal.exp != null) {
                    if (!lVal.exp.checkConst(curSymTab)) {
                        return false;
                    }
                }
                Symbol symbol = curSymTab.getSymbol(lVal.name);
                return symbol.isConst || symbol.isGlobal && curSymTab.preSymTab == null;
            } else if (primaryExp instanceof NumberConst || primaryExp instanceof CharacterConst) {
                return true;
            } else {
                throw new RuntimeException("未定义的PrimaryExp");
            }
        }

        public ConstInt getConstInt(SymTab curSymTab) {
            int sign = isPositive ? 1 : -1;
            int res;
            if (primaryExp instanceof Exp) {
                res = ((Exp) primaryExp).getConstInt(curSymTab).value * sign;
            } else if (primaryExp instanceof LVal) {
                Symbol symbol = curSymTab.getSymbol(((LVal) primaryExp).name);
                Value initVal = symbol.initVal;
                if (symbol.type instanceof PointerType) {
                    int index = ((LVal) primaryExp).exp.getConstInt(curSymTab).value;
                    if (!(initVal instanceof ArrayInitVal)) {
                        throw new RuntimeException("该数组初始化的时候没有数组初始化");
                    }
                    Value value = ((ArrayInitVal) initVal).getValueThroughIndex(index);
                    res = ((ConstInt) value).value * sign;
                } else {
                    res = ((ConstInt) initVal).value * sign;
                }
            } else if (primaryExp instanceof NumberConst) {
                res = ((NumberConst) primaryExp).value * sign;
            } else {
                throw new RuntimeException("未定义的PrimaryExp");
            }
            if (isNot) {
                //我认为再条件表达式中至于是否为0有关
                return res == 0 ? new ConstInt(1) : new ConstInt(0);
            }
            return new ConstInt(res);
        }
    }

    public static class PrimaryExp {
    }

    public static class LVal extends PrimaryExp {
        public final String name;
        public final Exp exp;

        public LVal(String name, Exp exp) {
            this.name = name;
            this.exp = exp;
        }

    }

    public static class FuncCall extends PrimaryExp {
        public final String name;
        public final ArrayList<Exp> paramList;

        public FuncCall(String name, ArrayList<Exp> paramList) {
            this.name = name;
            this.paramList = paramList;
        }
    }

    public static class NumberConst extends PrimaryExp {
        public final int value;

        public NumberConst(int value) {
            this.value = value;
        }
    }

    public static class CharacterConst extends PrimaryExp {
        private final char value;

        public CharacterConst(char value) {
            this.value = value;
        }
    }

    public static class Block extends Stmt {
        public final ArrayList<BlockItem> itemList;

        public Block(ArrayList<BlockItem> itemList) {
            this.itemList = itemList;
        }
    }

    public static class BlockItem {
    }

    public static class Stmt extends BlockItem {
    }

    public static class Assign extends Stmt {
        public final LVal lVal;
        public final Exp exp;

        public Assign(LVal lVal, Exp exp) {
            this.lVal = lVal;
            this.exp = exp;
        }
    }

    public static class IfStmt extends Stmt {
        public final Exp cond;
        public final Stmt thenStmt;
        public final Stmt elseStmt;

        public IfStmt(Exp cond, Stmt thenStmt, Stmt elseStmt) {
            this.cond = cond;
            this.thenStmt = thenStmt;
            this.elseStmt = elseStmt;
        }
    }

    public static class ForWholeStmt extends Stmt {
        private final ForStmt initStmt;
        public final Exp cond;
        public final ForStmt loopStmt;
        private final Stmt body;

        public ForWholeStmt(ForStmt initStmt, Exp cond, ForStmt loopStmt, Stmt body) {
            this.initStmt = initStmt;
            this.cond = cond;
            this.loopStmt = loopStmt;
            this.body = body;
        }
    }

    public static class ForStmt extends Stmt {
        private final LVal lVal;
        private final Exp exp;

        public ForStmt(LVal lVal, Exp exp) {
            this.lVal = lVal;
            this.exp = exp;
        }
    }

    public static class ExpStmt extends Stmt {
        public final Exp exp;

        public ExpStmt(Exp exp) {
            this.exp = exp;
        }
    }

    public static class ReturnStmt extends Stmt {
        public final Exp exp;

        public ReturnStmt(Exp exp) {
            this.exp = exp;
        }
    }

    public static class BreakStmt extends Stmt {
    }

    public static class ContinueStmt extends Stmt {
    }

    public static class PrintStmt extends Stmt {
        private final StringConst stringConst;
        private final ArrayList<Exp> exps;
        private final boolean isFormat;
        private ArrayList<String> format;

        public PrintStmt(StringConst stringConst, ArrayList<Exp> exps, boolean isFormat, ArrayList<String> format) {
            this.stringConst = stringConst;
            this.exps = exps;
            this.isFormat = isFormat;
            this.format = format;
        }
    }

    public static class GetintStmt extends Stmt {
        private final LVal lVal;

        public GetintStmt(LVal lVal) {
            this.lVal = lVal;
        }
    }

    public static class GetcharStmt extends Stmt {
        private final LVal lVal;

        public GetcharStmt(LVal lVal) {
            this.lVal = lVal;
        }
    }
}
