package frontend;

import error.Err;
import frontend.Node.ASTNode;
import frontend.Node.LeafNode;
import frontend.Node.Node;
import frontend.Node.ParType;
import frontend.Symbol.*;
import frontend.Token.LexType;

import java.util.ArrayList;

public class SemanticAnalyzer {
    private int curId;
    private int curLevel;
    private SymbolTable gloSymbolTable;
    private SymbolTable curSymbolTable;
    private ArrayList<Err> errorList;
    private int loop;
    private boolean isReturn;

    public SemanticAnalyzer(ArrayList<Err> errorList) {
        this.curId = 1;
        this.curLevel = 1;
        this.gloSymbolTable = new SymbolTable();
        this.curSymbolTable = gloSymbolTable;
        this.errorList = errorList;
        loop = 0;
    }

    public SymbolTable analysis(Node rootNode) {
        for (ASTNode node : rootNode.getChildNode()) {
            if (((Node)node).getParType() == ParType.Decl) {
                traverseDecl((Node)node);
            }
            else if (((Node)node).getParType() == ParType.FuncDef) {
                traverseFuncDef((Node)node);
            }
            else if (((Node)node).getParType() == ParType.MainFuncDef) {
                traverseMainFuncDef((Node)node);
            }
            else {
                System.out.println("Default");
            }
        }
        return gloSymbolTable;
    }

    private void traverseMainFuncDef(Node mainFuncDefNode) {
        isReturn = true;
        Node block = (Node) mainFuncDefNode.getChildNode().get(4);
        traverseBlock(block);
        int len = block.getChildNode().size();
        ASTNode blockItem = block.getChildNode().get(len-2);
        if (blockItem instanceof Node) {
            ASTNode stmt = ((Node) blockItem).getChildNode().get(0);
            if (stmt instanceof Node) {
                if (((Node) stmt).getChildNode().get(0) instanceof LeafNode) {
                    LeafNode ret = (LeafNode) ((Node) stmt).getChildNode().get(0);
                    if (ret.getLexType() == LexType.RETURNTK) {
                        return;
                    }
                }
            }
        }
        int line = ((LeafNode)block.getChildNode().get(len - 1)).getLineNum();
        errorList.add(new Err(line, "g"));
    }

    private void traverseFuncDef(Node funcDefNode) {
        LexType lexType = ((LeafNode)((Node)funcDefNode.getChildNode().get(0)).getChildNode().get(0)).getLexType();
        int funcType;
        if (lexType == LexType.VOIDTK) {
            funcType = 0;
        }
        else if (lexType == LexType.INTTK) {
            funcType = 1;
        }
        else {
            funcType = 2;
        }
        SymType symbolType;
        if (funcType == 0) {
            symbolType = SymType.VoidFunc;
            isReturn = false;
        }
        else if (funcType == 1) {
            symbolType = SymType.IntFunc;
            isReturn = true;
        }
        else {
            symbolType = SymType.CharFunc;
            isReturn = true;
        }
        LeafNode identNode = (LeafNode) funcDefNode.getChildNode().get(1);
        String funcName = identNode.getName();
        if (curSymbolTable.isRedefined(funcName)) {
            errorList.add(new Err(identNode.getLineNum(), "b"));  // b 错误：重定义
        }
        if (!(funcDefNode.getChildNode().get(3) instanceof LeafNode)) { // 有参数
            ArrayList<SymType> paramSymTypes = new ArrayList<>();
            traverseFuncParamTypes((Node) funcDefNode.getChildNode().get(3), paramSymTypes); // 分析参数类型
            FuncSymbol funcSymbol = new FuncSymbol(funcName, curSymbolTable.getId(), curLevel, symbolType, funcType, paramSymTypes.size(), paramSymTypes);
            curSymbolTable.addSymbol(funcSymbol); // 添加函数到符号表
        }
        else { // 无参数
            FuncSymbol funcSymbol = new FuncSymbol(funcName, curSymbolTable.getId(), curLevel, symbolType, funcType, 0, new ArrayList<>());
            curSymbolTable.addSymbol(funcSymbol);
        }
        curId++;
        curLevel++;
        SymbolTable funcSymbolTable = new SymbolTable(curId,curLevel,curSymbolTable);
        curSymbolTable.addChildTable(funcSymbolTable);
        curSymbolTable = funcSymbolTable; // 进入下一层符号表
        if (!(funcDefNode.getChildNode().get(3) instanceof LeafNode)) { // 有参数
            traverseFuncParams((Node) funcDefNode.getChildNode().get(3));
        }
        int num = funcDefNode.getChildNode().size();
        Node block = (Node) funcDefNode.getChildNode().get(num - 1); // 函数体
        traverseFuncBlock(block);
        curSymbolTable = curSymbolTable.getParentTable();
        curLevel--;
        if (isReturn) { // 有返回值函数 g: 缺少return语句
            int len = block.getChildNode().size();
            if (len > 2) {
                ASTNode ret = ((Node) ((Node) (block.getChildNode().get(len - 2))).getChildNode().get(0)).getChildNode().get(0);
                if (ret instanceof LeafNode && ((LeafNode) ret).getLexType() == LexType.RETURNTK) {
                    return;
                }
            }
            int line = ((LeafNode)block.getChildNode().get(len - 1)).getLineNum();
            errorList.add(new Err(line, "g"));
        }
    }

