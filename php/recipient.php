<?php
$phone = $_POST['q0'];
// expressID, pickupID, phone, picked
$argv = "query null null " . $phone . " null";
$command = "../cpp/main " . escapeshellcmd($argv);

echo "PHP: exec " . $command;
echo '<br>';
$output = array();
exec($command, $output);

// 输出查询结果

$label = 0;
for ($i = 0; $i < count($output); $i++) {
    if ($output[$i] == "Return for PHP begin:") {
        $label = 1;
        continue;
    } else if ($output[$i] == "Return for PHP end.") {
        $label = 0;
        continue;
    }
    if ($label == 0) {
        echo 'C++: ' . $output[$i];
        echo '<br>';
    } else {
        echo $output[$i];
    }
}