package symbol;

import java.util.ArrayList;

public class Symbol {
    private int lineNum;
    private String name;
    private String type;
    private int flag1;//1,2,3,4,5:const,var,func,array,const array
    private int flag2;//1,2,3:int,char,void
    private int dimension; // array维数
    private ArrayList<Symbol> paras = new ArrayList<>();//func参数


    public Symbol(int lineNum,String name,int flag1,int flag2) {
        this.lineNum = lineNum;
        this.name = name;
        this.type = null;
        this.flag1 = flag1;
        this.flag2 = flag2;
        this.dimension = 0;
        this.paras = new ArrayList<>();
    }

    public String Type(){
        if(flag1 == 1 && flag2 == 1){
            return "ConstInt";
        }
        if(flag1 == 1 && flag2 == 2){
            return "ConstChar";
        }
        if(flag1 == 2 && flag2 == 1){
            return "Int";
        }
        if(flag1 == 2 && flag2 == 2){
            return "Char";
        }
        if(flag1 == 3 && flag2 == 1){
            return "IntFunc";
        }
        if(flag1 == 3 && flag2 == 2){
            return "CharFunc";
        }
        if(flag1 == 3 && flag2 == 3){
            return "VoidFunc";
        }
        if(flag1 == 4 && flag2 == 1){
            return "IntArray";
        }
        if(flag1 == 4 && flag2 == 2){
            return "CharArray";
        }
        if(flag1 == 5 && flag2 == 1){
            return "ConstIntArray";
        }
        if(flag1 == 5 && flag2 == 2){
            return "ConstCharArray";
        }
        return "null";
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getFlag1() {
        return flag1;
    }

    public void setFlag1(int flag1) {
        this.flag1 = flag1;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFlag2() {
        return flag2;
    }

    public void setFlag2(int flag2) {
        this.flag2 = flag2;
    }

    public int getDimension() {
        return dimension;
    }

    public void setDimension(int dimension) {
        this.dimension = dimension;
    }

    public ArrayList<Symbol> getParas() {
        return paras;
    }

    public void setParas(ArrayList<Symbol> paras) {
        this.paras = paras;
    }

    public void addParas(Symbol para){
        this.paras.add(para);
    }
}
