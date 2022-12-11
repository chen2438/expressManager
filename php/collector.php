<?php

$argv = ["record", "query", "queryAll", "delete", "mark", "stats"];

echo "PHP: Get POST info"; //开始获取所有POST
echo '<br>';

for ($i = 0; $i <= 14; $i++) {
    $post = $_POST['r' . $i];
    $post = str_replace(" ", "_", $post);
    $argv[0] .= ' ' . $post;
}

for ($i = 0; $i <= 2; $i++) {
    $post = $_POST['q' . $i];
    $post = str_replace(" ", "_", $post);
    $argv[1] .= ' ' . $post;
}

for ($i = 0; $i <= 0; $i++) {
    $post = $_POST['qa' . $i];
    $post = str_replace(" ", "_", $post);
    $argv[2] .= ' ' . $post;
}

for ($i = 0; $i <= 0; $i++) {
    $post = $_POST['d' . $i];
    $post = str_replace(" ", "_", $post);
    $argv[3] .= ' ' . $post;
}

for ($i = 0; $i <= 1; $i++) {
    $post = $_POST['m' . $i];
    $post = str_replace(" ", "_", $post);
    $argv[4] .= ' ' . $post;
}

for ($i = 0; $i <= 0; $i++) {
    $post = $_POST['e' . $i];
    $post = str_replace(" ", "_", $post);
    $argv[5] .= ' ' . $post;
}

$enable = [$_POST['rs'], $_POST['qs'], $_POST['qas'], $_POST['ds'], $_POST['ms'], $_POST['es']];
$command = "";

for ($i = 0; $i <= 5; $i++) { //判断启用哪个功能
    if ($enable[$i] == 'enable') {
        $command = "../cpp/main " . escapeshellcmd($argv[$i]);
        break;
    }
}

if ($command == "") {
    echo 'PHP: ERROR: No input.';
    echo '<br>';
    exit(0);
}

echo "PHP: exec " . $command;
echo '<br>';
$output = array();
exec($command, $output);

// 输出查询结果
if ($enable[1] == "enable" or $enable[2] == "enable") {
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
} else {
    for ($i = 0; $i < count($output); $i++) {
        echo 'C++: ' . $output[$i];
        echo '<br>';
    }
}