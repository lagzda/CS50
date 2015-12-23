<?php
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] == "GET") {
        render("settings_form.php", ["title" => "Settings"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $rows = query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        $password = $rows[0]["hash"];
        printf ("%s,%s", $password, crypt($_POST["old_pass"]));
        if (crypt($_POST["old_pass"], $password) == $password) {
            if ($_POST["new_pass"] ===  $_POST["confirm"]) {
                $status = query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["new_pass"]), $_SESSION["id"]);
                if ($status === false) {
                    apologize("An error ocurred");
                }
                else {
                    redirect("index.php");
                }
            }
            else {
                apologize("The new passwords do not match");
            }   
        }
        else {
            apologize("The old password is not correct");
        }
    }      
?>
