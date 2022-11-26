<!DOCTYPE html>
<html lang="en-us">

<head>
    <meta charset="utf-8" />
    <title>Express Managert</title>
    <style>
        form {
            /* 居中表单 */
            margin: 0 auto;
            width: 400px;
            /* 显示表单的轮廓 */
            padding: 1em;
            border: 1px solid #CCC;
            border-radius: 1em;
        }

        ul {
            list-style: none;
            padding: 0;
            margin: 0;
        }

        form li+li {
            margin-top: 1em;
        }

        label {
            /* 确保所有 label 大小相同并正确对齐 */
            display: inline-block;
            width: 90px;
            text-align: right;
        }

        input,
        textarea {
            /* 确保所有文本输入框字体相同
     textarea 默认是等宽字体 */
            font: 1em sans-serif;

            /* 使所有文本输入框大小相同 */
            width: 300px;
            box-sizing: border-box;

            /* 调整文本输入框的边框样式 */
            border: 1px solid #999;
        }

        input:focus,
        textarea:focus {
            /* 给激活的元素一点高亮效果 */
            border-color: #000;
        }

        textarea {
            /* 使多行文本输入框和它们的 label 正确对齐 */
            vertical-align: top;

            /* 给文本留下足够的空间 */
            height: 5em;
        }

        .button {
            /* 把按钮放到和文本输入框一样的位置 */
            padding-left: 90px;
            /* 和 label 的大小一样 */
        }

        button {
            /* 这个外边距的大小与 label 和文本输入框之间的间距差不多 */
            margin-left: .5em;
        }
    </style>
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
                <input type="text" name="phone" />
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

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        名字: <input type="text" name="name" value="<?php echo $name; ?>">
        <span class="error">*
            <?php echo $nameErr; ?>
        </span>
        <br><br>
        E-mail: <input type="text" name="email" value="<?php echo $email; ?>">
        <span class="error">*
            <?php echo $emailErr; ?>
        </span>
        <br><br>
        网址: <input type="text" name="website" value="<?php echo $website; ?>">
        <span class="error">
            <?php echo $websiteErr; ?>
        </span>
        <br><br>
        备注: <textarea name="comment" rows="5" cols="40"><?php echo $comment; ?></textarea>
        <br><br>
        性别:
        <input type="radio" name="gender" <?php if (isset($gender) && $gender == "female")
       echo "checked"; ?>
        value="female">女
        <input type="radio" name="gender" <?php if (isset($gender) && $gender == "male")
       echo "checked"; ?> value="male">男
        <span class="error">*
            <?php echo $genderErr; ?>
        </span>
        <br><br>
        <input type="submit" name="submit" value="Submit">
    </form>
</body>

</html>