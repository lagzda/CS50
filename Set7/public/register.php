<?php

    //Configuration
    require('../includes/config.php');
    
    //If page reached via GET then render page
    if($_SERVER["REQUEST_METHOD"] == "GET"){
        render('register_form.php', ["title" => "Register"]);
    }
    //If page reached via POST then submit form
    else if($_SERVER["REQUEST_METHOD"] == "POST"){
        if(empty($_POST["username"]) || empty($_POST["password"])){
            apologize("You shouldn't leave any fields blank");
        }
        else if($_POST["password"] !== $_POST["confirmation"]){
            apologize("Passwords do not match");
        }
        else{
            $status = query("INSERT INTO users (username, hash, cash) VALUES (?,?,10000.00)", $_POST["username"], crypt($_POST["password"]));
            if($status === false){
                apologize("Username already exists");
            }
            else{
                $rows = query("SELECT LAST_INSERT_ID() AS id");
                $_SESSION["id"] = $rows[0]["id"];
                redirect("/");
            }
        }
    }
?>