    private void traverseFuncBlock(Node block) {
        for (ASTNode blockItemNode : block.getChildNode()) {
            if (blockItemNode instanceof Node) {
                Node blockItem = (Node) ((Node) blockItemNode).getChildNode().get(0);
                if (blockItem.getParType() == ParType.Decl) {
                    traverseDecl(blockItem);
                } else if (blockItem.getParType() == ParType.Stmt) {
                    traverseStmt(blockItem);
                }
            }
        }
    }

    private void traverseBlock(Node block) {
        curId++;
        curLevel++;
        SymbolTable funcSymbolTable = new SymbolTable(curId,curLevel,curSymbolTable);
        curSymbolTable.addChildTable(funcSymbolTable);
        curSymbolTable = funcSymbolTable; // 进入下一层符号表
        traverseFuncBlock(block);
        curSymbolTable = curSymbolTable.getParentTable();
        curLevel--;
    }

    private void traverseStmt(Node stmtNode) {
        ASTNode node = stmtNode.getChildNode().get(0);
        if (node instanceof Node) {
            switch (((Node)node).getParType()) {
                case LVal:
                    traverseUnchangedLVal((Node)node);
                    if (stmtNode.getChildNode().get(2) instanceof Node &&
                            ((Node)stmtNode.getChildNode().get(2)).getParType() == ParType.Exp) {
                        traverseExp((Node)stmtNode.getChildNode().get(2));
                    }
                    break;
                case Block:
                    traverseBlock((Node)node);
                    break;
                case Exp:
                    traverseExp((Node)node);
                    break;
                default:
                    System.out.println(((Node)node).getParType());
            }
        }
        else {
            switch (((LeafNode)node).getLexType()) {
                case SEMICN:
                    break;
                case IFTK:
                    traverseIfStmt(stmtNode);
                    break;
                case FORTK:
                    traverseForTk(stmtNode);
                    break;
                case BREAKTK:
                    traverseBreakStmt(stmtNode);
                    break;
                case CONTINUETK:
                    traverseContinueStmt(stmtNode);
                    break;
                case RETURNTK:
                    traverseReturnStmt(stmtNode);
                    break;
                case PRINTFTK:
                    traversePrintfStmt(stmtNode);
                    break;
                default:
                    System.out.println(((LeafNode)node).getLexType());

            }
        }
    }

    private void traverseForTk(Node forNode) { // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        int i = 2;
        if (forNode.getChildNode().get(i) instanceof Node) {
            traverseForStmt((Node) forNode.getChildNode().get(i));
            i = i + 2;
        }
        else {
            i++;
        }
        if (forNode.getChildNode().get(i) instanceof Node) {
            traverseCond((Node) forNode.getChildNode().get(i));
            i = i + 2;
        }
        else {
            i++;
        }
        if (forNode.getChildNode().get(i) instanceof Node) {
            traverseForStmt((Node) forNode.getChildNode().get(i));
            i = i + 2;
        }
        else {
            i++;
        }
        loop++;
        traverseStmt((Node) forNode.getChildNode().get(i));
        loop--;
    }

    private void traverseForStmt(Node forStmtNode) { //  LVal '=' Exp
        Node lValNode = (Node) forStmtNode.getChildNode().get(0);
        traverseUnchangedLVal(lValNode);
        Node expNode = (Node) forStmtNode.getChildNode().get(2);
        traverseExp(expNode);
    }


