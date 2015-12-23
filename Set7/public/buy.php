<?php
    require("../includes/config.php");
    if ($_SERVER["REQUEST_METHOD"] == "GET"){
        render("buy_form.php", ["title" => "Buy"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST"){
        if (!preg_match("/^\d+$/", $_POST["shares"])){
            apologize("You can only buy whole positive number of shares");
        }
        $stock = lookup($_POST["symbol"]);
        if ($stock === false){
            apologize("That stock does not exist");
        }
        $rows = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $cash = $rows[0]["cash"];
        $price = $stock["price"] * $_POST["shares"];
        if ($cash < $price){
            apologize("You don't have enough cash");
        }
        else {
        $status1 = query("INSERT INTO portfolio (id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?",
        $_SESSION["id"], $stock["symbol"], $_POST["shares"], $_POST["shares"]);
        if (status1 !== false){
            query("UPDATE users SET cash = cash - ? WHERE id = ?", $price, $_SESSION["id"]);
            query("INSERT INTO history (id, action, symbol, shares, price, date) VALUES (?, 'BUY', ?, ?, ?, CURRENT_TIMESTAMP)",
            $_SESSION["id"], $stock["symbol"], $_POST["shares"], $stock["price"]);
            redirect("index.php");
        }
        }   
    }
?>
