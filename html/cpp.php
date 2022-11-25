<?php
$arr = $_POST['arr'];
if(empty($arr)){
    echo "Arguments are empty";
}
else{
    $command = "./test " . escapeshellcmd($arr);
    $return = passthru($command);
}
?>