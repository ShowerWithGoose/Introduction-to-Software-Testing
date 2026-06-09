package frontend.tree.func;

import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.tree.Node;
import frontend.semantic.*;

/**
 * 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
 * error: b g j
 */
public class FuncDef extends Node {
    private FuncType funcType;
    private Token identifier;
    private FuncFParams funcFParams;
    private Block block;
    private FuncSymbol funcSymbol;

    @Override
    public void semanticAnalysis() {
        funcType = (FuncType) children.get(0);
        BType bType = funcType.getBType();
        identifier = (Token) children.get(1);
        String name = identifier.getValue();
        block = (Block) children.get(children.size() - 1);

        if (SymbolManager.getInstance().existsDupName(name)) { // 名字重定义
            ErrorList.getInstance().addError("b", identifier.getLineNum());
            return;
        } else {
            funcSymbol = (FuncSymbol) SymbolManager.getInstance().createAndAddSymbol(name, Type.FUNC, bType, false);
        }

        for (Node child : children) {
            if (child instanceof Block) {
                // 函数参数列表设置,准备进入函数作用域
                if (funcFParams!= null) {
                    funcSymbol.setParams(funcFParams.getParams());
                    SymbolManager.getInstance().enterFunc(funcFParams.getParams());
                } else {
                    SymbolManager.getInstance().enterFunc(null);
                }
            }
            child.semanticAnalysis();
            if (child instanceof FuncFParams) {
                funcFParams = (FuncFParams) child;
            }
        }

        boolean hasReturn = false;
        Node penult = block.getChildren().get(block.getChildren().size() - 2);
        if (penult instanceof Stmt) {
            if (((Stmt) penult).isReturnValue()) {
                hasReturn = true;
            }
        }
        if (bType != BType.VOID && !hasReturn) {
            // 有返回值的函数缺少return语句
            ErrorList.getInstance().addError("g", endLine);
        } else if (bType == BType.VOID && SymbolManager.getInstance().hasReturnStmt()) {
            // 无返回值的函数存在不匹配的return语句
            ErrorList.getInstance().addError("f", SymbolManager.getInstance().getReturnLine());
        }
        SymbolManager.getInstance().exitFunc();
    }
}
