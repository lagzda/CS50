<h1>Buy</h1>
<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <label for="symbol">Symbol</label>
            <input class="form-control" type="text" name="symbol" placeholder="Symbol" required />
        </div>
        <div class="form-group">
            <label for="shares">Shares</label>
            <input class="form-control" type="number" name="shares" required />
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Buy</button>
        </div>
    </fieldset>
</form>
