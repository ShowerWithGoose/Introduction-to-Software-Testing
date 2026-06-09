package frontend.semantic;

import frontend.error.ErrorList;
import frontend.tree.func.FuncFParam;

import java.util.ArrayList;
import java.util.Stack;

public class SymbolManager {
    private static final SymbolManager instance = new SymbolManager();
    private final ArrayList<SymbolTable> symbolTablesList;
    private final Stack<SymbolTable> stack;
    private BType curBType = null;
    private int loop = 0;
    private boolean needAddFuncFParams = false;
    private ArrayList<FuncFParam> funcFParams;
    private boolean isFunc = false;
    private boolean returnStmt = false;
    private int returnLine = -1;

    public SymbolManager() {
        symbolTablesList = new ArrayList<>();
        stack = new Stack<>();
    }

    public static SymbolManager getInstance() {
        return instance;
    }

    public void enterBlock() {
        createAndPushSymbolTable();
        if (needAddFuncFParams) { // 函数形参的作用域需要特殊处理
            for (FuncFParam f : funcFParams) {
                if (SymbolManager.getInstance().existsDupName(f.getName())) {
                    ErrorList.getInstance().addError("b", f.getLineNum());
                } else {
                    SymbolManager.getInstance().createAndAddSymbol(f.getName(), f.getType(), f.getBType(), false);
                }
            }
            needAddFuncFParams = false;
        }
    }

    public void exitBlock() {
        stack.pop();
    }

    public void enterLoop() {
        loop++;
    }

    public void exitLoop() {
        loop--;
    }

    public void enterFunc(ArrayList<FuncFParam> funcFParams) {
        isFunc = true;
        if (funcFParams != null && !funcFParams.isEmpty()) {
            needAddFuncFParams = true;
        }
        this.funcFParams = funcFParams;
    }

    public void exitFunc() {
        isFunc = false;
        returnStmt = false;
        returnLine = -1;
        needAddFuncFParams = false;
        funcFParams = null;
    }

    public void setReturnStmt(boolean returnStmt, int returnLine) {
        this.returnStmt = returnStmt;
        this.returnLine = returnLine;
    }

    public boolean hasReturnStmt() {
        return returnStmt;
    }

    public int getReturnLine() {
        return returnLine;
    }

    public void createAndPushSymbolTable() {
        SymbolTable parent = getStackTop();
        SymbolTable symbolTable;
        if (parent == null) {
            symbolTable = new SymbolTable(symbolTablesList.size() + 1, 0);
        } else {
            symbolTable = new SymbolTable(symbolTablesList.size() + 1, parent.getId());
        }
        stack.push(symbolTable);
        symbolTablesList.add(symbolTable);
    }

    public Symbol createAndAddSymbol(String name, Type type, boolean isConst) {
        SymbolTable symbolTable = getStackTop();
        return symbolTable.addAndReturnSymbol(name, type, curBType, isConst);
    }

    public Symbol createAndAddSymbol(String value, Type type, BType bType, boolean isConst) {
        SymbolTable symbolTable = getStackTop();
        return symbolTable.addAndReturnSymbol(value, type, bType, isConst);
    }

    public void setCurBType(BType bType) {
        curBType = bType;
    }

    public boolean existsDupName(String name) {
        SymbolTable symbolTable = getStackTop();
        return symbolTable.getSymbol(name) != null;
    }

    public boolean isDefined(String name) {
        SymbolTable symbolTable = getStackTop();
        while (true) {
            if (symbolTable.getSymbol(name) != null) {
                return true;
            }
            if (symbolTable.getParentId() == 0) {
                break;
            }
            symbolTable = symbolTablesList.get(symbolTable.getParentId() - 1);
        }
        return false;
    }

    public boolean isConst(String name) {
        SymbolTable symbolTable = getStackTop();
        while (true) {
            Symbol symbol = symbolTable.getSymbol(name);
            if (symbol != null) {
                return symbol.isConst();
            }
            if (symbolTable.getParentId() == 0) {
                break;
            }
            symbolTable = symbolTablesList.get(symbolTable.getParentId() - 1);
        }
        return false; // 没找到按不是常量处理，即不报错误h(不能改变常量的值)
    }

    public boolean isInLoop() {
        return loop > 0;
    }

    public Symbol getSymbol(String name) {
        SymbolTable symbolTable = getStackTop();
        while (true) {
            Symbol symbol = symbolTable.getSymbol(name);
            if (symbol != null) {
                return symbol;
            }
            if (symbolTable.getParentId() == 0) {
                break;
            }
            symbolTable = symbolTablesList.get(symbolTable.getParentId() - 1);
        }
        return null;
    }

    public SymbolTable getStackTop() {
        SymbolTable ret = null;
        if (!stack.isEmpty()) {
            ret = stack.peek();
        }
        return ret;
    }
    public void sortSymbolTables() {
        symbolTablesList.sort((o1, o2) -> o1.getId() - o2.getId());
    }

    public ArrayList<SymbolTable> getSymbolTableList() {
        return symbolTablesList;
    }
}
