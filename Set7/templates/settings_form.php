<h1>Change your password</h1>
<form action="settings.php" method = "post">
    <div class="form-group">
        <label>Old password</label><br/>
        <input class="form-control" type="password" placeholder="Current password" name="old_pass" />
    </div>
    <div class="form-group">
        <label>New password</label><br/>
        <input class="form-control" type="password" placeholder="New password" name="new_pass" />
    </div>
    <div class="form-group">
        <label>Confirm</label><br/>
        <input class="form-control" type="password" placeholder="New password(again)" name="confirm" />
    </div>
    <div class="form-group">
        <button type="submit" class="btn btn-default">Change</button>
    </div>
</form>