    private void traverseBreakStmt(Node breakNode) {
        if (loop == 0) { // 如果当前不在循环中
            LeafNode breakToken = (LeafNode) breakNode.getChildNode().get(0);
            errorList.add(new Err(breakToken.getLineNum(), "m")); // m: 表示非法的break语句
        }
    }

    private void traverseContinueStmt(Node continueNode) {
        if (loop == 0) { // 如果当前不在循环中
            LeafNode continueToken = (LeafNode) continueNode.getChildNode().get(0);
            errorList.add(new Err(continueToken.getLineNum(), "m")); // m:表示非法的continue语句
        }
    }

    private void traverseReturnStmt(Node returnNode) {
        if (!isReturn && returnNode.getChildNode().size() > 2) {
            errorList.add(new Err(((LeafNode)returnNode.getChildNode().get(0)).getLineNum(), "f")); // f:表示在不含返回值函数中出现return语句
        }
        if (returnNode.getChildNode().size() > 2) {
            Node expNode = (Node) returnNode.getChildNode().get(1);
            traverseExp(expNode);
        }
    }


    private void traverseIfStmt(Node ifStmtNode) { // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        ASTNode condNode = ifStmtNode.getChildNode().get(2); // 第三个节点应该是条件
        traverseCond((Node) condNode); // 处理条件表达式
        traverseStmt((Node) ifStmtNode.getChildNode().get(4)); // 第五个节点是 `then` 块
        if (ifStmtNode.getChildNode().size() > 5) {
            traverseStmt((Node) ifStmtNode.getChildNode().get(6)); // 第七个节点是 `else` 块
        }
    }

    private void traversePrintfStmt(Node printfNode) { //  'printf''('StringConst {','Exp}')'';'
        LeafNode stringConstNode = (LeafNode) printfNode.getChildNode().get(2); // 获取格式字符串
        String formatString = stringConstNode.getName();
        int expectedArgs = counter(formatString); // 计算格式字符串中%d的数量
        int actualArgs = (printfNode.getChildNode().size() - 4) / 2; // 计算Exp的数量
        if (actualArgs != expectedArgs) {
            errorList.add(new Err(stringConstNode.getLineNum(), "l")); // l: 表示参数数量不匹配
        }
        for (int i = 4; i < printfNode.getChildNode().size() - 1; i += 2) {
            traverseExp((Node) printfNode.getChildNode().get(i));
        }
    }

    private int counter(String formatString) {
        int count = 0;
        for (int i = 0; i < formatString.length() - 1; i++) {
            if (formatString.charAt(i) == '%' && (formatString.charAt(i + 1) == 'd' || formatString.charAt(i + 1) == 'c')) {
                count++;
            }
        }
        return count;
    }

    private void traverseCond(Node condNode) {
        traverseLOrExp((Node) condNode.getChildNode().get(0));
    }

    private void traverseLOrExp(Node lOrExpNode) {
        if (lOrExpNode.getChildNode().size() == 1) {
            traverseLAndExp((Node) lOrExpNode.getChildNode().get(0));
        }
        else { // 递归处理 LOrExp '||' LAndExp
            traverseLOrExp((Node) lOrExpNode.getChildNode().get(0)); // 处理左侧的 LOrExp
            traverseLAndExp((Node) lOrExpNode.getChildNode().get(2)); // 处理右侧的 LAndExp
        }
    }

    private void traverseLAndExp(Node lAndExpNode) {
        if (lAndExpNode.getChildNode().size() == 1) {
            traverseEqExp((Node) lAndExpNode.getChildNode().get(0));
        }
        else { // 递归处理 LAndExp '&&' EqExp
            traverseLAndExp((Node) lAndExpNode.getChildNode().get(0)); // 处理左侧的 LAndExp
            traverseEqExp((Node) lAndExpNode.getChildNode().get(2)); // 处理右侧的 EqExp
        }
    }

    private void traverseEqExp(Node eqExpNode) {
        if (eqExpNode.getChildNode().size() == 1) {
            traverseRelExp((Node) eqExpNode.getChildNode().get(0));
        }
        else { // 递归处理 EqExp '==' RelExp 或 EqExp '!=' RelExp
            traverseEqExp((Node) eqExpNode.getChildNode().get(0)); // 处理左侧的 EqExp
            traverseRelExp((Node) eqExpNode.getChildNode().get(2)); // 处理右侧的 RelExp
        }
    }

