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
    echo "\n";
    // fwrite($file, $output[$i] . "\n");
}

header("refresh:5;url=http://www.XXXXX.com");
echo "Please wait 3 seconds to turn back.\n";

exit;
// fclose($file);
?>