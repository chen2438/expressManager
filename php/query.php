<?php
$argv = "query";
for ($i = 0; $i < 3; $i++) {
    $post = $_POST['r' . $i];
    $post = str_replace(" ", "_", $post);
    $argv = $argv . ' ' . $post;
}

echo "PHP: Get POST infomation";
echo '<br>';

$command = "../cpp/main " . escapeshellcmd($argv);
$output = array();

echo "PHP: exec " . $command;
echo '<br>';

exec($command, $output);

$label = 0;
for ($i = 0; $i < count($output); $i++) {
    if ($output[$i] == "Return for PHP begin:") {
        $label = 1;
        continue;
    }
    if ($output[$i] == "Return for PHP end.") {
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
?>
<a href="javascript:history.go(-1);">
    <button>Turn Back</button>
</a>