    private void traverseRelExp(Node relExpNode) {
        if (relExpNode.getChildNode().size() == 1) {
            traverseAddExp((Node) relExpNode.getChildNode().get(0));
        } else { // 递归处理 RelExp '<' AddExp 等
            traverseRelExp((Node) relExpNode.getChildNode().get(0)); // 处理左侧的 RelExp
            traverseAddExp((Node) relExpNode.getChildNode().get(2)); // 处理右侧的 AddExp
        }
    }

    private SymType traverseExp(Node node) {
        return traverseAddExp((Node) node.getChildNode().get(0));
    }

    private SymType traverseAddExp(Node addExpNode) { // AddExp → MulExp | AddExp ('+' | '−') MulExp
        Node firstChild = (Node) addExpNode.getChildNode().get(0);
        if (firstChild.getParType() == ParType.MulExp) {
            return traverseMulExp(firstChild);
        }
        else { // AddExp ('+' | '−') MulExp
            SymType leftType = traverseAddExp(firstChild); // 左侧递归调用 AddExp
            LeafNode operatorNode = (LeafNode) addExpNode.getChildNode().get(1); // '+' 或 '−'
            traverseMulExp((Node) addExpNode.getChildNode().get(2)); // 右侧 MulExp
            return leftType;
        }
    }

    private SymType traverseMulExp(Node mulExpNode) { // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        Node firstChild = (Node) mulExpNode.getChildNode().get(0);
        if (firstChild.getParType() == ParType.UnaryExp) {
            return traverseUnaryExp(firstChild);
        }
        else { // MulExp ('*' | '/' | '%') UnaryExp
            SymType leftType = traverseMulExp(firstChild); // 左侧递归调用 MulExp
            LeafNode operatorNode = (LeafNode) mulExpNode.getChildNode().get(1); // '*' '/' 或 '%'
            traverseUnaryExp((Node) mulExpNode.getChildNode().get(2)); // 右侧 UnaryExp
            return leftType;
        }
    }

    private SymType traverseUnaryExp(Node unaryExpNode) { // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        ASTNode firstChild = unaryExpNode.getChildNode().get(0);
        if (firstChild instanceof Node && ((Node) firstChild).getParType() == ParType.PrimaryExp) {
            return traversePrimaryExp((Node) firstChild);
        }
        else if (firstChild instanceof LeafNode identNode) { // Ident '(' [FuncRParams] ')' 解析函数调用
            if (curSymbolTable.unDefined(identNode.getName())) { // c:
                errorList.add(new Err(identNode.getLineNum(),"c"));
                return null;
            }
            else {
                FuncSymbol symbol = (FuncSymbol) curSymbolTable.getSymbol(identNode.getName());
                if (unaryExpNode.getChildNode().get(2) instanceof Node) {
                    int ret = traverseFuncRParams((Node) unaryExpNode.getChildNode().get(2),symbol); // 返回实参个数
                    if (ret == 1) {
                        errorList.add(new Err(identNode.getLineNum(),"d"));
                        return symbol.getRetType() == 1? SymType.Int : symbol.getRetType() == 2? SymType.Char : SymType.VoidFunc;
                    }
                    else if (ret == 2) {
                        errorList.add(new Err(identNode.getLineNum(),"e"));
                        return symbol.getRetType() == 1? SymType.Int : symbol.getRetType() == 2? SymType.Char : SymType.VoidFunc;
                    }
                }
                return symbol.getRetType() == 0 ? SymType.VoidFunc : symbol.getRetType() == 1 ? SymType.Int : SymType.Char;
            }
        }
        else {
            LeafNode unaryOp = (LeafNode)((Node) unaryExpNode.getChildNode().get(0)).getChildNode().get(0); // UnaryOp UnaryExp 处理单目运算符
            return traverseUnaryExp((Node) unaryExpNode.getChildNode().get(1));
        }
    }

