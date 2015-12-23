<?php
    require("../includes/config.php");  
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        $positions = [];
        $rows = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
        if ($rows === false) {
            apologize("Someting went wrong");
        }
        else {
            foreach ($rows as $row) {
                $positions[] = [
                    "action" => $row["action"],
                    "symbol" => $row["symbol"],
                    "shares" => $row["shares"],
                    "price" => $row["price"],
                    "date" => $row["date"]
                ];    
            }
            render("history.php", ["positions" => $positions]);
        }
    }
?>
