package frontend.IRBuilder.structure;

import frontend.IRBuilder.structure.instruction.Instruction;
import frontend.IRBuilder.structure.instruction.binary.AndInstr;
import frontend.IRBuilder.structure.instruction.cmp.GeInstr;
import frontend.IRBuilder.structure.instruction.end.BranchInstr;
import frontend.IRBuilder.structure.instruction.end.JumpInstr;
import frontend.IRBuilder.structure.instruction.mem.AllocInstr;
import frontend.IRBuilder.structure.instruction.mem.GepInstr;
import frontend.IRBuilder.structure.instruction.mem.LoadInstr;
import frontend.IRBuilder.structure.instruction.mem.StoreInstr;
import frontend.IRBuilder.structure.instruction.otherInstr.CallInstr;
import frontend.IRBuilder.structure.lib.Lib;
import type.*;
import utils.CustomList;
import frontend.syntax.Ast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;


public class Procedure {
    private int curBlockIndex = 0;
    private int curRegIndex = 0;
    private final CustomList basicBlockList = new CustomList(this);
    private BasicBlock curBlock;
    private final BasicBlock exitBlock;
    private final HashMap<Symbol, IRParam> ast2IrParamMap = new HashMap<>();
    private final Stack<BasicBlock> loopStarts = new Stack<>();
    private final Stack<BasicBlock> loopEnds = new Stack<>();
    private final ArrayList<IRParam> IRParamList;

    public Procedure(BasicType returnType, ArrayList<Ast.FuncFParam> paramList, Ast.Block block, SymTab curSymTab,ArrayList<IRParam> IRParamList) {
        this.IRParamList = IRParamList;
        BasicBlock entryBlock = new BasicBlock(curBlockIndex++);
        BasicBlock exitBlock = new BasicBlock(curBlockIndex++);
        basicBlockList.addToTail(entryBlock);
        this.exitBlock = exitBlock;
        constructParams(paramList, curSymTab, ast2IrParamMap);
        constructReturnInstr(returnType, curSymTab);
        storeParams(ast2IrParamMap);
        constructBlock(block, returnType, curSymTab);
    }

    private void constructParams(ArrayList<Ast.FuncFParam> paramList, SymTab curSymTab, HashMap<Symbol, IRParam> ast2IrParamMap) {
        for (Ast.FuncFParam param : paramList) {
            String name = param.name;
            //TODO：函数参数为数组时的Pointer处理
            Symbol symbol;
            BasicType type;
            if (param.isArray) {
                type = new PointerType(param.type);
                Value initVal = new ArrayInitVal(type, -1, false);
                symbol = new Symbol(name, type, -1, false, false, initVal);
            } else {
                type = param.type;
                symbol = new Symbol(name, type, -1, false, false, null);
            }
            curSymTab.symbolMap.put(name, symbol);
            IRParam irParam = new IRParam(curRegIndex++, type);
            ast2IrParamMap.put(symbol, irParam);
        }
    }

    private void constructReturnInstr(BasicType returnType, SymTab curSymTab) {
        if (!(returnType instanceof VoidType)) {
            Symbol symbol = new Symbol("", returnType, -1, false, false, null);
            curSymTab.addSymbol(symbol);
            curBlock.addInstr(new AllocInstr(curRegIndex++, symbol));
            //缺省的返回值
            if (returnType instanceof IntType) {
                curBlock.addInstr(new StoreInstr(new ConstInt(0), symbol));
            } else if (returnType instanceof CharType) {
                curBlock.addInstr(new StoreInstr(new ConstChar(0), symbol));
            } else {
                throw new RuntimeException("不支持的返回值类型");
            }
        }
    }

    private void storeParams(HashMap<Symbol, IRParam> ast2IrParamMap) {
        for (Symbol symbol : ast2IrParamMap.keySet()) {
            curBlock.addInstr(new AllocInstr(curRegIndex++, symbol));
            IRParam irParam = ast2IrParamMap.get(symbol);
            curBlock.addInstr(new StoreInstr(irParam, symbol));
        }
    }

