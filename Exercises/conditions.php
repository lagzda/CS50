<?php
    //Simple condition program that checks if an inputed number is positive, negative or zero
    $n = readline("Please enter an integer: ");
    if ($n > 0){
        printf("You picked a positive number\n");
    }
    else if ($n == 0){
        printf("You picked zero\n");
    }
    else {
        printf("You picked a negative number\n");
    }
?>
