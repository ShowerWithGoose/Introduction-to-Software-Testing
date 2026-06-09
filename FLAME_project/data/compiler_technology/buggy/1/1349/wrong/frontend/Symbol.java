package frontend;

import frontend.Def.Def;
import frontend.Def.DefType;
import frontend.Node.Node;
import frontend.Node.NodeType;
import frontend.Token.Token;
import frontend.Token.TokenType;

import java.io.BufferedWriter;
import java.util.HashMap;

public class Symbol {
    private BufferedWriter stdWriter = Config.SYMBOL_WRITER;

    private ErrorHandler errorHandler;

    private final HashMap<String, FuncInfo> funcTable = new HashMap<>();

    private final Layer globalLayer = new Layer("global");

    private Node CompUnit;

    private int level = 0;

    public Symbol(Node CompUnit, ErrorHandler errorHandler) {
        this.errorHandler = errorHandler;
        this.CompUnit = CompUnit;
        begin();
    }

    public void printSymbols() {
        print(globalLayer);
    }

    public void print(Layer layer) {
        try {
            level ++;
            for (Def def : layer.declares) {
                stdWriter.write(level + " " + def.getName() + " " + def.getType() + "\n");
            }
            for (Layer l : layer.layers) {
                print(l);
            }
        } catch (Exception e) {
            throw new RuntimeException("Error writing to file");
        }
    }

    private void begin() {
        for (Object child : CompUnit.getChildren()) {
            if (child instanceof Node && isDecl((Node) child)) {
                handleDecl((Node) child, globalLayer);
            }
            if (child instanceof Node && ((Node) child).getType() == NodeType.FuncDef) {
                handleFuncDef((Node) child, globalLayer);
            }
        }
        handleMainFuncDef();
    }

    private void handleMainFuncDef() {
        Node mainFuncDef = (Node) CompUnit.getChildren().get(CompUnit.getChildren().size() - 1);
        Layer mainLayer = globalLayer.addNewLayer("main");
        FuncInfo funcInfo = new FuncInfo("main", 0, "int");
        funcTable.put("main", funcInfo);
        Node Block = (Node) mainFuncDef.getChildren().get(mainFuncDef.getChildren().size() - 1);
        handleBlock(Block, mainLayer);
    }

    private boolean isDecl(Node node) {
        return node.getType() == NodeType.VarDecl || node.getType() == NodeType.ConstDecl;
    }

    private void handleDecl(Node node, Layer layer) {
        if (node.getType() == NodeType.ConstDecl) {
            handleConstDecl(node, layer);
        } else if (node.getType() == NodeType.VarDecl) {
            handleVarDecl(node, layer);
        }
    }

    private void handleVarDecl(Node node, Layer layer) {
        Token Btype = (Token) node.getChildren().get(0);
        int index = 1;
        while (index < node.getChildren().size()) {
            Node VarDef = (Node) node.getChildren().get(index);
            Token Ident = (Token) VarDef.getChildren().get(0);
            Def def;
            if (VarDef.getChildren().size() > 1) {
                Object object = VarDef.getChildren().get(1);
                if (object instanceof Token && ((Token) object).getType() == TokenType.LBRACK) {
                    if (Btype.getType() == TokenType.INTTK) {
                        def = new Def(Ident.getValue(), DefType.IntArray);
                    } else {
                        def = new Def(Ident.getValue(), DefType.CharArray);
                    }
                } else {
                    if (Btype.getType() == TokenType.INTTK) {
                        def = new Def(Ident.getValue(), DefType.Int);
                    } else {
                        def = new Def(Ident.getValue(), DefType.Char);
                    }
                }
            } else {
                if (Btype.getType() == TokenType.INTTK) {
                    def = new Def(Ident.getValue(), DefType.Int);
                } else {
                    def = new Def(Ident.getValue(), DefType.Char);
                }
            }
            checkAndAddDef(def, layer, Ident.getLine());  // 检查变量是否重复定义
            Object object = VarDef.getChildren().get(VarDef.getChildren().size() - 1);
            if (object instanceof Node && ((Node) object).getType() == NodeType.InitVal){
                dfs((Node) object, layer);
            }
            index += 2;
        }
    }

