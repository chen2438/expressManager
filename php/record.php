<?php
$argv = "record";
for ($i = 0; $i < 12; $i++) {
    $tmp = 'r0';
    $argv = $argv . ' ' . $_post['r0'];
    echo $argv;
    echo '<br>';
}

echo "PHP: Get POST infomation";
echo '<br>';

$command = "../cpp/main " . escapeshellcmd($argv);
$output = array();

echo "PHP: exec " . $command;
echo '<br>';

exec($command, $output);

for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
}

// header("refresh: 5;url=../index.html");
echo "PHP: Please wait 3 seconds to turn back.\n";
?>