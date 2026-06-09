package frontend;

import com.sun.tools.javac.Main;

import java.util.HashSet;

public class FirstSet {
    public HashSet<SymbolType> CompUnitFirst;
    boolean testPrint = false;

    public void initCompUnitFirst() {
        if(CompUnitFirst != null) return;
        CompUnitFirst = new HashSet<>();

        initDeclFirst();
        initFuncDefFirst();
        initMainFuncDefFirst();
        CompUnitFirst.addAll(DeclFirst);
        CompUnitFirst.addAll(FuncDefFirst);
        CompUnitFirst.addAll(MainFuncDefFirst);
    }

    public HashSet<SymbolType> DeclFirst;
    public void initDeclFirst() {
        if(DeclFirst != null) return;
        DeclFirst = new HashSet<>();

        initConstDeclFirst();
        initVarDeclFirst();
        DeclFirst.addAll(ConstDeclFirst);
        DeclFirst.addAll(VarDeclFirst);
    }

    public HashSet<SymbolType> ConstDeclFirst;
    public void initConstDeclFirst() {
        if(ConstDeclFirst != null) return;
        ConstDeclFirst = new HashSet<>();

        ConstDeclFirst.add(SymbolType.CONSTTK);
    }

    public HashSet<SymbolType> BTypeFirst;
    public void initBTypeFirst() {
        if(BTypeFirst != null) return;
        BTypeFirst = new HashSet<>();

        BTypeFirst.add(SymbolType.INTTK);
        BTypeFirst.add(SymbolType.CHARTK);
    }

    public HashSet<SymbolType> ConstDefFirst;
    public void initConstDefFirst() {
        if(ConstDefFirst != null) return;
        ConstDefFirst = new HashSet<>();

        ConstDefFirst.add(SymbolType.IDENFR);
    }

    public HashSet<SymbolType> ConstInitValFirst;
    public void initConstInitValFirst() {
        if(ConstInitValFirst != null) return;
        ConstInitValFirst = new HashSet<>();

        initConstExpFirst();
        ConstInitValFirst.addAll(ConstExpFirst);
        ConstInitValFirst.add(SymbolType.IDENFR);
        ConstInitValFirst.add(SymbolType.LBRACE);
    }

    public HashSet<SymbolType> VarDeclFirst;
    public void initVarDeclFirst() {
        if(VarDeclFirst != null) return;
        VarDeclFirst = new HashSet<>();

        initBTypeFirst();
        VarDeclFirst.addAll(BTypeFirst);
    }

    public HashSet<SymbolType> VarDefFirst;
    public void initVarDefFirst() {
        if(VarDefFirst != null) return;
        VarDefFirst = new HashSet<>();

        VarDefFirst.add(SymbolType.IDENFR);
    }

    public HashSet<SymbolType> InitValFirst;
    public void initInitValFirst() {
        if(InitValFirst != null) return;
        InitValFirst = new HashSet<>();

        initExpFirst();
        InitValFirst.addAll(ExpFirst);
        InitValFirst.add(SymbolType.LBRACE);
        InitValFirst.add(SymbolType.STRCON);
    }

    public HashSet<SymbolType> FuncDefFirst;
    public void initFuncDefFirst() {
        if(FuncDefFirst != null) return;
        FuncDefFirst = new HashSet<>();

        initFuncTypeFirst();
        FuncDefFirst.addAll(FuncTypeFirst);
    }

    public HashSet<SymbolType> MainFuncDefFirst;
    public void initMainFuncDefFirst() {
        if(MainFuncDefFirst != null) return;
        MainFuncDefFirst = new HashSet<>();

        MainFuncDefFirst.add(SymbolType.INTTK);
    }

    public HashSet<SymbolType> FuncTypeFirst;
    public void initFuncTypeFirst() {
        if(FuncTypeFirst != null) return;
        FuncTypeFirst = new HashSet<>();

        FuncTypeFirst.add(SymbolType.VOIDTK);
        FuncTypeFirst.add(SymbolType.INTTK);
        FuncTypeFirst.add(SymbolType.CHARTK);
    }

    public HashSet<SymbolType> FuncFParamsFirst;
    public void initFuncFParamsFirst() {
        if(FuncFParamsFirst != null) return;
        FuncFParamsFirst = new HashSet<>();

        initFuncFParamFirst();
        FuncFParamsFirst.addAll(FuncFParamFirst);
    }

    public HashSet<SymbolType> FuncFParamFirst;
    public void initFuncFParamFirst() {
        if(FuncFParamFirst != null) return;
        FuncFParamFirst = new HashSet<>();

        initBTypeFirst();
        FuncFParamFirst.addAll(BTypeFirst);
    }

    public HashSet<SymbolType> BlockFirst;
    public void initBlockFirst() {
        if(BlockFirst != null) return;
        BlockFirst = new HashSet<>();

        BlockFirst.add(SymbolType.LBRACE);
    }

