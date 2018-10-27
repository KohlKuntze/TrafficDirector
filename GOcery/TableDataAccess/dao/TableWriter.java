package dao;

import model.Table;

import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class TableWriter {

    private static final String TAB_REGEX = "\t";
    private static final String NEXT_LINE_REGEX = "\n";

    public static void exportTableToFile(Table table) {
        List<String> headers = new ArrayList<>();

        for(String header : table.getHeaders()) {
            headers.add(header);
        }

        try {
            Writer fileWriter = new FileWriter(table.getFilename());

            for(int index = 0; index < headers.size(); index++) {
                fileWriter.write(headers.get(index));

                if(index < headers.size() - 1) {
                    fileWriter.write(TAB_REGEX);
                } else {
                    fileWriter.write(NEXT_LINE_REGEX);
                }
            }

            boolean addNextLine = true;
            int counter = 0;


            for(String primaryKey : table.getPrimaryKeys()) {
                counter++;

                if(counter == table.getPrimaryKeys().size()) {
                    addNextLine = false;
                }

                fileWriter.write(primaryKey + TAB_REGEX);

                for(int index = 0; index < headers.size(); index++) {

                    if(table.getData(primaryKey, headers.get(index)) != null) {
                        fileWriter.write(table.getData(primaryKey, headers.get(index)));
                    } else {
                        fileWriter.write(TableReader.NULL_DATA_STRING);
                    }

                    if(index < headers.size() - 1) {
                        fileWriter.write(TAB_REGEX);
                    } else if (addNextLine) {
                        fileWriter.write(NEXT_LINE_REGEX);
                    }
                }
            }

            fileWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
