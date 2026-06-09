package frontend.Visitor;

import frontend.Error.ErrorManager;
import frontend.Error.ErrorToken;
import frontend.Error.ErrorType;
import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.*;
import frontend.Symbol.*;
import frontend.Utils;

import java.util.*;

public class Visitor
{
    //<editor-fold> desc=单例模式
    private static final Visitor instance = new Visitor();

    private Visitor() {
    }

    public static Visitor GetInstance() {
        return instance;
    }

    //</editor-fold>
    private GrammarTreeNode root;
    private int checkingTypeIndex;
    private Map<Integer, MyType> checkingType = new HashMap<>();
    private int checkType = 0;
    private boolean typeIgnore;
    private MyType returnType;
    private int circleDepth = 0;

    public void Init() {
        root = Parser.GetInstance().GetTree();
    }

    public void Process() {
        ProcessCompUnit(root);
    }

    private void Error() {
    }

    public void Error(ErrorType errorType, Token token) {
        ErrorToken errorToken = new ErrorToken(null, token.getLineNo(), errorType);
        ErrorManager.GetInstance().setError(true);
        ErrorManager.GetInstance().addError(errorToken);

    }

    private void Error(ErrorType errorType, int lineNo) {
        ErrorToken errorToken = new ErrorToken(null, lineNo, errorType);
        ErrorManager.GetInstance().setError(true);
        ErrorManager.GetInstance().addError(errorToken);

    }

    private void SetCheckingType(int index, MyType type) {
        if (!checkingType.containsKey(index)) {
            checkingType.put(index, type);
        }
        else if (type == MyType.CharArray || type == MyType.IntArray) {
            checkingType.replace(index, type);
        }
        else if (type == MyType.Int && checkingType.get(index) != MyType.IntArray && checkingType.get(index) != MyType.CharArray) {
            checkingType.replace(index, type);
        }
        else if (type == MyType.Char && checkingType.get(index) != MyType.Int && checkingType.get(index) != MyType.IntArray && checkingType.get(index) != MyType.CharArray) {
            checkingType.replace(index, type);
        }

    }

    private void ProcessCompUnit(GrammarTreeNode node) {
        for (GrammarTreeNode nodeChild : node.getChildren()) {
            GrammarWord grammarWord = nodeChild.getGrammarWord();
            Nonterminal nonterminal = grammarWord instanceof Nonterminal ? (Nonterminal) grammarWord : null;
            if (nonterminal != null) {
                switch (nonterminal.getType()) {
                    case Decl -> ProcessDecl(nodeChild);
                    case FuncDef -> ProcessFuncDef(nodeChild);
                    case MainFuncDef -> ProcessMainFuncDef(nodeChild);
                }
            }
            else {
                Error();
            }
        }
    }

    private void ProcessMainFuncDef(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        ProcessBlock(childList.get(4), true, MyType.Int, new Symbol[0]);
    }

    private void ProcessDecl(GrammarTreeNode node) {
        if (node.getChildren().size() != 1) {
            Error();
            return;
        }
        GrammarWord grammarWord = node.getChildren().get(0).getGrammarWord();
        Nonterminal nonterminal = grammarWord instanceof Nonterminal ? (Nonterminal) grammarWord : null;
        if (nonterminal != null) {
            if (nonterminal.getType() == NonterminalType.ConstDecl) {
                ProcessConstDecl(node.getChildren().get(0));
            }
            else if (nonterminal.getType() == NonterminalType.VarDecl) {
                ProcessVarDecl(node.getChildren().get(0));
            }
            else {
                Error();
            }
        }
        else {
            Error();
        }
    }

    private void ProcessConstDecl(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        int typeIndex = 1;//表类型的下标
        TokenType type = ((Token) (childList.get(typeIndex).getChildren().get(0).getGrammarWord())).getType();
        MyType type1 = type == TokenType.CharTk ? MyType.Char : MyType.Int;
        int index = 2; //表Def的下标
        while (index < childList.size()) {
            ProcessConstDef(childList.get(index), type1);
            index += 2;
        }
    }

