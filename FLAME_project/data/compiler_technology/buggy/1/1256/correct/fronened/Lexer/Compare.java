package fronened.Lexer;

import java.util.Comparator;

public class Compare implements Comparator {
    @Override
    public int compare(Object o1, Object o2) {
        if (((Error)o1).getLine() > ((Error)o2).getLine()) {
            return 1;
        }
        return 0;
    }
}
