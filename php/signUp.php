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
echo "Please wait 3 seconds to turn back.";
exit;
sleep(3);
header("Location: ../index.php");
exit;
// fclose($file);
?>