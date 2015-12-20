<!--The structure will be quite similar in all other files in public-->
<!--Although I called this folder mvc I am still missing the model implementation which involves the use of a database-->
<!--Require the helper file which contains the render function and extract the title value and dynamically generates it to a page-->
<?php require("../includes/helpers.php"); ?>
<!--Render the header with the title parameter-->
<?php render("header", ["title" => "Beginning"]); ?>
<!--The only static content-->
<ul>
    <li><a href="middle.php">Middle</a></li>
    <li><a href="end.php">End</a></li>
</ul>
<!--Render the footer-->
<?php render("footer"); ?>
