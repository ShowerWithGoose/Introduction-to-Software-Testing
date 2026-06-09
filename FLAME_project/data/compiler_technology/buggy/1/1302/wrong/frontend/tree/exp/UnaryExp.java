package frontend.tree.exp;

import frontend.error.ErrorList;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.tree.Node;
import frontend.tree.func.FuncFParam;
import frontend.tree.func.FuncRParams;
import frontend.semantic.*;

import java.util.ArrayList;

/**
 * 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
 * error: c d e j
 */
public class UnaryExp extends Node {
    @Override
    public void semanticAnalysis() {
        if (children.get(0) instanceof Token && children.get(1) instanceof Token && ((Token)children.get(1)).getLexType() == LexType.LPARENT) {
            // Ident '(' [FuncRParams] ')'
            Token identifier = (Token)children.get(0);
            String name = identifier.getValue();
            if (!SymbolManager.getInstance().isDefined(name)) {
                // 未定义的名字
                ErrorList.getInstance().addError("c", identifier.getLineNum());
                return;
            } else {
                FuncSymbol funcSymbol = (FuncSymbol)SymbolManager.getInstance().getSymbol(name);
                ArrayList<FuncFParam> formParams = funcSymbol.getParams();
                ArrayList<Exp> realParams = new ArrayList<>();
                for (Node child : children) {
                    child.semanticAnalysis();
                    if (child instanceof FuncRParams) {
                        realParams = ((FuncRParams)child).getParams();
                    }
                }
                if (realParams.size() != formParams.size()) {
                    // 函数参数个数不匹配
                    ErrorList.getInstance().addError("d", identifier.getLineNum());
                } else {
                    for (int i = 0; i < realParams.size(); i++) {
                        if (TypeError(realParams.get(i), formParams.get(i))) {
                            // 函数参数类型不匹配
                            ErrorList.getInstance().addError("e", identifier.getLineNum());
                            break;
                        }
                    }
                }
            }
        } else {
            super.semanticAnalysis();
        }
    }

    @Override
    public Node getFirstLeaf() {
        if (children.get(0) instanceof PrimaryExp) {
            return children.get(0).getFirstLeaf();
        } else if (children.get(0) instanceof Token) {
            return children.get(0);
        } else {
            return children.get(1).getFirstLeaf();
        }
    }

    /**
     * 四种错误情况：1.传递数组给变量；2. 传递变量给数组；3. 传递 char 型数组给 int 型数组；4. 传递 int 型数组给 char 型数组。
     */
    private boolean TypeError(Exp realParam, FuncFParam formParam) {
        Type formType = formParam.getType();
        Type realType;
        Symbol realSymbol;
        Node first = realParam.getFirstLeaf();
        if (first instanceof Token) { // 函数、数字、字符都是VAR
            realSymbol = SymbolManager.getInstance().getSymbol(((Token) first).getValue());
            realType = Type.VAR;
        } else {
            realSymbol = SymbolManager.getInstance().getSymbol(((LVal) first).getIdentifierName());
            if (first.getChildren().size() > 1) {
                realType = Type.VAR;
            } else {
                realType = realSymbol.getType();
            }
        }

        if (formType != realType) {
            // 1,2
            return true;
        }

        if (formType == Type.ARRAY) {
            BType formBtype = formParam.getBType();
            BType realBtype = realSymbol.getBType();
            // 3,4
            return formBtype == BType.CHAR && realBtype == BType.INT
                    || formBtype == BType.INT && realBtype == BType.CHAR;
        }
        return false;
    }
}
