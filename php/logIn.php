<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];

echo "PHP: Get POST infomation";
echo '<br>';

$command = "../cpp/main " . escapeshellcmd('logIn ' . $phone . ' ' . $passwd);
$output = array();

echo "PHP: exec " . $command;
echo '<br>';

exec($command, $output);

for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
}
if ($output[count($output) - 1] == "Recipient, welcome!") {
    header("refresh: 5;url=../recipient.html?phone=" . $phone);
    echo "PHP: Please wait 3 seconds to refresh.";
    echo '<br>';
} elseif ($output[count($output) - 1] == "Collector, welcome!") {
    header("refresh: 5;url=../collector.html?phone=" . $phone);
    echo "PHP: Please wait 3 seconds to refresh.";
    echo '<br>';
} else {
    header("refresh: 5;url=../html.html");
    echo "PHP: Please wait 3 seconds to turn back.";
    echo '<br>';
}
?>