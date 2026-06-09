package frontend;

import nonTerminal.FuncFParam;
import nonTerminal.FuncFParams;
import nonTerminal.FuncRParams;

import java.util.ArrayList;

public class SymbolTableItem {
    private String name;

    private String type;

    private int domainNum;

    private ArrayInfo arrayInfo;

    private FuncInfo funcInfo;

    public SymbolTableItem(String name, String type, int domainNum) {
        this.name = name;
        this.type = type;
        this.domainNum = domainNum;
        arrayInfo = null;
        funcInfo = null;
    }

    public void analyzeFuncPara(FuncFParams params) {
        funcInfo = new FuncInfo();
        FuncFParam firstPara = params.getFuncFParam();
        ArrayList<FuncFParam> paramsList = params.getFuncFParams();
        if (firstPara.getBType().getBType().getType() == Token.Type.INTTK) {
            if (firstPara.getLbrack() != null) {
                funcInfo.addType("IntArray");
            } else {
                funcInfo.addType("Int");
            }
        } else {
            if (firstPara.getLbrack() != null) {
                funcInfo.addType("CharArray");
            } else {
                funcInfo.addType("Char");
            }
        }
        for (FuncFParam param : paramsList) {
            if (param.getBType().getBType().getType() == Token.Type.INTTK) {
                if (param.getLbrack() != null) {
                    funcInfo.addType("IntArray");
                } else {
                    funcInfo.addType("Int");
                }
            } else {
                if (param.getLbrack() != null) {
                    funcInfo.addType("CharArray");
                } else {
                    funcInfo.addType("Char");
                }
            }
        }
    }

    public int getDomainNum() {
        return domainNum;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public FuncInfo getFuncInfo() {
        return funcInfo;
    }
}
