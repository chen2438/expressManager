<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];
$userType = $_POST['userType'];

$values = 'signUp ' . $phone . ' ' . $passwd . ' ' . $userType;

$command = "../cpp/main " . escapeshellcmd($values);
// echo $command;
exec($command, $output);

// $file = fopen("signUp.txt", "w+") or die("Unable to open file!");
for ($i = 0; $i < count($output); $i++) {
    echo $output[$i];
    // fwrite($file, $output[$i] . "\n");
}
// fclose($file);
?>