package frontend.error;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Error {
    private static boolean isError = false;
    //    private static ArrayList<TokenError> tokenErrors = new ArrayList<>();
    static Comparator<TokenError> cmp = new Comparator<TokenError>() {
        @Override
        public int compare(TokenError o1, TokenError o2) {
            return o1.getLine() - o2.getLine();
        }
    };
    private static PriorityQueue<TokenError> tokenErrors = new PriorityQueue<>(cmp);

    public Error() {

    }

    public void addTokenError(TokenError tokenError) {
        isError = true;
        tokenErrors.add(tokenError);
    }

    public boolean getIsError() {
        return isError;
    }

    public void outputErrorInfo() {
        while (!tokenErrors.isEmpty()) {
            System.out.println(tokenErrors.poll().toString());
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        while (!tokenErrors.isEmpty()) {
            sb.append(tokenErrors.poll().toString());
        }
        return sb.toString();
    }


}
