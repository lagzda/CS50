<?php
    session_start();
    if(isset($_SESSION["counter"])){
        $counter = $_SESSION["counter"];
    }
    else{
        $counter = 0;
    }
    $_SESSION["counter"] = $counter + 1;
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Counter</title>
    </head>
    <body>
        <p>You visited this site <?= $counter ?> time(s).
    </body>
</html>