    public HashSet<SymbolType> BlockItemFirst;
    public void initBlockItemFirst() {
        if(BlockItemFirst != null) return;
        BlockItemFirst = new HashSet<>();

        initDeclFirst();
        initStmtFirst();
        BlockItemFirst.addAll(DeclFirst);
        BlockItemFirst.addAll(StmtFirst);
    }

    public HashSet<SymbolType> StmtFirst;
    public void initStmtFirst() {
        if(StmtFirst != null) return;
        StmtFirst = new HashSet<>();

        initLValFirst();
        StmtFirst.addAll(LValFirst);
        initExpFirst();
        StmtFirst.addAll(ExpFirst);
        StmtFirst.add(SymbolType.SEMICN);
        StmtFirst.add(SymbolType.IFTK);
        StmtFirst.add(SymbolType.FORTK);
        StmtFirst.add(SymbolType.BREAKTK);
        StmtFirst.add(SymbolType.CONTINUETK);
        StmtFirst.add(SymbolType.RETURNTK);
        StmtFirst.add(SymbolType.PRINTFTK);
    }

    public HashSet<SymbolType> ForStmtFirst;
    public void initForStmtFirst() {
        if(ForStmtFirst != null) return;
        ForStmtFirst = new HashSet<>();

        initLValFirst();
        ForStmtFirst.addAll(LValFirst);
    }

    public HashSet<SymbolType> ExpFirst;
    public void initExpFirst() {
        if(ExpFirst != null) return;
        ExpFirst = new HashSet<>();

        initAddExpFirst();
        ExpFirst.addAll(AddExpFirst);
    }

    public HashSet<SymbolType> CondFirst;
    public void initCondFirst() {
        if(CondFirst != null) return;
        CondFirst = new HashSet<>();

        initLOrExpFirst();
        CondFirst.addAll(LOrExpFirst);
    }

    public HashSet<SymbolType> LValFirst;
    public void initLValFirst() {
        if(LValFirst != null) return;
        LValFirst = new HashSet<>();

        LValFirst.add(SymbolType.IDENFR);
    }

    public HashSet<SymbolType> PrimaryExpFirst;
    public void initPrimaryExpFirst() {
        if(PrimaryExpFirst != null) return;
        PrimaryExpFirst = new HashSet<>();

        PrimaryExpFirst.add(SymbolType.LPARENT);
        initLValFirst();
        PrimaryExpFirst.addAll(LValFirst);
        initNumberFirst();
        PrimaryExpFirst.addAll(NumberFirst);
        initCharacterFirst();
        PrimaryExpFirst.addAll(CharacterFirst);
    }

    public HashSet<SymbolType> NumberFirst;
    public void initNumberFirst() {
        if(NumberFirst != null) return;
        NumberFirst = new HashSet<>();

        NumberFirst.add(SymbolType.INTCON);
    }

    public HashSet<SymbolType> CharacterFirst;
    public void initCharacterFirst() {
        if(CharacterFirst != null) return;
        CharacterFirst = new HashSet<>();

        CharacterFirst.add(SymbolType.CHRCON);
    }

    public HashSet<SymbolType> UnaryExpFirst;
    public void initUnaryExpFirst() {
        if(UnaryExpFirst != null) return;
        UnaryExpFirst = new HashSet<>();

        initPrimaryExpFirst();
        UnaryExpFirst.addAll(PrimaryExpFirst);
        UnaryExpFirst.add(SymbolType.IDENFR);
        initUnaryOpFirst();
        UnaryExpFirst.addAll(UnaryOpFirst);
    }

    public HashSet<SymbolType> UnaryOpFirst;
    public void initUnaryOpFirst() {
        if(UnaryOpFirst != null) return;
        UnaryOpFirst = new HashSet<>();

        UnaryOpFirst.add(SymbolType.PLUS);
        UnaryOpFirst.add(SymbolType.MINU);
        UnaryOpFirst.add(SymbolType.NOT);
    }

    public HashSet<SymbolType> FuncRParamsFirst;
    public void initFuncRParamsFirst() {
        if(FuncRParamsFirst != null) return;
        FuncRParamsFirst = new HashSet<>();

        initExpFirst();
        FuncRParamsFirst.addAll(ExpFirst);
    }

    public HashSet<SymbolType> MulExpFirst;
    public void initMulExpFirst() {
        if(MulExpFirst != null) return;
        MulExpFirst = new HashSet<>();

        initUnaryExpFirst();
        MulExpFirst.addAll(UnaryExpFirst);
    }

    public HashSet<SymbolType> AddExpFirst;
    public void initAddExpFirst() {
        if(AddExpFirst != null) return;
        AddExpFirst = new HashSet<>();

        initMulExpFirst();
        AddExpFirst.addAll(MulExpFirst);
    }

    public HashSet<SymbolType> RelExpFirst;
    public void initRelExpFirst() {
        if(RelExpFirst != null) return;
        RelExpFirst = new HashSet<>();

        initAddExpFirst();
        RelExpFirst.addAll(AddExpFirst);
    }

