package token;

public class Errorz implements Comparable<Errorz>{
    private int rowNumber;
    private String error;
    
    public Errorz(int rowNumber,String error) {
        this.rowNumber = rowNumber;
        this.error = error;
    }
    
    public String getError() {
        return error;
    }
    
    public int getRowNumber() {
        return rowNumber;
    }
    
    @Override
    public int compareTo(Errorz o) {
        return rowNumber - o.getRowNumber();
    }
}