    private void handleConstDecl(Node node, Layer layer) {
        Token Btype = (Token) node.getChildren().get(1);
        int index = 2;
        while (index < node.getChildren().size()) {
            Node ConstDef = (Node) node.getChildren().get(index);
            Token Ident = (Token) ConstDef.getChildren().get(0);
            Object object = ConstDef.getChildren().get(1);
            Def def;
            if (object instanceof Token && ((Token) object).getType() == TokenType.LBRACK) {
                if (Btype.getType() == TokenType.INTTK) {
                    def = new Def(Ident.getValue(), DefType.ConstIntArray);
                } else {
                    def = new Def(Ident.getValue(), DefType.ConstCharArray);
                }
            } else {
                if (Btype.getType() == TokenType.INTTK) {
                    def = new Def(Ident.getValue(), DefType.ConstInt);
                } else {
                    def = new Def(Ident.getValue(), DefType.ConstChar);
                }
            }
            checkAndAddDef(def, layer, Ident.getLine());  // 检查常量是否重复定义
            if (object instanceof Node && ((Node) object).getType() == NodeType.InitVal){
                dfs((Node) object, layer);
            }
            index += 2;
        }
    }

    private void handleFuncDef(Node node, Layer layer) {
        Node type = (Node) node.getChildren().get(0);
        Token FuncType = (Token) type.getChildren().get(0);
        Token Ident = (Token) node.getChildren().get(1);
        Object object = node.getChildren().get(3);
        Def def;
        if (FuncType.getType() == TokenType.VOIDTK) {
            def = new Def(Ident.getValue(), DefType.VoidFunc);
        } else if (FuncType.getType() == TokenType.INTTK) {
            def = new Def(Ident.getValue(), DefType.IntFunc);
        } else {
            def = new Def(Ident.getValue(), DefType.CharFunc);
        }
        if (checkAndAddDef(def, layer, Ident.getLine())) { // 检查函数名是否重复
            FuncInfo funcInfo;
            Layer newLayer = layer.addNewLayer(Ident.getValue());
            if (object instanceof Node && ((Node) object).getType() == NodeType.FuncFParams) { // 有参数
                Node FuncFParams = (Node) object;
                funcInfo = new FuncInfo(Ident.getValue(), (FuncFParams.getChildren().size() + 1) / 2, FuncType.getValue());
                int index = 0;
                while (index < FuncFParams.getChildren().size()) {
                    Node FuncFParam = (Node) FuncFParams.getChildren().get(index); // 参数
                    Token ParamType = (Token) FuncFParam.getChildren().get(0); // 参数类型
                    Token ParamIdent = (Token) FuncFParam.getChildren().get(1); // 参数名
                    Def paramDef;
                    if (FuncFParam.getChildren().size() > 2) {
                        if (ParamType.getType() == TokenType.INTTK) {
                            paramDef = new Def(ParamIdent.getValue(), DefType.IntArray);
                        } else {
                            paramDef = new Def(ParamIdent.getValue(), DefType.CharArray);
                        }
                    } else {
                        if (ParamType.getType() == TokenType.INTTK) {
                            paramDef = new Def(ParamIdent.getValue(), DefType.Int);
                        } else {
                            paramDef = new Def(ParamIdent.getValue(), DefType.Char);
                        }
                    }
                    checkAndAddDef(paramDef, newLayer, ParamIdent.getLine());
                    index += 2;
                }
            } else {
                funcInfo = new FuncInfo(Ident.getValue(), 0, FuncType.getValue());
            }
            funcTable.put(Ident.getValue(), funcInfo);
            Node Block = (Node) node.getChildren().get(node.getChildren().size() - 1);
            handleBlock(Block, newLayer); // 处理函数体
        }
    }

    private void handleBlock(Node node, Layer layer) {
        dfs(node, layer);
    }