    private SymType traversePrimaryExp(Node primaryExpNode) { // PrimaryExp → '(' Exp ')' | LVal | Number | Character
        ASTNode firstChild = primaryExpNode.getChildNode().get(0);
        if (firstChild instanceof LeafNode) {
            return traverseExp((Node) primaryExpNode.getChildNode().get(1));
        }
        else {
            Node child = (Node) firstChild;
            if (child.getParType() == ParType.LVal) {
                return traverseLVal((Node) firstChild); // 变量或数组
            } else if (child.getParType() == ParType.Number) {
                return SymType.Int;
            } else {
                return SymType.Char;
            }
        }
    }

    private int  traverseFuncRParams(Node funcRParamsNode, FuncSymbol funcSymbol) { // 1: 参数个数不匹配 2: 参数类型不匹配
        ArrayList<SymType> paramTypeList = funcSymbol.getParamTypeList();
        int paramNum = funcSymbol.getParamNum();
        int realParamNum = 0;
        for (ASTNode node : funcRParamsNode.getChildNode()) {
            if (node instanceof Node) {
                realParamNum++;
            }
        }
        if (realParamNum != paramNum) {
            return 1;
        }
        int i = 0;
        for (ASTNode node : funcRParamsNode.getChildNode()) {
            if (node instanceof Node realParamNode) {
                SymType realParamType = traverseExp(realParamNode); // 通过 traverseExp 获取实参的类型
                SymType expectedParamType = paramTypeList.get(i++); // 期望的参数类型
                if (realParamType == SymType.VoidFunc) {
                    return 2;
                }
                if (isArrayType(realParamType) && !isArrayType(expectedParamType)) {
                    return 2;
                }
                else if (!isArrayType(realParamType) && isArrayType(expectedParamType)) {
                    return 2;
                }
                else if ((realParamType == SymType.CharArray || realParamType == SymType.ConstCharArray) && (expectedParamType == SymType.IntArray || expectedParamType == SymType.ConstIntArray)) {
                    return 2;
                }
                else if ((realParamType == SymType.IntArray || realParamType == SymType.ConstIntArray) && (expectedParamType == SymType.CharArray || expectedParamType == SymType.ConstCharArray)) {
                    return 2;
                }
            }
        }
        return 0;
    }

    private boolean isArrayType(SymType type) {
        return type == SymType.IntArray || type == SymType.CharArray || type ==  SymType.ConstIntArray || type == SymType.ConstCharArray;
    }

    private void traverseUnchangedLVal(Node node) { // c: h:不可改变的左值
        LeafNode ident = (LeafNode)node.getChildNode().get(0);
        if (curSymbolTable.unDefined(ident.getName())) {
            errorList.add(new Err(ident.getLineNum(), "c"));
        }
        else if (curSymbolTable.isConst(ident.getName())) {
            errorList.add(new Err(ident.getLineNum(),"h"));
        }
    }

    private SymType traverseLVal(Node node) {
        LeafNode ident = (LeafNode)node.getChildNode().get(0);
        if (curSymbolTable.unDefined(ident.getName())) {
            errorList.add(new Err(ident.getLineNum(), "c"));
            return null;
        }
        else {
            Symbol symbol = curSymbolTable.getSymbol(ident.getName());
            if (symbol.isArray()) {
                if (node.getChildNode().size() < 3) {
                    return symbol.getSymType();
                }
                else {
                    if (symbol.getSymType() == SymType.CharArray) {
                        return SymType.Char;
                    }
                    else if (symbol.getSymType() == SymType.ConstCharArray) {
                        return SymType.ConstChar;
                    }
                    else if (symbol.getSymType() == SymType.ConstInt) {
                        return SymType.Int;
                    }
                    else {
                        return SymType.ConstInt;
                    }
                }
            }
            else {
                return symbol.getSymType();
            }

        }
    }

    private void traverseFuncParams(Node params) {
        for (ASTNode paramNode : params.getChildNode()) {
            if (paramNode instanceof Node) {
                traverseFuncParam((Node)paramNode);
            }
        }
    }

    private void traverseFuncParamTypes(Node params, ArrayList<SymType> paramSymTypes) {
        for (ASTNode paramNode : params.getChildNode()) {
            if (paramNode instanceof Node) {
                int bType = ((LeafNode)(((Node) ((Node)paramNode).getChildNode().get(0))).getChildNode().get(0)).getLexType() == LexType.INTTK ? 1 : 2;
                if (bType == 1 && ((Node) paramNode).getChildNode().size() > 2) {
                    paramSymTypes.add(SymType.IntArray);
                } else if (bType == 1 && ((Node) paramNode).getChildNode().size() == 2) {
                    paramSymTypes.add(SymType.Int);
                } else if (bType == 2 && ((Node) paramNode).getChildNode().size() > 2) {
                    paramSymTypes.add(SymType.CharArray);
                } else {
                    paramSymTypes.add(SymType.Char);
                }
            }
        }
    }