    public HashSet<SymbolType> EqExpFirst;
    public void initEqExpFirst() {
        if(EqExpFirst != null) return;
        EqExpFirst = new HashSet<>();

        initRelExpFirst();
        EqExpFirst.addAll(RelExpFirst);
    }

    public HashSet<SymbolType> LAndExpFirst;
    public void initLAndExpFirst() {
        if(LAndExpFirst != null) return;
        LAndExpFirst = new HashSet<>();

        initEqExpFirst();
        LAndExpFirst.addAll(EqExpFirst);
    }

    public HashSet<SymbolType> LOrExpFirst;
    public void initLOrExpFirst() {
        if(LOrExpFirst != null) return;
        LOrExpFirst = new HashSet<>();

        initLAndExpFirst();
        LOrExpFirst.addAll(LAndExpFirst);
    }

    public HashSet<SymbolType> ConstExpFirst;
    public void initConstExpFirst() {
        if(ConstExpFirst != null) return;
        ConstExpFirst = new HashSet<>();

        initAddExpFirst();
        ConstExpFirst.addAll(AddExpFirst);
    }

    public FirstSet() {
        initCompUnitFirst();
            if(testPrint) System.err.println("CompUnitFirst : " + CompUnitFirst);
        initDeclFirst();
            if(testPrint) System.err.println("DeclFirst : " + DeclFirst);
        initBTypeFirst();
            if(testPrint) System.err.println("BTypeFirst : " + BTypeFirst);
        initConstDefFirst();
            if(testPrint) System.err.println("ConstDefFirst : " + ConstDefFirst);
        initConstInitValFirst();
            if(testPrint) System.err.println("ConstInitValFirst : " + ConstInitValFirst);
        initVarDeclFirst();
            if(testPrint) System.err.println("VarDeclFirst : " + VarDeclFirst);
        initVarDefFirst();
            if(testPrint) System.err.println("VarDefFirst : " + VarDefFirst);
        initInitValFirst();
            if(testPrint) System.err.println("InitValFirst : " + InitValFirst);
        initFuncDefFirst();
            if(testPrint) System.err.println("FuncDefFirst : " + FuncDefFirst);
        initMainFuncDefFirst();
            if(testPrint) System.err.println("MainFuncDefFirst : " + MainFuncDefFirst);
        initFuncTypeFirst();
            if(testPrint) System.err.println("FuncTypeFirst : " + FuncTypeFirst);
        initFuncFParamsFirst();
            if(testPrint) System.err.println("FuncFParamsFirst : " + FuncFParamsFirst);
        initFuncFParamFirst();
            if(testPrint) System.err.println("FuncFParamFirst : " + FuncFParamFirst);
        initBlockFirst();
            if(testPrint) System.err.println("BlockFirst : " + BlockFirst);
        initBlockItemFirst();
            if(testPrint) System.err.println("BlockItemFirst : " + BlockItemFirst);
        initStmtFirst();
            if(testPrint) System.err.println("StmtFirst : " + StmtFirst);
        initForStmtFirst();
            if(testPrint) System.err.println("ForStmtFirst : " + ForStmtFirst);
        initExpFirst();
            if(testPrint) System.err.println("ExpFirst : " + ExpFirst);
        initCondFirst();
            if(testPrint) System.err.println("CondFirst : " + CondFirst);
        initLValFirst();
            if(testPrint) System.err.println("LValFirst : " + LValFirst);
        initPrimaryExpFirst();
            if(testPrint) System.err.println("PrimaryExpFirst : " + PrimaryExpFirst);
        initNumberFirst();
            if(testPrint) System.err.println("NumberFirst : " + NumberFirst);
        initCharacterFirst();
            if(testPrint) System.err.println("CharacterFirst : " + CharacterFirst);
        initUnaryExpFirst();
            if(testPrint) System.err.println("UnaryExpFirst : " + UnaryExpFirst);
        initUnaryOpFirst();
            if(testPrint) System.err.println("UnaryOpFirst : " + UnaryOpFirst);
        initFuncRParamsFirst();
            if(testPrint) System.err.println("FuncRParamsFirst : " + FuncRParamsFirst);
        initMulExpFirst();
            if(testPrint) System.err.println("MulExpFirst : " + MulExpFirst);
        initAddExpFirst();
            if(testPrint) System.err.println("AddExpFirst : " + AddExpFirst);
        initRelExpFirst();
            if(testPrint) System.err.println("RelExpFirst : " + RelExpFirst);
        initEqExpFirst();
            if(testPrint) System.err.println("EqExpFirst : " + EqExpFirst);
        initLAndExpFirst();
            if(testPrint) System.err.println("LAndExpFirst : " + LAndExpFirst);
        initLOrExpFirst();
            if(testPrint) System.err.println("LOrExpFirst : " + LOrExpFirst);
        initConstExpFirst();
            if(testPrint) System.err.println("ConstExpFirst : " + ConstExpFirst);
    }
}
