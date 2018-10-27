package util;

import model.Node;

import java.util.Comparator;

public class NodeComparators {

    class IntegerComparator implements Comparator<Integer> {
        public int compare(Integer a, Integer b) {
            return a - b;
        }
    }

}