    private void traverseFuncParam(Node funcFParamNode) {
        int bType = ((LeafNode)((Node)funcFParamNode.getChildNode().get(0)).getChildNode().get(0)).getLexType() == LexType.INTTK ? 1 : 2;
        LeafNode identNode = (LeafNode) funcFParamNode.getChildNode().get(1);
        String paramName = identNode.getName();
        if (curSymbolTable.isRedefined(paramName)) {
            errorList.add(new Err(identNode.getLineNum(),"b"));
            return;
        }
        if (bType == 1 && funcFParamNode.getChildNode().size() > 2) {
            ArraySymbol symbol = new ArraySymbol(paramName,curId,curLevel,SymType.IntArray,((LeafNode) funcFParamNode.getChildNode().get(3)).getNumber());
            curSymbolTable.addSymbol(symbol);
        }
        else if (bType == 1 && funcFParamNode.getChildNode().size() == 2) {
            Symbol symbol = new Symbol(paramName, curId, curLevel, SymType.Int);
            curSymbolTable.addSymbol(symbol);
        }
        else if (bType == 2 && funcFParamNode.getChildNode().size() > 2) {
            ArraySymbol symbol = new ArraySymbol(paramName,curId,curLevel,SymType.CharArray,((LeafNode) funcFParamNode.getChildNode().get(3)).getNumber());
            curSymbolTable.addSymbol(symbol);
        }
        else {
            Symbol symbol = new Symbol(paramName, curId, curLevel, SymType.Char);
            curSymbolTable.addSymbol(symbol);
        }
    }

    private void traverseDecl(Node node) {
        Node decl = (Node) node.getChildNode().get(0);
        if (decl.getParType() == ParType.ConstDecl) {
            traverseConstDecl(decl);
        } else if (decl.getParType() == ParType.VarDecl) {
            traverseVarDecl(decl);
        }
    }

    private void traverseConstDecl(Node node) {
        int bType = ((LeafNode)((Node)node.getChildNode().get(1)).getChildNode().get(0)).getLexType() == LexType.INTTK ? 1 : 2;
        for (ASTNode constDefNode : node.getChildNode()) {
            if (constDefNode instanceof Node && ((Node)constDefNode).getParType() == ParType.ConstDef) {
                traverseConstDef((Node) constDefNode, bType);
            }
        }
    }

    private void traverseVarDecl(Node node) {
        int bType = ((LeafNode)((Node)node.getChildNode().get(0)).getChildNode().get(0)).getLexType() == LexType.INTTK ? 1 : 2;
        for (ASTNode varDefNode : node.getChildNode()) {
            if (varDefNode instanceof Node && ((Node)varDefNode).getParType() == ParType.VarDef) {
                traverseVarDef((Node) varDefNode, bType);
            }
        }
    }

    private void traverseConstDef(Node constDef, int bType) { // 1:int 2:char
        LeafNode identNode = (LeafNode)constDef.getChildNode().get(0);
        if (curSymbolTable.isRedefined(identNode.getName())) { // b: 名字重定义
            errorList.add(new Err(identNode.getLineNum(),"b"));
        }
        else {
            if (bType == 1 && ((LeafNode)constDef.getChildNode().get(1)).getLexType() != LexType.LBRACK) { // int
                Symbol symbol = new Symbol(identNode.getName(), curId, curLevel, SymType.ConstInt);
                curSymbolTable.addSymbol(symbol);
                if (constDef.getChildNode().size() > 2) { // 有赋值
                    traverseInitVal((Node)constDef.getChildNode().get(2));
                }

            }
            else if (bType == 1 && ((LeafNode)constDef.getChildNode().get(1)).getLexType() == LexType.LBRACK) { // intArray
                ArraySymbol symbol = new ArraySymbol(identNode.getName(), curId, curLevel, SymType.ConstIntArray,identNode.getNumber());
                curSymbolTable.addSymbol(symbol);
                traverseExp((Node) constDef.getChildNode().get(2));
                if (constDef.getChildNode().size() > 5) {
                    traverseInitVal((Node)constDef.getChildNode().get(5));
                }
            }
            else if (bType == 2 && ((LeafNode)constDef.getChildNode().get(1)).getLexType() != LexType.LBRACK) { // char
                Symbol symbol = new Symbol(identNode.getName(), curId, curLevel, SymType.ConstChar);
                curSymbolTable.addSymbol(symbol);
                if (constDef.getChildNode().size() > 2) { // 有赋值
                    traverseInitVal((Node)constDef.getChildNode().get(2));
                }
            }
            else { // charArray
                Symbol symbol = new ArraySymbol(identNode.getName(), curId, curLevel, SymType.ConstCharArray,identNode.getNumber());
                curSymbolTable.addSymbol(symbol);
                traverseExp((Node) constDef.getChildNode().get(2));
                if (constDef.getChildNode().size() > 5) {
                    traverseInitVal((Node)constDef.getChildNode().get(5));
                }
            }
        }
    }

