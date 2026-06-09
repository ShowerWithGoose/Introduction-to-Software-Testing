package frontend.Parser.Exp;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;
import frontend.Parser.Func.FuncRparamsParser;
import frontend.symbol.FuncSymbol;
import frontend.symbol.RparamsType;
import frontend.symbol.SymbolTable;
import frontend.symbol.SymbolType;

import java.util.ArrayList;

import static frontend.Parser.Parser.StoreSyntax;
import static frontend.Parser.Parser.UnaryOp;

public class UnaryExpParser {
    private RparamsType rparamsType;

    public UnaryExpParser() {
        rparamsType = RparamsType.VARIABLE;
    }

    public RparamsType GetRparamsType() {
        return rparamsType;
    }

    public boolean Match(SymbolType symbolType,RparamsType rparamsType) {
        if (rparamsType == RparamsType.INTARRAY) {
            if (symbolType == SymbolType.Int || symbolType == SymbolType.Char ||
                    symbolType == SymbolType.ConstInt || symbolType == SymbolType.ConstChar ||
                    symbolType == SymbolType.CharArray || symbolType == SymbolType.ConstCharArray) {
                return false;
            }
        } else if (rparamsType == RparamsType.CHARARRAY) {
            if (symbolType == SymbolType.Int || symbolType == SymbolType.Char ||
                    symbolType == SymbolType.ConstInt || symbolType == SymbolType.ConstChar ||
                    symbolType == SymbolType.IntArray || symbolType == SymbolType.ConstIntArray) {
                return false;
            }
        } else if (rparamsType == RparamsType.VARIABLE) {
            if (symbolType == SymbolType.IntArray || symbolType == SymbolType.CharArray ||
                    symbolType == SymbolType.ConstIntArray || symbolType == SymbolType.ConstCharArray) {
                return false;
            }
        }
        return true;
    }

    public boolean Parser() {
        int store = TokenList.GetIndex();
        Token token = TokenList.GetToken();
        if (token.GetCategory() == Category.IDENFR && TokenList.NextIs(Category.LPARENT)) { // 一定是Func
            store = TokenList.GetIndex();
            String ident = token.GetContent();
            int scope = TokenList.Scope();
            boolean cError = true;
            while (scope!= 0) {
                if (SymbolTable.HaveDefine(scope,ident)) {
                    cError = false;
                    break;
                }
                scope = TokenList.ScopeFather(scope);
            }
            if (cError) {
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'c'));
            }
            FuncRparamsParser funcRparamsParser = new FuncRparamsParser();
            if (funcRparamsParser.Parser()) {
                store = TokenList.GetIndex();
            }
            if (!cError) {
                if (SymbolTable.GetParamsNumber(scope,ident) != funcRparamsParser.ParamsNumber()) {
                    ErrorMap.AddError(new Error(TokenList.ErrorLine(),'d'));
                } else {
                    ArrayList<SymbolType> fParamsTypeList = SymbolTable.GetParamsType(scope,ident);
                    ArrayList<RparamsType> rParamsTypeList = funcRparamsParser.GetParamsTypeList();
                    for (int i = 0;i < funcRparamsParser.ParamsNumber();i++) {
                        if (!Match(fParamsTypeList.get(i),rParamsTypeList.get(i))) {
                            ErrorMap.AddError(new Error(TokenList.ErrorLine(),'e'));
                            break;
                        }
                    }
                }
            }
            TokenList.SetIndex(store);
            if (TokenList.NextIs(Category.RPARENT)) {
                StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
                //System.out.println("<UnaryExp>");
                return true;
            } else {
                TokenList.SetIndex(store);
                ErrorMap.AddError(new Error(TokenList.ErrorLine(),'j'));
                StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
                //System.out.println("<UnaryExp>");
                return true;
            }
        }
        TokenList.SetIndex(store);
        PrimaryExpParser primaryExpParser = new PrimaryExpParser();
        if (primaryExpParser.Parser()) {
            rparamsType = primaryExpParser.GetRparamsType();
            StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<UnaryExp>");
            return true;
        }
        TokenList.SetIndex(store);
        if (UnaryOp() && this.Parser()) {
            StoreSyntax("<UnaryExp>",TokenList.GetIndex() - 1);
            //System.out.println("<UnaryExp>");
            return true;
        }
        return false;
    }
}
