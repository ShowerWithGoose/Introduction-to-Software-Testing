package src.ErrorHandle;

public class BaseError {
    private int row;
    private int col;
    private Errortype errortype;

    public BaseError(int row, int col, Errortype errortype) {
        this.row = row;
        this.col = col;
        this.errortype = errortype;
    }

    public int getRow() {
        return row;
    }

    public Errortype getErrortype() {
        return errortype;
    }
}
