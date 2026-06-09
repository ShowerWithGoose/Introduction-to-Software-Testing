package frontend;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Objects;

public class Parser {
    Lexer lexer;
    ArrayList<Token> tokens = new ArrayList<>();//一整个大数组，其中包括词法成分和语法成分
    ArrayList<Error> errors = new ArrayList<>();//存放错误的数组,包括语法错误和词法错误
    PrintStream ps1 = null;
    PrintStream ps2 = null;
    ArrayList<Token> total = new ArrayList<>();
    public Parser(String input){
        try {
            ps1 = new PrintStream("parser.txt");
            ps2 = new PrintStream("error.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        this.lexer = new Lexer(input,tokens,errors,total);
    }
    //在解析方法中，已经存起来的token必须是该语法成分的一部分
    public void parse(){
        CompUnit();
        for(int i = 0;i<errors.size();i=i+1){
            ps2.printf("%d %c\n",errors.get(i).getCurLine(),errors.get(i).getErrorType());
        }
        for(int i = 0;i<tokens.size()-1;i=i+1){
            if(tokens.get(i).getLexType() == LexType.FAKE){
                ps1.printf("%s\n",tokens.get(i).getToken());
            }else{
                ps1.printf("%s %s\n",tokens.get(i).getLexType(),tokens.get(i).getToken());
            }

        }
    }
    public void CompUnit(){
        getsym();

        while(now().equals("char")||now().equals("int")||now().equals("void")||now().equals("const")){//括号中的条件设置是为了终止程序的
            if(now().equals("void")){
                FuncDef();
            }else if(now().equals("const")){
                Decl();
            }else if(now().equals("char")){//上面两种情况是不会重复的,同时char和int也不一样，int还有主函数的情况
                if(prePreRead().equals("(")){
                    FuncDef();
                }else {
                    Decl();
                }
            }else{//这个时候情况比较复杂，还包括主函数
                if(preRead().equals("main")){
                    MainFuncDef();
                    break;
                }else{
                    if(prePreRead().equals("(")){
                        FuncDef();
                    }else {
                        Decl();
                    }
                }
            }
        }
        //fakeInsert("<>");
        fakeInsert("<CompUnit>");
    }
    public void Decl(){
        if(now().equals("const")){//不用getsym因为const就是其中的一部分
            ConstDecl();
        }else{
            VarDecl();
        }
        //不用输出所以不需要加到数组中
    }
    public void ConstDecl(){
        getsym();

        BType();
        ConstDef();
        while(now().equals(",")){
            getsym();
            ConstDef();
        }
        if(!now().equals(";")){
            Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
            errors.add(error);
        }else{
            getsym();
        }
        fakeInsert("<ConstDecl>");
    }
    public void BType(){
        getsym();
    }
    public void ConstDef(){
        getsym();

        if(now().equals("[")){
            getsym();
            ConstExp();
            if(!now().equals("]")){
                Error error = new Error(lexer.special(),'k');
                errors.add(error);
            }else{
                getsym();
            }
        }
        getsym();
        ConstInitVal();
        fakeInsert("<ConstDef>");
    }
    public void ConstInitVal(){
        if(now().equals("{")){
            getsym();
            if(now().equals("}")){
                getsym();
            }else{
                ConstExp();
                while(now().equals(",")){
                    getsym();
                    ConstExp();
                }
                getsym();
            }
        }else if(now().charAt(0) == '"'){
            getsym();
        } else {
            ConstExp();
        }
        fakeInsert("<ConstInitVal>");

    }
    public void VarDecl(){
        BType();
        VarDef();
        while(now().equals(",")){
            getsym();
            VarDef();
        }
        if(!now().equals(";")){
            Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
            errors.add(error);
        }else{
            getsym();
        }
        fakeInsert("<VarDecl>");


    }
    public void VarDef(){
        getsym();
        if(now().equals("=")){
            getsym();
            InitVal();
        }else if(now().equals("[")){
            getsym();
            ConstExp();
            if(!now().equals("]")){
                Error error = new Error(lexer.special(),'k');
                errors.add(error);
            }else{
                getsym();
            }
            if(now().equals("=")){
                getsym();
                InitVal();
            }
        }
        fakeInsert("<VarDef>");

    }
    public void InitVal(){
        if(now().charAt(0) == '"'){
            getsym();
        }else if(now().equals("{")){
            getsym();
            if(!now().equals("}")){
                Exp();
                while(now().equals(",")){
                    getsym();
                    Exp();
                }
                getsym();
            }else{
                getsym();
            }
        }else{
            Exp();
        }
        fakeInsert("<InitVal>");

    }
    public void FuncDef(){
        FuncType();

        getsym();

        getsym();

        if(now().equals("int")||now().equals("char")){
            FuncFParams();
        }
        if(!now().equals(")")){
            Error error = new Error(lexer.special(),'j');
            errors.add(error);
        }else {
            getsym();
        }
        Block();
        fakeInsert("<FuncDef>");

    }
    public void MainFuncDef(){
        getsym();
        getsym();
        getsym();
        if(!now().equals(")")){
            Error error = new Error(lexer.special(),'j');
            errors.add(error);
        }else{
            getsym();
        }
        Block();
        fakeInsert("<MainFuncDef>");

    }
    public void FuncType(){
        getsym();
        fakeInsert("<FuncType>");

    }
    public void FuncFParams(){
        FuncFParam();
        while(now().equals(",")){
            getsym();
            FuncFParam();
        }
        fakeInsert("<FuncFParams>");
    }
    public void FuncFParam(){
        BType();
        getsym();
        if(now().equals("[")){
            getsym();
            if(!now().equals("]")){
                Error error = new Error(lexer.special(),'k');//保留的是上一个token的行数
                errors.add(error);
            }else{
                getsym();
            }
        }
        fakeInsert("<FuncFParam>");

    }
    public void Block(){
        getsym();
        if(now().equals("}")){
            getsym();
        }else{
            while(!now().equals("}")){
                BlockItem();
            }
            getsym();
        }
        fakeInsert("<Block>");


    }
    public void BlockItem(){
        if(now().equals("char")||now().equals("int")||now().equals("const")){
            Decl();
        }else{
            Stmt();
        }
    }
    public void Stmt(){
        if(now().equals("{")){
            Block();
        }else if(now().equals("if")){
            getsym();
            getsym();
            Cond();
            if(!now().equals(")")){
                Error error = new Error(lexer.special(),'j');//保留的是上一个token的行数
                errors.add(error);
            }else{
                getsym();
            }
            Stmt();
            if(now().equals("else")){
                getsym();
                Stmt();
            }
        }else if(now().equals("for")){
            getsym();
            getsym();

            if(!now().equals(";")){
                ForStmt();
            }
            getsym();

            if(!now().equals(";")){
                Cond();
            }
            getsym();

            if(!now().equals(")")){
                ForStmt();
            }
            getsym();

            Stmt();
        }else if(now().equals("break")||now().equals("continue")){
            getsym();
            if(!now().equals(";")){
                Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                errors.add(error);
            }else {
                getsym();
            }
        }else if(now().equals("return")){
            getsym();
            if(now().equals("+")||now().equals("-")||now().equals("!")||lexer.getCurToken().getLexType() == LexType.IDENFR||now().equals("(")||Character.isDigit(now().charAt(0))
                    ||now().charAt(0) == '\''){//说明有Exp
                Exp();
            }
            if(!now().equals(";")){
                Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                errors.add(error);
            }else {
                getsym();
            }
        }else if(now().equals("printf")){
            getsym();
            getsym();
            getsym();
            while (now().equals(",")){
                getsym();
                Exp();
            }
            if(!now().equals(")")){
                Error error = new Error(lexer.special(),'j');//保留的是上一个token的行数
                errors.add(error);
            }else {
                getsym();
            }
            if(!now().equals(";")){
                Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                errors.add(error);
            }else {
                getsym();
            }
        }else if(now().equals(";")){
            getsym();
        }else if(now().equals("+")||now().equals("-")||now().equals("!")||now().charAt(0) == '\''||
                Character.isDigit(now().charAt(0))||now().equals("(")||((now().charAt(0) == '_'||
                Character.isLetter(now().charAt(0))) && Objects.equals(preRead(), "("))){
            Exp();
            if(!now().equals(";")){
                Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                errors.add(error);
            }else {
                getsym();
            }
        }else{//处理的是假处理LVal后确定是解析Exp还是其他分支的情况
            char tmpChar = lexer.getCurChar();
            int tmpCurLine = lexer.getCurLine();
            int tmpCurPos = lexer.getCurPos();
            StringBuilder tmpToken = new StringBuilder(lexer.getToken());
            int tmpFlag = lexer.getFlag();
            int tmpSize = errors.size();
            int tmpSize1 = total.size();


            ArrayList<Token> t = new ArrayList<>();
            for(int i = 0;i<tokens.size();i=i+1){
                t.add(tokens.get(i));
            }

            fakeLVal();

            if (now().equals("=")){
                lexer.reSet(tmpChar,tmpCurLine,tmpCurPos,tmpToken,tmpFlag);

                errors.subList(tmpSize,errors.size()).clear();
                total.subList(tmpSize1,total.size()).clear();

                tokens.clear();

                for(int i = 0;i<t.size();i=i+1){
                    tokens.add(t.get(i));
                }


                LVal();
                getsym();//跳过等号
                if(now().equals("getint")){
                    getsym();
                    getsym();
                    if(!now().equals(")")){
                        Error error = new Error(lexer.special(),'j');//保留的是上一个token的行数
                        errors.add(error);
                    }else {
                        getsym();
                    }
                    if(!now().equals(";")){
                        Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                        errors.add(error);
                    }else {
                        getsym();
                    }
                }else if(now().equals("getchar")){
                    getsym();
                    getsym();
                    if(!now().equals(")")){
                        Error error = new Error(lexer.special(),'j');//保留的是上一个token的行数
                        errors.add(error);
                    }else {
                        getsym();
                    }
                    if(!now().equals(";")){
                        Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                        errors.add(error);
                    }else {
                        getsym();
                    }
                }else{
                    Exp();
                    if(!now().equals(";")){
                        Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                        errors.add(error);
                    }else {
                        getsym();
                    }
                }
            }else{//发现隔了一个语法成分之后不是等于号，说明解析的是Exp
                lexer.reSet(tmpChar,tmpCurLine,tmpCurPos,tmpToken,tmpFlag);
                errors.subList(tmpSize,errors.size()).clear();
                total.subList(tmpSize1,total.size()).clear();

                tokens.clear();

                for(int i = 0;i<t.size();i=i+1){
                    tokens.add(t.get(i));
                }



                Exp();
                if(!now().equals(";")){
                    Error error = new Error(lexer.special(),'i');//保留的是上一个token的行数
                    errors.add(error);
                }else {
                    getsym();
                }
            }

        }
        fakeInsert("<Stmt>");
    }
    public void ForStmt(){
        LVal();
        getsym();
        Exp();
        fakeInsert("<ForStmt>");


    }
    public void Exp(){
        AddExp();
        fakeInsert("<Exp>");
    }
    public void Cond(){
        LOrExp();

        fakeInsert("<Cond>");

    }
    public void LVal(){
        getsym();
        if(now().equals("[")){
            getsym();
            Exp();
            if(!now().equals("]")){
                Error error = new Error(lexer.special(), 'k');
                errors.add(error);
            }else {
                getsym();
            }
        }
        fakeInsert("<LVal>");
    }
    public void fakeLVal(){//假解析
        getsym();
        if(now().equals("[")){
            getsym();
            Exp();
            if(now().equals("]")){
                getsym();
            }
        }
        //Token tok = new Token("<LVal>",LexType.FAKE,-1);
        //tokens.add(tok);
    }
    public void PrimaryExp(){
        if(now().equals("(")){
            getsym();
            Exp();
            if(!now().equals(")")){
                Error error = new Error(lexer.special(), 'j');
                errors.add(error);
            }else{
                getsym();
            }
        }else if(now().charAt(0) == '\''){
            Character();
        }else if(Character.isDigit(now().charAt(0))){
            Number();
        }else {
            LVal();
        }
        fakeInsert("<PrimaryExp>");
    }
    public void Number(){
        getsym();
        fakeInsert("<Number>");
    }
    public void Character(){
        getsym();
        fakeInsert("<Character>");
    }
    public void UnaryExp(){
        if(now().equals("+")||now().equals("-")||now().equals("!")){
            UnaryOp();
            UnaryExp();
        }else if((Character.isLetter(now().charAt(0))||now().charAt(0) == '_')&&preRead().equals("(")){
            getsym();
            getsym();
            if(now().equals("+")||now().equals("-")||now().equals("!")||now().charAt(0) == '_'||
                    Character.isLetter(now().charAt(0))||now().equals("(")||Character.isDigit(now().charAt(0))
            ||now().charAt(0) == '\''){//说明有实参
                FuncRParams();
            }
            if(!now().equals(")")){
                Error error = new Error(lexer.special(),'j');//保留的是上一个token的行数
                errors.add(error);
            }else {
                getsym();
            }
        }else{
            PrimaryExp();
        }
        fakeInsert("<UnaryExp>");
    }
    public void UnaryOp(){
        getsym();
        fakeInsert("<UnaryOp>");
    }
    public void MulExp(){

        UnaryExp();
        fakeInsert("<MulExp>");
        while(now().equals("*")||now().equals("/")||now().equals("%")){
            getsym();
            UnaryExp();
            fakeInsert("<MulExp>");
        }

    }
    public void RelExp(){
        AddExp();
        fakeInsert("<RelExp>");
        while(now().equals("<")||now().equals(">")||now().equals("<=")||now().equals(">=")){
            getsym();
            AddExp();fakeInsert("<RelExp>");
        }


    }
    public void EqExp(){
        RelExp();
        fakeInsert("<EqExp>");
        while(now().equals("==")||now().equals("!=")){
            getsym();
            RelExp();fakeInsert("<EqExp>");
        }


    }
    public void LAndExp(){
        EqExp();
        fakeInsert("<LAndExp>");
        while(now().equals("&&")){
            getsym();
            EqExp();fakeInsert("<LAndExp>");
        }


    }
    public void LOrExp(){
        LAndExp();
        fakeInsert("<LOrExp>");
        while(now().equals("||")){
            getsym();
            LAndExp();fakeInsert("<LOrExp>");
        }


    }

    public void AddExp(){
        MulExp();
        fakeInsert("<AddExp>");
        while(now().equals("+")||now().equals("-")){
            getsym();
            MulExp();fakeInsert("<AddExp>");
        }


    }
    public void ConstExp(){
        AddExp();
        fakeInsert("<ConstExp>");
    }
    public void FuncRParams(){
        Exp();
        while(now().equals(",")){
            getsym();
            Exp();
        }
        fakeInsert("<FuncRParams>");
    }
    public void getsym(){
        lexer.next();
    }
    public String now(){
        return lexer.getToken().toString();
    }
    public String prePreRead(){
        return lexer.prePreRead().toString();
    }
    public String preRead(){
        return lexer.preRead().toString();
    }
    public int curLine(){
        return lexer.getCurLine();
    }
    public void fakeInsert(String s){
        Token tok = new Token(s,LexType.FAKE,-1);
        tokens.add(tokens.get(tokens.size()-1));
        tokens.set(tokens.size()-2,tok);
    }
   
}
