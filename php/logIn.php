<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];

$values = 'logIn ' . $phone . ' ' . $passwd;

$command = "../cpp/main " . escapeshellcmd($values);
exec($command, $output);

// $file = fopen("signUp.txt", "w+") or die("Unable to open file!");
for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
    // fwrite($file, $output[$i] . "\n");
}

// header("refresh: 5;url=../index.html");
echo "PHP: Please wait 3 seconds to turn back.\n";

exit;
// fclose($file);
?>