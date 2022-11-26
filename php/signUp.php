<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];
$userType = $_POST['userType'];

$values = 'signUp ' . $phone . ' ' . $passwd . ' ' . $userType;
$command = "../cpp/main " . escapeshellcmd($values);
$output = array();
exec($command, $output);

for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
}

header("refresh: 5;url=../index.html");
echo "PHP: Please wait 3 seconds to turn back.\n";
?>