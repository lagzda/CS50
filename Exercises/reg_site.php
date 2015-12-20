<!DOCTYPE html>
<html>
    <head>
        <!--Title of page-->
        <title>Register</title>
    </head>
    <body>
        <!--Visible title of page-->
        <h1>Register</h1>
        <!--Form will be sent to reg.php which is in the same folder-->
        <form action="reg.php" method="post">
            Name: <input type="text" name="name"/>
            <br/>
            Age: <input type="number" name="age"/>
            <br/>
            <input type="radio" name="gender" value="F"/> Female 
            <input type="radio" name="gender" value="M"/> Male
            
            <input type="submit" value="Register"/>
        </form>
    </body>
</html>

