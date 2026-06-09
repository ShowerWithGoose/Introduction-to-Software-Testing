package frontend;

public class PreParser {
    private static PreParser preparser = new PreParser();
    private static Token token;
    public PreParser(){

    }
    public static Token start(){
        token = PreLexer.getSym(false);
        if(type()==Type.LBRACK){
            getToken();
            Exp();
            if(type()==Type.RBRACK){
                getToken();
            }
        }
        return token;
    }
    private static void AddExp(){
        MulExp();
        while(type()==Type.PLUS||type()==Type.MINU){
            getToken();
            MulExp();
        }
    }
    private static void MulExp(){
        UnaryExp();
        while(type()==Type.MULT||type()==Type.DIV||type()==Type.MOD){
            getToken();
            UnaryExp();
        }
    }
    private static void UnaryExp(){
        while(type()==Type.PLUS||type()==Type.MINU||type()==Type.NOT){
            UnaryOp();
        }
        if(pre(true,1,true)==Type.LPARENT&&type()==Type.IDENFR){
            getToken();
            getToken();
            if(type()==Type.PLUS||type()==Type.MINU||type()==Type.NOT||
                    type()==Type.IDENFR||type()==Type.LPARENT||type()==Type.INTCON||type()==Type.CHRCON){
                FuncRParams();
            }
            if(type()==Type.RPARENT){
                getToken();
            }
        }else{
            PrimaryExp();
        }
    }
    private static void UnaryOp(){
        getToken();
    }
    private static void FuncRParams(){
        Exp();
        while(type()==Type.COMMA){
            getToken();
            Exp();
        }
    }
    private static void PrimaryExp(){
        if(type()==Type.LPARENT){
            getToken();
            Exp();
            if(type()==Type.RPARENT){
                getToken();
            }
        }else if(type()==Type.IDENFR){
            LVal();
        }else if(type()==Type.INTCON){
            Number();
        }else{
            Character();
        }
    }

    private static void Exp(){
        AddExp();
    }
    private static void LVal(){
        getToken();
        if(type()==Type.LBRACK){
            getToken();
            Exp();
            if(type()==Type.RBRACK){
                getToken();
            }
        }
    }
    private static void Number(){
        getToken();
    }
    private static void Character(){
        getToken();
    }
    private static void error(){

    }
    public static PreParser getInstance() {
        return preparser;
    }
    private static void getToken(){
        token = PreLexer.getSym(true);
    }
    private static Type pre(boolean isContinuous,int count,boolean reset){
        Token t = new Token();
        int tmp = PreLexer.getPos();
        if(!isContinuous){
            t = PreLexer.getSym(false);
            while((--count)>0){
                t = PreLexer.getSym(true);
            }
        }else{
            while((--count)>=0){
                t = PreLexer.getSym(true);
            }
        }
        if(reset)PreLexer.setPos(tmp);
        return t.getType();
    }
    private static Type type(){
        return token.getType();
    }
}