    private void dfs(Node node, Layer layer) {
        for (Object child : node.getChildren()) {
            if (child instanceof Node && ((Node) child).getType() == NodeType.Block) {
                Node grandFather = ((Node) child).getFather().getFather();
                Layer newLayer;
                if (grandFather.getType() == NodeType.Stmt) {
                    Object object = grandFather.getChildren().get(0);
                    if (object instanceof Token && ((Token) object).getType() == TokenType.IFTK) {
                        newLayer = layer.addNewLayer("if");
                    } else if (object instanceof Token && ((Token) object).getType() == TokenType.FORTK) {
                        newLayer = layer.addNewLayer("for");
                    } else {
                        newLayer = layer.addNewLayer(null);  // 无名层
                    }
                } else {
                    newLayer = layer.addNewLayer(null);  // 无名层
                }
                dfs((Node) child, newLayer);
            }
            else if (child instanceof Node && isDecl((Node) child)) {
                handleDecl((Node) child, layer);
            }
            else if (child instanceof Node && ((Node) child).getType() == NodeType.LVal) {
                Token Ident = (Token) ((Node) child).getChildren().get(0);
                if (!searchGlobalIdent(Ident.getValue(), layer)) {
                    errorHandler.addError('c', Ident.getLine()); // 未定义的标识符
                } else {
                    Node father = ((Node) child).getFather();
                    if (father.getChildren().size() > 1 && father.getChildren().get(1) instanceof Token &&
                            ((Token) father.getChildren().get(1)).getType() == TokenType.ASSIGN) {
                        Node LVal = (Node) child;
                        Token LValIdent = (Token) LVal.getChildren().get(0);
                        if (isConstDef(LValIdent.getValue(), layer)) { // 常量不能被赋值
                            errorHandler.addError('h', LValIdent.getLine());
                        }
                    }
                }
            } else if (child instanceof Token &&
                    ((((Token) child).getType() == TokenType.BREAKTK) ||
                            (((Token) child).getType() == TokenType.CONTINUETK))) {
                Token token = (Token) child;
                if (!layer.getType().equals("for")) {
                    errorHandler.addError('m', token.getLine()); // break和continue语句只能出现在循环语句中
                }
            } else if (child instanceof Token && ((Token) child).getType() == TokenType.RETURNTK) {
                Token token = (Token) child;
                Node father = token.getFather();
                Object object = father.getChildren().get(1);
                String funcName = searchFuncName(layer);
                FuncInfo funcInfo = funcTable.get(funcName);
                if (funcInfo.getReturnType().equals("void") && object instanceof Node) {
                    errorHandler.addError('f', token.getLine()); // 无返回值的函数存在不匹配的return语句
                }
            } else if (child instanceof Token && ((Token) child).getType() == TokenType.PRINTFTK) {
                Token token = (Token) child;
                Node father = token.getFather();
                int num1 = (father.getChildren().size() - 5) / 2;
                int num2 = 0;
                String str = ((Token) father.getChildren().get(2)).getValue();
                for (int i = 0; i < str.length(); i++) {
                    if (str.charAt(i) == '%') {
                        num2++;
                    }
                }
                if (num1 != num2) {
                    errorHandler.addError('l', token.getLine()); // printf函数参数不匹配
                }
            } else if (isFunc(child)) {
                Node father = ((Token) child).getFather();
                Token Ident = (Token) child;
                if (!searchGlobalIdent(Ident.getValue(), layer)) {
                    errorHandler.addError('c', Ident.getLine()); // 未定义的标识符， 函数名不存在
                } else {
                    if (father.getChildren().get(2) instanceof Node &&
                            ((Node) father.getChildren().get(2)).getType() == NodeType.FuncRParams) {
                        Node FuncRParams = (Node) father.getChildren().get(2);
                        checkParams(Ident.getValue(), FuncRParams, Ident.getLine(), layer);
                    }
                }
            } else if (isBlockEnd(child)) {
                String layType = layer.getType();
                if (layType != null && !layType.equals("if") && !layType.equals("for")) {
                    FuncInfo funcInfo = funcTable.get(layType);
                    if (funcInfo.getReturnType().equals("int") || funcInfo.getReturnType().equals("char")) {
                        Node father = ((Token) child).getFather();
                        int len = father.getChildren().size();
                        Object object = father.getChildren().get(len - 2); // 获取倒数第二个节点
                        if (object instanceof Node && ((Node) object).getType() == NodeType.Stmt) {
                            Node Stmt = (Node) object;
                            Object child1 = Stmt.getChildren().get(0);
                            if (!(child1 instanceof Token && ((Token) child1).getType() == TokenType.RETURNTK)) {
                                errorHandler.addError('g', ((Token) child).getLine()); // 有返回值的函数缺少return语句
                            }
                        } else {
                            errorHandler.addError('g', ((Token) child).getLine()); // 有返回值的函数缺少return语句
                        }
                    }
                }
            }
            else {
                if (child instanceof Node) {
                    dfs((Node) child, layer);
                }
            }
        }
    }

    private boolean isBlockEnd(Object child) {
        if (child instanceof Token && ((Token) child).getType() == TokenType.RBRACE) {
            Node father = ((Token) child).getFather();
            if (father.getType() == NodeType.Block) {
                return true;
            }
            return false;
        }
        return false;
    }

    private boolean isFunc(Object child) {
        if (child instanceof Token && ((Token) child).getType() == TokenType.IDENFR) {
            Node father = ((Token) child).getFather();
            if (father.getChildren().size() > 1 && father.getChildren().get(1) instanceof Token &&
                    ((Token) father.getChildren().get(1)).getType() == TokenType.LPARENT) {
                return true;
            }
        }
        return false;
    }

