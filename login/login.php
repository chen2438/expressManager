<?php
$user_name = $_POST['user_name'];
$user_phone = $_POST['user_phone'];
$values = $user_name .' '.$user_phone;
if(empty($values)){
    echo "values is empty";
}
else{
    $command = "./login " . escapeshellcmd($values);
    $return = passthru($command);
}
?>