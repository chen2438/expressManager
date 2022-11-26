<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="utf-8" />
    <title>Express Managert</title>
    <link href="css/styles.css" type="text/css" rel="stylesheet">
    <script src="js/script.js" type="text/javascript"></script>
</head>

<body>
    <?php
    // exec("g++ cpp/MyDB.cpp cpp/main.cpp -o cpp/main `mysql_config --cflags --libs`");
    ?>
    <form action="php/signUp.php" method="post">
        <ul>
            <li>
                <h3>Sign Up</h3>
            </li>
            <li>
                <label for="phone">Phone:</label>
                <input type="text" name="phone" class="phone" />
            </li>
            <li>
                <label for="passwd">Password:</label>
                <input type="text" name="passwd" />
            </li>
            <li>
                <label for="userType">User Type:</label>
                <input type="text" name="userType" placeholder="'0' for recepient, or admin password for collector" />
            </li>
            <li class="button">
                <button type="submit">confirm</button>
            </li>
        </ul>
    </form>


</body>

</html>