    private void ProcessVarDecl(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        TokenType type = ((Token) (childList.get(0).getChildren().get(0).getGrammarWord())).getType();
        MyType type1 = type == TokenType.CharTk ? MyType.Char : MyType.Int;
        int index = 1;
        while (index < childList.size()) {
            ProcessVarDef(childList.get(index), type1);
            index += 2;
        }
    }

    private void ProcessVarDef(GrammarTreeNode node, MyType type) {
        List<GrammarTreeNode> childList = node.getChildren();
        Token token = (Token) childList.get(0).getGrammarWord();
        SymbolType symbolType;
        int index = 1;
        GrammarTreeNode sizeNode;
        GrammarTreeNode valueNode;
        Token tokenCheck;
        if (childList.size() > 1 && (tokenCheck = (Token) childList.get(1).getGrammarWord()).getType() == TokenType.LBracket) {
            //ARRAY
            if (type == MyType.Char) {
                symbolType = SymbolType.CharArray;
            }
            else {
                symbolType = SymbolType.IntArray;
            }
            sizeNode = childList.get(2);
            valueNode = childList.size() > 4 ? childList.get(5) : null;
            ProcessConstExp(sizeNode);
            if (valueNode != null) {
                ProcessInitVal(valueNode);
            }
            Symbol symbol = new Symbol(token, symbolType, valueNode, sizeNode, false);
            SymbolManager.GetInstance().AddSymbol(symbol);
        }
        else {
            //SINGLE VAR
            if (type == MyType.Char) {
                symbolType = SymbolType.CharVar;
            }
            else {
                symbolType = SymbolType.IntVar;
            }
            valueNode = childList.size() > 1 ? childList.get(2) : null;

            if (valueNode != null) {
                ProcessInitVal(valueNode);
            }

            Symbol symbol = new Symbol(token, symbolType, valueNode, false);
            SymbolManager.GetInstance().AddSymbol(symbol);

        }
    }

    private void ProcessInitVal(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        int size = childList.size();
        if (size == 1) {
            if (childList.get(0).getGrammarWord() instanceof Nonterminal) {
                ProcessExp(childList.get(0));
            }
        }
        else if (size != 2) {
            //数组初始化
            int index = 1;
            while (index < size - 1) {
                ProcessExp(childList.get(index));
                index += 2;
            }
        }

    }

    private void ProcessConstDef(GrammarTreeNode node, MyType type) {
        List<GrammarTreeNode> childList = node.getChildren();
        Token token = (Token) childList.get(0).getGrammarWord();
        SymbolType symbolType;
        int index = 1;
        GrammarTreeNode sizeNode;
        GrammarTreeNode valueNode;

        Token tokenCheck = (Token) childList.get(1).getGrammarWord();
        if (tokenCheck.getType() == TokenType.LBracket) {
            //Array
            if (type == MyType.Char) {
                symbolType = SymbolType.ConstCharArray;
            }
            else {
                symbolType = SymbolType.ConstIntArray;
            }
            sizeNode = childList.get(2);
            valueNode = childList.get(5);

            ProcessConstExp(sizeNode);
            ProcessConstInitVal(valueNode);

            Symbol symbol = new Symbol(token, symbolType, valueNode, sizeNode, true);
            SymbolManager.GetInstance().AddSymbol(symbol);


        }
        else {
            //Single Var
            if (type == MyType.Char) {
                symbolType = SymbolType.ConstChar;
            }
            else {
                symbolType = SymbolType.ConstInt;
            }
            valueNode = childList.get(2);

            ProcessConstInitVal(valueNode);

            Symbol symbol = new Symbol(token, symbolType, valueNode, true);
            SymbolManager.GetInstance().AddSymbol(symbol);
        }

    }

    private void ProcessConstInitVal(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        int size = childList.size();
        if (size == 1) {
            if (childList.get(0).getGrammarWord() instanceof Nonterminal) {
                ProcessConstExp(childList.get(0));
            }
        }
        else if (size != 2) {
            //数组初始化
            int index = 1;
            while (index < size - 1) {
                ProcessConstExp(childList.get(index));
                index += 2;
            }
        }
    }

    private void ProcessConstExp(GrammarTreeNode node) {
        ProcessAddExp(node.getChildren().get(0));
    }

    private void ProcessCond(GrammarTreeNode node) {
        ProcessLOrExp(node.getChildren().get(0));
    }

