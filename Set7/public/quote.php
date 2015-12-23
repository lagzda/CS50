<?php

    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        render("quote_form.php", ["title" => "Quote"]);
    }    
    
    if($_SERVER["REQUEST_METHOD"] == "POST"){
        $stock = lookup($_POST["symbol"]);
        if($stock === false){
            apologize("Couldn't find the stock");
        }
        else{
            render("quote.php", ["price" => number_format($stock["price"], 2, '.', '')]);
        }
    }
?>
