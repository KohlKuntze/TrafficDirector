package utils;

import model.Table;

import java.util.ArrayList;
import java.util.List;

public class TableUtilites {

    private static final String TAB_REGEX = "\t";
    private static final String NEXT_LINE_REGEX = "\n";


    public static void printTable(Table table) {
        List<String> headers = new ArrayList<>();

        System.out.print("entries: " + table.getPrimaryKeys().size() + TAB_REGEX);

        for(String header : table.getHeaders()) {
            System.out.print(header + TAB_REGEX);
            headers.add(header);
        }

        System.out.println("");

        for(String primaryKey : table.getPrimaryKeys()) {
            System.out.print(primaryKey + TAB_REGEX);

            for(int index = 0; index < headers.size(); index++) {
                System.out.print(table.getData(primaryKey, headers.get(index)));

                if(index < headers.size() - 1) {
                    System.out.print(TAB_REGEX);
                } else {
                    System.out.print(NEXT_LINE_REGEX);
                }
            }
        }
    }
}
