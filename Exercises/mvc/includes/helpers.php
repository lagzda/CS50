<?php
    //Define the function for rendering template
    //If data parameter is empty it is simply initiated to an empty array
    function render($template, $data = []){
        //Get the absolute path of the template file we want to include
        $path = __DIR__ . "/../templates/" . $template . ".php";
        //If file exists extract data and require the actual template
        if(file_exists($path)){
            extract($data);
            require($path);
        }
    }
?>
