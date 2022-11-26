<?php
$file = fopen("signUp.txt", "w+") or die("Unable to open file!");

$phone = $_POST['phone'];
$passwd = $_POST['passwd'];
$userType = $_POST['userType'];

$values = 'signUp' . $phone . ' ' . $passwd . ' ' . $userType;

$command = "./main " . escapeshellcmd($values);
exec($command, $output);
for ($i = 0; $i < count($output); $i++) {
    fwrite($file, $output[$i] . "\n");
}
fclose($file);
?>