    private void constructBlock(Ast.Block block, BasicType returnType, SymTab curSymTab) {
        for (Ast.BlockItem blockItem : block.itemList) {
            if (blockItem instanceof Ast.Decl) {
                constructDecl((Ast.Decl) blockItem, curSymTab);
            } else if (blockItem instanceof Ast.Stmt) {
                constructStmt((Ast.Stmt) blockItem, returnType, curSymTab);
            } else {
                throw new RuntimeException("未定义的BlockItem");
            }
        }
    }

    private void constructStmt(Ast.Stmt stmt, BasicType returnType, SymTab curSymTab) {
        if (stmt instanceof Ast.Assign) {
            constructAssign((Ast.Assign) stmt, curSymTab);
        } else if (stmt instanceof Ast.Block) {
            constructBlock((Ast.Block) stmt, returnType, new SymTab(curSymTab));
        } else if (stmt instanceof Ast.BreakStmt) {
            constructBreak();
        } else if (stmt instanceof Ast.ContinueStmt) {
            constructContinue();
        } else if (stmt instanceof Ast.ExpStmt) {
            calculateExp(((Ast.ExpStmt) stmt).exp, curSymTab, true);
        } else if (stmt instanceof Ast.ForWholeStmt) {
            constructForWholeStmt((Ast.ForWholeStmt) stmt, returnType, curSymTab);
        } else if (stmt instanceof Ast.IfStmt) {
            constructIf((Ast.IfStmt) stmt, returnType, curSymTab);
        } else if (stmt instanceof Ast.ReturnStmt) {
            constructReturn((Ast.ReturnStmt) stmt, returnType, curSymTab);
        } else {
            throw new RuntimeException("未定义的Stmt");
        }
    }

    public void constructAssign(Ast.Assign assign, SymTab curSymTab) {
        Ast.LVal lVal = assign.lVal;
        Symbol symbol = curSymTab.getSymbol(lVal.name);
        //NOTICE:理论上rightValue一定是int型
        Value rightValue = calculateExp(assign.exp, curSymTab, false);
        rightValue = convertToSameType(rightValue, symbol.type);
        //TODO:数组情况
        curBlock.addInstr(new StoreInstr(rightValue, symbol));
    }

    public Value convertToSameType(Value value, BasicType type) {
        //TODO:为什么不需要改symbol
        if (value.type == type) {
            return value;
        }
        if (value.type instanceof IntType && type instanceof CharType) {
            return new AndInstr(curRegIndex++, value, new ConstInt(0xff));
        }
        throw new RuntimeException("理论上不应该出现的类型组合");
    }

