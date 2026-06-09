package frontend.error;

import java.util.HashMap;

public class ErrorProcess {
    private boolean isError = false;
    private int errorCnt = 0;
    private HashMap<Integer, Error> errorHashMap = new HashMap<>();

    public boolean isError() {
        return isError;
    }

    public int getErrorCnt() {
        return errorCnt;
    }

    public void setError(Error error) {
        this.isError = true;
        this.errorHashMap.put(this.errorCnt, error);
        this.errorCnt++;
    }

    public HashMap<Integer, Error> getErrorHashMap() {
        return errorHashMap;
    }
}
