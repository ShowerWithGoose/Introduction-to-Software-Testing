package SysY.Error;

public class theError {
    public int row;
    public char type;
    public theError(int row,char type){
        this.row=row;
        this.type=type;
    }
    public int getRow(){
        return this.row;
    }


}