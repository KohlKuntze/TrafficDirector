package dao;

import model.Table;
import org.junit.Assert;
import org.junit.Test;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class TableWriterTest {

    private static final String TABLE_FILENAME = "/Users/kohlkuntze/Documents/Workspaces/GOcery/TableDataAccessTest/dao/data/sample_table2.tbl";

    @Test
    public void exportTableToFileOne() {
        Table tableOne = new Table(TABLE_FILENAME);

        String primaryKeyOne = "primKey1";
        String primaryKeyTwo = "primKey2";
        String primaryKeyThree = "primKey3";
        String headerOne = "header1";
        String headerTwo = "header2";
        String headerThree = "header3";

        String data_1_1 = "data1";
        String data_1_2 = "data2";
        String data_2_1 = "data3";
        String data_2_2 = "data4";
        String data_3_3 = "data5";

        tableOne.setData(primaryKeyOne, headerOne, data_1_1);
        tableOne.setData(primaryKeyOne, headerTwo, data_1_2);
        tableOne.setData(primaryKeyTwo, headerOne, data_2_1);
        tableOne.setData(primaryKeyTwo, headerTwo, data_2_2);

        TableWriter.exportTableToFile(tableOne);

        try {
            Table tableTwo = TableReader.loadTableFromFile(TABLE_FILENAME);
            Assert.assertEquals(data_1_1, tableTwo.getData(primaryKeyOne, headerOne));
            Assert.assertEquals(data_1_2, tableTwo.getData(primaryKeyOne, headerTwo));
            Assert.assertEquals(data_2_1, tableTwo.getData(primaryKeyTwo, headerOne));
            Assert.assertEquals(data_2_2, tableTwo.getData(primaryKeyTwo, headerTwo));

            tableTwo.setData(primaryKeyThree, headerThree, data_3_3);

            TableWriter.exportTableToFile(tableTwo);

            Table tableThree = TableReader.loadTableFromFile(TABLE_FILENAME);

            Assert.assertEquals(data_1_1, tableThree.getData(primaryKeyOne, headerOne));
            Assert.assertEquals(data_1_2, tableThree.getData(primaryKeyOne, headerTwo));
            Assert.assertEquals(null, tableThree.getData(primaryKeyOne, headerThree));

            Assert.assertEquals(data_2_1, tableThree.getData(primaryKeyTwo, headerOne));
            Assert.assertEquals(data_2_2, tableThree.getData(primaryKeyTwo, headerTwo));
            Assert.assertEquals(null, tableThree.getData(primaryKeyTwo, headerThree));

            Assert.assertEquals(null, tableThree.getData(primaryKeyThree, headerOne));
            Assert.assertEquals(null, tableThree.getData(primaryKeyThree, headerTwo));
            Assert.assertEquals(data_3_3, tableThree.getData(primaryKeyThree, headerThree));

            TableWriter.exportTableToFile(tableThree);

            Files.delete(Paths.get(TABLE_FILENAME));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
