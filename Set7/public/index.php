<?php

    // configuration
    require("../includes/config.php");
    
    $username = "";
    $positions = [];
    $cash = "";
    
    //Set a username to greet the user and get the users portfolio
    if (!empty($_SESSION["id"])){
        //Get username
        $rows = query("SELECT username, cash FROM users WHERE id = ?", $_SESSION["id"]);
        $username = $rows[0]["username"];
        
        //Get user's cash
        $cash = number_format($rows[0]["cash"], 2, '.', '');
        
        //Get user's portfolio
        $rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
        foreach($rows as $row){
            $stock = lookup($row["symbol"]);
            if ($stock !== false){
                $positions[] = [
                    "name" => $stock["name"],
                    "price" => $stock["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"]
                ];
            }
        }
        
    }
    
    
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "username" => $username, "cash" => $cash, "positions" => $positions]);

?>