    public Value calculateExp(Ast.Exp exp, SymTab curSymTab, boolean canBeEmpty) {
        if (exp == null) {
            if (canBeEmpty) {
                return null;
            }
            throw new RuntimeException("在表达式不能为空的时候为空了");
        }
        boolean isConst = exp.checkConst(curSymTab);
        if (isConst) {
            return exp.getConstInt(curSymTab);
        }
        if (exp instanceof Ast.BinaryExp) {
            Value firstValue = calculateExp(((Ast.BinaryExp) exp).exps.get(0), curSymTab, canBeEmpty);
            for (int i = 0; i < ((Ast.BinaryExp) exp).ops.size(); i++) {
                Ast.Exp restExp = ((Ast.BinaryExp) exp).exps.get(i + 1);
                Value restValue = calculateExp(restExp, curSymTab, canBeEmpty);
                String op = ((Ast.BinaryExp) exp).ops.get(i);
                Instruction instruction = Instruction.buildInstruction(firstValue, restValue, op, curRegIndex++);
                curBlock.addInstr(instruction);
                firstValue = instruction;
            }
            return firstValue;
        } else if (exp instanceof Ast.UnaryExp) {
            int sign = ((Ast.UnaryExp) exp).isPositive ? 1 : -1;
            Ast.PrimaryExp primaryExp = ((Ast.UnaryExp) exp).primaryExp;
            Value res;
            if (primaryExp instanceof Ast.Exp) {
                res = calculateExp((Ast.Exp) primaryExp, curSymTab, canBeEmpty);
            } else if (primaryExp instanceof Ast.FuncCall) {
                res = constructCall((Ast.FuncCall) primaryExp, curSymTab);
            } else if (primaryExp instanceof Ast.LVal) {
                Symbol symbol = curSymTab.getSymbol(((Ast.LVal) primaryExp).name);
                if (symbol.type instanceof PointerType) {
                    Value index = calculateExp(((Ast.LVal) primaryExp).exp, curSymTab, canBeEmpty);
                    //取指针
                    if (symbol.arraySize == -1) {
                        res = new LoadInstr(curRegIndex++, symbol);
                        //TODO:未完成
                    }
                    throw new RuntimeException("未完成");
                }
                throw new RuntimeException("未完成");
            } else if (primaryExp instanceof Ast.NumberConst) {
                res = new ConstInt(((Ast.NumberConst) primaryExp).value * sign);
                sign = 1;
            } else {
                throw new RuntimeException("未定义的PrimaryExp");
            }
            if (sign == -1) {
                res = Instruction.buildInstruction(new ConstInt(0), res, "-", curRegIndex++);
                curBlock.addInstr((Instruction) res);
            }
            if (((Ast.UnaryExp) exp).isNot) {
                res = Instruction.buildInstruction(new ConstInt(0), res, "==", curRegIndex++);
                curBlock.addInstr((Instruction) res);
            }
            return res;
        }
        throw new RuntimeException("未定义的Exp");
    }

    public Value constructCall(Ast.FuncCall funcCall, SymTab curSymTab) {
        ArrayList<Value> argList = new ArrayList<>();
        for (Ast.Exp exp : funcCall.paramList) {
            argList.add(calculateExp(exp, curSymTab, false));
        }
        CallInstr callInstr;
        Lib.LibFunc libFunc = Lib.getLibFunc(funcCall.name);
        if (libFunc != null) {
            //NOTICE:读文法发现，库函数参数不会出现不匹配，不做检查参数这一步
            //TODO:printf参数的隐式类型转换
            //TODO:库函数的call指令构建
            throw new RuntimeException("未完成");
        } else {
            Function function = Function.getFunction(funcCall.name);
            if (function == null) {
                throw new RuntimeException("未定义的函数");
            }
            //checkAndConvFuncParams(function.paramList, argList);
            callInstr = (function.returnType instanceof VoidType) ?
                    new CallInstr(-1, function, argList) :
                    new CallInstr(curRegIndex++, function, argList);
        }
        curBlock.addInstr(callInstr);
        return callInstr;
    }

    public void checkAndConvFuncParams(ArrayList<Ast.FuncFParam> fParams, ArrayList<Value> rParams) {
        if (fParams.size() != rParams.size()) {
            throw new RuntimeException("参数个数不一致");
        }
        for (int i = 0; i < fParams.size(); i++) {
            if (fParams.get(i).isArray && !(rParams.get(i).type instanceof PointerType)
                    || !fParams.get(i).isArray && rParams.get(i).type != fParams.get(i).type)
                throw new RuntimeException("数组和变量不能互传");
            if (fParams.get(i).isArray && rParams.get(i).type instanceof PointerType pointerType) {
                if (pointerType.eleType != fParams.get(i).type) {
                    throw new RuntimeException("数组内类型必须完全匹配");
                }
            }
            if (!fParams.get(i).isArray && !(rParams.get(i).type instanceof PointerType)) {
                if (fParams.get(i).type instanceof IntType && rParams.get(i).type instanceof CharType) {
                    AndInstr andInstr = new AndInstr(curRegIndex++, rParams.get(i), new ConstInt(0xff));
                    curBlock.addInstr(andInstr);
                    rParams.set(i, andInstr);
                }
            }
        }
    }

    public void constructBreak() {
        if (loopEnds.isEmpty()) {
            throw new RuntimeException("break语句不在循环内");
        }
        curBlock.addInstr(new JumpInstr(loopEnds.peek()));
        curBlock = new BasicBlock(curBlockIndex++);
        basicBlockList.addToTail(curBlock);
    }

