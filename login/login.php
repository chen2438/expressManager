<?php
$file = fopen("login.txt", "w+");
$user_name = $_POST['user_name'];
$user_phone = $_POST['user_phone'];
$values = $user_name . ' ' . $user_phone;
if (empty($values)) {
    echo "values is empty";
} else {
    $command = "./login " . escapeshellcmd($values);
    exec($command, $output);
    echo $output;
}
fclose($file);
?>