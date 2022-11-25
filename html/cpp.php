<?php
$arr = $_POST['arr'];
if(empty($arr)){
    echo "You didn't enter any arguments.";
}
else{
    $command = "./test " . escapeshellcmd($arr);
    $return = passthru($command);
}
?>