    public void constructForWholeStmt(Ast.ForWholeStmt forWholeStmt, BasicType returnType, SymTab curSymTab) {
        BasicBlock loopStart = new BasicBlock(curBlockIndex++);
        BasicBlock loopBody = new BasicBlock(curBlockIndex++);
        BasicBlock loopEnd = new BasicBlock(curBlockIndex++);
        curBlock.addInstr(new JumpInstr(loopStart));
        basicBlockList.addToTail(loopStart);
        curBlock = loopStart;
        Value condition = shortcirCalOr(forWholeStmt.cond, loopStart, loopEnd, curSymTab);
        curBlock.addInstr(new BranchInstr(condition, loopBody, loopEnd));
        basicBlockList.addToTail(loopBody);
        curBlock = loopBody;
        loopStarts.push(loopStart);
        loopEnds.push(loopEnd);
        constructStmt(forWholeStmt.loopStmt, returnType, new SymTab(curSymTab));
        loopStarts.pop();
        loopEnds.pop();
        curBlock.addInstr(new JumpInstr(loopStart));
        basicBlockList.addToTail(loopEnd);
        curBlock = loopEnd;
    }

    public Value shortcirCalOr(Ast.Exp exp, BasicBlock loopStart, BasicBlock loopEnd, SymTab curSymTab) {
        //短路求值
        if (!(exp instanceof Ast.BinaryExp binaryExp)) {
            return transform2i1(calculateExp(exp, curSymTab, false));
        }
        BasicBlock nextBlock;
        if (binaryExp.ops.isEmpty()) {
            nextBlock = loopEnd;
        } else {
            nextBlock = new BasicBlock(curBlockIndex++);
        }
        Value firstValue = transform2i1(shortcirCalAnd(binaryExp.exps.get(0), nextBlock, curSymTab));
        for (int i = 0; i < binaryExp.ops.size(); i++) {
            Ast.Exp nextExp = binaryExp.exps.get(i + 1);
            curBlock.addInstr(new BranchInstr(firstValue, loopStart, nextBlock));
            curBlock = nextBlock;
            basicBlockList.addToTail(nextBlock);
            if (i == binaryExp.ops.size() - 1) {
                nextBlock = loopEnd;
            } else {
                nextBlock = new BasicBlock(curBlockIndex++);
            }
            firstValue = transform2i1(shortcirCalAnd(nextExp, nextBlock, curSymTab));
        }
        return firstValue;
    }

    public Value shortcirCalAnd(Ast.Exp exp, BasicBlock loopEnd, SymTab curSymTab) {
        if (!(exp instanceof Ast.BinaryExp binaryExp)) {
            return transform2i1(calculateExp(exp, curSymTab, false));
        }
        BasicBlock nextBlock;
        Value firstValue = transform2i1(calculateExp(binaryExp.exps.get(0), curSymTab, false));
        for (int i = 0; i < binaryExp.ops.size(); i++) {
            nextBlock = new BasicBlock(curBlockIndex++);
            Ast.Exp nextExp = binaryExp.exps.get(i + 1);
            curBlock.addInstr(new BranchInstr(firstValue, nextBlock, loopEnd));
            curBlock = nextBlock;
            basicBlockList.addToTail(nextBlock);
            firstValue = transform2i1(calculateExp(nextExp, curSymTab, false));
        }
        return firstValue;
    }

    public Value transform2i1(Value value) {
        BasicType type = value.type;
        if (type instanceof BoolType) {
            return value;
        } else if (type instanceof IntType) {
            Instruction instr = Instruction.buildInstruction(value, new ConstInt(0), "!=", curRegIndex++);
            curBlock.addInstr(instr);
            return instr;
        } else {
            throw new RuntimeException("不支持的类型转换");
        }
    }

    public void constructContinue() {
        if (loopStarts.isEmpty()) {
            throw new RuntimeException("不在循环内的break语句");
        }
        curBlock.addInstr(new JumpInstr(loopStarts.peek()));
        curBlock = new BasicBlock(curBlockIndex++);
        basicBlockList.addToTail(curBlock);
    }

