<?php
$arr = $_POST['arr'];
if(empty($arr)){
    echo "Arguments are empty";
}
else{
    $command = "./login " . escapeshellcmd($arr);
    $return = passthru($command);
}
?>