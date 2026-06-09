package src;

import java.io.IOException;

public class State1 {
    private Words words;
    private Phrase phrase = new Phrase();
    private Sort sort;
    private Errors error = new Errors();

    public State1(String string) {
        words = new Words(string);
        sort = new Sort(phrase, words,error);
    }

    public void work() throws IOException {
        while (true) {
            if (words.max()) {
                if (error.error()) {
                    phrase.word();

                } else {
                    error.word();
                }
                break;
            }
            sort.work();
        }
    }
}
