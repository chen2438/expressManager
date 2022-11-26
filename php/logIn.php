<?php
$phone = $_POST['phone'];
$passwd = $_POST['passwd'];

$values = 'logIn ' . $phone . ' ' . $passwd;
$command = "../cpp/main " . escapeshellcmd($values);
exec($command, $output);

for ($i = 0; $i < count($output); $i++) {
    echo 'C++: ' . $output[$i];
    echo '<br>';
}
if ($output[count($output) - 1] == "Login successful!") {
    // header("refresh: 5;url=../recepient?phone=" . $phone . ".html");
    echo "PHP: Please wait 3 seconds to refresh.";
    echo '<br>';
} else {
    // header("refresh: 5;url=../html.html");
    echo "PHP: Please wait 3 seconds to turn back.";
    echo '<br>';
}
?>