<?php
$file = fopen("login.txt", "w+") or die("Unable to open file!");
$user_name = $_POST['user_name'];
$user_phone = $_POST['user_phone'];
$values = $user_name . ' ' . $user_phone;
if (empty($values)) {
    fwrite($file, "values is empty");
} else {
    $command = "./login " . escapeshellcmd($values);
    exec($command, $output);
    for ($i = 0; $i < count($output); $i++) {
        fwrite($file, $output[$i] . "\n");
    }
}
fclose($file);
?>