    private void traverseVarDef(Node varDef, int bType) {
        LeafNode identNode = (LeafNode)varDef.getChildNode().get(0);
        if (curSymbolTable.isRedefined(identNode.getName())) { // b: 名字重定义
            errorList.add(new Err(identNode.getLineNum(),"b"));
        }
        else {
            if (varDef.getChildNode().size() < 2) { // 声明char/int不赋值
                if (bType == 1) {
                    Symbol symbol = new Symbol(identNode.getName(), curSymbolTable.getId(), curLevel, SymType.Int);
                    curSymbolTable.addSymbol(symbol);
                }
                else {
                    Symbol symbol = new Symbol(identNode.getName(), curSymbolTable.getId(), curLevel, SymType.Char);
                    curSymbolTable.addSymbol(symbol);
                }
            }
            else { // 声明char、int数组、赋值
                if (bType == 1 && ((LeafNode) varDef.getChildNode().get(1)).getLexType() != LexType.LBRACK) { // int赋值
                    Symbol symbol = new Symbol(identNode.getName(), curSymbolTable.getId(), curLevel, SymType.Int);
                    curSymbolTable.addSymbol(symbol);
                    traverseInitVal((Node)varDef.getChildNode().get(2));
                } else if (bType == 1 && ((LeafNode) varDef.getChildNode().get(1)).getLexType() == LexType.LBRACK) { // int数组
                    ArraySymbol symbol = new ArraySymbol(identNode.getName(), curSymbolTable.getId(), curLevel, SymType.IntArray,identNode.getNumber());
                    curSymbolTable.addSymbol(symbol);
                    traverseConstExp((Node)varDef.getChildNode().get(2));
                    if (varDef.getChildNode().size() > 5) { // 有赋值
                        traverseInitVal((Node) varDef.getChildNode().get(5));
                    }
                } else if (bType == 2 && ((LeafNode) varDef.getChildNode().get(1)).getLexType() != LexType.LBRACK) { // char赋值
                    Symbol symbol = new Symbol(identNode.getName(), curSymbolTable.getId(), curLevel, SymType.Char);
                    curSymbolTable.addSymbol(symbol);
                    traverseInitVal((Node)varDef.getChildNode().get(2));
                } else { // char数组
                    ArraySymbol symbol = new ArraySymbol(identNode.getName(), curSymbolTable.getId(), curLevel, SymType.CharArray,identNode.getNumber());
                    curSymbolTable.addSymbol(symbol);
                    traverseConstExp((Node)varDef.getChildNode().get(2));
                    if (varDef.getChildNode().size() > 5) { // 有赋值
                        traverseInitVal((Node) varDef.getChildNode().get(5));
                    }
                }
            }
        }
    }

    private void traverseConstExp(Node constExp) {
        traverseAddExp((Node) constExp.getChildNode().get(0));
    }

    private void traverseInitVal(Node initVal) {
        if (initVal.getChildNode().get(0) instanceof LeafNode) { //{[exp{,exp}]}
            for (ASTNode node : initVal.getChildNode()) {
                if (node instanceof Node) {
                    traverseExp((Node) node);
                }
            }
        }
        else if (((Node)initVal.getChildNode().get(0)).getParType() == ParType.Exp) { // Exp
            traverseExp((Node) initVal.getChildNode().get(0));
        }
        // StringConst
    }

}
