<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];

$values = 'logIn ' . $phone . ' ' . $passwd;
$command = "../cpp/main " . escapeshellcmd($values);
$output = array();
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