    private boolean checkLvalInRParams(Node node, Layer layer) {
        for (Object child : node.getChildren()) {
            if (child instanceof Node && ((Node) child).getType() == NodeType.LVal) {
                Token Ident = (Token) ((Node) child).getChildren().get(0);
                if (!searchGlobalIdent(Ident.getValue(), layer)) {
                    errorHandler.addError('c', Ident.getLine()); // 未定义的标识符
                    return false;
                }
            } else {
                if (child instanceof Node) {
                    if (!checkLvalInRParams((Node) child, layer)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private boolean checkParams(String funcName, Node RParams, int line, Layer layer) {
        if (!checkLvalInRParams(RParams, layer)) { // 检查参数是否存在未定义的标识符
            return false;
        }
        FuncInfo funcInfo = funcTable.get(funcName);
        if (funcInfo.getParamNum() != RParams.getChildren().size() / 2 + 1) {
            errorHandler.addError('d', line); // 函数参数个数不匹配
            return false;
        }
        Layer layer1 = null;
        for (Layer l : globalLayer.layers) {
            if (l.getType().equals(funcName)) {
                layer1 = l;
                break;
            }
        }
        int index = 0;
        while(index < funcInfo.getParamNum()) {
            Node RParam = (Node) RParams.getChildren().get(2 * index);
            Node node = RParam;
            while (node.getChildren().size() == 1 && node.getType() != NodeType.LVal) {
                if (node.getChildren().get(0) instanceof Node) {
                    node = (Node) node.getChildren().get(0);
                } else {
                    break;
                }
            }
            DefType RdefType;
            DefType FdefType = layer1.declares.get(index).getType();;
            if (node.getType() == NodeType.LVal && node.getChildren().size() == 1) { // 单个标识符，只有这种情况可能为数组
                Token Ident = (Token) node.getChildren().get(0);
                RdefType = getDefType(Ident.getValue(), layer);
            } else {
                RdefType = DefType.Int;
            }
            if (!matchParam(RdefType, FdefType)) {
                errorHandler.addError('e', line); // 函数参数类型不匹配
                return false;
            }
            index ++;
        }
        return true;
    }

    private boolean matchParam(DefType RdefType, DefType FdefType) {
        if ((RdefType == DefType.CharArray || RdefType == DefType.IntArray) &&
                (FdefType == DefType.Char || FdefType == DefType.Int)) {
            return false;
        }
        else if ((RdefType == DefType.Char || RdefType == DefType.Int) &&
                (FdefType == DefType.CharArray || FdefType == DefType.IntArray)) {
            return false;
        }
        else if (RdefType == DefType.CharArray && FdefType == DefType.IntArray) {
            return false;
        }
        else if (RdefType == DefType.IntArray && FdefType == DefType.CharArray) {
            return false;
        }
        return true;
    }

    private String searchFuncName(Layer layer) {
        while(layer.getType() == null || layer.getType().equals("if") || layer.getType().equals("for")) {
            layer = layer.getFather();
        }
        return layer.getType();
    }

    private DefType getDefType(String name, Layer layer) { // 不需要返回const, 递归查找
        for (Def def : layer.declares) {
            if (def.getName().equals(name)) {
                if (def.getType() == DefType.ConstInt || def.getType() == DefType.Int) {
                    return DefType.Int;
                } else if (def.getType() == DefType.ConstChar || def.getType() == DefType.Char) {
                    return DefType.Char;
                } else if (def.getType() == DefType.ConstIntArray || def.getType() == DefType.IntArray) {
                    return DefType.IntArray;
                } else if (def.getType() == DefType.ConstCharArray || def.getType() == DefType.CharArray) {
                    return DefType.CharArray;
                }
            }
        }
        if (layer.getFather() == null) {
            return null;
        }
        return getDefType(name, layer.getFather());
    }

    private boolean searchGlobalIdent(String name, Layer layer) {
        for (Def def : layer.declares) {
            if (def.getName().equals(name)) {
                return true;
            }
        }
        if (layer.getFather() == null) {
            return false;
        }
        return searchGlobalIdent(name, layer.getFather());
    }

    private boolean searchLayerIdent(String name, Layer layer) {   // 搜索当前层是否有重复定义
        for (Def def : layer.declares) {
            if (def.getName().equals(name)) {
                return true;
            }
        }
        return false;
    }

    private boolean checkAndAddDef(Def def, Layer layer, int line) {
        if (searchLayerIdent(def.getName(), layer)) {
            errorHandler.addError('b', line);
            return false;
        } else {
            layer.addDeclare(def);
            return true;
        }

    }

    private boolean isConstDef(String name, Layer layer) {
        for (Def def : layer.declares) {
            if (def.getName().equals(name)) {
                if (def.getType() == DefType.ConstInt || def.getType() == DefType.ConstChar ||
                        def.getType() == DefType.ConstIntArray || def.getType() == DefType.ConstCharArray) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        return isConstDef(name, layer.getFather());
    }

}
