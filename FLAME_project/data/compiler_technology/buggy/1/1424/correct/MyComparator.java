import frontend.Error;

import java.util.Comparator;

public class MyComparator implements Comparator<Error> {
    @Override
    public int compare(Error o1, Error o2) {
        return o1.getLine()-o2.getLine();
    }
}