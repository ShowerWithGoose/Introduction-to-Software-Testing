package frontend.Parser.Func;

import frontend.Category.Category;
import frontend.Category.TokenList;
import frontend.symbol.SymbolType;

import java.util.ArrayList;

import static frontend.Parser.Parser.StoreSyntax;

public class FuncFParamsParser {
    private int paramsNumber;

    private ArrayList<SymbolType> symbolTypeList;

    private ArrayList<String> symbolNameList;

    public FuncFParamsParser() {
        paramsNumber = 0;
        symbolTypeList = new ArrayList<>();
        symbolNameList = new ArrayList<>();
    }

    public int GetParamsNumber() {
        return paramsNumber;
    }

    public ArrayList<SymbolType> GetSymbolTypeList() {
        return symbolTypeList;
    }

    public ArrayList<String> GetSymbolNameList() {
        return symbolNameList;
    }

    public void AddToSymbolType(Category bType,boolean isArray) {
        if (isArray) {
            if (bType == Category.INTTK) {
                symbolTypeList.add(SymbolType.IntArray);
            } else {
                symbolTypeList.add(SymbolType.CharArray);
            }
        } else {
            if (bType == Category.INTTK) {
                symbolTypeList.add(SymbolType.Int);
            } else {
                symbolTypeList.add(SymbolType.Char);
            }
        }
    }

    public boolean Parser() {
        FuncFParamParser funcFParamParser = new FuncFParamParser();
        if (funcFParamParser.Parser()) {
            int store = TokenList.GetIndex();
            paramsNumber++;
            AddToSymbolType(funcFParamParser.GetBType(), funcFParamParser.IsArray());
            symbolNameList.add(funcFParamParser.GetIdent());
            while (TokenList.NextIs(Category.COMMA) && funcFParamParser.Parser()) {
                store = TokenList.GetIndex();
                paramsNumber++;
                AddToSymbolType(funcFParamParser.GetBType(), funcFParamParser.IsArray());
                symbolNameList.add(funcFParamParser.GetIdent());
            }
            TokenList.SetIndex(store);
            StoreSyntax("<FuncFParams>",TokenList.GetIndex() - 1);
            //System.out.println("<FuncFParams>");
            return true;
        }
        return false;
    }
}
