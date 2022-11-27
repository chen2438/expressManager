<?php
$argv = "record";
for ($i = 0; $i < 12; $i++) {
    $argv = $argv . ' ' . $_post["r" . (string) ($i)];
}

$command = "../cpp/main " . escapeshellcmd($argv);
$output = array();
exec($command, $output);

for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
}

// header("refresh: 5;url=../index.html");
echo "PHP: Please wait 3 seconds to turn back.\n";
?>