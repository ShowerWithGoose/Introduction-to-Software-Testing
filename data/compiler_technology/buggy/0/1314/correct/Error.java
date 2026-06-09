public class Error {
    private char errorType;
    private int lineNum;

    public Error(char errorType,int lineNum){
        this.errorType=errorType;
        this.lineNum=lineNum;
    }

    @Override
    public String toString(){
        return String.format("%d %c",lineNum,errorType);
    }
}
