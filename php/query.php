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

for ($i = 0; $i < count($output); $i++) {
    // echo 'C++: ' . $output[$i];
    echo $output[$i];
    echo '<br>';
}

// $res = "?";
// $cnt = 0;
// $receive = 0;
// $is_first = 1;
// for ($i = 0; $i < count($output); $i++) {
//     if ($output[$i] == "Return for PHP begin:") {
//         $receieve = 1;
//         continue;
//     } elseif ($output[$i] == "Return for PHP end.") {
//         break;
//     }
//     if ($receieve == 1) {
//         if ($is_first == 1) {
//             $is_first = 0;
//         } else {
//             $res = "&" + $res;
//         }
//         $res = $res + "r" + $cnt + "=" + $output[$i];
//         $cnt++;
//     }
// }

// header("refresh: 3;url=../index.html");
echo "PHP: Please wait 3 seconds to turn back.\n";
?>