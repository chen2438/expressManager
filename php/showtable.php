<?php
//在表格中显示表的数据，常用方式
function ShowTable($table_name)
{
    $field_name = array("expressID", "pickupID", "company", "weight", "receiver", "receiverPhone", "receiverAddress", "receiverZip", "sender", "senderPhone", "senderAddress", "senderZip", "picked");
    echo "test数据库的" . "$table_name" . "表的所有用户数据如下：<br/>";
    echo "共计" . $rows . "行 " . $colums . "列<br/>";

    echo "<table style='border-color: #efefef;' border='1px' cellpadding='5px' cellspacing='0px'><tr>";
    for ($i = 0; $i < $colums; $i++) {
        echo "<th>" + $field_name[$i] + "</th>";
    }
    echo "</tr>";
    while ($row = mysql_fetch_row($res)) {
        echo "<tr>";
        for ($i = 0; $i < $colums; $i++) {
            echo "<td>$row[$i]</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}
ShowTable("test1");
?>