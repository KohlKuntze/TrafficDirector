package model;

import org.junit.Assert;
import org.junit.Test;

public class TableTest {

    private static final String TABLE_FILENAME = "table.tbl";

    @Test
    public void getFilenameOne() {
        Table table = new Table(TABLE_FILENAME);
        Assert.assertEquals(TABLE_FILENAME, table.getFilename());
    }

    @Test
    public void setDataTestOne() {
        Table table = new Table(TABLE_FILENAME);

        String primaryKeyOne = "primKey1";
        String primaryKeyTwo = "primKey2";
        String headerOne = "header1";
        String headerTwo = "header2";

        String data_1_1 = "data1";
        String data_1_2 = "data2";
        String data_2_1 = "data3";
        String data_2_2 = "data4";

        int primKeySize = 0;
        int headerSize = 0;

        Assert.assertTrue(table.getPrimaryKeys().size() == primKeySize++);
        Assert.assertTrue(table.getHeaders().size() == headerSize++);

        table.setData(primaryKeyOne, headerOne, data_1_1);

        Assert.assertTrue(table.getPrimaryKeys().size() == primKeySize++);
        Assert.assertTrue(table.getHeaders().size() == headerSize);

        table.setData(primaryKeyTwo, headerOne, data_2_1);

        Assert.assertTrue(table.getPrimaryKeys().size() == primKeySize);
        Assert.assertTrue(table.getHeaders().size() == headerSize++);

        table.setData(primaryKeyTwo, headerTwo, data_2_2);

        Assert.assertTrue(table.getPrimaryKeys().size() == primKeySize);
        Assert.assertTrue(table.getHeaders().size() == headerSize);
        Assert.assertEquals(null, table.getData(primaryKeyOne, headerTwo));

        table.setData(primaryKeyOne, headerTwo, data_1_2);

        Assert.assertEquals(data_1_2, table.getData(primaryKeyOne, headerTwo));

    }

    @Test
    public void getDataTestOne() {
        Table table = new Table(TABLE_FILENAME);

        String primaryKeyOne = "primKey1";
        String primaryKeyTwo = "primKey2";
        String headerOne = "header1";
        String headerTwo = "header2";

        String data_1_1 = "data1";
        String data_1_2 = "data2";
        String data_2_1 = "data3";
        String data_2_2 = "data4";

        table.setData(primaryKeyOne, headerOne, data_1_1);
        table.setData(primaryKeyOne, headerTwo, data_1_2);
        table.setData(primaryKeyTwo, headerOne, data_2_1);
        table.setData(primaryKeyTwo, headerTwo, data_2_2);

        Assert.assertEquals(data_1_1, table.getData(primaryKeyOne, headerOne));
        Assert.assertEquals(data_1_2, table.getData(primaryKeyOne, headerTwo));
        Assert.assertEquals(data_2_1, table.getData(primaryKeyTwo, headerOne));
        Assert.assertEquals(data_2_2, table.getData(primaryKeyTwo, headerTwo));

    }

    @Test
    public void removePrimaryKeyTestOne() {
        Table table = new Table(TABLE_FILENAME);

        String primaryKeyOne = "primKey1";
        String headerOne = "header1";
        String data_1_1 = "data1";

        int entries = 0;

        Assert.assertTrue(table.getPrimaryKeys().size() == entries++);

        table.setData(primaryKeyOne, headerOne, data_1_1);

        Assert.assertTrue(table.getPrimaryKeys().size() == entries--);

        table.removePrimaryKey(primaryKeyOne);

        Assert.assertTrue(table.getPrimaryKeys().size() == entries);

    }


}
