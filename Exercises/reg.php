<!DOCTYPE html>
<html>
    <head>
        <!--Title of page-->
        <title>Register Status</title>
    </head>
    <body>
        <!--Visible title of page-->
        <h1>Register Status</h1>
        <!-- If one of the form fields is empty throw error and provide the opportunity to go back and edit form-->
        <?php if (empty($_POST["name"]) || empty($_POST["age"]) || empty($_POST["gender"])): ?>
            Unfortunately you have missing fields. Please go <a href="reg_site.php">back</a> to edit your form.
        <!--If all is ok show the details that the user is registering with-->    
        <?php else: ?>
            You are registering (just kidding) with these details:
            <br/>
            <?php print_r($_POST)?>
        <?php endif ?>        
    </body>
</html>