    public void constructIf(Ast.IfStmt ifStmt, BasicType returnType, SymTab curSymTab) {
        boolean hasElse = ifStmt.elseStmt != null;
        BasicBlock thenBlock = new BasicBlock(curBlockIndex++);
        BasicBlock elseBlock = new BasicBlock(curBlockIndex++);
        BasicBlock endBlock = hasElse ? new BasicBlock(curBlockIndex++) : elseBlock;
        Value condition = shortcirCalOr(ifStmt.cond, thenBlock, elseBlock, curSymTab);
        curBlock.addInstr(new BranchInstr(condition, thenBlock, elseBlock));
        basicBlockList.addToTail(thenBlock);
        curBlock = thenBlock;
        constructStmt(ifStmt.thenStmt, returnType, new SymTab(curSymTab));
        //NOTICE:then块里先constructStmt，再跳转到endBlock，因此事先要保存
        BasicBlock thenEndBlock = curBlock;
        if (hasElse) {
            basicBlockList.addToTail(elseBlock);
            curBlock = elseBlock;
            constructStmt(ifStmt.elseStmt, returnType, new SymTab(curSymTab));
            curBlock.addInstr(new JumpInstr(endBlock));
        }
        thenEndBlock.addInstr(new JumpInstr(endBlock));
        basicBlockList.addToTail(endBlock);
        curBlock = endBlock;
    }

    public void constructReturn(Ast.ReturnStmt returnStmt, BasicType returnType, SymTab curSymTab) {
        Ast.Exp exp = returnStmt.exp;
        if (exp == null) {
            curBlock.addInstr(new JumpInstr(exitBlock));
        } else {
            Value value = calculateExp(exp, curSymTab, false);
            Symbol symbol = curSymTab.getSymbol("");
            value = convertToSameType(value, symbol.type);
            curBlock.addInstr(new StoreInstr(value, symbol));
            curBlock.addInstr(new JumpInstr(exitBlock));
        }
    }

    public void constructDecl(Ast.Decl decl, SymTab curSymTab) {
        List<Symbol> newSymList = curSymTab.parseSymbolsForDecl(decl);
        for (Symbol symbol : newSymList) {
            curBlock.addInstr(new AllocInstr(curRegIndex++, symbol));
            Value initVal = symbol.initVal;
            if (initVal != null) {
                if (initVal instanceof ConstInt) {
                    initVal = convertToSameType(initVal, symbol.type);
                    curBlock.addInstr(new StoreInstr(initVal, symbol));
                } else if (initVal instanceof InitExp) {
                    Value value = calculateExp(((InitExp) initVal).exp, curSymTab, false);
                    value = convertToSameType(value, symbol.type);
                    curBlock.addInstr(new StoreInstr(value, symbol));
                } else if (initVal instanceof ArrayInitVal arrayInitVal) {
                    //TODO:第一步，memset的处理
                    ArrayList<Integer> noneZeroIndex = arrayInitVal.getNoneZeroIndex();
                    for (Integer index : noneZeroIndex) {
                        Value value = arrayInitVal.getValueThroughIndex(index);
                        if (value instanceof ConstNum) {
                            //TODO:GEP有点问题
                            Instruction instr = new GepInstr(curRegIndex++, new ConstInt(index), symbol);
                            curBlock.addInstr(instr);
                            value = convertToSameType(value, symbol.type);
                            curBlock.addInstr(new StoreInstr(value, instr, symbol));
                        } else if (value instanceof InitExp) {
                            Instruction instr = new GepInstr(curRegIndex++, new ConstInt(index), symbol);
                            curBlock.addInstr(instr);
                            value = calculateExp(((InitExp) value).exp, curSymTab, false);
                            value = convertToSameType(value, symbol.type);
                            curBlock.addInstr(new StoreInstr(value, instr, symbol));
                        }
                    }
                }
            }
            if (!symbol.isConst) {
                curSymTab.addSymbol(symbol);
            }
        }
    }
}