    private void ProcessLOrExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.size() > 1) {
            ProcessLOrExp(childList.get(0));
            ProcessLAndExp(childList.get(2));
        }
        else {
            ProcessLAndExp(childList.get(0));
        }
    }

    private void ProcessLAndExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.size() > 1) {
            ProcessLAndExp(childList.get(0));
            ProcessEqExp(childList.get(2));
        }
        else {
            ProcessEqExp(childList.get(0));
        }
    }

    private void ProcessEqExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.size() > 1) {
            ProcessEqExp(childList.get(0));
            ProcessRelExp(childList.get(2));
        }
        else {
            ProcessRelExp(childList.get(0));
        }
    }

    private void ProcessRelExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.size() > 1) {
            ProcessRelExp(childList.get(0));
            ProcessAddExp(childList.get(2));
        }
        else {
            ProcessAddExp(childList.get(0));
        }
    }

    private void ProcessAddExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.size() > 1) {
            ProcessAddExp(childList.get(0));
            ProcessMulExp(childList.get(2));
        }
        else {
            ProcessMulExp(childList.get(0));
        }
    }

    private void ProcessMulExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.size() > 1) {
            ProcessMulExp(childList.get(0));
            ProcessUnaryExp(childList.get(2));
        }
        else {
            ProcessUnaryExp(childList.get(0));
        }
    }

    private void ProcessUnaryExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.get(0).getGrammarWord() instanceof Token token) {
            //先查符号表
            Symbol symbol = SymbolManager.GetInstance().TrySearchSymbol(token.getContent());
            if (symbol != null) {
                //查到了
                if (symbol.getSymbolExtend() instanceof Func func) {
                    SetCheckingType(checkingTypeIndex, func.returnType);
                    if (childList.size() > 3) {
                        if (((Nonterminal) childList.get(2).getGrammarWord()).getType() == NonterminalType.FuncRParams) {
                            ProcessFuncRParams(childList.get(2), token, symbol);
                        }
                    }
                    else {
                        if (func.paramSize != 0) {
                            Error(ErrorType.FuncParamNumUnmatched, token);
                        }
                    }
                }
            }
            else {
                Error(ErrorType.NameUndeclared, token);
                typeIgnore = true;
            }
        }
        else if (childList.get(0).getGrammarWord() instanceof Nonterminal nonterminal) {
            if (nonterminal.getType() == NonterminalType.PrimaryExp) {
                ProcessPrimaryExp(childList.get(0));
            }
            else if (nonterminal.getType() == NonterminalType.UnaryOp) {
                ProcessUnaryExp(childList.get(1));
            }
        }
    }

    private void ProcessFuncRParams(GrammarTreeNode node, Token token, Symbol symbol) {
        List<GrammarTreeNode> childList = node.getChildren();
        int paramSize = (childList.size() + 1) / 2;
        Func func = (Func) symbol.getSymbolExtend();
        List<MyType> types = new ArrayList<>();
        checkType++;
        if (paramSize == func.paramSize) {
            int index = 0;
            while (index < childList.size()) {
                int checkingIndex = checkingTypeIndex + 1;

                typeIgnore = false;

                ProcessExp(childList.get(index));
                index += 2;
                types.add(checkingType.get(checkingIndex));
            }
            if (!typeIgnore) {
                for (int i = 0; i < types.size(); i++) {
                    if (!Utils.CheckType(types.get(i), func.paramTypes[i])) {

                        Error(ErrorType.FuncParamTypeUnmatched, token);
                        break;
                    }
                }
            }
        }
        else {
            Error(ErrorType.FuncParamNumUnmatched, token);
        }
        checkType--;
    }

    private void ProcessExp(GrammarTreeNode node) {
        if (checkType > 0) {
            checkingTypeIndex++;
        }
        int index = checkingTypeIndex;
        ProcessAddExp(node.getChildren().get(0));
        if (checkType > 0 && !checkingType.containsKey(index)) {
            SetCheckingType(index, checkingType.get(index+1));
        }
    }

    private void ProcessPrimaryExp(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.get(0).getGrammarWord() instanceof Token token) {
            if (token.getType() == TokenType.LParent) {
                ProcessExp(childList.get(1));
            }
        }
        else if (childList.get(0).getGrammarWord() instanceof Nonterminal nonterminal) {
            if (nonterminal.getType() == NonterminalType.LVal) {
                ProcessLVal(node.getChildren().get(0));
            }
            else if (nonterminal.getType() == NonterminalType.Number) {
                SetCheckingType(checkingTypeIndex, MyType.Int);
            }
            else if (nonterminal.getType() == NonterminalType.Character) {
                SetCheckingType(checkingTypeIndex, MyType.Char);
            }
        }
    }

    private int ProcessLVal(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        Token ident = (Token) childList.get(0).getGrammarWord();
        Symbol symbol = SymbolManager.GetInstance().TrySearchSymbol(ident.getContent());
        int ret = 0;
        if (symbol != null) {
            if (childList.size() > 1) {
                SetCheckingType(checkingTypeIndex, Utils.SymbolTypeArray2SingleVarMyType(symbol.getSymbolType()));
            }
            else {
                SetCheckingType(checkingTypeIndex, Utils.SymbolType2VarMyType(symbol.getSymbolType()));
            }
            if (symbol.isConstant()) {
                ret = ident.getLineNo();
            }
        }
        else {
            Error(ErrorType.NameUndeclared, ident);
            typeIgnore = true;
        }
        if (childList.size() != 1) {

            ProcessExp(childList.get(2));
        }
        return ret;
    }

    private void ProcessFuncDef(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        TokenType returnTokenType = ((Token) childList.get(0).getChildren().get(0).getGrammarWord()).getType();
        SymbolType type = Utils.TokenType2FuncSymbolType(returnTokenType);
        MyType returnType = Utils.SymbolType2FuncMyType(type);
        Token ident = (Token) childList.get(1).getGrammarWord();
        //<editor-fold> desc=解析参数
        List<MyType> paramTypeList = new LinkedList<>();
        List<Symbol> paramSymbolList = new LinkedList<>();
        if (childList.size() > 5) {
            GrammarTreeNode funcFParams = childList.get(3);
            List<GrammarTreeNode> params = funcFParams.getChildren();
            int index = 0;
            while (index < params.size()) {
                GrammarTreeNode funcFParam = funcFParams.getChildren().get(index);
                List<GrammarTreeNode> targetParam = funcFParam.getChildren();
                MyType paramType;
                TokenType tokenType = ((Token) (targetParam.get(0).getChildren().get(0).getGrammarWord())).getType();
                if (targetParam.size() > 2) {
                    paramType = tokenType == TokenType.CharTk ? MyType.CharArray : MyType.IntArray;
                }
                else {
                    paramType = tokenType == TokenType.CharTk ? MyType.Char : MyType.Int;
                }
                Token identParam = (Token) targetParam.get(1).getGrammarWord();
                paramTypeList.add(paramType);
                SymbolType symbolType = Utils.MyType2VarSymbolType(paramType, false);
                Symbol symbol = new Symbol(identParam, symbolType, null, null, false);
                paramSymbolList.add(symbol);


                index += 2;
            }
        }
        //</editor-fold>


        Symbol symbol = new Symbol(ident, type, returnType, paramTypeList.toArray(new MyType[0]));
        SymbolManager.GetInstance().AddSymbol(symbol);

        ProcessBlock(childList.get(childList.size() - 1), true, returnType, paramSymbolList.toArray(new Symbol[0]));
    }

    /**
     * @param node         Block对应节点
     * @param funcBlock    该block是否为函数Block
     * @param returnType   若为funcBlock，填入返回类型，否则填null
     * @param paramSymbols 若为funcBlock，填入形参符号数组，否则填null
     */
    private void ProcessBlock(GrammarTreeNode node, boolean funcBlock, MyType returnType, Symbol[] paramSymbols) {
        List<GrammarTreeNode> childList = node.getChildren();
        //创建并进入作用域
        SymbolManager.GetInstance().CreateSymbolTable();
        if (funcBlock) {
            this.returnType = returnType;
            SymbolManager.GetInstance().AddSymbols(paramSymbols);
        }
        int index = 1;
        while (index < childList.size() - 1) {
            ProcessBlockItem(childList.get(index));
            index++;
        }
        if (funcBlock) {
//            if (returnType != MyType.Void && !returnFlag) {
//                Error(ErrorType.LackOfReturnOfUnVoid, (Token) childList.get(childList.size() - 1).getGrammarWord());
//            }
            if (returnType != MyType.Void) {
                if (!Utils.CheckReturn(childList.get(childList.size() - 2))) {
                    Error(ErrorType.LackOfReturnOfUnVoid, (Token) childList.get(childList.size() - 1).getGrammarWord());
                }
            }
            this.returnType = null;
        }
        //退出当前作用域
        SymbolManager.GetInstance().BackSymbolTable();
    }

    private void ProcessBlockItem(GrammarTreeNode node) {
        if (node.getChildren().get(0).getGrammarWord() instanceof Nonterminal nonterminal) {
            if (nonterminal.getType() == NonterminalType.Decl) {
                ProcessDecl(node.getChildren().get(0));
            }
            else if (nonterminal.getType() == NonterminalType.Stmt) {
                ProcessStmt(node.getChildren().get(0), false);
            }
        }
    }

    private void ProcessStmt(GrammarTreeNode node, boolean circle) {
        if (circle) {
            circleDepth++;
        }
        List<GrammarTreeNode> childList = node.getChildren();
        if (childList.get(0).getGrammarWord() instanceof Token token) {
            if (token.getType() == TokenType.IfTk) {
                ProcessCond(childList.get(2));
                ProcessStmt(childList.get(4), false);
                if (childList.size() > 5) {
                    ProcessStmt(childList.get(6), false);
                }
            }
            else if (token.getType() == TokenType.ForTk) {
                int stmtIndex = 1;
                int index = 2;
                for (; index < childList.size() - 2; index++) {
                    if (childList.get(index).getGrammarWord() instanceof Token token1) {
                        if (token1.getType() == TokenType.Semicolon) {
                            stmtIndex++;
                        }
                    }
                    else {
                        if (stmtIndex == 1 || stmtIndex == 3) {
                            ProcessForStmt(childList.get(index));
                        }
                        else {
                            ProcessCond(childList.get(index));
                        }
                    }
                }
                ProcessStmt(childList.get(childList.size() - 1), true);

            }
            else if (token.getType() == TokenType.BreakTk || token.getType() == TokenType.ContinueTk) {
                if (circleDepth <= 0) {
                    Error(ErrorType.RCNotInCircle, token);
                }
            }
            else if (token.getType() == TokenType.ReturnTk) {
                if (childList.size() > 2 && returnType == MyType.Void) {
                    Error(ErrorType.UnmatchedReturnOfVoid, token);
                }
            }
            else if (token.getType() == TokenType.PrintfTk) {
                String stringConst = ((Token) (childList.get(2).getGrammarWord())).getContent();
                int varNum = Utils.getNumFromPrintString(stringConst);
                int factVarNum = (childList.size() - 5) / 2;
                if (varNum != factVarNum) {
                    Error(ErrorType.UnmatchedPrintfParam, token);
                }
                if (childList.size() > 5) {
                    int index = 4;
                    while (index < childList.size() - 2) {
                        ProcessExp(childList.get(index));
                        index += 2;
                    }
                }
            }
        }
        else if (childList.get(0).getGrammarWord() instanceof Nonterminal nonterminal) {
            if (nonterminal.getType() == NonterminalType.LVal) {
                int r = ProcessLVal(childList.get(0));
                if (r != 0) {
                    Error(ErrorType.ChangeValueOfConst, r);
                }
                if (childList.get(2).getGrammarWord() instanceof Nonterminal nonterminal2) {
                    ProcessExp(childList.get(2));
                }
            }
            else if (nonterminal.getType() == NonterminalType.Block) {
                ProcessBlock(childList.get(0), false, null, null);
            }
            else {
                ProcessExp(childList.get(0));
            }
        }
        if (circle) {
            circleDepth--;
        }
    }

    private void ProcessForStmt(GrammarTreeNode node) {
        List<GrammarTreeNode> childList = node.getChildren();
        int r = ProcessLVal(childList.get(0));
        if (r != 0) {
            Error(ErrorType.ChangeValueOfConst, r);
        }
        ProcessExp(childList.get(2));
    }

}

