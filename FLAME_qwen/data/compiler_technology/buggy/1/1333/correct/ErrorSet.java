import java.util.Comparator;
import java.util.TreeSet;

public class ErrorSet {
    public static TreeSet<Error> errorSet = new TreeSet<>(new Comparator<Error>() {
        @Override
        public int compare(Error o1, Error o2) {
            return o1.getPosition() - o2.getPosition();
        }
    });
}
