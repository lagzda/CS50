<?php
    require("../includes/config.php");
    
    
    
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        $rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
        if ($rows === []){
            apologize("Nothing to sell");
        }
        else{
            $positions = [];
            foreach($rows as $row){
                $positions[] = [
                    "symbol" => $row["symbol"] 
                ];
            }
            render("sell_form.php", ["title" => "Sell", "positions" => $positions]);
        }
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST"){
        $rows = query("SELECT shares, symbol FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        $shares = $rows[0]["shares"];
        $stock = lookup($rows[0]["symbol"]);
        $status = query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        if ($status === false){
            apologize("The transaction was not successful");
        }
        else{
            $profit = $stock["price"] * $shares;
            query("UPDATE users SET cash = cash + ? WHERE id = ?", $profit, $_SESSION["id"]);
            query("INSERT INTO history (id, action, symbol, shares, price, date) VALUES (?, 'SELL', ?, ?, ?, CURRENT_TIMESTAMP)",
            $_SESSION["id"], $stock["symbol"], $shares, $stock["price"]);
            render("sell.php", ["title" => "Sell", "profit" => $profit]);
        }
    }
?>
