package assist;

import java.util.Arrays;
import java.util.HashSet;

public class Reserver {
    private HashSet<String> reservedWords = new HashSet<>();

    public Reserver() {
        String[] array = {"const","int","char","main",
                "void","if","else","for","break","continue",
                "return","getint","getchar","printf"};
        this.reservedWords.addAll(Arrays.asList(array));
    }

    public boolean isReserver(String identifier) {
        return this.reservedWords.contains(identifier);
    }
}
