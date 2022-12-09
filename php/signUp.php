<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];
$userType = $_POST['userType'];

echo "PHP: Get POST infomation";
echo '<br>';

$values = 'signUp ' . $phone . ' ' . $passwd . ' ' . $userType;
$command = "../cpp/main " . escapeshellcmd($values);
$output = array();

echo "PHP: exec " . $command;
echo '<br>';

exec($command, $output);

for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
}

// header("refresh: 3;url=../index.html");
// echo "PHP: Please wait 3 seconds to turn back.\n";
?>