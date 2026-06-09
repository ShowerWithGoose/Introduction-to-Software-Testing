package FrontEnd;

import FrontEnd.ASDTree.ASDNode;
import FrontEnd.ASDTree.Character;
import FrontEnd.ASDTree.CompUnit;
import FrontEnd.ASDTree.*;
import FrontEnd.ASDTree.Number;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class SytaxParser {
    private void errori() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("error.txt", true))) {  // "true" 表示追加内容到文件
            writer.println(tokens.get(tokenIndex-1).getLineNum()+ " " + "i");
            /*用这种方式去推出*/
//            tokenIndex++;
        } catch (IOException e) {
            e.printStackTrace();  // 捕获异常并打印
        }
        return;
    }
    private void errorj() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("error.txt", true))) {  // "true" 表示追加内容到文件
            writer.println(tokens.get(tokenIndex-1).getLineNum() + " " + "j");
            /*用这种方式去推出*/
//            tokenIndex++;
        } catch (IOException e) {
            e.printStackTrace();  // 捕获异常并打印
        }
        return;
    }
    private void errork() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("error.txt", true))) {  // "true" 表示追加内容到文件
            writer.println(tokens.get(tokenIndex-1).getLineNum() + " " + "k");
            /*用这种方式去推出*/
//            tokenIndex++;
        } catch (IOException e) {
            e.printStackTrace();  // 捕获异常并打印
        }
    }
    private static int debugMode=0;
    private ASDNode ASDRoot;
    private ArrayList<Token> tokens;
    private int tokenIndex;
    public SytaxParser(ArrayList<Token> tokens) {
        ASDRoot = null;
        this.tokens = tokens;
        tokenIndex = 0;
    }
    public boolean sytaxAnalyze() throws FileNotFoundException
    {
        this.ASDRoot = CompUnit();
        this.ASDRoot.printInfo();
        ErrorFileSorter.sortErrorFile("error.txt");
        return tokens.size() == tokenIndex;
    }
    public String getTokenType(int bias)
    {
        return this.tokens.get(bias).getTokenCode();
    }
    public CompUnit getASDTree()
    {
        return (CompUnit) this.ASDRoot;
    }

    public CompUnit CompUnit() throws FileNotFoundException
    {
//        for(Token token:tokens)
//        {
//            System.out.println("统计Token "+token.getOringinStr()+" "+token.getLineNum());
//        }

        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        MainFuncDef mainFuncDef;

        /*等到函数定义的时候tokenIndex+2就是左括号*/
        while((!getTokenType(tokenIndex+1).equals("MAINTK"))&&(!getTokenType(tokenIndex+2).equals("LPARENT")))
        {
            if (tokens.get(tokenIndex).getTokenCode().equals("CONSTTK"))
            {
                decls.add(new Decl(ConstDecl()));
                if(debugMode==2)
                System.out.println("ConstDecl Ends"+" "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
            }

            else
            {
                decls.add(new Decl(VarDecl()));
                if(debugMode==2)
                System.out.println("VarDecl Ends"+" "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
            }
        }
        if(debugMode==2)
        System.out.println("FuncDef Begins"+" "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());

        while(!tokens.get(tokenIndex+1).getOringinStr().equals("main"))
        {
//            System.out.println("new FuncDef"+" "+tokens.get(tokenIndex).getOringinStr());
            FuncDef funcDef=funcDef();
            funcDefs.add(funcDef);
        }

//        System.out.println("主函数开始行号"+this.tokens.get(tokenIndex).getLineNum());
        mainFuncDef=mainFuncDef();
        return new CompUnit(decls,funcDefs,mainFuncDef);
    }
    /*需要说下边所有的类都要调控tokenIndex*/
    public ConstDecl ConstDecl()
    {
        /*跳过const*/
        tokenIndex++;
        BType bType=BType();
        ArrayList<ConstDef> constDefArrayList = new ArrayList<>();
        /*这个btype应该传原始的*/
        constDefArrayList.add(ConstDef());

        while(getTokenType(tokenIndex).equals("COMMA"))
        {
            tokenIndex++;
            constDefArrayList.add(ConstDef());
        }
        /*跳过分号*/
        if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
        {
            errori();
        }
        else
        {
            tokenIndex++;
        }
//        System.out.println("ConstDecl跳过分号后的字符 "+tokens.get(tokenIndex).getOringinStr() );
        /*第一个不等于comma的字符*/
        return new ConstDecl(bType,constDefArrayList);
    }

    public VarDecl VarDecl()
    {
        BType bType = BType();
        ArrayList<VarDef> varDefs=new ArrayList<>();
//        System.out.println("VarDef Begins"+" "+tokens.get(tokenIndex).getOringinStr());
        varDefs.add(VarDef());
        while(tokens.get(tokenIndex).getOringinStr().equals(","))
        {
            tokenIndex++;
            varDefs.add(VarDef());
        }
        /*跳过分号*/
        if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
        {
            errori();
        }
        else
        {
            tokenIndex++;
        }
        return new VarDecl(bType,varDefs);
    }
    public VarDef VarDef()
    {
        Ident ident=Ident();
        ConstExp constExp=null;
        boolean haveExp=false;

        if(tokens.get(tokenIndex).getOringinStr().equals("["))
        {
            tokenIndex++ ;
            /*跳过那个左括号*/
            constExp=ConstExp();
            if(debugMode==2)
            System.out.println("VarDef ConstExp之后的符号 "+tokens.get(tokenIndex).getOringinStr()+tokens.get(tokenIndex).getLineNum());
            haveExp=true;

            if(!tokens.get(tokenIndex).getOringinStr().equals("]"))
            {
                errork();
            }
            else {
                tokenIndex++;
            }
        }
        if(tokens.get(tokenIndex).getOringinStr().equals("="))
        {
            tokenIndex++;
            InitVal initVal=InitVal();
            if(debugMode==2)
            System.out.println("收集过Inival之后的值 "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
            if(haveExp==true) {
                return new VarDef(ident, constExp, initVal);
            }
            else {
                return new VarDef(ident,initVal);
            }
        }

        /*没有初始化的两种定义*/
        if(haveExp==true)
        {
            return new VarDef(ident,constExp);
        }

        else
        {
            return new VarDef(ident);
        }

    }

    public FuncDef funcDef() throws FileNotFoundException {
        FuncType funcType=FuncType();
        Ident ident=Ident();
        /*这里应该在左括号*/
//        System.out.println("origin String"+" " +tokens.get(tokenIndex).getOringinStr());
        if(!tokens.get(tokenIndex+1).getOringinStr().equals(")"))
        {
            /*跳过左括号*/
            tokenIndex++;
            FuncFParams funcFParams=FuncFParams();
            /*跳过右括号*/
            if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
            {
                errorj();
            }
            else {
                tokenIndex++;
            }
            Block block=Block();
            return new FuncDef(funcType,ident,funcFParams,block);
        }
        /*跳过左括号*/
        tokenIndex++;

        if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
        {
            errorj();
        }
        else {
            tokenIndex++;
        }
//        System.out.println("before block"+" "+tokens.get(tokenIndex).getOringinStr());
        Block block=Block();
//        System.out.println("after block"+" "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
        return new FuncDef(funcType,ident,block);
    }

    public MainFuncDef mainFuncDef() throws FileNotFoundException {
        tokenIndex++;
        tokenIndex++;
        tokenIndex++;
        if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
        {
            errorj();
        }
        else
        {
            tokenIndex++;
        }
        /* 跳过int main()*/
        return new MainFuncDef(Block());
    }
    public ConstDef ConstDef()
    {
        UnaryExp.Type type;
        Ident ident;
        ConstExp constExp;
        ConstInitVal constInitVal;
        ident=new Ident(tokens.get(tokenIndex));
        tokenIndex++;
        /*这边处理数组情况*/
        if(tokens.get(tokenIndex).getOringinStr().equals("["))
        {
            tokenIndex++;
            constExp=ConstExp();
            /*跳过右括号和等号*/
            if(!tokens.get(tokenIndex).getOringinStr().equals("]"))
            {
                errork();
            }
            else {
                tokenIndex++;
            }
            /*下边是跳过等于号*/
            tokenIndex++;
            constInitVal=ConstInitVal();
            return new ConstDef(ident,constExp,constInitVal);
        }
        else
        {
            tokenIndex++;
            constInitVal=ConstInitVal();
            return new ConstDef(ident,constInitVal);
        }
    }
    public ConstExp ConstExp()
    {
        AddExp addExp= AddExp();
        return new ConstExp(addExp);
    }

    public UnaryExp UnaryExp()
    {
        ArrayList<ASDNode> asdNodes = new ArrayList<>();
        /*这个下边一定是个while*/
        if(getTokenType(tokenIndex).equals("PLUS")||getTokenType(tokenIndex).equals("MINU")||getTokenType(tokenIndex).equals("NOT"))
        {
//            asdNodes.add(new UnaryOp(tokens.get(tokenIndex)));
//            tokenIndex++;
//            asdNodes.add(UnaryExp());
            UnaryOp unaryOp=UnaryOp();
            UnaryExp unaryExp=UnaryExp();
            return new UnaryExp(unaryOp,unaryExp);
        }

        else if(getTokenType(tokenIndex).equals("IDENFR")&&getTokenType(tokenIndex+1).equals("LPARENT"))
        {
            if(debugMode==2)
            System.out.println("找到了一元表达式的函数调用 "+tokens.get(tokenIndex).getOringinStr()+tokens.get(tokenIndex).getLineNum());
            Ident m=new Ident(tokens.get(tokenIndex));
            FuncRParams k=null;
//            asdNodes.add(new Ident(tokens.get(tokenIndex)));
            tokenIndex++;
            tokenIndex++;
//            System.out.println("检测是不是右括号之前 "+tokens.get(tokenIndex).getOringinStr()+tokens.get(tokenIndex).getLineNum());
            if(!getTokenType(tokenIndex).equals("RPARENT"))
            {
                int SavedTokenIndex = tokenIndex;
                try {
//                    System.out.println("try to add RParams "+tokens.get(tokenIndex).getLineNum());
                    k=FuncRParams();
//                    asdNodes.add(FuncRParams());
                } catch (Error e) {
                    tokenIndex = SavedTokenIndex;
                }
            }
            /*这个是去掉右括号*/
            if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
            {
                errorj();
            }

            else
            {
                tokenIndex++;
            }
            if(debugMode==2)
            System.out.println("函数调用结束后的符号应该全是; "+tokens.get(tokenIndex).getOringinStr()+tokens.get(tokenIndex).getLineNum());
            return new UnaryExp(m,k);
        }
        else
        {
            asdNodes.add(PrimaryExp());
        }
        return new UnaryExp(asdNodes);
    }

    public FuncRParams FuncRParams()
    {
        ArrayList<Exp> expArrayList=new ArrayList<>();
        expArrayList.add(Exp());
//        tokenIndex++;
        while(tokens.get(tokenIndex).getOringinStr().equals(","))
        {
            tokenIndex++;
            expArrayList.add(Exp());
//            tokenIndex++;
        }
        return new FuncRParams(expArrayList);
    }
    public PrimaryExp PrimaryExp()
    {
        Exp exp=null;
        Lval lval=null;
        Number number=null;
        Character character=null;
        if(tokens.get(tokenIndex).getOringinStr().equals("("))
        {
            tokenIndex++;
            exp=Exp();
            if(!tokens.get(tokenIndex).getOringinStr().equals(")")) {
                errorj();
            }
            else
            {
                tokenIndex++;
            }
        }
        else if(getTokenType(tokenIndex).equals("IDENFR"))
        {
            lval=Lval();
        }
        else if(getTokenType(tokenIndex).equals("INTCON"))
        {
             number=Number();
        }
        else {
            character=Character();
        }
        if(exp!=null)
        {
            return new PrimaryExp(exp);
        }
        else if(lval!=null)
        {
            return new PrimaryExp(lval);
        }
        else if(number!=null)
        {
            return new PrimaryExp(number);
        }
        else if(character!=null)
        {
            return new PrimaryExp(character);
        }
        return null;
    }

    public Lval Lval()
    {
        /*这个Lval看起来基本没问题啊？*/
        Ident ident;
        Exp exp=null;
        ident=Ident();
        if(tokens.get(tokenIndex).getOringinStr().equals("["))
        {
            tokenIndex++;
            exp=Exp();
            /*如果是Ident 则直接进入下一个了就是*/
            if(!tokens.get(tokenIndex).getOringinStr().equals("]"))
            {
                errork();
            }
            else
            {
                tokenIndex++;
            }
        }
        if(exp!=null)
        {
            return new Lval(ident,exp);
        }
        return new Lval(ident);
    }
    public Exp Exp()
    {
        AddExp AddExp=AddExp();
        return new Exp(AddExp);
    }
    public AddExp AddExp()
    {
        ArrayList<Token> opList=new ArrayList<>();
        ArrayList<MulExp> mulExpArrayList=new ArrayList<>();
        mulExpArrayList.add(MulExp());
//        System.out.println("判断AddExp是否继续的单词 "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());

        while(tokens.get(tokenIndex).getOringinStr().equals("+")||tokens.get(tokenIndex).getOringinStr().equals("-"))
        {
//            System.out.println("Here AddExp");
            opList.add(tokens.get(tokenIndex));
            tokenIndex++;
            mulExpArrayList.add(MulExp());
        }
        if(opList.size()>0)
        {
            return new AddExp(opList,mulExpArrayList);
        }

        else return new AddExp(mulExpArrayList);
    }
    public MulExp MulExp()
    {
        ArrayList<UnaryExp> unaryExpArrayList=new ArrayList<>();
        ArrayList<Token> opList=new ArrayList<>();
        unaryExpArrayList.add(UnaryExp());
        /*这里是不是需要转义符*/
//        System.out.println("判断MulExp是否继续的单词 "+tokens.get(tokenIndex).getOringinStr());
        while(tokens.get(tokenIndex).getOringinStr().equals("*")||tokens.get(tokenIndex).getTokenCode().equals("DIV")||tokens.get(tokenIndex).getOringinStr().equals("%"))
        {
            opList.add(tokens.get(tokenIndex));
            tokenIndex++;
            unaryExpArrayList.add(UnaryExp());
        }
        if(opList.size()>0)
        {
            return new MulExp(opList,unaryExpArrayList);
        }
        else {
            return new MulExp(unaryExpArrayList);
        }
    }
    Block Block() throws FileNotFoundException {
        /*先跳过”{“ */
        tokenIndex++;
        ArrayList<BlockItem> blockItemArrayList=new ArrayList<>();
        while (!tokens.get(tokenIndex).getOringinStr().equals("}"))
        {
//            if(tokens.get(tokenIndex).getOringinStr().equals(";"))
//            {
//                tokenIndex++;
//            }
            if(tokens.get(tokenIndex).getOringinStr().equals("}"))
            {
                break;
            }
            BlockItem k=BlockItem();
            blockItemArrayList.add(k);
//            k.printInfo();
            /*总而言之就是blockItem没有延续到后边那一个符号*/
        }
        /*跳过了最后的}*/
        tokenIndex++;
        return new Block(blockItemArrayList);
    }
    BlockItem BlockItem() throws FileNotFoundException {
        if (getTokenType(tokenIndex).equals("CONSTTK")) {
            return new BlockItem(new Decl(ConstDecl()));
        }
        else if (getTokenType(tokenIndex).equals("INTTK"))
        {
//            System.out.println("Int BlockItem"+" "+tokens.get(tokenIndex).getOringinStr());
            return new BlockItem(new Decl(VarDecl()));
        }
        else if(getTokenType(tokenIndex).equals("CHARTK"))
        {
//            System.out.println("Char BlockItem"+" "+tokens.get(tokenIndex).getOringinStr());
            return new BlockItem(new Decl(VarDecl()));
        }
        else
        {
            if(debugMode==2)
            System.out.println("BlockStmt 之前"+" "+this.tokens.get(tokenIndex).getOringinStr()+" "+this.tokens.get(tokenIndex).getLineNum());
            return new BlockItem(Stmt());
        }
    }
    Stmt Stmt() throws FileNotFoundException {
        ArrayList<ASDNode> asdNodes = new ArrayList<>();
        if(getTokenType(tokenIndex).equals("SEMICN"))
        {
            tokenIndex++;
            return new Stmt(Stmt.Type.None,asdNodes);
        }
        /*Block的情况*/
        if(getTokenType(tokenIndex).equals("LBRACE"))
        {
            asdNodes.add(Block());
            return new Stmt(Stmt.Type.Block,asdNodes);
        }
        /*if条件句*/
        else if(getTokenType(tokenIndex).equals("IFTK"))
        {
            tokenIndex++;
            /*左右括号*/
            tokenIndex++;
            asdNodes.add(Cond());
//                System.out.println("Cond之后的单词 "+tokens.get(tokenIndex).getOringinStr());
            if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
            {
                errorj();
            }
            else
            {
                tokenIndex++;
            }
//                System.out.println("Cond 结束后的token "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());

//            System.out.println("Cond结束的单词 "+tokens.get(tokenIndex).getOringinStr());
            asdNodes.add(Stmt());
//            System.out.println("检测else之前的单词 "+tokens.get(tokenIndex).getOringinStr());
            if(tokens.get(tokenIndex).getOringinStr().equals("else"))
            {
                tokenIndex++;
                asdNodes.add(Stmt());
            }
            return new Stmt(Stmt.Type.ifBranch,asdNodes);
        }
        /*forBranch*/
        else if(getTokenType(tokenIndex).equals("FORTK"))
        {
            int flag=0;
            tokenIndex++;
            tokenIndex++;
            if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
            {
                flag=1;
                asdNodes.add(ForStmt());
            }
            tokenIndex++;
//            System.out.println("before for Cond "+tokens.get(tokenIndex).getOringinStr());
            if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
            {
                asdNodes.add(Cond());
            }
            tokenIndex++;
//            System.out.println("before for stmt2 "+tokens.get(tokenIndex).getOringinStr());
            if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
            {
                asdNodes.add(ForStmt());
            }
//
            tokenIndex++;
            asdNodes.add(Stmt());
            if(flag==1)
            {
                return new Stmt(Stmt.Type.forBranch,asdNodes,flag);
            }
            return new Stmt(Stmt.Type.forBranch,asdNodes);
        }
        /*break*/
        else if(tokens.get(tokenIndex).getOringinStr().equals("break"))
        {
            tokenIndex++;
            if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
            {
                errori();
            }
            else {
                tokenIndex++;
            }
            return new Stmt(Stmt.Type.breakStmt,asdNodes);
        }
        /*continue*/
        else if(tokens.get(tokenIndex).getOringinStr().equals("continue"))
        {
            tokenIndex++;
            if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
            {
                errori();
            }
            else {
                tokenIndex++;
            }

            return new Stmt(Stmt.Type.continueStmt,asdNodes);
        }

        /*return*/
        else if(tokens.get(tokenIndex).getOringinStr().equals("return"))
        {
            tokenIndex++;
            if(!tokens.get(tokenIndex).getOringinStr().equals(";")&&!tokens.get(tokenIndex).getOringinStr().equals("}"))
            {
                asdNodes.add(Exp());
            }
//            System.out.println("跳过return 分号后的东西"+tokens.get(tokenIndex).getOringinStr());
            /*跳过最后一个分号*/
            if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
            {
                errori();
            }
            else {
                tokenIndex++;
            }
            return new Stmt(Stmt.Type.returnStmt,asdNodes);
        }

        /*print*/
        else if(tokens.get(tokenIndex).getOringinStr().equals("printf"))
        {
            tokenIndex++;
            tokenIndex++;
//            System.out.println("printf 加字符串常量之前 "+tokens.get(tokenIndex).getOringinStr());
            asdNodes.add(StringConst());
//            System.out.println("printf 加字符串常量之后 "+tokens.get(tokenIndex).getOringinStr());
            boolean flag=false;
            while (tokens.get(tokenIndex).getOringinStr().equals(","))
            {
                flag=true;
                tokenIndex++;
//                System.out.println("Exp加之前的东西 "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
                asdNodes.add(Exp());
//                System.out.println("Exp加过结束后的东西 "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
            }
            /*是为了纯打印字符串的时候跳过最后一个右括号*/

            if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
            {
                errorj();
            }
            else {
                tokenIndex++;
            }

            if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
            {
                errori();
            }
            else {
                tokenIndex++;
            }
            /*还有一个符号交给上边的处理器*/
            if(debugMode==2)
            System.out.println("printf结束后的东西 "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
            return new Stmt(Stmt.Type.print,asdNodes);
        }
        else
        {
            boolean isExp = true;
            int savedTokenIndex = this.tokenIndex;
            Lval();
            if (getTokenType(tokenIndex).equals("ASSIGN"))
            {
                isExp = false;
            }
            this.tokenIndex = savedTokenIndex;

            if(isExp)//exp
            {
                asdNodes.add(Exp());
                /*跳过Exp末尾分号*/
                if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
                {
                    errori();
                }
                else {
                    tokenIndex++;
                }
                return new Stmt(Stmt.Type.Exp, asdNodes);
            }
            else { //LVAL
                asdNodes.add(Lval());
                /*Assign*/
                tokenIndex++;
                /*getInt*/
                if (tokens.get(tokenIndex).getOringinStr().equals("getint")) {
                    tokenIndex+=2;

                    if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
                    {
                        errorj();
                    }
                    else {
                        tokenIndex++;
                    }
                    if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
                    {
                        errori();
                    }
                    else {
                        tokenIndex++;
                    }
                }

                /*getChar*/
                if (tokens.get(tokenIndex).getOringinStr().equals("getchar")) {
                    tokenIndex+=2;

                    if(!tokens.get(tokenIndex).getOringinStr().equals(")"))
                    {
                        errorj();
                    }
                    else {
                        tokenIndex++;
                    }

                    if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
                    {
                        errori();
                    }
                    else {
                        tokenIndex++;
                    }
                    return new Stmt(Stmt.Type.intputChar, asdNodes);
                }

                asdNodes.add(Exp());
                if(!tokens.get(tokenIndex).getOringinStr().equals(";"))
                {
                    errori();
                }
                else
                {
                    tokenIndex += 1;
                }
                return new Stmt(Stmt.Type.Assign, asdNodes);
            }
        }
    }
    public Cond Cond()
    {
        return new Cond(LOrExp());
    }
    public LOrExp LOrExp()
    {
        ArrayList<LAndExp> lAndExpArrayList=new ArrayList<>();
        lAndExpArrayList.add(LAndExp());
//        System.out.println("判断LOREXP是否继续的单词 "+tokens.get(tokenIndex).getOringinStr());
        while (tokens.get(tokenIndex).getOringinStr().equals("||"))
        {
//            System.out.println("while循环里边token+之前的词 "+tokens.get(tokenIndex).getOringinStr());
            tokenIndex++;
//            System.out.println("while循环里边送进LAndExp的词 "+tokens.get(tokenIndex).getOringinStr());
            lAndExpArrayList.add(LAndExp());
        }
        return new LOrExp(lAndExpArrayList);
    }
    public LAndExp LAndExp()
    {
        ArrayList<EqExp> eqExpArrayList = new ArrayList<>();
        if(debugMode==2)
        System.out.println("准备开始统计LANDEXP的 token "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
        eqExpArrayList.add(EqExp());
//        System.out.println("判断LAND是否继续的单词 "+tokens.get(tokenIndex).getOringinStr());
        while(tokens.get(tokenIndex).getOringinStr().equals("&&"))
        {
            tokenIndex++;
            eqExpArrayList.add(EqExp());
        }
        return new LAndExp(eqExpArrayList);
    }
    public EqExp EqExp()
    {
        ArrayList<RelExp> relExpArrayList= new ArrayList<>();
        if(debugMode==2)
        System.out.println("加到EqExp 之前的token "+tokens.get(tokenIndex).getOringinStr()+tokens.get(tokenIndex).getLineNum());
        ArrayList<Token> opList=new ArrayList<>();
        relExpArrayList.add(RelExp());
//        System.out.println("判断EqExp是否继续的单词 "+tokens.get(tokenIndex).getOringinStr());
        while (tokens.get(tokenIndex).getOringinStr().equals("==")||tokens.get(tokenIndex).getOringinStr().equals("!="))
        {
            opList.add(tokens.get(tokenIndex));
            tokenIndex++;
            relExpArrayList.add(RelExp());
        }
//        System.out.println("EqExpEnd "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
        return new EqExp(relExpArrayList,opList);
    }
    public RelExp RelExp()
    {
        ArrayList<AddExp> addExpArrayList=new ArrayList<>();
        ArrayList<Token> opList=new ArrayList<>();
        addExpArrayList.add(AddExp());
//        System.out.println("判断Rel是否继续的单词 "+tokens.get(tokenIndex).getOringinStr());
        while(tokens.get(tokenIndex).getOringinStr().equals(">")||tokens.get(tokenIndex).getOringinStr().equals(">=")||tokens.get(tokenIndex).getOringinStr().equals("<")||tokens.get(tokenIndex).getOringinStr().equals("<="))
        {
            opList.add(tokens.get(tokenIndex));
            tokenIndex++;
            addExpArrayList.add(AddExp());
        }
//        System.out.println("RelExpEnd "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
        return new RelExp(addExpArrayList,opList);
    }
    public ForStmt ForStmt()
    {
        Lval lval = Lval();
        /*中间等于号也给跳了就是*/
        tokenIndex++;
        Exp exp=Exp();
        return new ForStmt(lval,exp);
    }
    public UnaryOp UnaryOp()
    {
        return new UnaryOp(tokens.get(tokenIndex++));
    }

    public Ident Ident()
    {
        return new Ident(tokens.get(tokenIndex++));
    }
    public Character Character()
    {
        CharConst charConst=CharConst();
        return new Character(charConst);
    }
    public CharConst CharConst()
    {
        Token token=tokens.get(tokenIndex++);
        return new CharConst(token);
    }
    public Number Number()
    {
        IntConst intConst=IntConst();
        return new Number(intConst);
    }
    public IntConst IntConst()
    {
        Token token=tokens.get(tokenIndex++);
        return new IntConst(token);
    }
    public ConstInitVal ConstInitVal()
    {
        StringConst stringConst=null;
        ArrayList<ConstExp> expArrayList=new ArrayList<>();
//        System.out.println("送进ConstInitval "+tokens.get(tokenIndex).getOringinStr()+" "+tokens.get(tokenIndex).getLineNum());
        if(tokens.get(tokenIndex).getOringinStr().equals("{"))
        {
//            System.out.println("ConstInitval here "+tokens.get(tokenIndex).getLineNum());
            tokenIndex++;
            if(tokens.get(tokenIndex).getOringinStr().equals("}"))
            {
                tokenIndex++;
                return  new ConstInitVal(true,expArrayList);
            }
            else
            {
                while(!tokens.get(tokenIndex).getOringinStr().equals("}"))
                {
                    if(debugMode==2)
                    System.out.println("要加入到ConstExp里边的东西 "+tokens.get(tokenIndex).getOringinStr());
                    expArrayList.add(ConstExp());
                    if(tokens.get(tokenIndex).getOringinStr().equals("}"))
                    {break;}
                    tokenIndex++;
                }
                tokenIndex++;
                return  new ConstInitVal(true,expArrayList);
            }
        }
        else if(getTokenType(tokenIndex).equals("STRCON"))
        {
            stringConst = StringConst();
            return new ConstInitVal(stringConst);
        }
        else
        {
            expArrayList.add(ConstExp());
            return new ConstInitVal(false,expArrayList);
        }
    }
    InitVal InitVal()
    {
        StringConst stringConst=null;
        ArrayList<Exp> expArrayList=new ArrayList<>();
        if(tokens.get(tokenIndex).getOringinStr().equals("{"))
        {
            tokenIndex++;
            if(tokens.get(tokenIndex).getOringinStr().equals("}"))
            {
                /*跳过分号*/
                tokenIndex++;
                return  new InitVal(expArrayList,true);
            }
            else
            {
                while(!tokens.get(tokenIndex).getOringinStr().equals("}"))
                {
                    /*跳过逗号*/
                    expArrayList.add(Exp());
                    if(tokens.get(tokenIndex).getOringinStr().equals("}"))
                    {
                        tokenIndex++;
                        break;
                    }
                    tokenIndex++;
                }
                return  new InitVal(expArrayList,true);
            }
        }
        else if(getTokenType(tokenIndex).equals("STRCON"))
        {
            stringConst = StringConst();
            return new InitVal(stringConst);
        }
        else
        {
            expArrayList.add(Exp());
            return new InitVal(expArrayList,false);
        }
    }

    StringConst StringConst()
    {
        return new StringConst(tokens.get(tokenIndex++));
    }
    BType BType()
    {
        return new BType(tokens.get(tokenIndex++).getOringinStr());
    }
    FuncType FuncType()
    {
        return new FuncType(tokens.get(tokenIndex++));
    }
    FuncFParams FuncFParams()
    {
        ArrayList<FuncFPram> funcFPramArrayList=new ArrayList<>();
        funcFPramArrayList.add(FuncFPram());
        while(tokens.get(tokenIndex).getOringinStr().equals(","))
        {
            tokenIndex++;
            funcFPramArrayList.add(FuncFPram());
        }
        return new FuncFParams(funcFPramArrayList);
    }
    FuncFPram FuncFPram()
    {
        BType bType=BType();
        Ident ident=Ident();
        boolean isArray=false;
        if(tokens.get(tokenIndex).getOringinStr().equals("["))
        {
            isArray=true;
            tokenIndex++;
            if(!tokens.get(tokenIndex).getOringinStr().equals("]"))
            {
                errork();
            }
            else {
                tokenIndex++;
            }
        }
        return new FuncFPram(bType,ident,isArray);
    }
}
